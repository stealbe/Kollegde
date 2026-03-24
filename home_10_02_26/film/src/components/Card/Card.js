import "./Card.css";

export function Card(props) {
  return (
    <div className="Card">
      <img src={props.img} alt="preview" />
      <h2>{props.name}</h2>
      <p className="description">{props.description}</p>
      <div className="footer">
        <p>{props.poducer}</p>
        <p>{props.year}</p>
        <p>{props.studio}</p>
        <p>{props.country}</p>
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
          poducer={item.poducer}
          year={item.year}
          studio={item.studio}
          country={item.country}
        />
      ))}
    </div>
  );
}
