import {
    sortByAboutReducerAC,
    sortByEyesColorReducerAC,
    sortByFirstNameReducerAC,
    sortByLastNameReducerAC
} from "../../../../../store/sortTableReducer.js";
import {ASCENDING, DESCENDING} from "../../../../../consts.js";

//Сортировка может быть по возрастанию(ASCENDING) и по убыванию(DESCENDING),
// по умолчанию изначально - по возрастанию, при
// нажатии тип сортировки меняется на противоположный
const sortTable = (e,store) => {
    let table = document.querySelector('.table');
    let activeRow = table.querySelector('.allocated');
    //Если была выделена строка, снимает выделение и удаляет блок изменений
    if(activeRow){
        activeRow.classList.remove('allocated');
        let divChanges = document.querySelector('.changes_div');
        divChanges.remove();
    }

    if(e.target.innerHTML === 'Sort ascending'){
        e.target.innerHTML = 'Sort descending';
        if(e.target.classList.contains('sortByFirstName')){
            store.dispatch(sortByFirstNameReducerAC(ASCENDING));
        }
        if(e.target.classList.contains('sortByLastName')){
            store.dispatch(sortByLastNameReducerAC(ASCENDING));
        }
        if(e.target.classList.contains('sortByEyeColor')){
            store.dispatch(sortByEyesColorReducerAC(ASCENDING));
        }
        if(e.target.classList.contains('sortByAbout')){
            store.dispatch(sortByAboutReducerAC(ASCENDING));
        }
    }else if(e.target.innerHTML === 'Sort descending'){
        e.target.innerHTML = 'Sort ascending';
        if(e.target.classList.contains('sortByFirstName')){
            store.dispatch(sortByFirstNameReducerAC(DESCENDING));
        }
        if(e.target.classList.contains('sortByLastName')){
            store.dispatch(sortByLastNameReducerAC(DESCENDING));
        }
        if(e.target.classList.contains('sortByEyeColor')){
            store.dispatch(sortByEyesColorReducerAC(DESCENDING));
        }
        if(e.target.classList.contains('sortByAbout')){
            store.dispatch(sortByAboutReducerAC(DESCENDING));
        }
    }
    store._callSubscriber(this);
}

export default sortTable;