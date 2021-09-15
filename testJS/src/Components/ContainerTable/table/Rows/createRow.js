const createRow = (table,user,idRow) =>{
    let ths = table.getElementsByTagName('th');
    let tr = document.createElement('tr');
    tr.classList.add('tr');
    tr.id = idRow;
    for(let i = 0; i<4; i++){
        let td = document.createElement('td');
        td.classList.add('showed');
        switch (i){
            case(0):
                td.classList.add('firstName');
                if(ths[0].classList.contains('hide')){
                    td.classList.add('hide');
                }
                td.innerHTML = user.name.firstName;
                break
            case(1):
                td.classList.add('lastName');
                if(ths[1].classList.contains('hide')){
                    td.classList.add('hide');
                }
                td.innerHTML = user.name.lastName;
                break;
            case(2):
                td.classList.add('eyeColor');
                if(ths[2].classList.contains('hide')){
                    td.classList.add('hide');
                }
                td.innerHTML = user.eyeColor;
                td.style.background = user.eyeColor;
                break;
            case(3):
                td.classList.add('about');
                if(ths[3].classList.contains('hide')){
                    td.classList.add('hide');
                }
                td.innerHTML = user.about;
                break;
        }
        tr.appendChild(td);
    }
    return tr;
}

export default createRow;