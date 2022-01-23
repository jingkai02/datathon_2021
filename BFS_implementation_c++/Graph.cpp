#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <functional>   // std::greater
#include <algorithm>
#include <tuple>
#include <set>  

typedef pair<double, string> pi;
typedef tuple<double, string, string> minpqweight;
using namespace std;

//Step1: implement a disjointset helper class
class disjointset{
    // private:
    //     unordered_map<string,string> uptree;
    public:
        //Constructor
        //initialize all nodes in their own set;
        //create a forest of sentinel nodes; 
        unordered_map<string,string> uptree;
        disjointset(unordered_map<string,unordered_map<string,double>> adjacencylist){
            for(auto it : adjacencylist){
            uptree.insert({it.first, ""});
            }
        }

        // int size(string u){};
        string Find(string u){
            if(uptree[u] == ""){
                return u;
            }

            else{ return Find(uptree[u]);}
        }

        void Union(string u,string v){
            string uParent = Find(u);
            string vParent = Find(v);

            //if u and v is in the same set, do nothing
            if(uParent == vParent){ return;}
            //first Arbitrarily put vParent as uParent's parent
            uptree[uParent] = vParent;
        }
};

// Constructor definition outside the class
// disjointset::disjointset(unordered_map<string,unordered_map<string,double>> adjacencylist){
//     //initialize all nodes in their own set;
//     //create a forest of sentinel nodes;
//     for(auto it : adjacencylist){
//         uptree.insert({it.first, ""});
//     }
// }

// // Method/function definition outside the class
// // int disjointset::size(string u){

// // }

// string disjointset::Find(string u){
//     if(uptree[u] == ""){
//         return u;
//     }

//     else{ return Find(uptree[u]);}
// }

// void disjointset::Union(string u,string v){
//     string uParent = Find(u);
//     string vParent = Find(v);

//     //first Arbitrarily put vParent as uParent's parent
//     uptree[uParent] = vParent;
// }

Graph::Graph(const char* const & edgelist_csv_fn) {
    // TODO

    //parse .csv file and store info into data structures.

    //TO DO: Handle edge cases like file does not exist.

    //The code snippet below of parsing .csv files is from Project2 Design Notes
    ifstream my_file(edgelist_csv_fn);      // open the file
    string line;                     // helper var to store current line
    
    //Read file twice. 
    //For the first time insert every node with empty neigbors to adjacencylist
    //also set all nodes as unvisited(0) in the vector visited.  
    while(getline(my_file, line)) {  // read one line from the file
        istringstream ss(line);      // create istringstream of current line
        string first, second, third; // helper vars
        getline(ss, first, ',');     // store first column in "first"
        getline(ss, second, ',');    // store second column in "second"
        getline(ss, third, '\n');    // store third column column in "third"

        //print statment to check if parsing is correct
        //cout << first << ", " << second << ", " << third << endl;

        //Build the adjacency list
        //Case1: node appears for the first time. 
        if(adjacencylist.find(first) == adjacencylist.end()){
            //insert it with an empty map of neighbors to the list.
            
            //potential problem: Memory leak! No way to retrieve this neighbors
            //unordered_map<string,double> neighbors; // empty map of neighbors
            adjacencylist.insert({first,{}});
            //set all nodes as unvisited
            //visited.insert({first,0});
        }

        if(adjacencylist.find(second) == adjacencylist.end()){
            //insert it with an empty map of neighbors to the list.
            
            //potential problem: Memory leak! No way to retrieve this neighbors
            //unordered_map<string,double> neighbors; // empty map of neighbors
            adjacencylist.insert({second,{}});
            //set all nodes as unvisited
            //visited.insert({second,0});
        }


    }
    //Closing the file
    my_file.close();

    //For the second time, add all edges to adjacencylist.
    //TO DO: find a clean way to read the file again. (like reset())
    ifstream my_file2(edgelist_csv_fn);     // open the file again
    //string line;                     // helper var to store current line

    while(getline(my_file2, line)) {  // read one line from the file
        istringstream ss(line);      // create istringstream of current line
        string first, second, third; // helper vars
        getline(ss, first, ',');     // store first column in "first"
        getline(ss, second, ',');    // store second column in "second"
        getline(ss, third, '\n');    // store third column column in "third"

        //print statment to check if parsing is correct
        //cout << first << ", " << second << ", " << third << endl;

        //Adding all edges and weights to neighbors.
        //insert the new edge with its weight to the neighbors list. 
        adjacencylist.find(first)->second.insert({{second, stod(third)}});
        adjacencylist.find(second)->second.insert({{first, stod(third)}});
        //print statement to check insertion content
        //cout << "inserting: " << first << "-" << second << ", " << third << endl;
        //cout << "inserting: " << second << "-" << first << ", " << third << endl;
    }

    //Closing the file
    my_file2.close();

    //print statement to check the content of adjacencylist
    // for(auto it = adjacencylist.cbegin(); it != adjacencylist.cend(); it++){
    //     cout << (*it).first << "- " << endl;
    //     for(auto it2 = ((*it).second).cbegin(); it2 != ((*it).second).cend(); it2++){
    //     cout << "  " << (*it2).first << ", " << (*it2).second << endl;
    //     }
    // }
    
}

