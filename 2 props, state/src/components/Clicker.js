import React from "react";

export class Clicker extends React.Component {
    constructor(props) {
        super(props);
        this.state = { count: 0 };
        this.click = this.func.bind(this);
    }
    func() {
        this.setState({ count: this.state.count + 1 });
    }
    render() {
        if (this.state.count % 10 == 0 && this.state.count != 0) {
            alert("🎉");
        }
        return <div style={{ display: "flex", flexDirection: "row", alignItems: "center", gap: "8px" }}>
            <button onClick={this.click}>➕ 1️⃣</button>
            <p>Количество нажатий: {this.state.count} 🥶</p>
            <button onClick={() => { if (this.state.count > 0) this.setState({ count: this.state.count - 1 }) }}>➖ 1️⃣</button>
            <button onClick={() => this.setState({ count: 0 })}>🔄</button>
        </div>
    }
}