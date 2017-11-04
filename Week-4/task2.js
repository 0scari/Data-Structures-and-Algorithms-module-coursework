/**
 * Quicksort Algorithm
 * Usage:
 * var arr = [8,3,1,7,6];
 * qSort(arr).findNthSmallest(n); //this is in-place
 * console.log(arr);
 *
 * The quicksort algorithm is an intellectual property of (Ajaxtown 2016).
 * It's been modified so that it was possible to retrieve the nth smallest element in the sorted array.
 *
 */

var qSort = function(arr) {

    // An associative array whose keys will be
    // the elements of the array which is being sorted
    var set = {};

    /* Swap positions */
    function swap(idx1, idx2) {

        var temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;

    }

    /* Partiton the array */
    function partition(left,right,pivot) {

        //incremenet this counter when we find an element
        //less than the pivot value
        var j = left;

        for(var i = left; i < right; i++) {

            // add element to the set with no value
            // because only keys will be needed
            set[arr[i]] = undefined;

            if(arr[i] < arr[pivot]) {
                swap(j,i);
                j++;
            }
        }

        set[arr[pivot]] = undefined;

        var newPivot = j;
        //bring the pivot in the right position
        swap(pivot, newPivot);

        return newPivot;

    }

    /**
     * Triggers the sort. Initially left and right will be undefined.
     * @param int left   | default: 0
     * @param int right  | default: lastIndex of array
     */
    function sort(left, right) {

        left = (typeof left === 'number') ? left : 0;

        right = (typeof right === 'number') ? right : arr.length - 1;

        if(left < right) {
            //the last index is going to be the pivot
            var pivot = right;
            // identify the new pivot, so that the
            //left elements < pivot and right elements > pivot
            var newPivot = partition(left,right,pivot);

            //apply the sort on the left elements
            sort(left, newPivot - 1);
            //apply the sort on the right elements
            sort(newPivot+1, right);

        }
    }

    /**
     * This function fetches the n_th smallest element from the associative array whose keys are sorted ascending
     * by default. Keys are extracted and the corresponding element is returned.
     * @param n
     * @returns {*}
     */
    function findNthSmallest(n) {
        return Object.keys(set)[n-1]
    }

    sort();
    
    return {
        findNthSmallest: findNthSmallest
    }

}

/**
 * Ajaxtown (2016) ALGORITHM - QUICKSORT IN JAVASCRIPT [online] available from
 <https://www.ajaxtown.com/article/algorithm-quicksort-in-javascript> [19 January 2016]
 */