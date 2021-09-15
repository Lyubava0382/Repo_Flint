import {COUNT_ROWS_TABLE} from "../../../../consts.js";


//Возвращает список ячеек в столбце
const getColumn = (head) => {
    let table = document.querySelector('.table');
    let col = table.querySelectorAll(head);
    return col;
}

//Добавляет и удаляет классы showed и hide для показа/скрытия колонок.
// Ячейки с классом hide имеют свойство display: none и не отображаются.
const showhideCol = (className) => {
    return function () {
        let col = getColumn(className);
        if (col[0].classList.contains('showed')) {
            for (let i = 0; i < COUNT_ROWS_TABLE + 1; i++) {
                col[i].classList.remove('showed');
                col[i].classList.add('hide');
            }
        } else {
            for (let i = 0; i < COUNT_ROWS_TABLE +1; i++) {
                col[i].classList.remove('hide');
                col[i].classList.add('showed');
            }
        }

    }
}

//Создает UI - блок для выбора, какие столбцы скрыть.
const Div_showed_columns = () => {
    let div = document.createElement('div');
    div.classList.add('showed_columns');
    let header = document.createElement('div');
    header.classList.add('header');
    header.innerHTML = 'Столбцы таблицы';
    let list = document.createElement('ul');
    let nameCol = ['Имя', 'Фамилия', 'Цвет глаз','Описание'];
    let classListCol = ['.firstName','.lastName','.eyeColor','.about'];
    for(let i = 0; i < 4; i++){
        let item = document.createElement('li');
        let checkbox = document.createElement('input');
        checkbox.addEventListener('click',showhideCol(classListCol[i]));
        checkbox.type = 'checkbox';
        checkbox.checked = true;
        let span = document.createElement('span');
        span.innerHTML = nameCol[i];
        item.appendChild(checkbox);
        item.appendChild(span);
        list.appendChild(item);
    }
    div.appendChild(header);
    div.appendChild(list);
    return div;
}

export default Div_showed_columns;