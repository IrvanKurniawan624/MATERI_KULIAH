import React from 'react'
import { Link } from 'react-router-dom'
import { MdOutlineAddShoppingCart } from "react-icons/md";

function Product(props) {
  const {name, price, image, slug} = props.data;
  return (
    <div className= 'card'>
      <div className='text-center'>
        <Link to={slug}>
           <img src={image} alt='' className='img-thumbnail mt-4'/>
        </Link>
      </div>
      <div className='card-body'>
        <h3 className='fs-6 fw-medium'>{name}</h3>
      </div>
      <div className='mx-3 mb-3 d-flex justify-content-between align-items-center'>
        <p className='align-self-cente mb-0'>
          Rp.<span className='fs-6 fw-medium'>{price}.000</span>
        </p>
      </div>
        <button className='border border-2 rounded-2 p-1 px-2 mb-3 mx-3 fw-semibold'>
          <MdOutlineAddShoppingCart className='me-1'/>
          Add To Cart
        </button>
    </div>
  )
}

export default Product