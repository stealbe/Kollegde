import './Book.css'
import React from 'react'
// дз 1
export function Book(props) {
    return <div className='main'>
        <div id='radio'>
            <span>Dark</span><input type='radio' name='radio'></input>
            <span>Ligth</span><input type='radio' name='radio'></input>
           
        </div>
         <p>{props.text}</p>
    </div>
}
// дз 2
 export class Book2 extends React.Component
 { 
    constructor(props)
    {
        super(props)
    }
   render()
    {
    return <div className='main'>
        <div id='radio'>
            <span>Dark</span><input type='radio' name='radio'></input>
            <span>Ligth</span><input type='radio' name='radio'></input>           
        </div>
        <div> <p>Шевченко Т.Г.</p> </div>
       
    </div>
    }
}