import "./App.css";
import { Group } from "./components/Person/Person";
import { Header, Footer } from "./components/Main/Main";

function App() {
  return (
    <div className="App" id="main">
      <Header />
      <Group />
      <Footer />
    </div>
  );
}

export default App;
