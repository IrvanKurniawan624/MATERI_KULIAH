import React, { useState } from 'react';
import '../Tugas.css';

function Tugas(){
    const [activeSize, setActiveSize] = useState("M");

    const handleChangeSize = (size) => {
        setActiveSize(size);
    }
    
    const sizes = ['XS', 'S', 'M', "L"];

    return (
        <div className="container">
            <div className="product">
                <div className="product-image">
                <img src="headphone-2.jpg" alt='headphone-2'/>
                </div>
                <div className="product-info">
                <h2 className='product-title'>The best headphones</h2>
                <p className='font-bold'>NOVEMBER RELEASE</p>
                <p className='product-number'>Number: <span>897879</span></p>
                <p className='product-desc'>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Animi beatae ex consectetur, ab ad sint magnam perspiciatis nostrum, doloribus, alias quasi libero. Voluptates, blanditiis dicta temporibus voluptas debitis vitae molestiae.</p>
                <div className="size-info">
                    <h6>SIZE</h6>
                    <ul className='list-size-info'>
                    {sizes.map((size)=>(
                        <li key={size} className={(size === activeSize) ? 'active' : ''} onClick={() => handleChangeSize(size)}>{size}</li>
                    ))}
                    </ul>
                </div>
                <div className="button-info">
                    <button type='button' className='btn btn-buy'>BUY NOW</button>
                    <button type='button' className='btn btn-wishlist'>ADD TO WISHLIST</button>
                </div>
                <p className='limit-info'>*Only 1 Avaiable</p>
                </div>
            </div>
        </div>
    )
}

export default Tugas;