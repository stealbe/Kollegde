import "./Card.css";

export function Card(props) {
  return (
    <div className="Card">
      <img src={props.img} alt="preview" />
      <p>{props.name}</p>
      <div className="footer">
        <p>{props.type}</p>
        <p>{props.year}</p>
        <p>{props.breed}</p>
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
          type={item.type}
          year={item.year}
          breed={item.breed}
        />
      ))}
    </div>
  );
}
