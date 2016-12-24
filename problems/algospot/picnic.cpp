#include<cstdio>
#include<memory.h>

using namespace std;

const int MAXN = 10;

int n, m;
int counter;
int partner[MAXN]; //partner[i] := index of i's matched friend  
bool enable[MAXN][MAXN]; // enable[i][j] : true if i and j are friend.


void dfs(int depth)
{
    if(depth == n/2)
    {
        counter ++;
        return;
    }
    
    
    int i;
    for(i = 0 ; i < n ; i ++)
    {
        if(partner[i] == -1)
        {
            break;
        }
    }
    
    for(int j = i+1; j < n; j++)
    {
        if(partner[j] == -1 && enable[i][j])
        {
            partner[i] = j;
            partner[j] = i;
            dfs(depth+1);
            partner[i] = -1;
            partner[j] = -1;
        }
    }
}
void test_case()
{
    memset(partner, -1, sizeof(partner));
    memset(enable, false, sizeof(enable));
    counter = 0;
    
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        enable[a][b] = true;
        enable[b][a] = true;
    }
    
    dfs(0);
    printf("%d\n", counter);
}
int main(){
    int c;
    scanf("%d",&c);
    for(int i = 0 ; i < c ; i++){
        test_case();
    }
    return 0;
}