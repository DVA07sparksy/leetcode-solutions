// 912 ms | 12.9 MB
int removeDuplicates(int* nums, int numsSize) {
    int size = numsSize;
    for(int i=0; i<size-1; i++){
        for (int j = i + 1; j < size; j++) {
            if (nums[i] == nums[j]) {
                // Delete s[i] by shifting everything after it left
                for (int k = i; k < size - 1; k++) {
                    nums[k] = nums[k + 1];
                }
                size--;

                // Since a new character moved into position i,
                // check that new character again.
                i--;

                break;
            }
        }
    }
    //new size of elemrnts even though resize still remains numSIze
    return size;
}