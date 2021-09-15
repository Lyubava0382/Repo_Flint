import Div_pages_table from "./pages_table/Div_pages_table.js";
import Table from "./table/Table.js";
import Div_showed_columns from "./showed_columns/Div_showed_columns.js";

const Container_table = (store) => {
    let Container = document.createElement('div');
    Container.classList.add('containerTable');

    //Блок для переключения страниц таблицы
    let divPages = Div_pages_table(store);
    Container.appendChild(divPages);

    //Создается таблица и все ее элементы с событиями
    let table = Table(store,['Имя','Фамилия','Цвет глаз','Описание']);
    Container.appendChild(table);

    //Блок для сокрытия и отображения столбцов
    let divShowedCol = Div_showed_columns();
    Container.appendChild(divShowedCol);

    return Container;
}

export default Container_table;