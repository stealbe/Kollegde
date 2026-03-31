import { Link, Outlet } from "react-router-dom";

export function Home() {
    return <h1>Home component</h1>
}
export function About() {
    return <h1>About component</h1>
}

export function Main() {
    return <>
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

        <hr></hr>

       <Outlet />


        <hr></hr>
        <div>Footer</div>
    </>


}