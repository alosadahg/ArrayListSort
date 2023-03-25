#include "list.h"
#include <cstdlib>
#include <iostream>
using namespace std;

class ArrayList : public List { // : means "is-a" / extend
    int* array;
    int index;

    public:
        // CONSTRUCTOR
        ArrayList() {
            array = (int*) malloc(10);
            index = 0;
        }

        void add(int num) {
            *(array + index) = num;
            index++;
        }

        void remove(int num){ // first num that we found
            // FIND the num
            for (int i = 0; i < index; i++) {
                if (num == *(array + i)) { // we have found the num
                    for (int j = i; j < index - 1; j++) {
                        *(array + j) = *(array + j + 1);
                    }
                    index--;
                    return;
                }
            }
        }

        int get(int pos){
            return *(array + pos - 1);
        }

        int size(){
            return index;
        }

        void print() {
            cout << "[";
            for (int i = 0; i < index; i++) {
                cout << *(array + i);
                if (i != index - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
        }

        void addAt(int num, int pos) {
           if(pos > index+1 || pos < 1) {
               cout << "Position value invalid" << endl;
           }
            else {
                for(int i=index-1; i>=pos-1; i--) { 
                    array[i+1] = array[i]; 
                    if(i==pos-1) {
                        array[i] = num;
                    }
                }
                index++;
            }
        }

        void removeAt(int pos) {
            if(pos > index || pos < 1) {
               cout << "Position value invalid" << endl;
           } else {
                for(int i=pos-1; i<index; i++) {
                    array[i] = array[i+1];
                }
                index--;
           }
        }

        void removeAll(int num) {
            for(int i=0; i<index; i++) {
                if(array[i]==num) {
                    for(int k=i; k<index; k++) {
                        array[k] = array[k+1];
                    }
                    index--;
                    i--;
                }
            }
        }

        void flip() {
        	//Invere of the Array List
            int mid = index/2;
            int other = index-1;
            for(int i=0; i<mid; i++) {
                int temp = array[i];
                array[i] = array[other];
                array[other] = temp;
                other--;
            }
        }

        void plus(int num) {
            for(int i=0; i<index; i++) {
                array[i]+=num;
            }
        }

        int summation() {
            int sum = 0;
            for(int i=0; i<index; i++) {
                sum += array[i];
            }
            return sum;
        }
};