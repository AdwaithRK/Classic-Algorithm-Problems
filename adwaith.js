

birthday_date  = "29-02";

let ans = "";

let space = false;

for(let i = 2016; i < 2016 + 50; i++){
    let input = birthday_date + "-" + i;
    //console.log(input);
    let output = input.replace(/(\d\d)-(\d\d)-(\d{4})/, "$3-$2-$1");

    console.log(output);

    let date = new Date(output);

    
    
    if(date.getDay() == 5) {
        ans += ("Fri-" + i);
        if(space) ans+= " ";
    }

    else if(date.getDay() == 6){
        ans += ("Sat-" + i);
        if(space) ans+= " ";
    }

    else if(date.getDay() == 0){
        ans += ("Sun-" + i);
        if(space) ans+= " ";
    }

    space = true;
}


console.log(ans);