const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const { spawn } = require('child_process');

const app = express();
const port = 3000;
const dic = {
"How to tie a shoe" : 1,
"How to cut steak" : 2,
"How to do a flip" : 3,
"How to reset iPhone password" : 4,
"How to steal from target" : 5,
"How to set up a node.js server" : 6,
"How to eat oysters" : 7,
"How to play catan" : 8,
"How to sleep on your side" : 9,
"How to be friends with a crow" : 10,
"How to write a book" : 11,
"How to potty train your son" : 12,
"How to win at slots" : 13,
"How to sew ripped jeans" : 14,
"How to do my tax return" : 15}

// Serve static files from the 'public' directory
app.use(express.static(path.join(__dirname, '..', 'public')));

// Use body-parser middleware to parse JSON in the request body
app.use(bodyParser.json());

// Handle GET requests for the home page
app.get('/', (req, res) => {
    // This route should handle dynamic content, not static files
    res.sendFile(path.join(__dirname, '..', 'public', 'index.html'));
});

// Handle POST requests to the "/submit" endpoint
app.post('/submit', (req, res) => {
    const formData = req.body;
    const string = formData.query;
    const x = dic[string];
    

    // Process the form data as needed
    console.log('Received form data:', formData);
    console.log(string);
    console.log(x);

    if (string === null || dic[string] === undefined) {
        // Respond with an error or appropriate message
        return res.status(400).json({ error: 'Invalid input or not in the dictionary' });
    }

    
    const backProcess = spawn('src/backend.exe', [x], { stdio: 'inherit' });
    const frontProcess = spawn('src/json.exe', [], { stdio: 'inherit' });
    
    backProcess.on('exit', (code, signal) => {
        console.log(`Child process exited with code ${code} and signal ${signal}`);
    });
    
    backProcess.on('error', (err) => {
        console.error('Error during backend.exe execution:', err);
    });

    // Respond with a success message or perform other actions
    res.json({ message: 'Form submitted successfully!' });
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}/`);
});
