import './Second.css';
import { useNavigate } from 'react-router-dom';
import img from "../Image/kenyang.png";
import React, { useState } from 'react';

function Second() {
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const handleSubmit = (event) => {
        event.preventDefault();

        if (email === '' || password === '') {
            alert('Email and password are required');
            return;
        }

        console.log('email:', email);
        console.log('password:', password);
        navigate('/home');
    };

    const navigate = useNavigate();

    return (
        <div className="card mt-5">
        <div className="login-container">
        <div className="row d-flex">
        <div className="kiri col-5">

            <header className="login-header">
                <h1 className="text-center">Welcome Back!</h1>
                <p className="text-center">Good to see you again</p>
            </header>
            <div className="login-form">
                <form onSubmit={handleSubmit}>
                    <div className="form-group">
                        <label htmlFor="email">Email</label>
                        <input
                            className="input"
                            type="email"
                            id="email"
                            value={email}
                            placeholder="Email"
                            onChange={(e) => setEmail(e.target.value)}
                        />
                    </div>
                    <div className="form-group">
                        <label htmlFor="password">Password</label>
                        <input
                            className="input"
                            type="password"
                            id="password"
                            placeholder="Password"
                            onChange={(e) => setPassword(e.target.value)}
                        />
                    </div>
                    <button className="btn-2" type="submit">
                        Login
                    </button>
                </form>
                <p className="forgot-password">Forgot password?</p>
                </div>
            </div>
            <div className="kanan col-7">
                <img src={img} width="50%" />
                <p>Lorem ipsum...</p>
            </div>
        </div>
        </div>
        </div>
    );
}

export default Second;