function Item(props) 
{
    return (
      <li>
        {props.name} {props.isPacked ? '✔' : '❌'}
      </li>
    );
  }
  
  export function PackingList() {
    return (
      <section>
        <h1>Sally Ride's Packing List</h1>
        <ul>
          <Item isPacked={true}  name="Space suit" />
          <Item isPacked={true}  name="Helmet with a golden leaf" />
          <Item isPacked={false} name="Photo of Tam" />
          <Item isPacked={true} name="Photo of Tam" />
        </ul>
      </section>
    );
  }
  