import {BrowserRouter as Router, Routes, Route} from 'react-router-dom'
import './App.css';
import Home from './Pages/Home'
import Login from './Pages/Login';
import Cart from './Pages/Cart';
import Bakso from './Components/Bakso';
import Gudeg from './Components/Gudeg';
import Rendang from './Components/Rendang';
import Pempek from './Components/Pempek';
import Selat from './Components/Selat';
import Klepon from './Components/Klepon';
import Dongkal from './Components/Dongkal';
import Putu from './Components/Putu';
import Lumpia from './Components/Lumpia';
import Terbul from './Components/Terbul';
import Martabak from './Components/Martabak';
import Geprek from './Components/Geprek';
import { useState } from 'react';

function App() {
  const [cart, setCart] = useState([]);
  const addToCart = (product) => {
    const cartItem = {...product};
    setCart([...cart, cartItem]);
  };
  const handleCheckout = () => {
    setCart([]); 
    alert("Barang telah di checkout!");
  };
  
  return (
    <Router>
    <Routes>
      <Route path='/' element={<Login />} />
      <Route path='/home' element={<Home addToCart={addToCart} cart={cart}/>} />
      <Route path="/Cart" element={<Cart cart={cart} onCheckout={handleCheckout} />} />
      <Route path='/Bakso' element={<Bakso addToCart={addToCart} cart={cart}/>} />
      <Route path='/Gudeg' element={<Gudeg addToCart={addToCart} cart={cart}/>} />
      <Route path='/Rendang' element={<Rendang addToCart={addToCart} cart={cart}/>} />
      <Route path='/Pempek' element={<Pempek addToCart={addToCart} cart={cart}/>} />
      <Route path='/Selat' element={<Selat addToCart={addToCart} cart={cart}/>} />
      <Route path='/Klepon' element={<Klepon addToCart={addToCart} cart={cart}/>} />
      <Route path='/Dongkal' element={<Dongkal addToCart={addToCart} cart={cart}/>} />
      <Route path='/Putu' element={<Putu addToCart={addToCart} cart={cart}/>} />
      <Route path='/Lumpia' element={<Lumpia addToCart={addToCart} cart={cart}/>} />
      <Route path='/Terbul' element={<Terbul addToCart={addToCart} cart={cart}/>} />
      <Route path='/Martabak' element={<Martabak addToCart={addToCart} cart={cart}/>} />
      <Route path='/Geprek' element={<Geprek addToCart={addToCart} cart={cart}/>} />
    </Routes>
  </Router>
  )
}

export default App;
