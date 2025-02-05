import ProductDetails from "../Pages/ProductDetails"
import terbul from '../Image/Martabak manis.jpg'
function Terbul({addToCart, cart}){
    return(
        <>
        <ProductDetails
        image = {terbul}
        name = "Martabak Manis"
        price = "Rp. 35.000"
        desc = "Kondisi mulu 99%"
        btn = "Add to cart"
        addToCart={addToCart}
        cart={cart}
        />
        </>
    )
}
export default Terbul