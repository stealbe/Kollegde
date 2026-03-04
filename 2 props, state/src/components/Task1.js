import React from 'react';
import './Task1.css';
import { Buttons } from '@testing-library/user-event/dist/cjs/system/pointer/buttons.js';

export class Quote extends React.Component {
    constructor(props) {
        super(props);

        this.state = { class: 'hide', btnText: "Show" }; // !!! поле компонента
        this.click = this.func.bind(this);  // явная привязка !!!
    }

    func() {
        let value = (this.state.class === 'hide' ? 'show' : 'hide');
        this.setState({ class: value, btnText: this.state.btnText === "Show" ? "Hide" : "Show" });// сеттер для поля class

    }
    render() {
        return <div>
            <button onClick={this.click}>{this.state.btnText}</button>
            <div>
                <p className={this.state.class}>
                    "Телевизор отупляет и убивает много времени. Выключите его, и вы сохраните несколько клеток вашего мозга. Однако будьте осторожны — отупеть можно и за компьютером Apple".  <br></br>
                    "Будь честен с самим собой, и с людьми, всегда делай все вовремя, никогда не сдавайся, иди к своим целям, даже если все плохо".
                    <br />
                    <br />
                    <span>{this.props.author}</span>
                </p>
            </div>

        </div>
    }
}
