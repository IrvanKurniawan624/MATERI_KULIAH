import { Link } from 'react-router-dom';
import { NavLink } from 'react-router-dom';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faShoppingCart } from '@fortawesome/free-solid-svg-icons';
import './navbar.css'

function Navbar({cart}) {
    const HitungBarang = () => {
        return cart.length;
    };
    const totalBarang = HitungBarang();
    return (
        <nav className="navbar">
                <Link to ="/home" className="title">Home</Link>
                
                <div className="menu">
                    <span></span>
                    <span></span>
                    <span></span>
                </div>
                <ul>
                <li className="item-navbar p-4"><NavLink to ="/Cart"><FontAwesomeIcon icon={faShoppingCart} width="20px"/><span className="angka-cart text-2xl">
                    {totalBarang}</span></NavLink></li>                
                </ul>
        </nav>
    )
}

export default Navbar