#include<iostream>
using namespace std ;

int main(){
    int n ; 
    cin >> n ;
    int sum = 0 ;  
    while(n--){
        int a, b ,c; 
        cin >> a >> b >> c ; 
        if((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1))
        sum++; 
    }
    cout << sum ; 
}