unsigned int Graph::num_nodes() {
    // TODO
    return adjacencylist.size();
}

vector<string> Graph::nodes() {
    // TODO
    vector<string> nodes;
    for(auto it = adjacencylist.cbegin(); it != adjacencylist.cend(); it++){
        nodes.push_back((*it).first);
    }

    return nodes;
}

// unordered_map<string,int> Graph::Isvisited(){
//     return visited;
// }

unsigned int Graph::num_edges() {
    // TODO
    unsigned int edgeCount = 0;
    for(auto it = adjacencylist.cbegin(); it != adjacencylist.cend(); it++){
        edgeCount += ((*it).second.size());
    }

    edgeCount = edgeCount / 2;
    return edgeCount;
}

unsigned int Graph::num_neighbors(string const & node_label) {
    // TODO

    //handle edge case: node not found 
    if(adjacencylist.find(node_label) == adjacencylist.cend()){
        return 0;
    }

    unordered_map<string,double> neighbors = (*(adjacencylist.find(node_label))).second;
    return neighbors.size();
}

double Graph::edge_weight(string const & u_label, string const & v_label) {
    // TODO

    //handle edge case: node not found 
    if(adjacencylist.find(u_label) == adjacencylist.cend()){
        return -1.0;
    }

    //handle edge case: node not found 
    // if(adjacencylist.find(v_label) == adjacencylist.cend()){
    //     return 0;
    // }

    //find the neighbors of u_label
    //potential problem: will find(u_label) return the pointer to the end? 
    unordered_map<string,double> neighbors = (*(adjacencylist.find(u_label))).second;
    //check if v_label is a neighbor of u_label
    if(neighbors.find(v_label) != neighbors.cend()){
        return (*(neighbors.find(v_label))).second;
    }

    else{return -1.0;}
}

vector<string> Graph::neighbors(string const & node_label) {
    // TODO
    vector<string> nei;
    //handle edge case: node not found 
    if(adjacencylist.find(node_label) == adjacencylist.cend()){
        return nei;
    }
    //find the neighbors of node_label
    //potential problem: will find(u_label) return the pointer to the end? 
    unordered_map<string,double> neighbors = (*(adjacencylist.find(node_label))).second;
    for(auto it = neighbors.cbegin(); it != neighbors.cend(); it++){
        nei.push_back((*it).first);
    }
    return nei;
}

