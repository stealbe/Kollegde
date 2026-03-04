import React from 'react';

// export default function Header({ version, subtitle }) {
//     return (
//         <header>
//             <h1 style={{ margin: 0 }}>MyApp <span className="badge">{version}</span></h1>
//             <div className="muted">{subtitle}</div>
//         </header>
//     )
// };

export default class Header extends React.Component {
    constructor(props) {
        super(props);
        this.state = { theme: "light" };
    }
    render() {
        return (
            <header>
                <div>
                    <h1 style={{ margin: 0 }}>MyApp <span className="badge">{this.props.version}</span></h1>
                    <div className="muted">{this.props.subtitle}</div>
                </div>
                <button className='ThemeSwich' onClick={() => { this.setState({ theme: this.state.theme === "light" ? "dark" : "light" }); this.props.root.style.setProperty("--bg", this.state.theme === "light" ? "#333" : "#fff"); this.props.root.style.setProperty("--text", this.state.theme === "light" ? "#fff" : "#333"); this.props.root.style.setProperty("--line", this.state.theme === "light" ? "#555" : "#e6e8ef"); this.props.root.style.setProperty("--card", this.state.theme === "light" ? "#444" : "#fff"); this.props.root.style.setProperty("--second-text", this.state.theme === "light" ? "#bbb" : "#596072"); }}>
                    {this.state.theme === "light" ? <img src="/light.svg" alt="light theme" /> : <img src="/dark.svg" alt="Dark theme" />}
                </button>
            </header >
        )
    }
}