import React from "react";

export function UserData2(props) {

const [user, setUser] = React.useState({name:"Oleg", age: 36});
     
  React.useEffect(() => {   

  setUser(props.user)
  console.log("UseEffect");
    
  },[1]);


    function handleNameChange(event) { 
      setUser({...user, name: event.target.value});   
   }
     
    function handleAgeChange(event) {   
      setUser({...user, age: event.target.value});   
   }
    return (
      <div>
        <h3>Имя: {user.name}</h3>
        <h3>Возраст: {user.age}</h3>
         
        <div>
          <p>Имя: <input type="text" value={user.name} onChange={handleNameChange} /></p>
          <p>Возраст: <input type="number" min="0" max="110" value={user.age} onChange={handleAgeChange} /></p>
        </div>
      </div>
    );
}
  
          