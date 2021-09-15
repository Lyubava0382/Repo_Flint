const CHOICE_PAGE = 'CHOICE_PAGE';

const choicePageReducer = (action, state) => {
    switch (action.type){
        case (CHOICE_PAGE):
            let arr = [];
            for(let i = action.rows[0]; i < action.rows[1]; i++){
                arr.push({...state.users[i]});
            }
            return {
                ...state,
                usersOnPage: [...arr]
            };
    }
    return {...state};
}

export const choicePageReducerAC = (rows) => ({type: CHOICE_PAGE, rows: rows});

export default choicePageReducer;
