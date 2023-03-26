#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <tuple>
#include <map>
using namespace std;

map<tuple<string, char>, vector<string>> delta;
vector<string> F;
bool ok;


//alg de backtracking                     multimea de stari curente       stari parcurse
void verifCuv(const char cuv[], int k, const vector<string>& states, vector<string>& prevstates){
    if(k < strlen(cuv)) {
        for (auto i = states.begin(); i != states.end(); i++)
            if (!delta[make_tuple(*i, cuv[k])].empty()) {
                prevstates.push_back(*i);
                verifCuv(cuv, k + 1, delta[make_tuple(*i, cuv[k])], prevstates);
                prevstates.pop_back();
            }
    }
    else for(auto i=states.begin(); i!=states.end(); i++) {
            for(auto j=F.begin(); j!=F.end(); j++)
                if(*i == *j){
                    ok = true;
                    for(auto p=prevstates.begin(); p!=prevstates.end(); p++)
                        cout<<*p<<" -> ";
                    cout<<*i<<"\n";
                }
        }
}


int main()
{
    ifstream fin("AF.in");
    string q0;
    fin>>q0;
    string f;
    fin>>f;
    while(f != ";"){
        F.push_back(f);
        fin>>f;
    }
    string qi, qj;
    char l;
    while(fin>>qi>>l){
        tuple<string, char> tuple1;
        tuple1 = make_tuple(qi, l);
        fin>>qj;
        while(qj != ";") {
            delta[tuple1].push_back(qj);
            fin >> qj;
        }
    }
    char cuv[100];
    cin>>cuv;
    while(strcmp(cuv, "stop")){
        ok = false;
        vector<string> states, prevstates;
        states.push_back(q0);
        verifCuv(cuv, 0, states, prevstates);
        if (!ok)cout << "Neacceptat\n";
        cin>>cuv;
    }
    return 0;
}
