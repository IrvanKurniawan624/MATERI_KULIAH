import ProductDetails from "../Pages/ProductDetails"
import putu from '../Image/Putu.jpg'
function Putu({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {putu}
        name = "Putu"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Putu