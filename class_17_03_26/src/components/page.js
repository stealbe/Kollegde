import Card from "./card";

export default function CategoryPage(props) {
  return (
    <section
      className="catalog"
      style={{
        display: "flex",
        flexDirection: "row",
        flexWrap: "wrap",
        gap: "1px",
      }}
    >
      {props.list.data.map((item) => (
        <Card
          key={item.id}
          id={item.id}
          href={item.href}
          previewImg={item.images?.main}
          name={item.title}
          price={item.price}
          addToFavorite={props.addToFavorite}
          removeFavorite={props.removeFavorite}
          favoriteList={props.favoriteList}
        />
      ))}
    </section>
  );
}
