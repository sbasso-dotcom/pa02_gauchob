#include "movies.h"



void printMovies(map<string, float> movies){
    for (auto it = movies.begin(); it != movies.end(); it++){
        cout << it->first << ", " << it->second << endl;
    }
}

void checkPrefixes(vector<string> prefixes, map<string, float> movies){
    for (int i = 0; i < prefixes.size(); i ++){
        string bestName = "";
        float bestRating = 0;

        for (auto it = movies.begin(); it != movies.end();it++){
            if(it->first.substr(0,prefixes[i].length()) == prefixes[i]){
                if (it->second > bestRating){
                    bestRating = it->second;
                    bestName = it->first;
                }
            }
        }
        if (bestName.empty()){
            cout << "No movies found with prefix " << prefixes[i];
        }
        else {
            cout << "Best movie with prefix " << prefixes[i] << " is: " << bestName << " with the rating " << bestRating << endl;
        }
    }
}