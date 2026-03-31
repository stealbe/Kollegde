import './App.css';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import { Home, About,NotFound } from './components/Task1'
import { MainPage } from './components/Task2';
import { MainPage2 } from './components/Task3';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<MainPage/>} >
        {/* <Route path="/" element={<MainPage2/> } >   */}
        {/* <Route  element = {<Home/> } /> */}
        <Route path="home" element={<Home />} />
        <Route path="about" element={<About />} />
        <Route path="*" element= {<NotFound />} />   {/*подстановочный путь 404 страница*/}
       </Route>
      </Routes>
     
      <div className='div'>        
        <p>Lorem import</p>      
      </div>  
    </BrowserRouter>

  );
}

export default App;