import ProductDetails from "../Pages/ProductDetails"
import martabak from '../Image/Martabak Telur.jpg'
function Martabak({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {martabak}
        name = "Martabak"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Martabak