package sort;
 
import java.util.ArrayList;
import java.util.List;
 
public class BasicSort {
    public static void basicSort(int[] array) {
        //创建叠加数组
        List<ArrayList> dyadic = new ArrayList<>();
        //给大数组dyadic添加子数组
        for(int i = 0; i < 10; i++) {
            ArrayList<Integer> arr = new ArrayList<>();
            dyadic.add(arr);
        }
 
        //找出数组中的最大值
        int max = 0;
        for(int i = 0; i <array.length; i++) {
            if(array[i] > max) {
                max = array[i];
            }
        }
 
        //判断最大值为几位数，其位数就是应该循环的次数
        int times = 0;
        while(max > 0) {
            max /= 10;
            times++;
        }
 
        //循环times次，每次将对应位的数分配到相应的自数组中
        for(int i = 0; i < times; i++) {
            for(int j = 0; j < array.length; j++) {
                //找出每个数对应的位的数值
                int x = array[j] % (int)Math.pow(10, i + 1) / (int)Math.pow(10, i);
                //将该数组作为下标，找到对应的子数组
                ArrayList arr = dyadic.get(x);
                //将该元素添加到子数组中
                arr.add(array[j]);
                //因为子数组改变，因此更新大数组
                dyadic.set(x, arr);
            }
 
            //将重新排好的子数组的值依次将需要被排序的数组的值覆盖
            int index = 0;   //用index作为数组array的下标
            //将子数组依次遍历，将每个子数组中的元素添加到array中
            for(int k = 0; k < 10; k++) {
                //当下标为k的子数组中有元素时
                while(dyadic.get(k).size() > 0) {
                    //得到该数组
                    ArrayList arr = dyadic.get(k);
                    ///将该数组的第一个元素添加到array中
                    array[index] = (int)arr.get(0);
                    //移除子数组中的第一个元素，这样就能在第一个元素被使用之后，后面元素替换
                    arr.remove(0);
                    //将array数组中下标也后移一位
                    index++;
                }
            }
        }
    }
}