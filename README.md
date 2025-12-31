# PROGRAM5_GRAPH
Programming Assignment 5
Working with Graphs

Description:
You are to develop a C++ class called Graph that represents a weighted, directed graph.  
You may represent your graph using either of the two standard graph representations discussed in class.  
Your class must clearly and correctly use either an adjacency matrix or an adjacency list representation.  
It is your choice which of the two representations you use. Your class must provide the following public methods:
	•	readGraph will accept the name of a file as a parameter and read in a new graph from that file (replacing whatever the object currently holds, if anything). It will return a bool which will be true unless the input file could not be opened. It should not print anything to the console, even if an error occurs opening the file, just return the appropriate bool value.
	•	printGraph will print your graph to standard output (cout) in the same format as the graphs you are reading. This must read the data from your class member variables (e.g., adjacency matrix/list, etc.), and is primarilty meant to be used as a debugging tool for you. Do not just store the file contents in a string and regurgitate them to the console.
	•	computeTopologicalSort will print to standard output a topological sort of the graph or an error message indicating that a topological sort of the graph is not possible. You will use a queue for the algorithm. See below for the exact output format.
	•	computeShortestPaths will accept a node name as a parameter and print to standard output the actual path and the cost to each other vertex that can be reached (one path and cost per line). For any nodes that cannot be reached, it will print a message indicating that. Again, see below for the exact output format. You must use Dijkstra’s algorithm implemented using a priority queue as discussed in class (NOTE: the book does not use this algorithm; do not use the book’s code). For a refresher on the algorithm, please refer to the Dr Califf’s Djikstra’s shortest paths videos as necessary.
	•	computeMinimumSpanningTree will print to standard output a list of the edges in the minimum spanning tree for the graph, one per line, with the weight of each edge, followed by the total weight of the minimum spanning tree. 
	See below for the exact output format.
	Your method will have the graph being connected as a precondition (and your comments must make that clear). 
	You will compute the minimum spanning tree with Kruskal’s algorithm, using your DisjointSet class from program 4. 
	In order to guarantee that your results match the provided output, make sure that your sort of the edges orders by edge weight (obviously), 
	then index of the from node, then index of the to node.  
If you are allocating memory dynamically, your class MUST handle it correctly. 
You are, however, encouraged to make use of relevant STL classes such as vector, list, stack, queue, priority_queue, etc. There is a sample program for making a vector of vectors provided. Making a vector of lists is very similar (but a little easier)).

Note that this must be an efficient class, so the graph representation and all of the algorithms must treat the nodes as integer indices.
You will immediately translate node names into the appropriate index when reading data from the user or the file, and translate back from index to node name only when printing.

You are being provided with a program that will use your Graph class (a single object of it) to allow the user to perform the various functions required. The program makes use of a TextMenu class that you will not submit. You will need to modify the graphRunner.cpp file to add your calls to the Graph class, but do not alter the basic functionality. Your program will be automatically evaluated for correctness (as usual), so it is important that your output match the provided information and the correct output format. Spacing discrepancies count as differences in the program output. You are strongly recommended to use the test data provided along with the diff command to confirm the correctness of your output.

Note that stray debugging printing will cause your program’s output to be incorrect. 
Make sure any such print statements are eliminated (commented or removed) prior to submission.
In general, unless the debugging code would be helpful when making later changes to a program, we want to delete it.

Input file format:
The input file will consist of 4 parts:
	•	The number of vertices
	•	The vertex names, one per line – these will be character strings which will not include spaces
	•	The number of edges
	•	Edge data with one edge per line – first vertex, second vertex, weight. 
The elements will be separated by spaces

You may assume that all edges will have positive non-zero integer weights. 
You may also assume that there will be at least one vertex, though there may be zero edges. The input file format file format is guaranteed and is designed to simplify reading the graph. Make sure your life easier by using >> for reading item by item instead of approaches like getline.

The starting code and sample files can be found in /home/ad.ilstu.edu/mbhatt1/Public/it279/Program5.
Here is a short description of each of the files:
	•	sampleInputFile.txt à A collection of inputs that you can redirect your console input to, to perform a consistent test of your program.
	•	sampleOutputFile.txt à The console output that should be produced by your program, when you use console output redirection
	•	sampleOutputFile-withInput.txt à The text that should be displayed in your console when you run the program and its inputs manually.
	•	graph1.txt, graph2.txt à Two sample graph input files you can (and should) use to test your program.
	•	TextMenu.h and TextMenu.cppà The class used to display the program menu and get the user’s choices (with validation).
	•	graphRunner.cpp à The file with main. You will add calls to your graph class to complete this program. Places where you need to add code are indicated with comments.

You will write Graph.h and Graph.cpp from scratch, to match the above specifications.

You can use the input and output files most effectively by running the following commands, which will perform input and output redirection for your program and compare the output files:

./a.out < sampleInputFile.txt > mySampleOutputFile.txt
diff sampleOutputFile.txt mySampleOutputFile.txt

You are highly encouraged to do your own testing beyond the input files that are provided to you, 
since there is no guarantee that every test case is covered with the above files. 
It is always recommended that you test your program as you go
and write your own test inputs that you can use to validate whether your program is working as expected or not.

Output specifications:

Topological Sort:
First print “Topological Sort:\n”
For a successful topological sort, the node names will be printed on a single line, separated by arrows, ending with a newline character. For example:
A --> B --> C --> D\n
If a topological sort is not possible, print the message “This graph cannot be topologically sorted.\n”.

Shortest Path:
First, print “Shortest paths from ” + the name of the node + “:\n”
For each node that can be reached, print the path in this form:
v1 --> v3 --> v6 --> v4 || Weight: 13
For a node that cannot be reached, print:
No path from startingNodeName to nodeNameThatCouldNotBeReached found.
In either case, the output for each target node will be on one line followed by a newline character.

Minimum Spanning Tree:
First, print “Minimum Spanning Tree:\n”
Then list each edge as the two nodes separated by two hyphens followed by the weight of the edge, as formatted below (note the spacing as well):
LAX -- SFO || Weight: 400
At the bottom print:
Total Cost: theCostOfTheTree
There’s just one space there.

The diff command will be used to validate the accuracy of your printed output. In order for your printed output to be correct, the spacing also MUST match. See the provided sample input and output files mentioned above for further details, and feel free to ask for clarification where needed.


Zip your program files (DisjointSet.cpp, Graph.h, Graph.cpp, and graphRunner.cpp) and submit the zip file to Canvas. 
As always, make sure you do not zip folders, only the files.
