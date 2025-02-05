import './ProductDetails.css'
import Navbar from '../Components/navbar';
function ProductDetails(props) {
    const { image, name, price, desc, btn, addToCart, cart } = props;
    return (
      <div>
            <Navbar cart={cart}/>
      <div className="container">
        <div className="row">
          <div className="gambar">
            <img className="gambar" src={image} width="300px" height="300px "style={{ borderRadius: '10px', border: '1px solid #ccc', marginTop: '20px' }} />
          </div>
          <div className="description ">
            <h2 className="fw-bold text-center">{name}</h2>
            <p>{price}</p>
            <p className="desc">{desc}</p>
  
            <button className="btn-2" onClick={() => addToCart(props)}>{btn}</button>
          </div>
        </div>
      </div>
      </div>
    )
}
export default ProductDetails