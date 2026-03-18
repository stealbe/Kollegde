import "./App.css";
import list from "./details.json";

import SideBar from "./components/sidebar";
import Header from "./components/header";
import Footer from "./components/footer";
import CategoryPage from "./components/page";
import { useEffect, useState } from "react";

function App() {
  const [favorite, setFavorite] = useState(Array());

  function addToFavorite(name) {
    setFavorite([...favorite, name]);
  }

  return (
    <div className="App">
      <Header />
      <section>
        <p>В избранном {favorite.length}</p>
        <button onClick={
          () => { setFavorite(list.data.map(item => item.id)); }
        }>Выбрать все</button>
        <button onClick={() => { setFavorite([]) }}>Убрать все из избранного</button>
      </section>
      <main className="content">
        <SideBar>
          <nav className="catalog-nav">
            <ul className="catalog-list">
              <li className="catalog-item">
                <a href="#">Ноутбуки и компьютеры</a>
              </li>
              <li className="catalog-item">
                <a href="#">Смартфоны, ТВ и электроника</a>
              </li>
              <li className="catalog-item">
                <a href="#">Бытовая техника</a>
              </li>
              <li className="catalog-item">
                <a href="#">Товары для дома</a>
              </li>
              <li className="catalog-item">
                <a href="#">Инструменты и автотовары</a>
              </li>
              <li className="catalog-item">
                <a href="#">Детские товары</a>
              </li>
              <li className="catalog-item">
                <a href="#">Спорт и увлечения</a>
              </li>
              <li className="catalog-item">
                <a href="#">Одежда и обувь</a>
              </li>
            </ul>
          </nav>
        </SideBar>
        <CategoryPage list={list} addToFavorite={addToFavorite} removeFavorite={(id) => setFavorite(favorite.filter(item => item != id))} favoriteList={favorite} />
      </main>
      <Footer />
    </div>
  );
}

export default App;
