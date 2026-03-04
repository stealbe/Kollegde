import React from 'react';

export class State1 extends React.Component
 {
    constructor(props)
     {
        super(props);

        this.state = {
            welcome: "Добро пожаловать на сайт!"
        };        
     }  
    render() {
       
       return <h1>{this.state.welcome} {this.props.value}</h1>;
    }
}

export class ClickButton extends React.Component
{             
    constructor(props)
    {
        super(props);   

        this.state = {class: "off", label: "Нажми", background:"ThemeLight"};          
        this.pressproperty = this.press.bind(this);   // связывание метода press с объектом
    }
    press()
    {
        let className = (this.state.class === "off")?"on":"off";
        let text = (this.state.label==="Нажми")?"OK":"Нажми";

        let bg = (this.state.background==="ThemeLight")?"ThemeDark":"ThemeLight";                
        this.setState({class: className, label:text, background:bg});
    }

    render() {
        return <div id="buttonDiv" className={this.state.background}>
        <button onClick = {this.pressproperty} className={this.state.class}> {this.state.label}
         
        </button>
        </div>
    }
}
// 3 == '3'  // true
// 3 === '3' // false ТИПЫ РАЗНЫЕ   