const addon = require('./build/Debug/addon.node')
const {performance} = require('perf_hooks')

const number = 48112959837082048697n

const test = (number, name, callback) => {
    let t = performance.now()
    console.log(`Starting ${name} factorial recursion`)
    const value = callback(number)
    console.log(`The factorial of ${number} is ${value}. ${name} finished in ${(performance.now() - t) / 1000} seconds`)
}

test(number, "Single Threaded", addon.Single)