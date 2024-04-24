// By: Vincent fealy
// 5/3/23

#include "d_graph.h" 
//#include "d_util.h"
#include <iostream>
#include <fstream>

template <typename Iterator>
void writeContainer(Iterator first, Iterator last,
						  const string& separator)
{
	Iterator iter = first;

	while (iter != last)
	{
		cout << *iter << separator;
		iter++;
	}
}

int main()
{
    graph <string> graph;
    std::ifstream graphB;
    
    graphB.open("graphB.dat",ios::in);
    
    if(graphB.is_open())
    {
        
        int count;
        graphB>>count;
       
        string v1;
        string v2;
        
        int weight;
        
        while(count !=0)
        {
            graphB >> v1;    
            graph.insertVertex(v1);
            count--;
        }
        graphB>>count;
        while(count !=0)
        {
            graphB >> v1 >> v2 >> weight;    
            graph.insertEdge(v1,v2,weight);
            count--;
        }
    }
    graphB.close();

    string input;
    
    std::cout << "Enter a vertex: ";
    std::cin >> input;


    std::list<string> path;
    
    int minPathVal = 0;
    string v3;
    string myV;
    
    int count = 0;

    graphB.open("graphB.dat",ios::in);
    graphB >> count;
    
    while(count!=0)
    {
        graphB>>v3;
       
        if(minimumPath(graph,v3,input,path)>minPathVal)
        {
            minPathVal = minimumPath(graph,v3,input,path);
            myV = v3;
        }
        count--;
    }

    minimumPath(graph,myV,input,path);
    
    std::cout << "Vertex with largest minimum-path value = " << myV << std::endl;
    std::cout << "Minimum-path value = " << minPathVal << std::endl;
    std::cout << "Minimum-path = ";
   
    writeContainer(path.begin(),path.end()," ");
    std::cout << std::endl;
    graphB.close();
}