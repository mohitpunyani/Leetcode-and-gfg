
class Solution
{
	public:

		bool DFSRec(int s, vector<bool> &visited, vector<bool> &currVisited, vector< int > adj[], stack<int> &st)
		{
			visited[s] = true;
			currVisited[s] = true;

			for (auto x: adj[s])
			{
				if (!visited[x])
				{
					if (DFSRec(x, visited, currVisited, adj, st))
					{
						return true;
					}
				}
				else if (currVisited[x])
				{
					return true;
				}
			}

			st.push(s);
			currVisited[s] = false;

			return false;
		}

	vector<int> findOrder(int numCourses, vector<vector < int>> &prerequisites)
	{
		int n = numCourses;
		vector<int> adj[n];
		for (auto x: prerequisites)
		{
			vector<int> data = x;
			int a = data[0];
			int b = data[1];
			adj[b].push_back(a);
		}

		stack<int> st;
		vector<bool> visited(n, false), currVisited(n, false);

		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				if (DFSRec(i, visited, currVisited, adj, st))
				{
					return {};
				}
			}
		}

		vector<int> ans;
		while (!st.empty())
		{
			int x = st.top();
			st.pop();
			ans.push_back(x);
		}

		return ans;
	}
};