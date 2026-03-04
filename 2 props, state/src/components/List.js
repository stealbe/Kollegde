import React from 'react';

function ListItem(props)
{
  return <li>{props.value}</li>
}

export function List (props)
 {
  return (
    <ul>{
      props.items.map(item => <ListItem value={item}/>)
    }</ul>
  );
}
