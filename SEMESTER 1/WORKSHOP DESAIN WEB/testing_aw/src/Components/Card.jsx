import React, { useState } from 'react';
import ProductCard from './ProductCard'
import Bakso from'../Image/Bakso.jpg'
import Gudeg from'../Image/Gudeg.jpg'
import Klepon from'../Image/Klepon.jpg'
import Dongkal from'../Image/Kue dongkal.jpg'
import Pempek from'../Image/Pempek.jpg'
import Putu from'../Image/Putu.jpg'
import Rendang from'../Image/Rendang.jpg'
import SelatSolo from'../Image/Selat Solo.jpg'
import Lumpia from '../Image/Lumpia.jpg'
import Terbul from'../Image/Martabak manis.jpg'
import Martabak from '../Image/Martabak Telur.jpg'
import Geprek from '../Image/Geprek.jpg'
import './Card.css'
import { useNavigate } from 'react-router-dom';

function Card({addToCart}) {
    const navigate = useNavigate();
    const [searchTerm, setSearchTerm] = useState('');

    const handleSearch = (event) => {
        setSearchTerm(event.target.value);
    };

    const filteredProducts = products.filter((product) =>
        product.name.toLowerCase().includes(searchTerm.toLowerCase())
    );

    return (
        <div className="container">
        <input
                type="text"
                placeholder="Cari produk..."
                value={searchTerm}
                onChange={handleSearch}
            />
        <div className="App">
            <div className="product">
                <div className="product-grid row">
                    {filteredProducts.map((product) => (
                        <div key={product.id} className="col-sm-4 col-md-3">
                            <div onClick={() => navigate(`/${product.alamat}`)} addToCart={addToCart}>
                                <ProductCard
                                    image={product.image}
                                    name={product.name}
                                    price={product.price}
                                    desc={product.description}
                                    addToCart={addToCart}
                                    />
                            </div>
                        </div>
                    ))}
                </div>
            </div>
        </div>
        </div>
    );
}

const products = [
    { alamat: 'Bakso', id: 1, name: 'Bakso', price: 'Rp.15000', description: '...', image: Bakso },
    { alamat: 'Gudeg', id: 2, name: 'Gudeg', price: 'Rp.5000', description: '...', image: Gudeg },
    { alamat: 'Rendang', id: 3, name: 'Rendang', price: 'Rp.5000', description: '...', image: Rendang },
    { alamat: 'Pempek', id: 4, name: 'Pempek', price: 'Rp.5000', description: '...', image: Pempek },
    { alamat: 'Selat', id: 5, name: 'Selat Solo', price: 'Rp.5000', description: '...', image: SelatSolo },
    { alamat: 'Geprek', id: 6, name: 'Ayam Geprek', price: 'Rp.5000', description: '...', image: Geprek },
    { alamat: 'Klepon', id: 7, name: 'Klepon', price: 'Rp.5000', description: '...', image: Klepon },
    { alamat: 'Dongkal', id: 8, name: 'Kue Dongkal', price: 'Rp.5000', description: '...', image: Dongkal },
    { alamat: 'Putu', id: 9, name: 'Putu', price: 'Rp.5000', description: '...', image: Putu },
    { alamat: 'Terbul', id: 10, name: 'Martabak Manis', price: 'Rp.5000', description: '...', image: Terbul },
    { alamat: 'Martabak', id: 11, name: 'Martabak', price: 'Rp.5000', description: '...', image: Martabak },
    { alamat: 'Lumpia', id: 12, name: 'Lumpia', price: 'Rp.5000', description: '...', image: Lumpia },
];

export default Card;