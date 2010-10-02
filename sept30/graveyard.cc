using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); \
                           x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//Complejidad: O(V*E)
const int MAXNODES = 1000;
const int oo = 1000000000;
struct edge{
  int v, w; edge(){} edge(int v, int w) : v(v), w(w) {}
};
vector<edge> g[MAXNODES];

int d[MAXNODES];
int p[MAXNODES];
// Retorna falso si hay un ciclo de costo negativo alcanzable
// desde s.  Si retorna verdadero, entonces d[i] contiene la
// distancia más corta para ir de s a i.  Si se quiere
// determinar la existencia de un costo negativo que no
// necesariamente sea alcanzable desde s, se crea un nuevo
// nodo A y nuevo nodo B. Para todo nodo original u se crean
// las aristas dirigidas (A, u) con peso 1 y (u, B) con peso
// 1. Luego se corre el algoritmo de Bellman-Ford iniciando en
// A.
bool bellman(int s, int n){
  for (int i=0; i<n; ++i){
    d[i] = oo;
    p[i] = -1;
  }

  d[s] = 0;
  for (int i=0, changed = true; i<n-1 && changed; ++i){
    changed = false;
    for (int u=0; u<n; ++u){
      for (int k=0; k<g[u].size(); ++k){
        int v = g[u][k].v, w = g[u][k].w;
        if (d[u] + w < d[v]){
          d[v] = d[u] + w;
          p[v] = u;
          changed = true;
        }
      }
    }
  }

  for (int u=0; u<n; ++u){
    for (int k=0; k<g[u].size(); ++k){
      int v = g[u][k].v, w = g[u][k].w;
      if (d[u] + w < d[v]){
        return false;
      }
    }
  }
  return true;
}
int graph[30][30];
int W, H;
void link(int u, int v, int c=1)
{
  g[u].push_back(edge(v,c));
  g[v].push_back(edge(u,c));
}

void create()
{
  for(int i = 0; i < H ; ++i)
    for(int j = 0; j < W ; ++j)
      g[i*W + j].clear();
  for(int i = 0; i < H ; ++i)
    {
      for(int j = 0; j < W ; ++j)
        {
          if(i+1 < H and graph[i+1][j] == 0)
            link(i*W + j,(i+1)*W + j);
          if(j+1 < W and graph[i][j+1] == 0)
            link(i*W + j, i*W + j + 1);
        }
    }
}
void hole(int u, int v, int c)
{
  g[u].push_back(edge(v,c));
}
int main()
{

  while(scanf("%d %d", &W, &H) == 2)
    {
      if(W == 0 and H == 0) break;
      memset(graph, 0, sizeof graph);
      int g;
      scanf("%d", &g);
      for(int i = 0, x, y; i < g and scanf("%d %d", &x, &y) == 2; ++i)
        graph[y][x] = -1;
      create();
      int e;
      scanf("%d", &e);
      for(int i = 0, x1, y1, x2, y2, t; i < e and scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t) == 5; ++i)
        hole(y1*W+x1,y2*W+x2,t);
      
      if(bellman(0,H*W))
        {
          if(d[(H-1)*W + W - 1] != oo)
            printf("%d\n",d[(H-1)*W + W - 1]);
          else
            puts("Impossible");
        }
      else
        puts("Never");
    }
  return 0;
}
