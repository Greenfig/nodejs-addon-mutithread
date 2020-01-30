const addon = require('./build/Debug/addon.node')
const {performance} = require('perf_hooks')

const number = '16522060140317034287'

const test = (number, name, callback) => {
    let t = performance.now()
    console.log(`Starting ${name} factorial recursion`)
    const value = callback(number)
    console.log(`The factorial of ${value[0]} is ${value[1]} * ${value[2]}. ${name} finished in ${(performance.now() - t) / 1000} seconds`)
}

test(number, "Single Threaded", addon.Single)