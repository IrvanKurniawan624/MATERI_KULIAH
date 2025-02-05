import ProductDetails from "../Pages/ProductDetails"
import pempek from '../Image/Pempek.jpg'
function Pempek({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {pempek}
        name = "Pempek"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Pempek