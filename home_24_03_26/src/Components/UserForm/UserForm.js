import './UserForm.css';
import React from 'react';

export default function UserForm() {
    const [formData, setFormData] = React.useState({
        userId: '',
        password: '',
        name: '',
        address: '',
        country: '',
        zip: '',
        email: '',
        sex: '',
        language: [],
        about: ''
    });
    const [formValid, setFormValid] = React.useState({
        userId: "empty",
        password: "empty",
        name: "empty",
        address: "empty",
        country: "empty",
        zip: "empty",
        email: "empty",
    });
    function handleSubmit(event) {
        if (Object.values(formValid).every(v => v === "valid")) {
            alert(JSON.stringify(formData));
        } else {
            alert("Please fill out the form correctly.");
        }
        event.preventDefault();
    }
    return (
        <form onSubmit={handleSubmit}>
            <label className={formValid.userId}>
                User id <span style={{ color: 'red' }}>*[5 to 7 characters]</span>:
                <input type="text" name="userId" onChange={(event) => { if (5 <= event.target.value.length <= 7) { setFormData({ ...formData, userId: event.target.value }); setFormValid({ ...formValid, userId: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, userId: "invalid" }); else setFormValid({ ...formValid, userId: "empty" }); }} />
            </label>
            <label className={formValid.password}>
                Password <span style={{ color: 'red' }}>*[6 to 12 characters]</span>:
                <input type="text" name="password" onChange={(event) => { if (6 <= event.target.value.length <= 12) { setFormData({ ...formData, password: event.target.value }); setFormValid({ ...formValid, password: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, password: "invalid" }); else setFormValid({ ...formValid, password: "empty" }); }} />
            </label>
            <label className={formValid.name}>
                Name <span style={{ color: 'red' }}>*[Alphabetes characters]</span>:
                <input type="text" name="name" onChange={(event) => { if (/^[A-Za-zА-Яа-я]+$/.test(event.target.value)) { setFormData({ ...formData, name: event.target.value }); setFormValid({ ...formValid, name: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, name: "invalid" }); else setFormValid({ ...formValid, name: "empty" }); }} />
            </label>
            <label className={formValid.address}>
                Address <span style={{ color: 'red' }}>*[alphanumeric characters]</span>:
                <input type="text" name="address" onChange={(event) => { if (/^[А-Яа-яA-Za-z0-9\s]+$/.test(event.target.value)) { setFormData({ ...formData, address: event.target.value }); setFormValid({ ...formValid, address: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, address: "invalid" }); else setFormValid({ ...formValid, address: "empty" }); }} />
            </label>
            <label className={formValid.country}>
                Country <span style={{ color: 'red' }}>*[must select a country]</span>:
                <select name="country" onChange={(event) => { setFormData({ ...formData, country: event.target.value }); setFormValid({ ...formValid, country: "valid" }); }}>
                    <option value="">Select a country</option>
                    <option value="usa">USA</option>
                    <option value="canada">Canada</option>
                    <option value="uk">UK</option>
                    <option value="Ukraine">Ukraine</option>
                </select>
            </label>
            <label className={formValid.zip}>
                ZIP Code <span style={{ color: 'red' }}>*[alphanumeric characters]</span>:
                <input type="text" name="zip" onChange={(event) => { if (/^[A-Za-z0-9]+$/.test(event.target.value)) { setFormData({ ...formData, zip: event.target.value }); setFormValid({ ...formValid, zip: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, zip: "invalid" }); else setFormValid({ ...formValid, zip: "empty" }); }} />
            </label>
            <label className={formValid.email}>
                Email <span style={{ color: 'red' }}>*[Valid email]</span>:
                <input type="text" name="email" onChange={(event) => { if (/^\S+@\S+\.\S+$/.test(event.target.value)) { setFormData({ ...formData, email: event.target.value }); setFormValid({ ...formValid, email: "valid" }); } else if (event.target.value.length > 0) setFormValid({ ...formValid, email: "invalid" }); else setFormValid({ ...formValid, email: "empty" }); }} />
            </label>
            <div style={{ display: "flex", flexDirection: "row" }}>
                Sex:
                <input checked type="radio" name="sex" value="male" onChange={(event) => { setFormData({ ...formData, sex: event.target.value }); }} /><label htmlFor="male">Male</label>
                <input type="radio" name="sex" value="female" onChange={(event) => { setFormData({ ...formData, sex: event.target.value }); }} /><label htmlFor="female">Female</label>
            </div>
            <div style={{ display: "flex", flexDirection: "row" }}>
                Language:
                <input type="checkbox" name="language" value="english" onChange={(event) => { if (event.target.checked) { setFormData({ ...formData, language: [...formData.language, event.target.value] }); } else { setFormData({ ...formData, language: formData.language.filter(v => v !== event.target.value) }); } }} /><label htmlFor="english">English</label>
                <input type="checkbox" name="language" value="Non English" onChange={(event) => { if (event.target.checked) { setFormData({ ...formData, language: [...formData.language, event.target.value] }); } else { setFormData({ ...formData, language: formData.language.filter(v => v !== event.target.value) }); } }} /><label htmlFor="non-english">Non English</label>
            </div>
            <label>
                About:
                <textarea name="about" onChange={(event) => { setFormData({ ...formData, about: event.target.value }) }} />
            </label>
            <input type="submit" value="Submit" />
        </form>
    );
}