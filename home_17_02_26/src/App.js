import './App.css';
import UserTable from './components/UserTable/UserTable';

let users = [
  { id: 1, name: "Олег", age: 30, city: "Киев" },
  { id: 3, name: "Саша", age: 18, city: "Днепр" },
  { id: 2, name: "Кирилл", age: 26, city: "Одесса" },
  { id: 3, name: "Саша", age: 24, city: "Днепр" },

]

function App() {
  return (
    <div className="App">
      <UserTable list={users} AgeFunc={(age)=>{return(String(age)+" лет")}}/>
    </div>
  );
}

export default App;
