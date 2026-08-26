class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int pivot = -1, n = A.size();
        
        //1 finding pivot
        for(int i = n-2; i>=0; i--){
            if(A[i] < A[i+1]){
                pivot = i;
                break;
            }
        }
        // if pivot not found
        if(pivot == -1){
            reverse(A.begin(), A.end());
            return;
        }

        //2 swapping pivot with next largest 
        for(int i = n-1; i > pivot; i--){
            if(A[i] > A[pivot]){
                swap(A[i], A[pivot]);
                break;
            }
        }

        //3 reverse(piv+1, n-1)
        int i = pivot+1, j = n-1;
        while(i <= j){
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};