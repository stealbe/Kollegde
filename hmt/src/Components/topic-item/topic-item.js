import './topic-item.css';
import { Link } from 'react-router-dom';

export default function TopicItem({ num, title, link }) {
    return (
        <Link to={link} className="topic-item">
            <h2>{num + ' ' + title}</h2>
            <span> Перейти </span>
        </Link>
    );
}