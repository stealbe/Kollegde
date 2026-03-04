// import React from 'react';
import './App.css';
// import { List } from './components/List';
// import { PrintButton, ShowUser } from './components/events';
// import { State1, ClickButton } from './components/state';
// import { PackingList } from './components/list2';
import { Quote } from './components/Task1';
// import { Club } from './components/Clubs';
import { Color } from './components/Color';
import { Clicker } from './components/Clicker';

const myclubs = [
  {
    name: "Dinamo", city: "Kyiv", year: 1990,
    commands: [
      { Name: "Petrov Petr", Age: 26 },
      { Name: "Ivanov Ivan", Age: 36 },
      { Name: "Sidorov Oleg", Age: 46 },
      { Name: "Kotov Nikolay", Age: 36 }]
  },

  {
    name: "Manchester", city: "Madrid", year: 1990,
    commands: [
      { Name: "Vovchenko Vladimir", Age: 26 },
      { Name: "Samoilov Oleg", Age: 26 },
      { Name: "Sidorov Oleg", Age: 36 },
      { Name: "Kotov Nikolay", Age: 36 }]
  }
];

const arr = ["Hello", "World", "Пhивет мир"]

function App() {
  return (
    <div className="App">
      <header className="App-header">

        {/* <ClickButton></ClickButton> */}

        {/* <Club myclub = {myclubs}></Club> */}
        <Color text="Многие заблуждаются, думая, что Stateless компоненты могут быть только в виде function. Единственное, что отличает Stateless от Stateful компонентов  это отсутствие внутреннего состояния "> </Color>

        <Quote author='Стив Джобс'></Quote>

        <Clicker />

      </header>
    </div>
  );
}

export default App;
