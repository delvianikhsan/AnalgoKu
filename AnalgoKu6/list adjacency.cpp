#include <iostream>
#include <cstdlib>
using namespace std;

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

class Graph
{
    private:
        int V;
        struct AdjList* array;
    public:
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        }

        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        }
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (pCrawl)
                {
                    cout<<"-> "<<pCrawl->dest;
                    pCrawl = pCrawl->next;
                }
                cout<<endl;
            }
        }
};

int main()
{
    int pilihan,a,b,n;
    cout<<"Banyak node : ";cin>>n;
    Graph gh(n);
    for(; ;)
    {
        cout<<"\nMenu\n"
            <<"1. Tambah edge\n"
            <<"2. Print Edge\n"
            <<"0. Exit\n\n"
            <<"Pilihan : ";cin>>pilihan;
        
        switch (pilihan)
        {
            case 1:
                cout<<"\nedge(a,b)\n"
                    <<"Input a : ";cin>>a;
                cout<<"Input b : ";cin>>b;
                gh.addEdge(a,b);
                continue;

            case 2:
                gh.printGraph();
                continue;

            case 0:
                return 0;
                break;

            default:
                continue;
        }
    }
    return 0;
}


