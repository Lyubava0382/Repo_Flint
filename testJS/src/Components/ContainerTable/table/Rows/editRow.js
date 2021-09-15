import showDivEdit from "../../../EditRow/divEdit.js";

//Выделяем или снимаем изменяемую строку, посредством добавления/удаления класса allocated
const markRow = (tr) => {
    let table = tr.parentNode;
    let rows = table.rows;
    if(tr.classList.contains('allocated')){
        tr.classList.remove('allocated');
    }else{
        for(let i=0;i<rows.length;i++){
            if (rows[i].classList.contains('allocated')){
                rows[i].classList.remove('allocated');
            }
        }
        tr.classList.add('allocated');
    }
}


//При клике на строку создается блок для изменений данных через функцию showDivEdit
const editRow = (e,usr,dispatch) => {
    markRow(e.target.parentNode);
    showDivEdit(e.target.parentNode,usr,dispatch);
}

export default editRow;
