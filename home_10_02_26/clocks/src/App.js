import "./App.css";
import { MyClock } from "./components/Clocks/Clocks";
import { Header, Footer } from "./components/Main/Main";

function App() {
  return (
    <div className="App" id="main">
      <Header />
      <MyClock />
      <Footer />
    </div>
  );
}

export default App;
