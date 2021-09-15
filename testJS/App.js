import Container_table from "./src/Components/ContainerTable/Container_table.js";

const App = (store) => {
    let ContainerAll = document.createElement('div');
    ContainerAll.classList.add('ContainerAll');

    //Создается контейнер для таблицы и связанных с ней элементов
    let ContainerTable = Container_table(store);
    ContainerAll.appendChild(ContainerTable);
    return ContainerAll;
}

export default App;