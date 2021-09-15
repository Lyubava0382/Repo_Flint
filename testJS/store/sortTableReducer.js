import {ASCENDING, DESCENDING} from "../consts.js";

const SORT_BY_FIRST_NAME = 'SORT_BY_FIRST_NAME';
const SORT_BY_LAST_NAME = 'SORT_BY_LAST_NAME';
const SORT_BY_EYES_COLOR = 'SORT_BY_EYES_COLOR';
const SORT_BY_ABOUT = 'SORT_BY_ABOUT';


const sortTableReducer = (action,state) => {
    switch (action.type) {
        case (SORT_BY_FIRST_NAME):
            if(action.direction === ASCENDING){
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.name.firstName > b.name.firstName){
                            return 1;
                        }
                        if(a.name.firstName < b.name.firstName){
                            return -1;
                        }
                        return 0;
                    })
                }
            }else {
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.name.firstName > b.name.firstName){
                            return -1;
                        }
                        if(a.name.firstName < b.name.firstName){
                            return 1;
                        }
                        return 0;
                    })
                }
            }
        case (SORT_BY_LAST_NAME):
            if(action.direction === ASCENDING){
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.name.lastName > b.name.lastName){
                            return 1;
                        }
                        if(a.name.lastName < b.name.lastName){
                            return -1;
                        }
                        return 0;
                    })
                }
            }else{
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.name.lastName > b.name.lastName){
                            return -1;
                        }
                        if(a.name.lastName < b.name.lastName){
                            return 1;
                        }
                        return 0;
                    })
                }
            }
        case (SORT_BY_EYES_COLOR):
            if(action.direction === ASCENDING){
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.eyeColor > b.eyeColor){
                            return 1;
                        }
                        if(a.eyeColor < b.eyeColor){
                            return -1;
                        }
                        return 0;
                    })
                }
            }else{
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.eyeColor > b.eyeColor){
                            return -1;
                        }
                        if(a.eyeColor < b.eyeColor){
                            return 1;
                        }
                        return 0;
                    })
                }
            }
        case(SORT_BY_ABOUT):
            if(action.direction === ASCENDING){
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.about > b.about){
                            return 1;
                        }
                        if(a.about < b.about){
                            return -1;
                        }
                        return 0;
                    })
                }
            }else{
                return {
                    ...state,
                    usersOnPage: Array.from(state.usersOnPage).sort(function (a,b){
                        if(a.about > b.about){
                            return -1;
                        }
                        if(a.about < b.about){
                            return 1;
                        }
                        return 0;
                    })
                }
            }
    }
    return {...state};
}

export const sortByFirstNameReducerAC = (drc) => ({type: SORT_BY_FIRST_NAME, direction: drc})
export const sortByLastNameReducerAC = (drc) => ({type: SORT_BY_LAST_NAME, direction: drc})
export const sortByEyesColorReducerAC = (drc) => ({type: SORT_BY_EYES_COLOR, direction: drc})
export const sortByAboutReducerAC = (drc) => ({type: SORT_BY_ABOUT, direction: drc})

export default sortTableReducer;