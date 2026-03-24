import './Myform.css';
import React from 'react';

export function Myform() 
{ 
  const [user,Setuser] = React.useState ( {login:"", pass:""} ) 

  const [validlog,Setstyle] = React.useState("nonvalid")
  
  const [validpass,Setstylepass] = React.useState("nonvalid")
  function handlesubmit()
  {
    alert(user.login + " " + user.pass);

  }
  function onChangeLogin(event)
  { 
    Setuser({login:event.target.value,pass:user.pass})
    if(user.login.length>=3)
    {
      Setstyle("valid")
    }
    else{
      Setstyle("nonvalid")
    } 
  }
  function onChangePassword(event)
  {
    if(user.pass.length>=3)
    {
      Setstylepass("valid")
    }
    else{
      Setstylepass("nonvalid")
    }
 
    Setuser({login:user.login, pass:event.target.value})
    
  }

  return <div className="Myform">
    <form onSubmit = {handlesubmit}>
    <div>
      <span>Login</span>
      <input type="text" className={validlog} onChange={onChangeLogin}></input>
    </div>

    <div>
      <span>Password</span>
      <input type="text" className={validpass} onChange={onChangePassword}></input>
    </div>

    <input type="submit"  value="Ok"  ></input>
  </form>
  </div>
}
export default Myform;
