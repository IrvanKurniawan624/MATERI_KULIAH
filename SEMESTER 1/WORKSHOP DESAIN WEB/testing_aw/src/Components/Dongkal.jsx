import ProductDetails from "../Pages/ProductDetails"
import dongkal from '../Image/Kue dongkal.jpg'
function Dongkal({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {dongkal}
        name = "Dongkal"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Dongkal