//��һ������ѭ������kλ
//�α����н��ܹ������㷨�����ε��� 
 void reverse(int[] arr,int b,int e){
    for(;b<e;b++,e--){
        int tmp=arr[e];
        arr[e]=arr[b];
        arr[b]=tmp;
    }
}

 void shiftK(int[] arr,int k){
    int len=arr.length;
    reverse(arr,len-k,len-1);
    reverse(arr,0,len-k-1);
    reverse(arr,0,len-1);
}
