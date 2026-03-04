import React from "react";
import './Color.css'

export class Color extends React.Component
{
    constructor(props)
    {
        super(props);
        this.state = {buttonText: "Light", class:"button"}
       
        this.click = this.Func.bind(this);
    }
    Func()
    {
        if(this.state.buttonText==="Light")
        {
            this.setState({buttonText: "Dark", class: this.state.class})
        }
        else{
             this.setState({buttonText: "Light", class: this.state.class})

        }
    }
    render()
    {
        return <div>
            <button onClick={this.click} className={this.state. buttonText}>{this.state.buttonText}</button>
            
            <div id="text" className={this.state.buttonText}>          
            <p>{this.props.text}</p>

        </div>
        </div>
    }
}