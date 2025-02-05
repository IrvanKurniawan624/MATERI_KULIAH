import React from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';
import Tugas from './components/Tugas';
import Navbar from './components/Navbar';
import Latihan from './components/Latihan';
import './App.css';

function App() {
  
  return (
    <Router>
      <Navbar/>

      <Routes>
        <Route path="/" element={<Navigate to="/tugas" />} />
        <Route path="/tugas" element={<Tugas />} />
        <Route path="/latihan" element={<Latihan />} />
      </Routes>
    </Router>
  );
}

export default App;
