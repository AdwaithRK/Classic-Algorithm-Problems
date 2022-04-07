let a = {
    agnus: "agnus!!!",
    getname: () => {
        console.log(`hi ${a.agnus}`)
    }
}

this.agnus = "agnus"
setTimeout(a.getname, 10);