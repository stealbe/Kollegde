export default function UserRow({ id, name, age, city, young }) {
    return <tr style={{background:young?"red":"none"}} id={"user_" + id}>{name},{age},{city}</tr>
}