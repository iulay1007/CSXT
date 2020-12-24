private  void core(int[] array) {
        int arrayLength = array.length;
        boolean oddSorted = false;
        boolean evenSorted = false;
        
        while(!oddSorted || !evenSorted) {
            int base = 0;
            oddSorted = true;
            evenSorted = true;
            
            for (int i = base; i < arrayLength - 1; i += 2) {
                if (array[i] > array[i + 1]) {
                
         array[i] = array[i+1] + array[i];
            array[i+1] = array[i] - array[i+1];
            array[i] = array[i] - array[i+1];
                    oddSorted = false;
                }
            }
            
            base = 1;
            for (int i = base; i < arrayLength - 1; i += 2) {
                if (array[i] > array[i + 1]) {
                    
            array[i] = array[i+1] + array[i];
            array[i+1] = array[i] - array[i+1];
            array[i] = array[i] - array[i+1];
                    evenSorted = false;
                }
            }
        }
    }

