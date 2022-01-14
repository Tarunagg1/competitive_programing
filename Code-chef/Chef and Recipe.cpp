// Chef and Recipe Problem Code: CHEFRECP
// Add problem to Todo list
// Submit
// Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
// In Chefland, types of ingredients are represented by integers and recipes are represented by sequences of ingredients that are used when cooking. One day, Chef found a recipe represented by a sequence A1,A2,…,AN at his front door and he is wondering if this recipe was prepared by him.

// Chef is a very picky person. He uses one ingredient jar for each type of ingredient and when he stops using a jar, he does not want to use it again later while preparing the same recipe, so ingredients of each type (which is used in his recipe) always appear as a contiguous subsequence. Chef is innovative, too, so he makes sure that in each of his recipes, the quantity of each ingredient (i.e. the number of occurrences of this type of ingredient) is unique ― distinct from the quantities of all other ingredients.

// Determine whether Chef could have prepared the given recipe.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains a single integer N.
// The second line contains N space-separated integers A1,A2,…,AN.
// Output
// For each test case, print a single line containing the string "YES" if the recipe could have been prepared by Chef or "NO" otherwise (without quotes).

// Constraints
// 1≤T≤100
// 1≤N≤103
// 1≤Ai≤103 for each valid i
// Sample Input 1 
// 3
// 6
// 1 1 4 2 2 2
// 8
// 1 1 4 3 4 7 7 7
// 8
// 1 7 7 3 3 4 4 4
// Sample Output 1 
// YES
// NO
// NO
// Explanation
// Example case 1: For each ingredient type, its ingredient jar is used only once and the quantities of all ingredients are pairwise distinct. Hence, this recipe could have been prepared by Chef.

// Example case 2: The jar of ingredient 4 is used twice in the recipe, so it was not prepared by Chef.


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    int freq[1001] = {0};
	    
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        freq[arr[i]]++;
	    }
	    
	    
	    int flag = 0;
	    int unq[1001] = {0};

	    for(int i=0; i<1001; i++){
	        if(freq[i] > 0)
	            unq[freq[i]]++;
	    }
	    
	    for(int i : unq){
	        if(i > 1){
	            flag = 1;
	            break;
	        }
	    }
	    
	    if(flag == 1){
	       cout<<"NO"<<endl;  
	    }else{
	        cout<<"YES"<<endl;
	    }
	    
	}   
	   
    
	return 0;
}














