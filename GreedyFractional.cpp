#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> B1,pair<int,int> B2){
    double result1 = (double)B1.first/(double)B1.second;
    double result2 = (double)B2.first/(double)B2.second;
    return result1 > result2;
}

int main()
{
    int N, a, b, W, maxProfit=0;
    cout << "Enter Number of Objects: ";
    cin >> N;
    cout << "Enter Capacity of Bag: ";
    cin >> W;

    vector<pair<int, int>> item;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter Profit and Weight of object " << i+1 << " : ";
        cin >> a >> b;
        item.push_back(make_pair(a, b));
    }

    sort(item.begin(),item.end(),cmp);

    for(int i=0;i<N;i++){
        if(item[i].second <= W){
            W -= item[i].second;
            maxProfit += item[i].first;
        }
        else{
            maxProfit += (double) (item[i].first * W)/item[i].second;
            break;
        }
    }
    cout<<"Maximum Profit is: "<<maxProfit<<endl;
    return 0;
}