import {choicePageReducerAC} from "../../../../store/choicePageReducer.js";
import {COUNT_ROWS_TABLE} from "../../../../consts.js";



const choicePage = (store,e) => {

    //При клике на кнопку смены страницы, удаляется выделение строк и блок изменений данных.
    let table = document.querySelector('.table');
    let activeRow = table.querySelector('.allocated');
    if(activeRow){
        activeRow.classList.remove('allocated');
        let divChanges = document.querySelector('.changes_div');
        divChanges.remove();
    }

    //Рассчитывается необходимый диапазон пользователей, которых надо отобразить
    let pages = document.querySelector('.divPages').querySelectorAll(".page");
    let indexPage;
    if(e.target.classList.contains('page')){
        for(let i = 0; i < pages.length;i++){
            if(pages[i].classList.contains('active')){
                pages[i].classList.remove('active');
                break;
            }
        }
        e.target.classList.add('active');
        indexPage = Number(e.target.id)-1;
    }else if(e.target.classList.contains('arrow')){
        for(let i = 0; i < pages.length;i++){
            if(pages[i].classList.contains('active')){
                if(i === 0 && e.target.classList.contains('refBackPage')){
                    indexPage = Number(pages[i].id)-1;
                    break;
                }else if (i === pages.length-1 && e.target.classList.contains('refNextPage')){
                    indexPage = Number(pages[i].id)-1;
                    break;
                }
                if(e.target.classList.contains('refBackPage')){
                    pages[i].classList.remove('active');
                    pages[i-1].classList.add('active');
                    indexPage = Number(pages[i-1].id)-1;
                }else if(e.target.classList.contains('refNextPage')){
                    pages[i].classList.remove('active');
                    pages[i+1].classList.add('active');
                    indexPage = Number(pages[i+1].id)-1;
                }
                break;
            }
        }
    }

    //Вызывается метод store , использующий вспомогательную функцию reducer для изменения данных state
    store.dispatch(choicePageReducerAC([indexPage*COUNT_ROWS_TABLE,(indexPage+1)*COUNT_ROWS_TABLE]));

    //Таблица перерисовывается в соответствии с новыми данными
    store._callSubscriber(this);
}

export default choicePage;