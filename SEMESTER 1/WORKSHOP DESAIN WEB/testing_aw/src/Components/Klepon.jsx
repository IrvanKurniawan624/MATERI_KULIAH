import ProductDetails from "../Pages/ProductDetails"
import klepon from '../Image/Klepon.jpg'
function Klepon({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {klepon}
        name = "Klepon"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Klepon