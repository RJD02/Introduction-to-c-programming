/*
 * Given two arrays of integers output the largest number in the
first array not present in the second one.

Input: 

The first line contains the size of the first array. -> n1
Next line give the contents of the first array. -> a[i]
Next line contains the size of the second array. -> n2
Next line give the contents of the second array. -> b[i]

Output Format:
Output must be a single number which is the largest number occurring
in the first array that does not occur in the second. In case there is
no such number, output 0.

Variable Constraints:
The sizes of the arrays are smaller than 20.
Each array entry is an integer which fits an int data type.

Example:
Input:
3
2 3 4
4
1 4 5 7

Output: 3

Input
1
1
2
1 2

Output: 0
*/

//Pre-Requisites: Array operations and indexing and how to pass arrays by value and by reference

#include<stdio.h>
//We are stepping into some modern techniques here
//So grab your seat and HERE WE GO!!!!

//Things to make life easy
#define sf scanf	//Now we only write sf for scanf
#define pf printf	//Now we only write pf for printf

//This function basically scans the array from standard input.
void scanArray(int *a, int n) {	//Notice that we have a pointer to the original array so that we can modify it according to our requirement
	for(int i = 0; i < n; i++) {
		sf("%d", &*(a + i));	//Our shortcut saves time
		//It is not efficient though, don't worry we will refactor it next time, for now follow KISS
	}
}

//This algorithm is basically insertion sort, which sorts the array in O(n^2) time 
void sort(int *a, int n) {
	for(int i = 1; i < n; i++) {
		int key = *(a + i);
		int j = i - 1;
		while(j >= 0 && key < *(a + j)) {
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = key;
	}
}
//Write this algorithm if you want, it is good to have a running sorting algorithm in your coding arsenal other than bubble Sort, which is basically iterating like a mad man/woman.
//If you are happy using bubble sort, suit yourself, I don't care.

//This is a pretty famous algorihtm to find something from a long array.
//The value that you are finding is called key, just follow along with this terminology
//The basic idea is, if there were a sorted sequence and you had to find a value in that array, then you just look up in the middle,
//if the value in the middle is less than your key value, then you look ahead in the array, that is you scan the right half
//if the value in the middle is greater than your key value, then you look behind, that is you scan the left half
//if the value in the middle matches with your key value, VOILA!, you found it!
//if you don't find it after doing it recursively, then you can confidentally say it does not exist in the given array.
int binarySearch(int *arr, int n, int value) {
	int max = n - 1, min = 0, mid;
	while(max >= min) {
		mid = (max + min) / 2;
		if(*(arr + mid) == value) {
			return 1;
		}
		else if(*(arr + mid) > value) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	return 0;
}
//This algorithm follows divide and conquer paradigm so, it runs in O(lg n), and is pretty quick for small n

int main() {
	int n;
	sf("%d", &n);	//Scanning the number of elements
	int a[n];	//Creating the array.
	scanArray(a, n);	//Scanning the array by calling scanArray().
	int m;	
	sf("%d", &m);	//Scanning the number of elements of the second array
	int b[m];	//Creating the second array
	scanArray(b, m);	//Scanning the array by calling scanArray()
	sort(a, n);	sort(b, m);	//This is an important step, because binary search algorithm only works if the array is sorted!
	for(int i = n - 1; i >= 0; i--) {
		if(binarySearch(b, m, *(a + i))) {	//So we iterate over all n and we find if that value exists in array b.
			//Notice that we are putting in the whole function in if condition, some call it madness, and I personally call it suicide.
			//But the thing is there is method to this madness!
			//Notice what the binary search returns, it returns either 1 or 0, which is boolean equivalent of true or false.
			continue;	//if yes we skip the further process.
		}
		else {
			pf("%d", *(a + i));	//Notice that we terminate the main function after the execution of this statement, since we need only one value
			return 0;
		}
	}
	pf("0");	//if above condition fails and we exit out of loop without finding the key, we execute this statement.
	return 0;
}
//The below part is just for me, if you don't know what this means, don't bother about it
//It's just part of my OCD!
//Total time complexity the program takes is O(n ^ 2)
//Which can be reduced using merge Sort or heap Sort
//Best time complexity will be: O(nlgn)
