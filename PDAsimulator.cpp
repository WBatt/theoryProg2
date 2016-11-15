#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main(){
    
    std::stack<char> PDA;
    PDA.push('z');
    
    string line;
    ifstream myfile ("sequence.txt");
    
    if (myfile.is_open()){
        while (getline(myfile,line)){
            for(int i = 0; i < line.length(); i++){
                if(line[i] == 'i'){
                    PDA.push('i');
                }
                if(line[i] == 'e'){
                    if(PDA.top() == 'z'){
                        cout << "Sequence is syntactically incorrect" << endl;
                        return 0;
                    }
                    PDA.pop();
                    i += 3;
                }
            }
        }
        myfile.close();
        
        if(PDA.top() ==  'z'){
            cout << "Correct sequence" << endl;
        }else{
            cout << "Sequence is syntactically incorrect" << endl;
        }
    }
    
    return 0;
}