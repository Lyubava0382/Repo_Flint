import choicePage from "./choicePage.js";
import {COUNT_ROWS_TABLE} from "../../../../consts.js";

const callChoicePage = (store) => (e) => {
    choicePage(store,e);
}

//Создается блок со страницами. На каждую страницу
// наброшено ожидание клика, при клике вызывается функция choicePage

const Div_pages_table = (store) => {
    //Создается блок для страниц таблицы
    let divPages = document.createElement('div');
    divPages.classList.add('divPages');

    //В зависимости от количества данных создается отдельные страницы
    let countPages = Math.ceil(store.getState().users.length/COUNT_ROWS_TABLE);
    let backPage = document.createElement('button');
    backPage.textContent = '<<';
    backPage.classList.add('refBackPage');
    backPage.classList.add('arrow');
    backPage.addEventListener('click',callChoicePage(store));
    divPages.appendChild(backPage);
    for(let i = 1; i< countPages+1;i++){
        let page = document.createElement('span');
        page.classList.add('page');
        if(i === 1){
            page.classList.add('active');
        }
        page.id = i;
        page.textContent = i;
        page.addEventListener('click',callChoicePage(store));
        divPages.appendChild(page);
    }
    let nextPage = document.createElement('button');
    nextPage.textContent = '>>';
    nextPage.classList.add('refNextPage');
    nextPage.classList.add('arrow');
    nextPage.addEventListener('click',callChoicePage(store));
    divPages.appendChild(nextPage);

    return divPages;
}

export default Div_pages_table;