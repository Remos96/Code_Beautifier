#include <iostream>
using namespace std;

string removeLeadingSpaces(string line);
int countChar(string line, char c);
void indent();

int main()
{
    indent();
}


void indent(){

    int open_braces; 
    int closed_braces;
    int open_blocks = 0;
    int indentation_level;  
    
    string line;
    while (getline(cin, line)){
        line = removeLeadingSpaces(line);
        indentation_level = open_blocks;
        
        if (line[0] == '}'){
            indentation_level--;
        }

        for (int i = 0; i < indentation_level; i++){
            cout << '\t';
        }
        cout << line << endl;
        
        open_braces = countChar(line, '{');
        closed_braces = countChar(line, '}');
        open_blocks += open_braces - closed_braces;
    }
}


int countChar(string line, char c){

    int ans = 0;
    for (int i = 0; i < line.size(); i++){
        if (line[i] == c){
            ans++;
        }
    }
    return ans;
}


string removeLeadingSpaces(string line){

    int len = line.size(), i;
    for (i = 0; i < len; i++){
        if (not isspace(line[i])){
            break;
        }
    }
    return line.substr(i);  
}