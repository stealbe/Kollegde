import logo from './logo.svg';
import './App.css';
import { BrowserRouter, Routes,Route } from 'react-router-dom';
import { About, Home,Main } from './Main';

function App() 
{
  return (
  <BrowserRouter>
    <Routes>
      <Route path="/" element={<Main/>}>
            <Route path="home" element={<Home/>}/>
            <Route path="about" element={<About/>}/>    
      </Route>  
      </Routes>

      <div className='div'>        
        <p>Lorem import</p>      
      </div>  
    
    </BrowserRouter>
    
  );
}

export default App;
