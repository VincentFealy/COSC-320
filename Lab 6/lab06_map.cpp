// 3/20/23
// Vincent Fealy

#include <iostream>
#include <set>
#include <map>

#include "d_state.h"

int main(){
  map<string, string>  s;

  s["MD"] = "Salisbury";
  s["NY"] = "New York City";
  s["CA"] = "LosAngelos";
  s["FL"] = "MIAMI";
  s["MI"] = "Deluth";

  string state;

  std::cout << "Enter a state: " << std::endl;
  std::cin >> state;


  map<string, string>::iterator iter;

  iter = s.find(state);
  if(iter != s.end()){
      std::cout << iter->second << std::endl;
  }else{
      std::cout << "State not found" << std::endl;
  }

}