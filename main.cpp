#include <iostream>
#include "arraylist.h"
int n;
using namespace std;

List* bubbleSort(List* list);
List* insertionSort(List* list);
List* selectionSort(List* list);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	List* list = new ArrayList();
	cout<<"Enter number of elements: ";
    cin>>n;
    int input;
    for(int i=0; i<n; i++) {
    	cout << "Enter element " << i+1 <<": ";
    	cin>>input;
    	list->add(input);
	}
	selectionSort(list);
	list->print();
	return 0;
}

List* bubbleSort(List* list) {
	//iterating through entire array
    for(int i=0; i<n; i++) {
        //iterating from index 0 to unsorted index
        for(int j=0; j<n-i-1; j++) {
            //check if leftelement > rightelement
            if ((list->get(j+1) > list->get(j+2) )&& (j+2) <= n){
            	int left = list->get(j+1);
            	int right = list->get(j+2);
                //swap the elements
            	list->removeAt(j+1);
            	list->removeAt(j+1);
            	if(j==(n-2)) {
            		list->add(right);
            		list->add(left);
				} else {
					list->addAt(right,j+1);
                	list->addAt(left,j+2);
				}
            }
        }
    }
    return list;
}

List* insertionSort(List* list) {
	for(int i=1; i<=n; i++){
        int j = i;
        if(j==n) {
        	break;
		}
        while(list->get(j)>list->get(j+1) && j!=0) {
//        	cout << "j = " << j << endl;
            int left = list->get(j);
            int right = list->get(j+1);
//            cout << "left: " << left << endl;
//            cout << "right: " << right << endl;
            //swap the elements
            list->removeAt(j);
            list->removeAt(j);
            if(j==(n-1
			)) {
            	list->add(right);
            	list->add(left);
			} else {
				list->addAt(right,j);
               	list->addAt(left,j+1);
			}
//			cout << "After:" << endl;
//			cout << "left: " << list->get(j) << endl;
//            cout << "right: " << list->get(j+1) << endl;
//            list->print();
            cout << endl;
            j--;
        }
    }
}

List* selectionSort(List* list) {
	for(int i=1; i<=n; i++) {
        int min = i;
        for(int j=i+1; j<=n; j++) {
            if(list->get(j) < list->get(min)) {
                min = j;
            }
        }
        if(min!=i) {
            int left = list->get(i);
            int right = list->get(min);
            //swap the elements
            list->removeAt(i);
            list->removeAt(min-1);
            if(min==n) {

				if(i>list->size()) {
					list->add(right);
				} else {
					list->addAt(right,i);
				}	
            	list->add(left);
			} else {
				list->addAt(right,i);
				if(min==i+1) {
					list->addAt(left, min);
				} else
               	list->addAt(left,min-1);
			}
        }
    }
    return list;
}




