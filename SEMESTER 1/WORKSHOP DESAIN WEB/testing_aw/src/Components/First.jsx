import Card from "./Card"
import './First.css'
import Navbar from './navbar';

function First({addToCart, cart}){
    return (
        <>
    <Navbar cart={cart}/>

        <h3>TOKO </h3>
        <div className="Container">
                <div className="row">
                <Card addToCart={addToCart}/>
            </div>
        </div>
        </>
    )
}
export default First