import ProductDetails from "../Pages/ProductDetails"
import rendang from '../Image/Rendang.jpg'
function Rendang({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {rendang}
        name = "Rendang"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Rendang