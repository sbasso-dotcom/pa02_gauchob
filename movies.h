#include <map>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

void printMovies(map<string, float> movies);

void printMoviesDecreasing(map<string, float> hasPre);

bool Sort(pair<string, int> a, pair<string, int> b);

void checkPrefixes(vector<string> prefixes, map<string, float> movies);