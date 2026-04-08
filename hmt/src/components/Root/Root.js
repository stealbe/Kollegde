import { Routes, Route, Navigate, Outlet } from "react-router-dom";
import SubjectMap from "../SubjectNetwork/SubjectMap";
import SubjectPage from "../SubjectPage/SubjectPage";
import "./Root.css";
import Header from "../Header/Header";
import TopicPage from '../TopicPage/TopicPage';
import NotesPage from '../NotesPage/NotesPage';

function Root() {
  return (
    <div className="Root">
      <Header />
      <Routes>
        <Route path="/" element={<Navigate to="/home" replace />} />
        <Route path="/home" element={<SubjectMap />} />
        <Route path="/about" element={<div>About Page</div>} />
        <Route path="/subject/:id" element={<SubjectPage />} />
        <Route path="/subject/:subjectId/topic/:topicId" element={<TopicPage />} />
        <Route path="/subject/:subjectId/topic/:topicId/note" element={<NotesPage />} />
        {/* <Route path="/subject/:subjectId/topic/:topicId/quiz" element={<QuizPage />} /> */}
      </Routes>
      <Outlet />
    </div>
  );
}

export default Root;
