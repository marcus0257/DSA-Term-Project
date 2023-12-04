# Splay Tree Implementation
For our splay tree implementation we created a search autofiller. The following changes were made to our original splay tree class in order to acheive this:
  - Updated splayNode with 2 additional data members; bool purple(representing if the query has already been searched) and std::string query(representing the autofill result)
  - Updated constrcutors and insert function to handle these extra parameters
  - Added LevelOrder function that writes the tree structure to the output file in level order
  - Updated InOrder function to write tree structure to output file

Required Packages:
  - Node
  - Express
  - Nodemon (if running in local browser)
  - Body Parser

![Alt text](https://github.com/Jusconn/DSA-Term-Project/blob/main/imgs/demo-home.png?raw=true)
^ Web form ^ <br>
We set up a simple web page that contains a form which the user can submit their search into. The form sends a POST to the express server we are using as the backend. The server then uses child processes to run c++ executables which update a text file containing the current state of the tree, and a json file containing the autofill results, their original index in the list and whether or not to be displayed as purple in the autofiller.
Server running locally <br>
v server running locally v
![Alt text](https://github.com/Jusconn/DSA-Term-Project/blob/main/imgs/server-startup.png?raw=true)



The main.cpp and main_2.cpp were compiled using the following lines inside of the src terminal
- g++ main.cpp splay.cpp -o backend.exe
- g++ main_2.cpp -o json.exe

Executables were not include in this repository, please compile on your own before trying to run server!


  
