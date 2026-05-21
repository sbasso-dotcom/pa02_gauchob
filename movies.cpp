#include "movies.h"



void printMovies(map<string, float> movies){
    for (auto it = movies.begin(); it != movies.end(); it++){
        cout << it->first << ", " << it->second << endl;
    }
}
bool mySort(pair<string, float> a, pair<string, float> b){
    if (a.second == b.second){
        return a.first < b.first;
    }    
    return a.second > b.second;
    }
void printMoviesDecreasing(map<string, float> hasPre){
    vector<pair<string,float>> v(hasPre.begin(), hasPre.end());
    sort(v.begin(),v.end(), mySort);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << ", " << v[i].second << endl;
    }
}


void checkPrefixes(vector<string> prefixes, map<string, float> movies){
    map<string, float> hasPre;
    for (int i = 0; i < prefixes.size(); i ++){
        hasPre.clear();
        string bestName = "";
        float bestRating = 0;
        for (auto it = movies.begin(); it != movies.end();it++){
            if(it->first.substr(0,prefixes[i].length()) == prefixes[i]){
                if (it->second > bestRating){
                    bestRating = it->second;
                    bestName = it->first;
                }
                hasPre[it->first] = it->second;
            }
        }
        printMoviesDecreasing(hasPre);

        if (hasPre.empty()){
            cout << "No movies found with prefix " << prefixes[i] << endl;
        }
        else {
            cout << "Best movie with prefix " << prefixes[i] << " is: " << bestName << " with the rating " << bestRating << endl;
        }
    }
}