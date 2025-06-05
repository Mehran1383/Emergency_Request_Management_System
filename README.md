# Emergency Request Management System

## Project Description
A priority queue management system for processing emergency requests with fast search capabilities. The system combines a **Heap** for priority-based processing and a **Binary Search Tree (BST)** for efficient search and deletion operations.

## Key Features
1. **Add New Request**
   - Stores complete request details (ID, name, time, priority, description) in BST
   - Stores only priority and request ID in Heap for fast processing

2. **Process High-Priority Request**
   - Extracts from Heap (priority queue)
   - Removes corresponding entry from BST using the request ID

3. **Search by Request ID**
   - Performed efficiently using BST

4. **Update Request Priority**
   - Removes and re-inserts request in Heap with new priority
   - BST remains unchanged during priority updates

## Data Structures Used
- **Heap (Priority Queue)**
  - Implemented using array
  - Stores only priority and request ID
  - Enables O(1) access to highest priority request

- **Binary Search Tree**
  - Stores complete request information
  - Enables O(log n) search operations by request ID

