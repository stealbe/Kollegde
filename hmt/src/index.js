import ReactDOM from 'react-dom/client';
import './index.css';
import reportWebVitals from './reportWebVitals';

import TopicList from './Components/topic-list/topic-list';
import {
  createBrowserRouter,
  createRoutesFromElements,
  RouterProvider,
  Route,
  Outlet
} from 'react-router-dom';

const Root = () => {
  return (
    <div className='container' style={{display: "flex", justifyContent:"center"}}>
      <TopicList
        title="Список тем"
        list={[
          { chapter_id: 1, name: "Введение в React", link: "/topic/1" },
          { chapter_id: 2, name: "Компоненты и пропсы", link: "/topic/2" },
          { chapter_id: 3, name: "Состояние и жизненный цикл", link: "/topic/3" },
          { chapter_id: 4, name: "Обработка событий", link: "/topic/4" },
          { chapter_id: 5, name: "Условный рендеринг", link: "/topic/5" },
          { chapter_id: 6, name: "Списки и ключи", link: "/topic/6" },
          { chapter_id: 7, name: "Формы", link: "/topic/7" },
          { chapter_id: 8, name: "Подъем состояния", link: "/topic/8" },
          { chapter_id: 9, name: "Композиция и наследование", link: "/topic/9" },
          { chapter_id: 10, name: "Паттерны проектирования", link: "/topic/10" },
        ]}
      />
      <Outlet />
    </div>
  );
}

const router = createBrowserRouter(
  createRoutesFromElements(
    <Route path='/' element={<Root />} >

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
