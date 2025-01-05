/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const backup = new Map();
    let count=0;
    return function(...args) {
        const argument=args.toString();
        if(backup.has(argument)){
            return backup.get(argument);
        }
        let res=fn(...args);
        backup.set(argument,res);
        count+=1;
        return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */