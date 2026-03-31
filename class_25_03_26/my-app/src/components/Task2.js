import { Link, Outlet  } from 'react-router-dom';

export const MainPage = () => (
    <>
  <nav>
    <ul>
      <li>
        <Link to="/home">Home</Link>
      </li>
      <li>
        <Link to="/about">About</Link>
      </li>
    </ul>  
  </nav>
   <hr/> 
{/* !!!!!!!!!!!!!!!!!!!!!! */}

  <Outlet/> 
  
{/* !!!!!!!!!!!!!!!!!!!!!! */}
  <p>Hello world !!!!</p>
  
  <hr/>  
  </>

);