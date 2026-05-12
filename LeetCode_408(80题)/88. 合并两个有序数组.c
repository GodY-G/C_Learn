void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
        //双指针写法
        //int p1,p2 = 0;
        //int sorted[m + n];
        //int temp;

       // while(p1 < m || p2 <n){
            //if(p1 == m){
                //temp = nums2[p2++];
           // }else if(p2 == n){
            //    temp = nums1[p1++];
       //     }else if(nums1[p1] < nums2[p2]){
            //    temp = nums1[p1++];
       //     }else{
       //         temp = nums2[p2++];
       //     }

        //    sorted[p1 + p2 - 1] = temp;
       // }

       // for(int i = 0;i < m + n;++i){
       //     nums1[i] = sorted[i];
       // }

        //逆向双指针写法
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;
        while(p2 >= 0){
            if(p1 >= 0 && nums1[p1] > nums2[p2]){
                nums1[p--] = nums1[p1--];
            }else{
                nums1[p--] = nums2[p2--];
            }
        }
    }