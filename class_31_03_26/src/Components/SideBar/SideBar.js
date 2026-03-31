import { Link } from "react-router-dom";

export default function SideBar() {
    return (
        <aside className="sidebar">
            <nav className="catalog-nav">
                <ul className="catalog-list">
                    <li className="catalog-item">
                        <Link to="#">Ноутбуки и компьютеры</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Смартфоны, ТВ и электроника</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Бытовая техника</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Товары для дома</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Инструменты и автотовары</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Детские товары</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Спорт и увлечения</Link>
                    </li>
                    <li className="catalog-item">
                        <Link to="#">Одежда и обувь</Link>
                    </li>
                </ul>
            </nav>
        </aside>
    );
}