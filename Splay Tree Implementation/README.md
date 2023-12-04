# Splay Tree Implementation
For our splay tree implementation we created a search autofiller. The following changes were made to our original splay tree class in order to acheive this:
  - Updated splayNode with 2 additional data members; bool purple and std::string query
  - Updated constrcutors and insert function to handle these extra parameters
  - Added LevelOrder function that writes the tree structure to the output file in level order
  - Updated InOrder function to write tree structure to output file

Required Packages: <br>
  - Node
  - Express
  - Nodemon (if running in local browser)
  - Body Parser
  
