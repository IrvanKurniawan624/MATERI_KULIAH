import { useNavigate } from 'react-router-dom';
import './ProductCard.css'
import React, {useState} from "react";

function ProductCard(props){
    const navigate = useNavigate();
    return(
        <div className="product_box">
            <img src={props.image} ></img>
            <div className="description">
                <div>
                <h2>{props.name}</h2>
                <p>{props.price}</p>
                <p className="desc">{props.desc}</p>
                </div>
            </div>
        </div>
    )
}
export default ProductCard