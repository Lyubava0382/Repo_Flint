const EDIT_FIRSTNAME = 'EDIT_FIRSTNAME';
const EDIT_LASTNAME = 'EDIT_LASTNAME';
const EDIT_EYES_COLOR = 'EDIT_EYES_COLOR';
const EDIT_ABOUT = 'EDIT_ABOUT';

const editReducer = (action,state) => {
    let cell;
    switch (action.type){
        case (EDIT_FIRSTNAME):
            cell = document.getElementById(action.row).querySelector('.firstName');
            cell.innerHTML = action.target.target.value;
            return {
                ...state,
                users: state.users.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr,name: {...usr.name,
                                firstName: action.target.target.value}}
                    }
                    return {...usr};
                }),
                usersOnPage: state.usersOnPage.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr,name: {...usr.name,
                                firstName: action.target.target.value}}
                    }
                    return {...usr};
                })
            }
        case (EDIT_LASTNAME):
            cell = document.getElementById(action.row).querySelector('.lastName');
            cell.innerHTML = action.target.target.value;
            return {
                ...state,
                users: state.users.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr,name: {...usr.name,
                                lastName: action.target.target.value}}
                    }
                    return {...usr};
                }),
                usersOnPage: state.usersOnPage.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr,name: {...usr.name,
                                lastName: action.target.target.value}}
                    }
                    return {...usr};
                })
            }
        case (EDIT_EYES_COLOR):
            cell = document.getElementById(action.row).querySelector('.eyeColor');
            cell.innerHTML = action.target.target.value;
            let obj = {
                ...state,
                users: state.users.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr, eyeColor: action.target.target.value}
                    }
                    return {...usr};
                }),
                usersOnPage: state.usersOnPage.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr, eyeColor: action.target.target.value}
                    }
                    return {...usr};
                })
            }
            return obj;
        case (EDIT_ABOUT):
            cell = document.getElementById(action.row).querySelector('.about');
            cell.innerHTML = action.target.target.value;
            return {
                ...state,
                users: state.users.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr, about: action.target.target.value}
                    }
                    return {...usr};
                }),
                usersOnPage: state.usersOnPage.map((usr)=>{
                    if(usr.id === action.row){
                        return {...usr, about: action.target.target.value}
                    }
                    return {...usr};
                })
            }
    }
    return {...state};
}

export const editReducerFirstNameAC = (rowId,e) => ({type: EDIT_FIRSTNAME, row: rowId, target: e});
export const editReducerLastNameAC = (rowId,e) => ({type: EDIT_LASTNAME, row: rowId, target: e});
export const editReducerEyesColorAC = (rowId,e) => ({type: EDIT_EYES_COLOR, row: rowId, target: e});
export const editReducerAboutAC = (rowId,e) => ({type: EDIT_ABOUT, row: rowId, target: e});

export default editReducer;