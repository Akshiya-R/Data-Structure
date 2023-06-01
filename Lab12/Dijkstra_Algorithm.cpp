#include <iostream>
using namespace std;


//number of cities = 6
#define cities 6

/* function to find the node with the smallest time from the source node 
that has not yet been included in the shortest path tree*/
int minDistance(int time[], bool sptSet[])
{
    int min = INT_MAX, min_index;

	for (int v = 0; v < cities; v++)
		if (sptSet[v] == false && time[v] <= min)
			min = time[v], min_index = v;

	return min_index;
}

// function to print the time array
void printTimeArray(int time[])
{
	for (int i = 0; i < cities; i++)
		cout <<"Time taken for city "<< i << " is = " << time[i] << endl;
}

// function to print the average time
void printAverage(int time[],int source){
    int sum =0;
    for (int i = 0; i < cities; i++){
        sum+=time[i];
    }
    cout<<"The Average time taken = "<<(sum/5)<<endl;
}

void dijkstra(int graph[cities][cities], int source)
{
	int time[cities]; 
	bool sptSet[cities]; 
    /*sptSet[i] will be true if vertex i is included in shortest path tree 
    or shortest distance from source to i is finalized*/

    // Initialize all Time as INFINITE and stpSet[] as false
	for (int i = 0; i < cities; i++)
		time[i] = INT_MAX, sptSet[i] = false;

	// Initialize the source vertex as 0
	time[source] = 0;

	// Find shortest time for all cities
	for (int count = 0; count < cities - 1; count++) {
		
		int u = minDistance(time, sptSet);
        sptSet[u] = true;

		for (int v = 0; v < cities; v++)
        /*Update time[v] only if is not in sptSet,
        there is an edge from u to v, and 
        total weight of path from source to v through u is
		smaller than current value of time[v]*/ 
			if (!sptSet[v] && graph[u][v]
				&& time[u] != INT_MAX
				&& time[u] + graph[u][v] < time[v])
				time[v] = time[u] + graph[u][v];
	}

	// call the function to print the time array
	printTimeArray(time);
    // call the function to print the average
    printAverage(time,source);
}


int main()
{
    // Weighted Adjacency matrix of the city graph
	int graph[cities][cities] = { { 0, 10, 0, 0, 15, 5},
						          { 10, 0, 10, 30, 0, 0},
						          { 0, 10, 0, 12, 5, 0},
						          { 0, 30, 12, 0, 0, 20},
						          { 15, 0, 5, 0, 0, 0},
						          { 5, 0, 0, 20, 0, 0}};
    // Calling dijkstra() function to all the cities as source node
	for(int n=0; n<6;n++){
        cout<<"Source node--city "<<n<<endl;
        dijkstra(graph, n);
        cout<<endl;
    }
	
    
	return 0;
}


