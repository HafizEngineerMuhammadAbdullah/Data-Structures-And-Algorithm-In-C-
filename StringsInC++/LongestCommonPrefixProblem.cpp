#include<iostream>
#include<vector>
using namespace std;


// TC:O(n*k) = O(n) , SC:O(1)
string longestCommonPrefixProblem(vector<string>str){
	// assume/supppose the first string will be the prefix string
   string firstStrAndPrefixStr = str[0];
   
   // (loop through)scan the remaining/rest of the string array
   for(int i = 1; i < str.size(); i++){
   	if(firstStrAndPrefixStr == "") break;
     // each time when we comparing/try to matching two strings, we empty the prefix str as we don't know what will be the longest common prefix between two strings
      string prefixBtwTwoStrings = "";
      string secStr = str[i];
      for(int j = 0; j < firstStrAndPrefixStr.size() && j < secStr.size(); j++){
         if(firstStrAndPrefixStr[j] == secStr[j]){
            prefixBtwTwoStrings += firstStrAndPrefixStr[j];
         } else{
            break;
         }
      }
      firstStrAndPrefixStr = prefixBtwTwoStrings;
   }

   return firstStrAndPrefixStr;
}
int main(){
    cout << "\n \t \t \t \t \t \t \t Program to Solve Longest Common prefix Problem" << endl;
    cout << "\n \t \t \t \t \t \t \t=================================================" << endl;
//    vector<string> str = {"bat","bank","bag","band"};
//    vector<string> str = {"dag","dog","dig","dug"};
    vector<string> str = {"neet","feet"};
//    vector<string> str = {"!abdul","!hafizabdullah"};
    cout << "longest common prefix str is : " << "'" << longestCommonPrefixProblem(str) << "'" << endl;
}