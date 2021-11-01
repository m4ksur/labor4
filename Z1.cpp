#include <iostream>
#include <ctime>

using namespace std;

const int Vmax = 100, Emax = Vmax * 2;
int head[Vmax];
int next_el[Emax];
int terminal[Emax];
int n, m, i, j, k, v, u, r, t;

void Add(int v, int u)
{
    k = k + 1;
    terminal[k] = u;
    next_el[k] = head[v];
    head[v] = k;
}

void main()
{
    system("chcp 1251"); system("cls");

    t = clock();
    k = 0;
    cout << "Количество вершин > "; cin >> n;
    cout << "Количество ребер > "; cin >> m;
    cout << "Вводите  смежные вершины:\n";
    for (i = 0; i < m; i++)
    {
        cin >> v >> u;
        cout << "Ребро направленное? (1/0) > "; cin >> r;
        if (r == 1) Add(v, u);
        else
        {
            Add(v, u);
            Add(u, v);
        }
        if (i < (m - 1)) cout << "Следующие вершины...\n";
    }

    cout << "Список смежности графа:";
    for (i = 0; i < n + 1; i++)
    {
        j = head[i];
        if (i) cout << i << "->";
        while (j > 0)
        {
            if (!next_el[j]) cout << terminal[j];
            else cout << terminal[j] << ", ";
            j = next_el[j];
        }
        cout << endl;
    }
    cout << "\nТактов:" << ((float)t / CLOCKS_PER_SEC) << "\n";
    system("pause");
}