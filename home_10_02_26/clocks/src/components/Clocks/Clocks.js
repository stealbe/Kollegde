import "./Clocks.css";

export function Clocks(props) {
  return (
    <div className="Clocks">
      <span>{props.hour}</span>
      <span>:</span>
      <span>{props.minute}</span>
      <span>:</span>
      <span>{props.second}</span>
      <span>:</span>
      <span>{props.millisecond}</span>
    </div>
  );
}
export function MyClock() {
    let now = new Date();
  return (
    <div id="conteiner">
      <Clocks
        hour={now.getHours()}
        minute={now.getMinutes()}
        second={now.getSeconds()}
        millisecond={now.getMilliseconds()}
      />
    </div>
  );
}
