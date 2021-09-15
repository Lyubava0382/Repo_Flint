import createRow from "./Rows/createRow.js";
import editRow from "./Rows/editRow.js";
import createButtonsSort from "./Sort/createButtonsSort.js";

export const callEditRow = (usr,dispatch) => (e) => {
    editRow(e,usr,dispatch);
}

//Создает строки таблицы
export const createRowsTable = (table,store) => {
    for(let i = 0;i < store.getState().usersOnPage.length;i++){
        let row = createRow(table,store.getState().usersOnPage[i],store.getState().usersOnPage[i].id);
        row.addEventListener('click',callEditRow(store.getState().usersOnPage[i],store.dispatch.bind(store)));
        table.appendChild(row);
    }
}

//Главная задача этой функции - создать заголовки и кнопки сортировки
const Table = (store,headers) => {
    let table = document.createElement('table');
    table.classList.add('table');
    let tr = document.createElement('tr');
    table.appendChild(tr);
    let classListTh = ['firstName','lastName','eyeColor','about'];//Список слассов для ячеек, нужны для работы со столбцами
    for(let i = 0;i<headers.length;i++){
        let th = document.createElement('th');
        th.classList.add('showed');//Скрыта ли ячейка, нужен для показа/скрытия столбцов
        th.classList.add(classListTh[i]);
        tr.appendChild(th);
        th.textContent = headers[i];
    }

    createRowsTable(table,store);

    let classListButtons = ['sortByFirstName','sortByLastName','sortByEyeColor','sortByAbout'];//Список классов кнопок, упрощает обращение
    createButtonsSort(table,classListButtons,store);
    return table;
}

export default Table;