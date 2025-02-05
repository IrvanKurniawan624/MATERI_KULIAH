import React, {useState} from 'react';
import '../Latihan.css';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faCheck } from '@fortawesome/free-solid-svg-icons'; 
import { faCircleQuestion } from '@fortawesome/free-regular-svg-icons'; 

function Latihan(){
    const [activeColor, setActiveColor] = useState('red');
    const [activeCable, setActiveCable] = useState('');
    
    const handleChangeCables = (cable) => {
        setActiveCable(cable);
    }

    const handleChangeColor = (color) => {
        setActiveColor(color);
    }

    const colors = ['red', 'darkblue', 'black'];
    const cables = ['Straight', 'Coiled', 'Long-coiled'];

    return (
        <div className="container">
            <div className="product-2">
                <div className="product-image-2">
                    <img src="headphone-3.jpg" alt='headphone-3'/>
                </div>
                <div className="product-info-2">
                    <p className='product-category'>HEADPHONE</p>
                    <h2 className='product-title'>Beats EP</h2>
                    <p className='product-desc'>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Animi beatae ex consectetur, ab ad sint magnam perspiciatis nostrum, doloribus, alias quasi libero. Voluptates, blanditiis dicta temporibus voluptas debitis vitae molestiae.</p>
                    <div className='color-info'>
                        <p>Color</p>
                        <ul className='color-list-info'>
                            {colors.map((color) => (
                                <li key={color} className={`color-selection ${color}`} onClick={() => handleChangeColor(color)}> <FontAwesomeIcon icon={faCheck} className={`color-selection-icon ${color === activeColor ? 'active' : ''}`} /></li>
                            ))}
                        </ul>
                    </div>
                    <div className='cable-config-info'>
                        <p>Cable Configuration</p>
                        <ul className='list-cable-config-info'>
                            {cables.map((cable) => (
                                <li key={cable} className={cable === activeCable ? 'active' : ''} onClick={() => handleChangeCables(cable)}>{cable}</li>
                            ))}
                        </ul>
                    </div>
                    <a href="https://youtu.be/-VhIy25KVVQ?si=eYTTF7VX5xZul6wd" className="how-to-config-info">
                       <FontAwesomeIcon icon={faCircleQuestion} /> How to configurate your headphones
                    </a>
                    <div className="price-cart-info">
                        <h3>148$</h3>
                        <button type='button' className='btn-cart'>Add to cart</button>
                    </div>
                </div>
            </div>
        </div>
    )
}

export default Latihan;