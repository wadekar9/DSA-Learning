let arr = [66,96,1,0,11,65,840,77,651,7151,674,125,34,44,58,21,22];

for(let i=0;i<arr.length;i++){
    for(let j=0;j<=i;j++){
        if(arr[i]>arr[j]){
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
console.log(arr);