import React from'react'
import './Clubs.css'

class Info extends React.Component
{
    constructor(props)
    {
        super(props);             
    }    
    render()
    {  
        return <div>
              <p>{this.props.params.name}</p>
             </div>
    }

}
class Info2 extends React.Component
{
    constructor(props)
    {
        super(props);
    }
    render()
    {
        return<div>
            <p>{this.props.params.city}</p>
        </div>
    }

}
class Comands extends React.Component
{
    constructor(props)
    {
        super(props);
    }
    render()
    {
        return <div>
        <ul>
         {
         this.props.params.map(item=> <li>{item.Name}  -  {item.Age}</li>)}
        </ul>
        </div>
    }

}

export class Club extends React.Component
{
    constructor(props)
    {
        super(props);
    } 
    render()
    {
          return <div>
          <Info params =  {this.props.myclub[0]}></Info>
          <Info2 params = {this.props.myclub[0]}></Info2>
          <Comands params = {this.props.myclub[0].commands}> </Comands>

          <Info params =  {this.props.myclub[1]}></Info>
          <Info2 params = {this.props.myclub[1]}></Info2>
          <Comands params = {this.props.myclub[1].commands}> </Comands>

          </div>
    }
}