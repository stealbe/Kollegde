import React from "react";

export function NameForm (props)
{
   const[value, setValue] = React.useState('Oleg');   
  
   function handleChange(event) {
      setValue(event.target.value);
    }  
    function handleSubmit(event) {
      if (value.trim() === '')
        {
        alert('Please enter a name.');
      } 
      else {
       
      alert('A name was submitted: ' + value);
   
      }
      event.preventDefault();
    }
      return (        
        <form onSubmit={handleSubmit}>
          <p>Value: {value}</p>
          <label>
            Name:
            <input type="text" value={value} onChange={handleChange} />
          </label>
          <input type="submit" value="Submit" />
        </form>
      );
    }
  
  