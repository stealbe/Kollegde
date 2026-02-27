import UserRow from "../UserRow/UserRow";

export default function UserTable({ list, AgeFunc }) {
    return (
        list.length === 0 ? <p>Нет пользователей</p> :
            <table>
                <td>Users</td>
                {
                    list.map(item => (
                        <UserRow id={item.id} name={item.name} age={AgeFunc(item.age)} city={item.city} young={item.age >= 25 ? false : true} />
                    ))
                }
            </table>
    )
}