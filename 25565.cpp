#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <deque>

using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
bool compare2(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int map[2001][2001];
int n,m,k;
int checking[2001][2001];
int main(){
    cin >> n >> m >> k;
    int total_k = 0;
    vector< pair<int,int> > temp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                temp.push_back(make_pair(i,j));
                total_k += 1;
            }
        }
    }
    sort(temp.begin(),temp.end(),compare);
    if(total_k - k*2 == 0){
        cout<< 0<< endl;
        return 0;
    }
    if(total_k == k){
        cout << k << endl;
        for(int i=0; i<k; i++){
            cout << temp[i].first << " " << temp[i].second << endl;
        }
        return 0;
    }
    int checkX = temp[0].second;
    int checkY = temp[0].first;
    int flag; //0이면 크로스. 1이면 한 라인
    for(int i=1; i<total_k; i++){
        if(temp[i].first != checkY && temp[i].second != checkX ){
            flag = 0;
            break;
        }
        else if(temp[i].first == checkY && temp[i].second != checkX){
            flag = 1;
        }
        else if(temp[i].first != checkY && temp[i].second == checkX){
            flag = 1;
        }
    }
    if(flag == 0){
        //교차하는경우x,y좌표가 제일 많이 나온 놈이 교차하는곳.
        cout<<1<<endl;
        sort(temp.begin(),temp.end(),compare);
        int arrY[2001] = {0,};
        int arrX[2001] = {0,};
        for(int i=0; i<total_k; i++){
            arrY[temp[i].first] += 1;
            arrX[temp[i].second] += 1;
        }
        int maxX = 0 , maxY = 0;
        int x = 0, y = 0;
        for(int i=1; i<=k; i++){
            if(maxX<arrX[i]){
                maxX = arrX[i];
                x = i;
            }
            if(maxY<arrY[i]){
                maxY = arrY[i];
                y = i;
            }
        }
        cout << y << " " << x << endl;
    }
    else if(flag == 1){
        int result = k*2-total_k;
        cout << result << endl;
        for(int i=(total_k-k); i<total_k-(total_k-k); i++){
            //cout << i << endl;
            cout<< temp[i].first << " "<< temp[i].second<<endl;
        }

    }
}