vector<string> Graph::shortest_path_unweighted(string const & start_label, string const & end_label) {
    // TODO: Write BFS based on https://stepik.org/lesson/28946/step/8?unit=9958
    
    //edge case1: start or end label not in Graph
    vector<string> spu; //shortest_path_unweighted
    if(adjacencylist.find(start_label) == adjacencylist.cend() || adjacencylist.find(end_label) == adjacencylist.cend()){
        //warning message
        //cout << "Warning: at least one label is not in graph." << endl;
        return spu;
    }

    //edge case2: start_label is the same as end_label
    if(start_label == end_label){
        //warning message
        // cout << "Warning: Start_label: " << start_label << " equals end_label: " << end_label << endl;
        // cout << "shortest_path_unweighted is simply: " << start_label << endl;
        spu.push_back(start_label);
        return spu;
    }

    //print statment for debugging
    //cout << "Finding the shortest_path_unweighted from " << start_label << " to " << end_label << endl;
    //First mark all nodes as not visited
    unordered_map<string,bool> visited;
    for(auto it : adjacencylist){
        visited.insert({it.first, false});
    }

    //Using an unordered_map to store the distances of nodes from start_label;
    unordered_map<string,int> dist;
    
    // BFS(u,v):
    queue<pair<int, string>> q;// q = an empty queue
    q.push(make_pair(0,start_label));// add (0,u) to q // (0,u) -> (length from u, current vertex)
    while(!q.empty()){// while q is not empty:
        pair<int,string> curr = q.front();//     curr.first = dist, curr.second = node
        q.pop();                          //     (length,curr) = q.dequeue()
        visited[curr.second] = true;         //     mark curr as visited
        dist.insert({curr.second, curr.first}); //also store this information to dist.
        //print statement to check content
        //cout << "inserting to dist: " << curr.second << ": " << curr.first << endl;
        if(curr.second == end_label){      //     if curr == v: // if we have reached the vertex we are searching for
            //return curr.first;//         instead of return length, simply stop bfs and search the path from v to u.
            //print statment to check the condition
            //cout << "End/Current label: " << end_label << " / " << curr.second << endl;
            break;
        }
        unordered_map<string,double> neighbors = (*(adjacencylist.find(curr.second))).second;
        for(auto it : neighbors){ //for all outgoing edges (curr,w) from curr: // otherwise explore all neighbors
            if(!visited[it.first]){//if w has not yet been visited:
                q.push(make_pair(curr.first+1, it.first));//add (length+1,w) to q
            }

            //print statement for debugging
            // else{
            //     cout << "visited status: " << visited[it.first] << endl; 
            // }
        }
    }
    
    //problem: This block below did not set visit to 0?
    //reset all nodes as not visited.
    // for(auto it : visited){
    //     it.second = ;

    //     //print statment to check if visited status is correctly set to 0
    //     cout << "Changing visited status to: " << it.first << " " << it.second << endl; 
    // }

    //print statment to check content of dist
    // for(auto it : dist){ 
    //     cout << it.first << " has distance: " << it.second << " from " << start_label << endl; 
    // }

    
    // If F is not in dist, then no path exists from u to v.
    if(dist.find(end_label) == dist.cend()){// return "FAIL" 
        //warning message
        //cout << "Warning: " << end_label << " and " << start_label << " is not connected." << endl;
        return spu;
    }

    //TO DO: find the shortest_path_unweighted based on dist, and store it in spu.
    //algorithm:
    string curr = end_label;//Start for curr = end_label, find its neighbors that also has dist 1 less than itself, update curr to that neighbor, also update its neighbors.
    unordered_map<string,double> neighbors = (*(adjacencylist.find(curr))).second; //unordered_map<string,double> neighbors = (*(adjacencylist.find(curr.second))).second;
    int distance = dist[curr];
    stack<string> path_reverse;
    path_reverse.push(curr); // pushing end_label to the path_reverse
    
   
    //potential problem: infinite while loop
    //Keep doing this until dist = 1 (reach the neighbor of start_label)
    while(distance > 1){
        //search all its neighbors
        for(auto it: neighbors){
            //find the neighbor that also has dist 1 less than itself
            if(dist[it.first] == distance - 1){          
                //pushing nodes along the path to a stack (in reverse order)
                path_reverse.push(it.first); // pushing it.first node to path_reverse 
            
                //print statement to check content of path
                //cout << "Reached if(). Adding to stack: " << it.first << " with distance: " << dist[it.first] << endl;
                //update curr, neighbors, and distance
                curr = it.first;
                neighbors = (*(adjacencylist.find(curr))).second;
                distance = dist[curr];

                break; //break from for loop to start next round of searching.
            }
        }    
    }

    // now dist should be 1. Simply push start_label to path_reverse, and pop path_reverse to get spu.
    path_reverse.push(start_label);
    //print statement to check content of path
    //cout << "shortest_path_unweighted from " << start_label << " to " << end_label << endl;
    while(!path_reverse.empty()){
        //print statement to check content of path
        //cout << path_reverse.top() << endl;
        spu.push_back(path_reverse.top());
        path_reverse.pop();
    }

    //pop the stack so that we get the path  
    return spu;
}

