import Card from "../../Components/Card/Card";
import list from "../../data/products.json";
import { useState } from "react";

export default function Catalog(props) {
    const [favorite, setFavorite] = useState([]);

    function addToFavorite(id) { setFavorite([...favorite, id]); }
    function removeFavorite(id) { setFavorite(favorite.filter(item => item !== id)); }
    return (
        <section className="catalog" style={{ display: "flex", flexDirection: "row", flexWrap: "wrap", gap: "1px" }}>
            {list.map(item => (
                <Card
                    key={item.id}
                    id={item.id}
                    href={item.href}
                    previewImg={item.images?.main}
                    name={item.title}
                    price={item.price}
                    addToFavorite={addToFavorite}
                    removeFavorite={removeFavorite}
                    favoriteList={favorite}
                />
            ))}
        </section>
    );
}