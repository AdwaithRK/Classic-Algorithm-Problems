function gpseries(a, r) {

    k = a;
    let x = {
        next: () => {
            old = k;
            k = k * r;
            return k;
        }
    }


    return x;
}
var myseries = gpseries(1, 3);
console.log(myseries);
a = myseries.next();
console.log(a);
a = myseries.next();
console.log(a);
a = myseries.next();
console.log(a);