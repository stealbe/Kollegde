import "./SubCard.css";

export default function SubCard({ title, price, features, unavailable, background }) {
    return (
        <div className="SubCard">
            <div className="name" style={{ background: background }}>
                <h2>{title}</h2>
                <div className="price">{price}</div>
            </div>
            <ul>
                {features.map((feature, index) => <li key={index} className="features"><img src="/accept_svg.svg" alt="allowed icon" /> {feature}</li>)}
                {unavailable.map((feature, index) => <li key={index} className="unavailable"><img src="/decline_svg.svg" alt="not allowed icon" /> {feature}</li>)}
            </ul>
            <button className="Subscribe" style={{ background: background }}>SELECT PACKAGE</button>
        </div>
    )
}