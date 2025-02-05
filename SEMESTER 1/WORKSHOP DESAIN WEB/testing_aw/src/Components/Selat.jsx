import ProductDetails from "../Pages/ProductDetails"
import selat from '../Image/Selat Solo.jpg'
function Selat({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {selat}
        name = "Selat Solo"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Selat