vector<tuple<string,string,double>> Graph::shortest_path_weighted(string const & start_label, string const & end_label) {
    // TODO:

    // Data structures needed:
    priority_queue <pi,vector<pi>, greater<pi>> pq; // Initialization: pq = empty priority queue
    //vector of nodes to perform dijkstra algorithm
    unordered_map<string,tuple<double,string, bool>> nodes; // 2. { v: (dist,prev,done)}
    stack<tuple<string,string,double>> path; // 3. stack (to store the path in reverse order)
    vector<tuple<string,string,double>> spw; // 4. tuple to return shortest_path_weighted
    unordered_map<string,double> neighbors; //5. neighbors

    //TO DO: handle edge cases
    //edge case1: start or end label not in Graph
    if(adjacencylist.find(start_label) == adjacencylist.cend() || adjacencylist.find(end_label) == adjacencylist.cend()){
        //warning message
        //cout << "Warning: at least one label is not in graph." << endl;
        return spw;
    }

    //edge case2: start_label is the same as end_label
    if(start_label == end_label){
        //warning message
        //cout << "Warning: Start_label: " << start_label << " equals end_label: " << end_label << endl;
        //cout << "shortest_path_unweighted is simply: " << start_label << endl;
        spw.push_back(make_tuple(start_label, end_label, -1.0));
        return spw;
    }

    // dijkstra(s):
    // // perform initialization step
    //Initialize all nodes
    // for each vertex v (except for the start vertex itself):
    //     v.dist = infinity           // the maximum possible distance from s
    //     v.prev = NULL               // we don't know the optimal previous node yet
    //     v.done = False              // v has not yet been discovered
    for(auto it : adjacencylist){
        //(v,dist,prev,done)
        tuple<double,string, bool> info = make_tuple(99999.0,"", false);
        
        //dist is set to 0 for the start vertex
        if(it.first == start_label){
            get<0>(info) = 0;
        }
        nodes.insert({it.first, info});
        //print statment to check content
        //cout << it.first << endl; 
    }

    // // perform the traversal
    //pair<int, string> pi
    pair<double,string> curr;
    pq.push(make_pair(0, start_label));// enqueue (0, s) onto pq  // enqueue the starting vertex
    double c; //total cost so far
    while(!pq.empty()){// while pq is not empty:
        curr = pq.top();      // dequeue (weight, v) from pq
        pq.pop();             // weight = curr.first; v = curr.second;
        neighbors = (*(adjacencylist.find(curr.second))).second;    
        if(!get<2>(nodes[curr.second])){            // if v.done == False:         // if the vertex's min path hasn't been discovered yet
            get<2>(nodes[curr.second]) = true;      //v.done = True
            //nodes {v: (dist, prev, done)}
            //neighbors: {w : d}
            for( auto it : neighbors){              //for each edge (v,w,d):  // (v,w,d) = edge from v to w with edge-weight d
                //c = get<0>(nodes[curr.second]) + it.second;         //c = v.dist(weight?) + d; weight = curr.first; d = it.second; w = it.first;     // c is the total distance to w through v
                c = curr.first + it.second;
                
                //print statemnet for debugging
                //cout << "c is: " << c << endl;
                //nodes: { w: (dist,prev,done)}
                if(c < get<0>(nodes[it.first])){    //if c < w.dist:      // if a smaller-weight path has been found
                                                    // (remember, all distances start at infinity!)
                    get<1>(nodes[it.first]) = curr.second;  //w.prev = v      // update the node that comes just before w in the path from s to w
                    get<0>(nodes[it.first]) = c;            //w.dist = c      // update the distance of the path from s to w
                    pq.push(make_pair(c, it.first));        //enqueue (c, w) onto pq
                    //print statemnet for debugging
                    // cout << it.first << ", dist: " << get<0>(nodes[it.first]) << ", prev: " << get<1>(nodes[it.first]) << ", done: " << get<2>(nodes[it.first]) << endl;
                    // cout << "Pushing (" << c << ", " << it.first << ") to pq." << endl; 
                }
            }
        }
    }

    //print statment to check content of nodes
    //cout << "Finding shortest_path_weighted from " << start_label << " to " << end_label << endl;
    // for( auto it : nodes){
    //     cout << it.first << ", dist: " << get<0>(it.second) << ", prev: " << get<1>(it.second) << ", done: " << get<2>(it.second) << endl; 
    // }
    //The algorithm modifies information in nodes: { w: (dist,prev,done)}
    //Next step: Use nodes to produce spw.

    
    //start from curr = end_label, go to its prev, push (prev, curr, adjacencylist[prev][curr]) to stack
    //until reach start_label (curr == start_label)
    string current = end_label;
    //if end_label and start label is not connected, return empty spw
    if(get<1>(nodes[current]) == ""){
        //print statement for debugging
        //cout << end_label << " and " << start_label << " not connected " << endl;
        return spw;
    }

    //potential problem: infinite while loop
    string prev;
    //cout << "Pushing to stack: " << endl;
    while(current != start_label){
        prev = get<1>(nodes[current]);
        path.push(make_tuple(prev, current, (adjacencylist[prev])[current]));
        //print statement to check content of path
        //cout << get<1>(nodes[current]) << "-" << current << "-" << (adjacencylist[prev])[current] << endl; 
        //update curr to prev
        current = prev;
    }

    //push stack to spw to get the path in correct order
    //print statement for debugging
    //cout << "Printing shortest_path_weighted from " << start_label << " to " << end_label << endl;
    while(!path.empty()){
        spw.push_back(path.top());
        //cout << get<0>(path.top()) << "-" << get<1>(path.top()) << "-" << get<2>(path.top()) << endl;
        path.pop();
    }
}

