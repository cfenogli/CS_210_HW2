#include <vector>
#include <iostream>

#define INF 999

using namespace std;

struct Solution
{
	vector<int> P;
	vector<int> D;
};

Solution dijkstra(vector<vector<int>> graph)
{
	Solution dijkstra_solution;

	vector<bool> SPFound(graph.size());
	vector<pair<int, int>> edges;
	vector<int> dist(graph.size());
	vector<int> path(graph.size());

	bool solved = false;

	for (int i = 0; i < graph.size(); i++)
	{
		dist[i] = INF;
	}
	//distance from source to source; the shortest path is found
	dist[0] = 0;
	path[0] = 0;
	SPFound[0] = true;

	int iteration = 0;
	while (!solved)
	{
		int minPath = INF;
		edges.push_back(make_pair(0, 0));
		for (int i = 0; i < SPFound.size(); i++)
		{
			//if the shortest path to this vertex wasn't already found
			if (!SPFound[i])
			{
				for (int j = 0; j < SPFound.size(); j++)
				{
					//only using a predecessor vertex if its shortest path was found
					if (SPFound[j] && graph[j][i] + dist[j] < minPath)
					{
						minPath = graph[j][i] + dist[j];
						/*
						cout << "Graph[" << j << "][" << i << "]: " << graph[j][i] << endl;
						cout << "Dist[" << j << "]: " << dist[j] << endl;
						cout << "minPath: " << minPath << endl << endl;
						*/
						edges[iteration] = make_pair(j, i);
					}
				}
			}
		}

		//shortest path found
		SPFound[edges[iteration].second] = true;
		//add the distance to this vertex to the distance vector
		dist[edges[iteration].second] = minPath;
		//add the predecessor vertex to the path vector
		path[edges[iteration].second] = edges[iteration].first;

		iteration++;

		//check if the problem is solved
		solved = true;
		for (int i = 0; i < SPFound.size(); i++)
		{
			if (!SPFound[i])
			{
				solved = false;
			}
		}
	}
	
	dijkstra_solution.P = path;
	dijkstra_solution.D = dist;

	return dijkstra_solution;
}

void print_dist_and_path(Solution soln)
{
	cout << "Distance (D): [ ";
	for (int i = 0; i < soln.D.size(); i++)
	{
		cout << soln.D[i] << " ";
	}

	cout << "]" << endl;

	cout << "Path (P): [ ";
	//only the source vertex has an undefined path
	cout << "0 "; 
	for (int i = 1; i < soln.P.size(); i++)
	{
		cout << soln.P[i] + 1 << " ";
	}
	cout << "]\n" << endl;
}

void print_spaths(Solution soln, int v_r)
{
	if (soln.P[v_r] == 0)
	{
		cout << "v1";
	}
	else
	{
		print_spaths(soln, soln.P[v_r]);
	}
	cout << " -> v" << (v_r + 1);
}

int main()
{
	Solution soln1;
	Solution soln2;
	Solution soln3;
	Solution soln4;

	vector<vector<int>> graph1 = {	{ 0, 7, 4, 6, 1 },
									{ INF, 0, INF, INF, INF },
									{ INF,2, 0, 5,INF },
									{ INF, 3, INF, 0, INF },
									{ INF, INF, INF, 1, 0} };

	vector<vector<int>> graph2 = {	{0, 7, 5},
									{INF, 0, -5},
									{INF, INF, 0} };

	vector<vector<int>> graph3 = {	{0, 5, 3, 7},
									{INF, 0, INF, INF},
									{INF, INF, 0, INF},
									{INF, -3, -5, 0} };

	vector<vector<int>> graph4 = {	{0, 3, 1, INF, INF},
									{INF, 0, INF, INF, 1},
									{INF, INF, 0, 4, 2},
									{2, INF, INF, 0, INF}, 
									{INF, INF, INF, 1, 0} };

	cout << "**********Supplied Test Cases**********\n\n";

	soln1 = dijkstra(graph1);
	print_dist_and_path(soln1);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph1.size(); i++)
	{
		print_spaths(soln1, i);
		cout << endl;
	}
	cout << "\n" << endl;

	cout << "--------------------------------------------------------\n\n";

	soln2 = dijkstra(graph2);
	print_dist_and_path(soln2);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph2.size(); i++)
	{
		print_spaths(soln2, i);
		cout << endl;
	}
	cout << "\n" << endl;

	cout << "--------------------------------------------------------\n\n";

	cout << "**********Our Group's Test Cases**********\n\n";

	cout << "-----------------With Negative Edges-------------------\n\n";

	soln3 = dijkstra(graph3);
	print_dist_and_path(soln3);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph3.size(); i++)
	{
		print_spaths(soln3, i);
		cout << endl;
	}
	cout << "\n" << endl;

	cout << "-----------------Without Negative Edges----------------\n\n";

	soln4 = dijkstra(graph4);
	print_dist_and_path(soln4);
	cout << "Shortest paths:" << endl;
	for (int i = 1; i < graph4.size(); i++)
	{
		print_spaths(soln4, i);
		cout << endl;
	}
	cout << "\n" << endl;
}