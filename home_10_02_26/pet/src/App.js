import "./App.css";
import { Group } from "./components/Card/Card";
import { Header, Footer } from "./components/Main/Main";

function App() {
  return (
    <div className="App" id="main">
      <Header />
      <p>Your pets</p>
      <Group
        list={[
          {
            img: "https://cdn2.thecatapi.com/images/MTY3ODIyMQ.jpg",
            name: "Murka",
            type: "cat",
            year: 2015,
            breed: "Siamese",
          },
          {
            img: "https://cdn2.thecatapi.com/images/MTY3ODIyMQ.jpg",
            name: "Murka",
            type: "cat",
            year: 2015,
            breed: "Siamese",
          },
        ]}
      />
      <Footer />
    </div>
  );
}

export default App;
