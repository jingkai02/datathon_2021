#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <functional>   // std::greater
#include <algorithm>    // std::sort
#include <unordered_set>
#include <queue>
#include "Graph.h"
using namespace std;



typedef pair<int, string> pi;
int main(int argc, char* argv[]){

    //Step2: Test disjointset class

    //Step3: Use disjointset 
    //TO DO: Test each module of Graph.cpp

    //Testing minimum priority queue:
    // priority_queue <int,vector<int>, greater<int>> pq;
    // pq.push(5);
    // pq.push(1);
    // pq.push(10);
    // pq.push(30);
    // pq.push(20);
    
    // priority_queue <pi,vector<pi>, greater<pi>> pq;
    // pq.push(make_pair(5, "A"));
    // pq.push(make_pair(1, "B"));
    // pq.push(make_pair(20, "C"));
    // pq.push(make_pair(10, "D"));
    // pq.push(make_pair(30, "E"));
    // // One by one extract items from min heap
    // while (pq.empty() == false)
    // {
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }
    //1. Testing Constructor
    Graph test1(argv[1]);
    
    //Testing disjointset helper class
   
    //cout << "Hello, world!" << endl;
    
    //2.Testing unsigned int num_nodes();
    // cout << "2.Testing num_nodes():" << endl;
    // cout << "Graph has: " << test1.num_nodes() << " nodes." << endl;
    
    // //3.Testing vector<string> nodes();
    // vector<string> nodes = test1.nodes();
    // cout << "3.Testing nodes():" << endl;
    // cout << "The nodes are: " << endl;
    // for (auto it = nodes.begin(); it != nodes.end(); it++){
    //     cout << *(it) << endl;
    // }

    // //3.Testing vector<string> nodes();
    // //unordered_map<string, int> visited = test1.Isvisited();
    // // cout << "Extra:Testing visited():" << endl;
    // // for (auto it = visited.begin(); it != visited.end(); it++){
    // //     cout << (*(it)).first << ": " << (*(it)).second << endl;
    // // }

    // //4.Testing unsigned int num_edges();
    // // cout << "4.Testing num_edges():" << endl;
    // // cout << "Graph has: " << test1.num_edges() << " edges." << endl;
    
    //5.Testing double edge_weight(string const & u_label, string const & v_label);
    // cout << "5.Testing edge_weight():" << endl;
    // cout << "Edge A-B has weight: " << test1.edge_weight("A", "B") << endl;
    // cout << "Edge A-C has weight: " << test1.edge_weight("C", "A") << endl; 
    // cout << "Edge F-A has weight: " << test1.edge_weight("F", "A") << endl;
    // cout << "Edge M-R has weight: " << test1.edge_weight("M", "R") << endl;
    
    // // //6.Testing unsigned int num_neighbors(string const & node_label);
    // // cout << "6.Testing num_neighbors():" << endl;
    // // cout << "A has: " << test1.num_neighbors("A") << "neighbors" << endl;
    // // cout << "G has: " << test1.num_neighbors("G") << "neighbors" << endl;
    // // cout << "R has: " << test1.num_neighbors("R") << "neighbors" << endl;

    // // //7.Testing vector<string> neighbors(string const & node_label);
    // // cout << "7.Testing neighbors():" << endl;
    // // vector<string> neiA = test1.neighbors("A");
    // // vector<string> neiB = test1.neighbors("B");
    // // vector<string> neiF = test1.neighbors("F");
    // // vector<string> neiR = test1.neighbors("R");
    // // cout << "The neigbors of A are: " << endl;
    // // for (auto it = neiA.begin(); it != neiA.end(); it++){
    // //     cout << *(it) << endl;
    // // }
    // // cout << "The neigbors of B are: " << endl;
    // // for (auto it = neiB.begin(); it != neiB.end(); it++){
    // //     cout << *(it) << endl;
    // // }
    // // cout << "The neigbors of F are: " << endl;
    // // for (auto it = neiF.begin(); it != neiF.end(); it++){
    // //     cout << *(it) << endl;
    // // }
    // // cout << "The neigbors of R are: " << endl;
    // // for (auto it = neiR.begin(); it != neiR.end(); it++){
    // //     cout << *(it) << endl;
    // // }
    
    
    // //--------------//
    // //TO DO:
    //8.Testing vector<string> shortest_path_unweighted(string const & start_label, string const & end_label);
    // test1.shortest_path_unweighted("D", "A");
    // test1.shortest_path_unweighted("D", "B");
    // test1.shortest_path_unweighted("D", "C");
    // test1.shortest_path_unweighted("D", "D");
    // test1.shortest_path_unweighted("D", "E");
    // test1.shortest_path_unweighted("D", "F");
    // test1.shortest_path_unweighted("D", "G");

    //----------------------------//
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-3xy_09-05-12_1346803200");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-4cy_08-28-09_1251417600");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-4zd_12-01-09_1259625600");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-4d7_12-13-05_1134432000");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-4ib_10-08-08_1223424000");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-2fj_09-08-08_1220832000");
    // test1.shortest_path_unweighted("222-47r_07-27-04_1090886400", "222-4i7_09-11-08_1221091200");
    
    //9.Testing vector<tuple<string,string,double>> shortest_path_weighted(string const & start_label, string const & end_label);
    // test1.shortest_path_weighted("D", "A");
    // test1.shortest_path_weighted("D", "B");
    // test1.shortest_path_weighted("D", "C");
    // test1.shortest_path_weighted("D", "D");
    // test1.shortest_path_weighted("D", "E");
    // test1.shortest_path_weighted("D", "F");
    // test1.shortest_path_weighted("D", "G");
    //10.Testing vector<vector<string>> connected_components(double const & threshold);
    // cout << "Testing with threshold 0.3: " << endl;
    // test1.connected_components(0.3);
    // cout << "Testing with threshold 0.75: " << endl;
    // test1.connected_components(0.75);
    // cout << "Testing with threshold 1.0: " << endl;
    // test1.connected_components(1.0);
    // cout << "Testing with threshold 0.5: " << endl;
    // test1.connected_components(0.5);
    // cout << "Testing with threshold 0.25: " << endl;
    // test1.connected_components(0.25);
    // cout << "Testing with threshold 0.125: " << endl;
    // test1.connected_components(0.125);
    // cout << "Testing with threshold 0.0625: " << endl;
    // test1.connected_components(0.0625);
    // cout << "Testing with threshold 0.00001: " << endl;
    // test1.connected_components(0.00001);
    // cout << "Testing with threshold 0: " << endl;
    // test1.connected_components(0);
    // cout << "Testing with threshold -1.0: " << endl;
    // test1.connected_components(-1.0);

    //--------------
    //This test results in infinite loop with example/hiv.csv 
    // cout << "Testing with threshold 0.00332011: " << endl;
    // test1.connected_components(0.00332011);
    //--------------

    //11.Testing smallest_connecting_threshold(string const & start_label, string const & end_label);
     // test1.smallest_connecting_threshold("E", "M");
    // test1.smallest_connecting_threshold("E", "A");
    // test1.smallest_connecting_threshold("E", "B");
    // test1.smallest_connecting_threshold("E", "C");
    // test1.smallest_connecting_threshold("E", "D");
    // test1.smallest_connecting_threshold("E", "E");
    // test1.smallest_connecting_threshold("E", "F");
    // test1.smallest_connecting_threshold("E", "G");

    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-3xy_09-05-12_1346803200");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-4cy_08-28-09_1251417600");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-4zd_12-01-09_1259625600");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-4d7_12-13-05_1134432000");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-4ib_10-08-08_1223424000");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-2fj_09-08-08_1220832000");
    test1.smallest_connecting_threshold("222-47r_07-27-04_1090886400", "222-4i7_09-11-08_1221091200");
}
    
