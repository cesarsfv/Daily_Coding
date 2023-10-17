/* This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.   

*/


// Defina a função cons para criar pares
function cons(a, b) {
    function pair(f) {
        return f(a, b);
    }
    return pair;
}

// Defina a função car para obter o primeiro elemento do par
function car(pair) {
    return pair((a, b) => a);
}

// Defina a função cdr para obter o último elemento do par
function cdr(pair) {
    return pair((a, b) => b);
