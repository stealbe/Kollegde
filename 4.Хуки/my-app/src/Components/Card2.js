import React from 'react';
import './Card2.css'

export function Quote()
{  
   const[state, setState] = React.useState('hide'); 

   function func()
    {
        let value =(state=='hide'?'show':'hide');   
        setState (value);
    }
    return <div>
        <button onClick={func}>Цитата</button>
        <div>
            <p className={state}>
            "Телевизор отупляет и убивает много времени. Выключите его, и вы сохраните несколько клеток вашего мозга. Однако будьте осторожны — отупеть можно и за компьютером Apple".  <br></br>
            "Будь честен с самим собой, и с людьми, всегда делай все вовремя, никогда не сдавайся, иди к своим целям, даже если все плохо".
            <br/>
            </p>
        </div>

        </div>
    }

