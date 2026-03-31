import ReactDOM from 'react-dom/client';
import './index.css';
import reportWebVitals from './reportWebVitals';

import {
  createBrowserRouter,
  createRoutesFromElements,
  RouterProvider,
  Route,
  Outlet
} from 'react-router-dom';

import Header from './Components/Header/Header';
import SideBar from './Components/SideBar/SideBar';
import Footer from './Components/Footer/Footer';
import Main from './Pages/Main';
import Catalog from './Pages/Catalog/Catalog';

const Root = () => {
  return (
    <div className='container' style={{ display: "flex", flexDirection: "column", justifyContent: "center" }}>
      <Header />
      <section style={{ display: "flex", flexDirection: "row", flexWrap: "nowrap", width: "100%" }}>
        <SideBar />
        <Outlet />
      </section>
      <Footer />
    </div>
  );
}

const router = createBrowserRouter(
createRoutesFromElements(
  <Route path='/' element={<Root />} >
    <Route index element={<Main />} />
    <Route path='catalog' element={<Catalog />} />
  </Route>
)
);

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <RouterProvider router={router} />
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
