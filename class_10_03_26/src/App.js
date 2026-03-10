import React from 'react';
import './App.css';
import Nav from './components/Nav/Nav';
import Header from './components/Header/Header';
import Card from './components/Card/Card';
import Footer from './components/Footer/Footer';
import SubCard from './components/SubCard/SubCard';

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

const subscriptionPlans = [
  {
    title: "Basic",
    price: "$2.99",
    features: ["Sample Text Here"],
    unavailable: ["Other Text Title", "Text Space Goes Here", "Description Space"],
    background: "#017e59"
  },
  {
    title: "Standard",
    price: "$5.99",
    features: ["Sample Text Here", "Other Text Title", "Text Space Goes Here"],
    unavailable: ["Description Space"],
    background: "#0068da"
  },
  {
    title: "Premium",
    price: "$0.99",
    features: ["Sample Text Here", "Other Text Title", "Text Space Goes Here", "Description Space"],
    unavailable: [],
    background: "#01356e"
  }
];

function App() {
  return (
    <div className="App">
      <Header version="v1.0" subtitle="Макет страницы на React (JSX)" root={document.querySelector(':root')} />
      <Nav items={navItems} />
      <section className="subscriptions">
        {subscriptionPlans.map((plan, index) => (
          <SubCard key={index} title={plan.title} price={plan.price} features={plan.features} unavailable={plan.unavailable} background={plan.background} />
        ))}
      </section>
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
            <p className='longText'>lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.lore ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</p>
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