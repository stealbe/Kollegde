export default function Library(props) {
    return (
        <div className="library" style={{ display: "flex", flexDirection: "row", width: "100%", justifyContent: "space-between", flexWrap: "wrap" }}>
            {
                props.list.length === 0 ? <p>Нет изображений</p> :
                    props.list.map(elem => (
                        <div className={"card_" + elem.id} style={{ width: "100%", maxWidth: "350px", display: "flex", flexDirection: "column", minWidth: "200px" }}>
                            <img src={elem.url} alt={elem.title} style={{ width: "100%" }} />
                            <h2>{elem.title}</h2>
                            <p>{elem.author}</p>
                        </div>
                    ))
            }
        </div>
    )
}