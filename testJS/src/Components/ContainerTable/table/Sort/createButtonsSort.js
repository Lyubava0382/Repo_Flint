import sortTable from "./sortTable.js";

const callSortTable = (store) => (e) => {
    //Функция сортировки столбцов таблицы
    sortTable(e,store);
}

//Создает кнопки сортировки, если количество столбцов
// не соответствует количеству кнопок, выбрасывает ошибку об этом
const createButtonsSort = (table,classList,store) => {
    let ths = table.firstChild.getElementsByTagName('th');
    if(ths.length !== classList.length){
        throw 'Count "th" does math with count classes of buttons';
    }
    for(let i = 0;i<classList.length;i++){
        let sortButton = document.createElement('button');
        sortButton.innerHTML = 'Sort ascending';
        sortButton.classList.add('sort');
        sortButton.classList.add(classList[i]);
        sortButton.addEventListener('click', callSortTable(store));
        ths[i].appendChild(sortButton);
    }
}

export default createButtonsSort;