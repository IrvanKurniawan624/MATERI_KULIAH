import ProductDetails from "../Pages/ProductDetails";
import gudeg from "../Image/Gudeg.jpg"
function Gudeg({addToCart, cart}) {
    return (
        <>
            <ProductDetails
                image={gudeg}
                name="Gudeg"
                price="Rp.100"
                desc="Kondisi mulu 99%"
                btn = "Add to cart"
                addToCart={addToCart}
                cart={cart}
            />
        </>
    )
}
export default Gudeg