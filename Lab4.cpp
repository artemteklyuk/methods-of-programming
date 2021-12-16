#include <vector>
#include <iostream>
#include <set>

using namespace std;

int clStart, clEnd;
int n, m;
std::vector <vector <int> > g(100);
std::vector <int>  cl(100, 0);
std::vector<int> res;

int invert(int c) {
    return c == 1 ? 2 : 1;
}

void dfs(int v, int c) {
    cl[v] = c;
    for (auto i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (cl[to] == 0)
        {
            dfs(to, invert(c));
        }
        else if (cl[to] == c) {
            std::cout << "NO";
            exit(0);
        }

    }
}

int main() {
    std::cin >> n;
    std::cin >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        std::cin >> a;
        std::cin >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    clStart = -1;
    for (int i = 0; i < n; ++i)
        if (cl[i] == 0)
            dfs(i, 1);


    std::cout << "YES" << "\n";



    return 0;
}