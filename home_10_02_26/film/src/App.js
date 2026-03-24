import "./App.css";
import { Group } from "./components/Card/Card";
import { Header, Footer } from "./components/Main/Main";

function App() {
  return (
    <div className="App" id="main">
      <Header />
      <Group list={
        [
          {
            img: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR3qotdhvZJim0MEFRYTesAVEPpWJAMB3auAgkhM0WPf0eXfe8WUOJsfHfI_sSZPXu4SQqwehU7A_wl-OesMVSn7S-p1uEcDPlbkmKF-Tv5Zw&s=10",
            name: "The Batman",
            description: "When a sadistic serial killer begins murdering key political figures in Gotham, Batman is forced to investigate the city's hidden corruption and question his family's involvement.",
            poducer: "Matt Reeves",
            year: "2022",
            studio: "Warner Bros. Pictures",
            country: "USA"
          },
          {
            img: "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR3qotdhvZJim0MEFRYTesAVEPpWJAMB3auAgkhM0WPf0eXfe8WUOJsfHfI_sSZPXu4SQqwehU7A_wl-OesMVSn7S-p1uEcDPlbkmKF-Tv5Zw&s=10",
            name: "The Batman",
            description: "When a sadistic serial killer begins murdering key political figures in Gotham, Batman is forced to investigate the city's hidden corruption and question his family's involvement.",
            poducer: "Matt Reeves",
            year: "2022",
            studio: "Warner Bros. Pictures",
            country: "USA"
          }
        ]
      } />
      <Footer />
    </div>
  );
}

export default App;
