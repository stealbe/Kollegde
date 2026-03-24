import "./App.css";
import { Group } from "./components/Card/Card";
import { Header, Footer } from "./components/Main/Main";

function App() {
  return (
    <div className="App" id="main">
      <Header />
      <Group
        list={[
          {
            img: "https://static.thenounproject.com/png/2932881-200.png",
            name: "Paradovskiy Oleksandr",
            description:
              "I am a student of the 2nd year of the Faculty of Computer Science at kolledge 'It Step'. I am interested in programming and web development. I am currently learning React and System Programing.",
            desition: "No desition yet",
            phone: "+380633333333",
            country: "Ukraine",
            mail: "paradovskiialex@gmail.com",
            city: "Odessa",
          },
          {
            img: "https://static.thenounproject.com/png/2932881-200.png",
            name: "Paradovskiy Oleksandr",
            description:
              "I am a student of the 2nd year of the Faculty of Computer Science at kolledge 'It Step'. I am interested in programming and web development. I am currently learning React and System Programing.",
            desition: "No desition yet",
            phone: "+380633333333",
            country: "Ukraine",
            mail: "paradovskiialex@gmail.com",
            city: "Odessa",
          },
        ]}
      />
      <Footer />
    </div>
  );
}

export default App;
