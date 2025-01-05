/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let usedonce=false;
    let res=0;
    return function(...args){
        if(!usedonce){
           res = fn(...args);
           usedonce=true;
           return res;
        }
        else{
            return undefined;
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
