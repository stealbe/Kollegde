import React from "react";

function Card(props)
{
    return <div id='card'>
        <h3>{props.name}</h3>
        <h2>{props.price}</h2>
        <ul>
            <li>Lorem ipsum 1</li>
            <li>Lorem ipsum 2</li>
            <li>Lorem ipsum 3</li>
            <li>Lorem ipsum 4</li>
            <li>Lorem ipsum 5</li>
            <li>Lorem ipsum 6</li>
        </ul>
        <button>Sign up</button>

    </div>
      
}

export function CardList()
{
    return <div id='cardList'>
        <Card name="Tom" price="100$"/>
        <Card name="Bob" price="200$"/>
        <Card name="Sam" price="300$"/>
    </div>
}