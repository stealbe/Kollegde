import "./Card.css";

export function Card(props) {
  return (
    <div className="card">
      <img src={props.img} alt="preview" />
      <h2>{props.name}</h2>
      <p className="description">{props.description}</p>
      <p>{props.desition}</p>
      <div className="footer">
        <a href={"tel:" + props.phone}>{props.phone}</a>
        <p>{props.country}</p>
        <a href={"mail:" + props.mail}>{props.mail}</a>
        <p>{props.city}</p>
      </div>
    </div>
  );
}

export function Group(props) {
  return (
    <div id="conteiner">
      {props.list.map((item) => (
        <Card 
        img={item.img}
        name={item.name}
        description={item.description}
        desition={item.desition}
        phone={item.phone}
        country={item.country}
        mail={item.mail}
        city={item.city}
        />
      ))}
    </div>
  );
}
