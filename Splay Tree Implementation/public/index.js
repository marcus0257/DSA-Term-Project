let availableKeywords = [];
let indices = [];
let purple = [];
async function loadDictionary() {
    try {
        const response = await fetch('info.json');
        const data = await response.json();
        return data.queries;
    } catch (error) {
        console.error('Error loading keywords:', error);
        return [];
    }
}
async function loadIndices() {
    try {
        const response = await fetch('info.json');
        const data = await response.json();
        return data.indexes;
    } catch (error) {
        console.error('Error loading indices:', error);
        return [];
    }
}
async function loadPurple() {
    try {
        const response = await fetch('info.json');
        const data = await response.json();
        return data.purple;
    } catch (error) {
        console.error('Error loading purple:', error);
        return [];
    }
}
loadDictionary()
    .then(data => {
        availableKeywords = data;
        console.log(availableKeywords);
    })
    .catch(error => {
        console.error('Error initializing keywords:', error);
    });
    
    loadIndices()
    .then(data => {
        indices = data;
        console.log(indices);
    })
    .catch(error => {
        console.error('Error initializing keywords:', error);
    });

    loadPurple()
    .then(data => {
        purple = data;
        console.log(purple);
    })
    .catch(error => {
        console.error('Error initializing keywords:', error);
    });

    function submitForm(event) {
        event.preventDefault(); // Prevent the form from submitting normally

        // Your custom logic for handling the form submission
        const inputBoxValue = document.getElementById('input-box').value;
        console.log('Form submitted with value:', inputBoxValue);

        // Make a POST request to your server

        fetch('http://localhost:3000/submit', {

        method: 'POST',

        headers: {

            'Content-Type': 'application/json',

        },

        body: JSON.stringify({

            query:inputBoxValue,

            // Add more fields as needed

        }),

    })

    .then(response => response.json())

    .then(data => {

        console.log('Response from server:', data);

        // Handle the response from the server as needed

    })

    .catch(error => console.error('Error:', error));
}

const resultBox = document.querySelector(".result-box");
const inputBox = document.getElementById("input-box");

inputBox.onkeyup = function () {
    let result = [];
    let p = [];
    let input = inputBox.value.toLowerCase();

    if (input.length) {
        result = availableKeywords.filter((keyword, index) => {
            if (keyword.toLowerCase().includes(input)) {
                p.push(index);
                return true;
            }
            return false;
        });
        console.log(result);
        console.log(p); // Indices of filtered keywords
    }

    display(result,p);

    if (!result.length) {
        resultBox.innerHTML = '';
    }
};


function display(result,p){
    const content = result.map((list, index) => {
        const isPurple = purple[p[index]] !== 0; // Check if purple value is not 0 for the corresponding index
        const textColor = isPurple ? 'purple' : 'black';
        return `<li onclick="selectInput(this)" style="color: ${textColor};">${list}</li>`;
    });

    resultBox.innerHTML = "<ul>" + content.join(' ') + "</ul>";
}

function selectInput(list){
    inputBox.value = list.innerHTML;
    resultBox.innerHTML = '';
}