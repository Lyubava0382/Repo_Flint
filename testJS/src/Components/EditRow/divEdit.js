import {
    editReducerAboutAC,
    editReducerEyesColorAC,
    editReducerFirstNameAC,
    editReducerLastNameAC
} from "../../../store/editReducer.js";



const editFirstName = (tr,dispatch) => (e) => {
    dispatch(editReducerFirstNameAC(tr.id,e));
}
const editLastName = (tr,dispatch) => (e) => {
    dispatch(editReducerLastNameAC(tr.id,e));
}
const editEyesColor = (tr,dispatch) => (e) => {
    dispatch(editReducerEyesColorAC(tr.id,e));
}
const editAbout = (tr,dispatch) => (e) => {
    dispatch(editReducerAboutAC(tr.id,e));
}


//Создает блок для редактирования данных,
// начальные значения берутся из значений ячеек
export const createDivEdit = (tr, user, dispatch) => {
    let divChanges = document.createElement('div');
    let allFields = document.createElement('div');
    allFields.classList.add('allFields');
    divChanges.classList.add('changes_div');
    for(let i = 0; i < 4;i++){
        let divProp = document.createElement('div');
        let prop = document.createElement('span');
        divProp.appendChild(prop);
        let changeInput = document.createElement('input');
        divProp.appendChild(changeInput);
        allFields.appendChild(divProp);
        switch (i){
            case 0:
                prop.textContent = 'Имя';
                changeInput.classList.add('firstName');
                changeInput.value = tr.querySelector('.firstName').innerHTML;
                changeInput.addEventListener('input',editFirstName(tr,dispatch));
                break;
            case 1:
                prop.textContent = 'Фамилия';
                changeInput.classList.add('lastName');
                changeInput.value = tr.querySelector('.lastName').innerHTML;
                changeInput.addEventListener('input',editLastName(tr,dispatch));
                break;
            case 2:
                prop.textContent = 'Цвет глаз';
                changeInput.classList.add('eyesColor');
                changeInput.value = tr.querySelector('.eyeColor').innerHTML;
                changeInput.addEventListener('input',editEyesColor(tr,dispatch));
                break;
            case 3:
                prop.textContent = 'Описание';
                changeInput.classList.add('about');
                changeInput.value = tr.querySelector('.about').innerHTML;
                changeInput.addEventListener('input',editAbout(tr,dispatch));
                break;
        }
    }
    divChanges.appendChild(allFields);
    return divChanges;
}

//Создает и удаляет блок с редактированием который вставляется в корневой контейнер ContainerAll
const showDivEdit = (tr,user,dispatch) => {
    let divChanges = document.querySelector('.changes_div');
    if(divChanges && !tr.classList.contains('allocated')){
        divChanges.remove();
    }else if(divChanges && tr.classList.contains('allocated')){
        divChanges.remove();
        document.querySelector('.ContainerAll').appendChild(createDivEdit(tr,user,dispatch));
    }else if(!divChanges){
        document.querySelector('.ContainerAll').appendChild(createDivEdit(tr,user,dispatch));
    }
}

export default showDivEdit;