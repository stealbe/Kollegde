import TopicItem from "../topic-item/topic-item";
import './topic-list.css';

export default function TopicList({ title, list }) {
    return (
        <div className="topic-list">
            <h1>{title}</h1>
            {list.map((item, index) => (
                <TopicItem
                    key={index}
                    num={index.chapter_id}
                    title={item.name}
                    link={item.link}
                />
            ))}
        </div>
    );
}