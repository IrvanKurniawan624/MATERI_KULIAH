import React from "react";
import '../App.css';
import {useLocation, Link} from 'react-router-dom';

function Navbar() {
  const location = useLocation(); // Get current location

  return (
    <nav className="navbar-class">
      <Link
        className={location.pathname === '/tugas' ? 'active' : ''}
        to="/tugas"
      >
        Tugas
      </Link>
      <Link
        className={location.pathname === '/latihan' ? 'active' : ''}
        to="/latihan"
      >
        Latihan
      </Link>
    </nav>
  );
}

export default Navbar;