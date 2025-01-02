/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let pres=init;
    const increment=()=>{
        return ++pres;
    };
    const decrement=()=>{
        return --pres;
    };
    const reset=()=>{
        pres=init
        return pres;
    };
    return { increment, decrement, reset };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */