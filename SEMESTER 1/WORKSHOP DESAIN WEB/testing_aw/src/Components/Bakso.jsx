import ProductDetails from "../Pages/ProductDetails"
import bakso from '../Image/Bakso.jpg'
function Bakso({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {bakso}
        name = "Bakso"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Bakso