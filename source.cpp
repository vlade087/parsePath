//============================================================================
// Name        : source.cpp
// Author      : Vladimir Charchabal
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#include<complex>
#include<numeric>
#include<list>
#include<deque>
#include<stdlib.h>
#define printnVector(R) cout<<R.size()<<endl;for(int i =0;i<R.size();i++) cout<<R[i]<<" ";
#define mod 1000000007
#define inf 9223372036854775807L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 20005
#define EPS 1e-9
#define par pair<int,int>
using namespace std;


//
string parsePath(string path , int length){
	//Validate input
	string drive = path.substr(0,3);
	string firstFolder = "...\\";
	string fileName="";
	int i = path.size()-1;
	while(path[i]!='\\'){//Assuming the input is a valid path to avoid infinity loop
		fileName = path[i] + fileName;
		i--;
	}
	i = 3;
	while(i < path.length() && path[i]!='\\') i++; //looking for the second slash
	string currentFolder = "";
	string result = drive + firstFolder;
	bool isFileNameAttached = false;
	for(int j = i+1;j< path.length();j++){
		if(path[j] == '\\'){
			if(result.length()+ currentFolder.length()+path.length() - j <= length){
				result += currentFolder + path.substr(j);
				isFileNameAttached = true;
				break;
			}
			currentFolder = "";
		}else{
			currentFolder+=path[j];
		}
	}
	if(!isFileNameAttached) result += fileName;
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	string a = "C:\\Users\\Navin\\Documents\\Bar\\foo\\file.txt";
	// C:\Documents\Newsletters\Summer2018.pdf
	// C:\...\Summer2018.pdf
	cout<<a<<" "<<a.size()<<endl;
	cout<<parsePath(a, 40)<<endl;
	return 0;
}

