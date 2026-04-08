import './MyForm.css';
import React from 'react';

export function Myform() {
    const [user, Setuser] = React.useState({ login: "", email: "", pass: "" })

    const refForm = React.useRef();

    const refLogin = React.useRef();
    const refEmail = React.useRef();
    const refPass = React.useRef();

    function handlesubmit(event) {
        if (user.login.length === 0) {
            refLogin.current.focus();
        }
        else if (user.email.length === 0) {
            refEmail.current.focus();
        }
        else if (user.pass.length < 6) {
            alert("Пароль должен быть не менее 6 символов");
        }
        else alert(user.login + " " + user.email + " " + user.pass);
        event.preventDefault();
    }
    function onChangeLogin() {
        Setuser({ login: refLogin.current.value, email: user.email, pass: user.pass })
        if (user.login.length >= 3) {
            refLogin.current.className = "valid";
        }
        else if (user.login.length === 0) {
            refLogin.current.className = "empty";
        }
        else {
            refLogin.current.className = "nonvalid";
        }
    }

    function OnChangeEmail() {
        if (refEmail.current.value.includes("@") && refEmail.current.value.length > 5) {
            refEmail.current.className = "valid";
        }
        else if (refEmail.current.value.length === 0) {
            refEmail.current.className = "empty";
        }
        else {
            refEmail.current.className = "nonvalid";
        }
        Setuser({ login: user.login, email: refEmail.current.value, pass: user.pass })
    }
    function onChangePassword() {
        Setuser({ login: user.login, email: user.email, pass: refPass.current.value })
        if (user.pass.length >= 3) {
            refPass.current.className = "valid";
        }
        else if (user.pass.length === 0) {
            refPass.current.className = "empty";
        }
        else {
            refPass.current.className = "nonvalid";
        }
    }

    //     ```  
    // ---- Получать значения input через useRef
    // ---- Делать простую валидацию

    // Создаем форму с полями:
    //   Имя
    //   Email
    //   Пароль
    //   Кнопка «Отправить»

    // Поведение формы:
    // При нажатии на кнопку:

    //   если поле имя пустое → фокус на поле имени
    //   если email пустой → фокус на email
    //   если пароль короче 6 символов → alert
    // Если всё заполнено правильно → вывести данные(alert)

    //   ```

    return <div className="Myform">
        <form onSubmit={handlesubmit} ref={refForm}>
            <div>
                <span>Login</span>
                <input type="text" className="empty" ref={refLogin} onChange={onChangeLogin}></input>
            </div>
            <div>
                <span>Email</span>
                <input type="text" className="empty" ref={refEmail} onChange={OnChangeEmail}></input>
            </div>
            <div>
                <span>Password</span>
                <input type="text" className="empty" ref={refPass} onChange={onChangePassword}></input>
            </div>

            <input type="submit" value="Ok"  ></input>
        </form>
    </div>
}
export default Myform;
