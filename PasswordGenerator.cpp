/*
Github: BenasKc
This is the Password Generator, written in C++. Once launched, it is possible to choose:
	- Length of the string
	- Numerical generation type
	- Lowercase and Uppercase generation type
	- And also the option to throw in some basic ASCII symbols
	- ...And to combine them all!
*/
#include <iostream> c
#include <vector>
#include <stdlib.h>
bool alphalow = false;
bool alphaupp = false;
bool numer = false;
bool ASCII = false;
int length = 10;
std::vector<std::string> parameters;
bool isNumber(std::string str){
    for(int i = 0;i < str.length();i++){
        if(std::isdigit(str[i]) == 0) return false;
    }
    return true;
}
char chargen(){
    int a = rand() % 4;
    switch(a){
        case 0:return (char) (rand() % 15 + 33);
        case 1:return (char) (rand() % 7 + 58);
        case 2:return (char) (rand() % 4 + 123);
        case 3:return (char) (rand() % 6 + 91);
    }
}
char itemgen(){
    int choice = rand() % 4;
    switch(choice){
        case 0: if(alphalow == true){return (char) (rand() % 26 + 97);}else(itemgen());break;
        case 1: if(alphaupp == true){return (char) (rand() % 26 + 65);}else(itemgen());break;
        case 2: if(numer == true){return (char) (rand() % 10 + 48);}else(itemgen());break;
        case 3: if(ASCII == true){return chargen();}else(itemgen());break;
    }
}
std::string generated(){
    for(int i = 0;i < parameters.size();i++){
        switch(parameters[i][0]){
            case 'a': alphalow = true;break;
            case 'A': alphaupp = true;break;
            case 'n': numer = true;break;
            case 's': ASCII = true;break;
            case 'l': if(isNumber(parameters[i+1]) == 0){std::cout << "Wrong length parameter passed\n";return 0;}else{length=std::stoi(parameters[i+1]);i++;}break;
            default: std::cout <<"Wrong parameter passed!\n"; return "exit";
        }
    }
    srand(time(NULL));
    std::string pass = "";
    for(int i = 0; i < length;i++){
        pass += itemgen();
    }
    return pass;
}
int main(){
    std::cout << "Welcome to password generator 1.0!";
    std::cout << "\nTo quit press Ctrl+C \n";
    std::cout << "Parameters for generator: a - alphabetical lowercase, n - numeric, s - ASCII symbols, A - alphabetical uppercase, l length(by default 10) \n";
    std::cout << "Example: a A l 5 would return something like KfpAQ\n\n";
    std::string a;
    std::getline(std::cin, a);
    int last_ = 0;
    for(int i = 0; i <= a.length(); i++){
        if(a[i]==' ' || a[i] == '\0'){
            std::string tempstr = "";
            for(int j = last_; j < i;j++){
                if(j != ' '){
                    tempstr+=a[j];
                }
            }
            if(tempstr.length() != 0)parameters.push_back(tempstr);
            tempstr.clear();
            last_ = i+1;
        }
    }
    std::string f = generated();
    if(f == "exit"){return 0;}
    std::cout << f << '\n';
    return 0;
}
