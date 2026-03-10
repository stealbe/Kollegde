import React from "react";

export function UserData() {
  
    const [user, setUser] = React.useState({name:"Tom", age: 36});
     
    function handleNameChange(event) { 
      setUser({name: event.target.value, age: user.age});   
   }
     
    function handleAgeChange(event) {   
      setUser({name: user.name, age: event.target.value});   
   }
    return (
      <div>
        <h3>Имя: {user.name}</h3>
        <h3>Возраст: {user.age}</h3>
         
        <div>
          <p>Имя: <input type="text" value = {user.name} onChange={handleNameChange} /></p>
          <p>Возраст: <input type="number" min="0" max="110" value={user.age} onChange={handleAgeChange} /></p>
        </div>
      </div>
    );
  }