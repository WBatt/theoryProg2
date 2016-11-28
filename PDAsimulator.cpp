#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main(){
    
    std::stack<char> PDA;   //stack
    PDA.push('z');          //bottom of stack
    
    string line;
    ifstream myfile ("sequence.txt");
    
    if (myfile.is_open()){
        while (getline(myfile,line)){                   //while there are more lines - get the next line
            for(int i = 0; i < line.length(); i++){     //loop through each character in the line
                if(line[i] == 'i'){                     
                    PDA.push('i');                      //push when you find an 'i'
                }
                if(line[i] == 'e'){                                 
                    if(PDA.top() == 'z'){               //too many "else" statements = bad           
                        i = line.length() + 1;
                        PDA.push('e');
                    }
                    if(i != line.length() +1)
                        PDA.pop();                          //pop when you find an 'e'
                    i += 3;                             //add 3 to skip the second 'e' in "else"
                }
            }
            
            if(PDA.top() ==  'z'){                          //if 'z' is left everything worked
                cout << "Correct sequence" << endl;
            }else{                                          //else it didn't work
                cout << "Sequence is syntactically incorrect" << endl;
                while(!PDA.empty()){
                    PDA.pop();
                }
               PDA.push('z');
            }
            
            
            
    
        }
    }
    
    myfile.close();
        
    
    return 0;
}