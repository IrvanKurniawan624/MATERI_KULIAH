import ProductDetails from "../Pages/ProductDetails"
import lumpia from '../Image/Lumpia.jpg'
function Lumpia({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {lumpia}
        name = "Lumpia"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Lumpia