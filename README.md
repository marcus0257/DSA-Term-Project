# DSA-Term-Project
Group Members: Justin Chacon, Marcus Diaz, Angel Castano, Monet Gailloux

Our project was the splay tree data structure. We created two splay tree classes under Initial Splay Tree and Splay Tree Implementation.

**Initial Splay Tree** <br>
  The initial splay tree folder contains our basic implementation of a splay tree. Which behaves very similar to a binary search tree, except for its ability to perform "splays". Splays are a method of structuring the tree based on inserts,deletes and searches. Splays follow what is called a zig zag pattern. What is special about splay trees is that searched items are splayed to the root of the tree, allowing for faster referencing to frequently used nodes. Our main file under the inital splay tree folder shows an example of this.
The Inital Splay Tree main file is compiled using the following line:
- g++ main.cpp splay.cpp -o test

**Splay Tree Implementation** <br>
The splay tree implementation folder contains our application of the splay tree data structure for use as a suggested-search autofiller. There is a second README.md inside the folder which contains a list of changes as well as dependencies.

Below is a visualization of the splaying operation, in which node D, is searched and subsequently brought to the root use a mix of zigs and zags.
![Alt text](https://github.com/Jusconn/DSA-Term-Project/blob/main/imgs/Splay_Tree_Search_Animation.gif?raw=true)


