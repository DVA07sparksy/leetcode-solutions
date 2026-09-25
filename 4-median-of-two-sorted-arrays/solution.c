// 83 ms | 12.1 MB
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size =nums1Size + nums2Size;
    int temp[size];
    for (int i = 0; i < nums1Size; i++) {
        temp[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        temp[i + nums1Size] = nums2[i];
    }
    double sum=0;
    for(int i = 0; i < size; i++){
       sum=sum+temp[i];
    }
    //sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (temp[j] > temp[j + 1]) {
                int p = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = p;
            }
        }
    }
    if (size % 2 != 0) {
        return temp[size / 2];
    }

    return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;

}