//  main.cpp
//  AlgorithmsProject
//  Created by Habiba Mohamed on 19/05/2022.


#include <iostream>
#include <vector>
using namespace std;

//first thing is to make a function that returns the string with the shortest length
int shortestLength(string arr[], int noOfStrings){
    int min = arr[0].length();
    for(int i = 1; i < noOfStrings; i++){
        if(arr[i].length() < min){
            min = arr[i].length();
        }
    }
    return (min);
    
}

// Getting the LCP using Brute Force Approach.
string LongestCommonPrefix(string arr[], int noOfStrings){
    int min = shortestLength(arr, noOfStrings);
    
    string result;
    for(int i = 0; i < min; i++){
        char current = arr[0][i];
        
        for (int j=1 ; j<noOfStrings; j++)
            if (arr[j][i] != current)
                return result;
        // we could have made it with an array but pushback is better because the size is more dynamic.
        // we don't know LCP kam harf, fa l array ayza size mo3yan,then l vector aw pushback ahsan.
        result.push_back(current);
    }
    return (result);
}




//Getting the LCP with Dynamic Programming.
string getMinString(string X, string Y){
    if(X.length()>= Y.length())
        return Y;
   
    return X;
}
string LCPdynamic(string X, string Y)
{
    if (X[0] != Y[0])
        return "";
    
    string S = getMinString(X,Y);
    int min = S.length();
    
    int arr[min]; //int x = 1;
    arr[0]=1; // hashel da aslan
        
    for(int i = 1; i < min; i++ ){
        if (X[i] != Y[i]){
            arr[i] = arr[i-1]; // continue
           
            
        }
        else{
            arr[i] = arr[i-1]+1; // x++
        }
    }
    return S.substr(0,arr[min-1]); // (0,x)
    
}


//Getting the LCP with Divide and Conquer Approach.
string commonPrefix(string str1, string str2)
{
    string result;
    string minimum = getMinString(str1, str2);
 
    for (int i=0; i<minimum.length();i++)
    {
        if (str1[i] != str2[i])
            break;
        result.push_back(str1[i]);
    }
    return (result);
}


string Divide(string arr[], int low, int high)
{
    if (low == high)
        return (arr[low]);
 
    if (high > low)
    {
        int mid = (low + high)/ 2;
 
        string str1 = Divide(arr, low, mid);
        string str2 = Divide(arr, mid+1, high);
 
        return (commonPrefix(str1, str2));
    }
    return "";
}



int main() {
    //Brute force testing
    string arr[] = {"Hibiba", "Hassan","Hanya"};
    //fl java kan andna .size() enama hna fl c++ lazm n3ml kda ashan ngeeeb size of the array
       int n = sizeof (arr) / sizeof (arr[0]);
       string ans = LongestCommonPrefix (arr, n);
    
       if (ans.length())
           cout << "The longest common prefix using Brute Force is " << ans << endl;
       else
           cout << "There is no common prefix" << endl;
       
    //Divide and Conquer testing
    string arr2[] = {"Appropriate","Appreciation","Application", "Apssple"};
    int n2 = sizeof (arr2) / sizeof (arr2[0]);
    string ans1 = Divide(arr2, 0, n2-1);
 
    if (ans.length())
        cout << "The longest common prefix using Divide and Conquer is "  << ans1 << endl;
    else
        cout << "There is no common prefix" << endl;
    
    
    //Dynamic testing
    string X = "Algorithms Analysis", Y = "Algorithm Analysis and Design";
    cout << "The longest common Prefix using Dynamic Programming is " << LCPdynamic(X,Y) << endl;
    

//    cout << "The longest common Prefix is " << LCPdynamic2({"Habiba", "Hassan","Hanya"}) << endl;
    
   
    
     


}




































//int shortestLength2(vector<string> arr, int noOfStrings){
//    int min = arr[0].length();
//    for(int i = 1; i < noOfStrings; i++){
//        if(arr[i].length() < min){
//            min = arr[i].length();
//        }
//    }
//    return (min);
//
//}
//
//string LCPdynamic2(vector<string> x)
//{
//    vector<vector<string>> table(x.size(),vector<string>(x.size()));
//    int k=0;
//    for(int i = 0; i<x.size(); i++){
//        for(int j =k; j<x.size(); j++){
//            if(j==i)
//                table[j][j]= x[j];
//            else if(k!=0)
//                table[i][j] = LCPdynamic(table[i+k][j-1], table[i+1][j]);
//        }
//        k++;
//    } return table[0][x.size()-1];
//
//
//
//}
