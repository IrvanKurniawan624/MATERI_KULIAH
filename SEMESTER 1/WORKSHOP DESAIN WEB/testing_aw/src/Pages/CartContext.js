import React, { createContext, useContext, useState } from 'react';

// Membuat Context
const CartContext = createContext();

// Provider untuk Context
export const CartProvider = ({ children }) => {
    const [cart, setCart] = useState([]);

    const addToCart = (product) => {
        setCart([...cart, product]);
        console.log("Item ditambahkan ke keranjang:", product);
    };

    return (
        <CartContext.Provider value={{ cart, addToCart }}>
            {children}
        </CartContext.Provider>
    );
};

// Hook untuk menggunakan CartContext
export const useCart = () => useContext(CartContext);