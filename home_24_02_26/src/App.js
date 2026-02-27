import './App.css';
import Nav from './components/Nav/Nav';
import Header from './components/Header/Header';
import Card from './components/Card/Card';
import Footer from './components/Footer/Footer';

const navItems = [
  { label: "Домой", href: "#" },
  { label: "Компоненты", href: "#components" },
  { label: "Контакты", href: "#contacts" }
];

const sidebarLinks = [
  { label: "Документация", href: "#docs" },
  { label: "Быстрый старт", href: "#start" },
  { label: "О проекте", href: "#about" }
];

function App() {
  return (
    <div className="App">
      <Header version="v1.0" subtitle="Макет страницы на React (JSX)" />
      <Nav items={navItems} />
      <div className="layout">
        <Card className="main" title="Главная область">
          <>
            <p>Макет страницы на React + JSX (без состояния).</p>

            <div className="cards">
              <Card title="Карточка 1">Простой текст в карточке.</Card>
              <Card title="Карточка 2">Компонент можно переиспользовать.</Card>
              <Card title="Карточка 3">JSX упрощает структуру.</Card>
              <Card title="Карточка 4">Всё без useState.</Card>
            </div>
          </>
        </Card>
        <Card title="Боковая панель" className="sidebar">
          <ul>
            {sidebarLinks.map((s, i) => (
              <li key={i}>
                <a href={s.href}>{s.label}</a>
              </li>
            ))}
          </ul>
        </Card>
      </div>
      <Footer />
    </div>
  );
}

export default App;
