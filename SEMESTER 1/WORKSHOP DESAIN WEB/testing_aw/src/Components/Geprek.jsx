import ProductDetails from "../Pages/ProductDetails"
import geprek from '../Image/Geprek.jpg'
function Geprek({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {geprek}
        name = "Geprek"
        price = "Rp.100"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Geprek