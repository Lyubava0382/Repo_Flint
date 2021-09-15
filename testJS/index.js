import store from "./store/store.js";
import App from "./App.js";
import {COUNT_ROWS_TABLE} from "./consts.js";
import {createRowsTable} from "./src/Components/ContainerTable/table/Table.js";


/*Приложение основано на FLUX-архитектуре,
используется объект store для хранения данных - state и
набор методов для изменения state
* */


//Функция перерисовки таблицы, используется при переключении страниц и сортировке
const rerenderTable = (store) => {
    let table = document.querySelector('.table');
    if(table.rows.length !== 0){
        for(let i = 0; i < COUNT_ROWS_TABLE; i++){
            table.querySelector('.tr').remove();
        }
    }
    createRowsTable(table,store);
}

//В корневом элементе body создается div с главным контейнером
document.body.appendChild(App(store));

//Используя паттерн observer помещаем в store функцию rerenderTable
store.subscribe(rerenderTable.bind(this,store));