vector<vector<string>> Graph::connected_components(double const & threshold) {
    // TODO
    
    //Data structures:
    unordered_map<string,bool> unvisited_nodes; // stores all remaining unvisited nodes. Also use this for BFS(u)
    vector<vector<string>> all_components; // the vector to return; vector of all connected_components;
    
    //handle edge cases:
    //edge case1: threshold is negative
    if(threshold <= 0){
        return all_components;
    }


    //Initialization
    //Note: only intialize edges with weight <= threshold
    //algorithm: 
    //create a copy of adjacencylist;
    //iterate through copy,
    //  initialize all nodes as unvisited_nodes;
    //  remove all edges with weight > threshold;
    //iterate through copy again,
    //  this time push nodes whose neighbors is empty(obsolete) to one_component;
    //  and remove them from unvisited_nodes. 
    unordered_map<string,unordered_map<string,double>> copy = adjacencylist;
    for(auto it : copy){
        unvisited_nodes.insert({it.first, false}); // insert all nodes as unvisited_nodes;
        //{{u:false}, {v:false}, etc}
        for(auto node_weight : it.second){
            if(node_weight.second > threshold){
                // u-v-weight. u = it.first; v = node_weight.first; weight = node_weight.second;
                (copy[it.first]).erase(node_weight.first); //remove u-v-weight.
                (copy[node_weight.first]).erase(it.first); //also remove v-u-weight.
            }
        }
        //removing edges with weight greater than threshold
        //if 
        //unvisited_nodes.insert({it.first, false});// Initialize all nodes in the graph to "unvisited"
    }

    for(auto it : copy){
        if(it.second.empty()){ //if this is a node with no neighbors (obsolete node)
            unvisited_nodes.erase(it.first);//mark it as visited and remove from unvisited_nodes
            vector<string> one_component;
            one_component.push_back(it.first);
            all_components.push_back(one_component);
        }
    }

    //if no nodes remains at all, return empty vector;
    if(unvisited_nodes.empty()){ return all_components;}
    //print statement for debugging
    //cout << unvisited_nodes.size() << endl;
    //algorithm:
    // Initialize all nodes in the graph to "unvisited"
    // While there are still unvisited nodes:
        // Arbitrarily choose one of the remaining unvisited nodes (call it u)
        // Perform BFS starting at u, and store all nodes visited in the BFS (including u) in a set c
        // Once BFS is complete, output c as a component of the graph
    while(!unvisited_nodes.empty()){// While there are still unvisited nodes:
        //print statement for debugging
        // cout << unvisited_nodes.size() << endl;
        // cout << "threshold is " << threshold << endl;
        string u = (unvisited_nodes.begin())->first;// Arbitrarily choose one of the remaining unvisited nodes (call it u)
        //print statement for debugging
        //cout << "choosing " << u << endl;
        //Next: BFS on u
        //BFS(u):
        vector<string> one_component; // the specific connected_component found by this round of BFS
        queue<pair<int, string>> q;// q = an empty queue
        q.push(make_pair(0,u));// add (0,u) to q // (0,u) -> (length from u, current vertex)
        while(!q.empty()){// while q is not empty:
            pair<int,string> curr = q.front();//     curr.first = dist, curr.second = node
            q.pop();                          //     (length,curr) = q.dequeue()
            if(!unvisited_nodes[curr.second]){
                unvisited_nodes[curr.second] = true;         //     mark curr as visited
                //print statement to check content
                //cout << "Setting to true: " << curr.second << unvisited_nodes[curr.second] << endl;
                one_component.push_back(curr.second);//add curr to one_component;
                //print statement to check content
                //cout << "Visiting: " << curr.second << curr.first << endl;
                unordered_map<string,double> neighbors = (*(copy.find(curr.second))).second;
                for(auto it : neighbors){ //for all outgoing edges (curr,w) from curr: // otherwise explore all neighbors
                    if(unvisited_nodes[it.first] == false && it.second <= threshold){//if w has not yet been visited && edge weight <= threshold:
                        //print statement for debugging
                        //cout << "pushing to queue: " << it.first << " " << unvisited_nodes[it.first] << " " << it.second << endl;
                        q.push(make_pair(curr.first+1, it.first));//add (length+1,w) to q
                    }

                    //print statement for debugging
                    // else{
                    //     cout << "visited status: " << visited[it.first] << endl; 
                    // }
                }
            }
        }
        
        //print statement for debugging
        //cout << "printing one connected component: " << endl;
        for(auto str : one_component){
            unvisited_nodes.erase(str); // remove all nodes in one_component from unvisited_nodes;
            //cout << str << endl;
        }

        //print statement to check remaining unvisited_nodes
        //cout << "The remaining unvisited_nodes are: " << endl;
        // for(auto it : unvisited_nodes){
        //     cout << it.first << " " << it.second << endl;
        // }
        //after this round of BFS, push one_component to all_components
        all_components.push_back(one_component);
        // vector<string> vector_copy(one_component.begin(), one_component.end());
        // all_components.push_back(vector_copy);
    }

    //print statment for debugging
    // for(auto it : all_components){
    //     cout << "{";
    //     for(auto str : it){
    //         cout << str << ", ";
    //     }
    //     cout << "}, " << endl;
    // }
    return all_components;
}

