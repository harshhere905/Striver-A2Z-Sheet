/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let res=[];
    let j=0;
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i],i)){
            res[j]=arr[i];
            j=j+1;
        }
    }
    return res;
};