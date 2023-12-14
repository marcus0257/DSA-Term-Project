# Splay Tree Data Structure — Splay Tree

Implementing Splay Trees in an Express JavaScript Server for Autocomplete

In this project, we incorporated Splay Trees into an Express JavaScript server to enhance the autocomplete feature of a search engine on the frontend. This involved suggesting autocompletions for searches and optimizing search results by splaying searches to the top of the autocomplete list for subsequent access.

## Splay Trees: A Brief Overview

Splay Trees are a self-adjusting binary search tree with the property that recently accessed elements are quick to access again. This property makes them suitable for optimizing search operations. When a node is accessed, it is moved to the root of the tree, reducing future access time for that node.

## Implementation Details

1. **Express JavaScript Server:**
   - We utilized the Express framework to build a JavaScript server that handles search requests and provides autocomplete suggestions.
   - The server is designed to efficiently interact with the Splay Trees to retrieve relevant search results.

2. **Autocomplete on the Frontend:**
   - The frontend incorporates a search bar similar to Google's, allowing users to type their queries.
   - As users type, the server suggests autocompletions based on the Splay Tree's search results, providing a dynamic and responsive experience.

3. **Splaying Searches:**
   - Each search query is splayed to the top of the Splay Tree, ensuring that frequently searched terms become quickly accessible for subsequent users.

## User Interaction Visualization

![Search Bar](Users/marcusdiaz/Downloads/searchh.png)
*Figure 1: A visual representation of the search bar on the frontend, allowing users to input queries.*

![Search Results Turning Purple](Users/marcusdiaz/Downloads/searchh.png)
*Figure 2: Visualization of the search results turning purple, indicating the optimized search result through Splay Trees.*

---

&copy; 2023 My Documentation. All rights reserved.
