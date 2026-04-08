import {React,useState} from "react";

export function EssayForm(props)
{
   const [state,setState] = useState('Будьте любезны, напишите сочинение о вашем любимом DOM-элементе.');       
   
   function  handleChange(event)
    {
      setState(event.target.value);
    }
    
   function  handleSubmit(event) 
   {
      if(state.length<5)
      {
        alert('Сочинение должно быть не менее 5 символов.');
        event.preventDefault();
      }
      else
      {      
        alert('Сочинение отправлено: ' + state);
     }
    }  
      return <form onSubmit={handleSubmit}>
          <label>
            Сочинение:
            <textarea value={state} onChange={handleChange} />
          </label>
          <input type="submit" value="Отправить" />
        </form>   
  }

  /*В React <textarea> использует атрибут value!!
  инициализация  this.state.value в конструкторе, так что в текстовой области изначально есть текст.
  
  */