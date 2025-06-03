#include <bits/stdc++.h>
using namespace std;

// the GFG method - but doesn't follow comparison constraint
void matchSets(int n , vector<char>& nuts,vector<char>& bolts){
    int freq[256] = {0};

    for(char c : nuts){
        freq[(int)c]++;
    }
    int j=0;
    for(int i=0; i<256;i++){
        if(freq[i]>0){
            nuts[j] = (char)i;
            bolts[j] = (char)i;
            j++;
        }
    }

}

// using partitioning in nuts based on a bolt

int compare(char nut, char bolt){
    string order = "!#$%&*@^~";
    int indNut = order.find(nut);
    int indBolt = order.find(bolt);
    if(indNut<indBolt) return -1;
    else if(indNut> indBolt) return 1;
    else return 0;
}

int partition(vector<char>& arr, char pivot, int s, int e,bool isNut){
    int i = s;
    for(int j=s;j<e;j++){
        int res = isNut? compare(arr[j], pivot): compare(pivot,arr[j]);
        if(res<0){
            swap(arr[i], arr[j]);
            i++;
        }
        else if(res==0){
            swap(arr[j], arr[e]);
            j--;
        }
        swap(arr[i], arr[e]);
        return i;
    }
}

void matchPairs(vector<char> &nuts, vector<char> &bolts, int s, int e){
    if(s<e){
        // last nut as pivot
        int pivotIndex = partition(bolts, nuts[e], s,e, false);
        partition(nuts, bolts[pivotIndex], s,e,true);

        matchPairs(nuts, bolts, s, pivotIndex -1);
        matchPairs(nuts, bolts, pivotIndex+1,e);

    }
}

int main(){
     vector<char> nuts = {'@', '#', '$', '%', '^', '&'};
    vector<char> bolts = {'$', '%', '&', '^', '@', '#'};

    // matchSets(nuts.size(), nuts, bolts);

    matchPairs(nuts, bolts,0, nuts.size() -1);

    for (int i = 0; i < nuts.size(); i++) {
        cout << nuts[i] << " - " << bolts[i] << endl;
    }

    return 0;
}