double Graph::smallest_connecting_threshold(string const & start_label, string const & end_label) {
    // TODO

    //handle edge cases:
    //edge case1: start or end label not in Graph
    if(adjacencylist.find(start_label) == adjacencylist.cend() || adjacencylist.find(end_label) == adjacencylist.cend()){
        //warning message
        //cout << "Warning: at least one label is not in graph." << endl;
        return -1.0;
    }

    //edge case2: start_label is the same as end_label
    if(start_label == end_label){
        //warning message
        //cout << "Warning: Start_label: " << start_label << " equals end_label: " << end_label << endl;
        //cout << "shortest_path_unweighted is simply: " << start_label << endl;
        //spw.push_back(make_tuple(start_label, end_label, -1.0));
        return 0;
    }

    //Test disjointset Class implemented at the top of this file
    disjointset djs(adjacencylist);

    //Testing djs
    // //print statement that tests content of Constructor
    // cout << "Testing Constructor: " << endl;
    // for(auto it : djs.uptree){
    //     cout << it.first << ", parent: " << it.second << endl;
    // }

    // //Testing Find()
    // cout << "Testing Find(): " << endl;
    // for(auto it : djs.uptree){
    //     cout << it.first << ", parent: " << djs.Find(it.first) << endl;
    // }

    // //Testing Union()
    // cout << "Testing Union(): " << endl;
    // djs.Union("A","C");
    // djs.Union("B","D");
    // djs.Union("E","F");
    // for(auto it : djs.uptree){
    //     cout << it.first << ", parent: " << djs.Find(it.first) << endl;
    // }
    // cout << "Second Round: " << endl;
    // djs.Union("A","B");
    // djs.Union("G","F");
    // for(auto it : djs.uptree){
    //     cout << it.first << ", parent: " << djs.Find(it.first) << endl;
    // }
    
    //Next: find a way to eliminate duplicate ( 0.1-u-v and 0.1-v-u)
    //  create a copy of adjacencylist, for each edge u-v in copy, if v-u is also in copy, erase v-u 
    unordered_map<string,unordered_map<string,double>> copy = adjacencylist;
    unordered_map<string,double> neighbors; // u-v
    //unordered_map<string,double> mirror;    //v-u
    for( auto it : copy){
        //u = it.first;
        neighbors = it.second;
        //v = pair.first
        for( auto pair : neighbors){
            //for each u-v, check if v-u is also in copy
            //mirror = copy[pair.first];
            if(copy[pair.first].find(it.first) != copy[pair.first].end()){ // if v-u is also in copy
                copy[pair.first].erase(it.first);
            }
        }
    }

    //Next: create a min priority_queue of tuples of all edges (edge_weight, x, y)
    priority_queue <minpqweight,vector<minpqweight>, greater<minpqweight>> pq; // Initialization: pq = empty priority queue
    for(auto it: copy){
        for( auto pair : it.second){
            pq.push(make_tuple(pair.second,it.first, pair.first));
            //Testing pq
            //cout << "Pushing: " << pair.second << "-" << it.first << "-" << pair.first <<endl;
        }
    }

    //Testing pq:
    // cout << "Testing pq: " << endl;
    // while(!pq.empty()){
    //     minpqweight elt = pq.top();
    //     cout << get<0>(elt) << "-" << get<1>(elt) << "-" << get<2>(elt) <<endl;
    //     pq.pop();
    // }

    //Next: perform algorithm.
    //algorithm:
    //Create a Disjoint Set containing all nodes in the graph, each in their own set
        // For each edge (x,y,w) between nodes x and y with weight w increasing order of edge weight:
        // Perform union(x,y)
        // If find(u) is equal to find(v) (meaning u and v, the function arguments, are now in the same set), return w as the smallest connecting threshold
        // If we get here, u and v were never connected, so no such threshold exists
    while(!pq.empty()){
        // w = get<0>(elt), x = get<1>(elt), y = get<2>(elt)
        minpqweight elt = pq.top();
        djs.Union(get<1>(elt),get<2>(elt));
        //cout << "Unioning " << get<1>(elt) << " and " << get<2>(elt) << endl;
        if(djs.Find(start_label) == djs.Find(end_label)){
            //cout << "smallest threshold between " << start_label << " and " << end_label << " is " << get<0>(elt) << endl; 
            return get<0>(elt);
        }
        pq.pop();
    }

    //cout << start_label << " and " << end_label << " is not connected. Returning -1.0" << endl; 
    return -1.0;
}
