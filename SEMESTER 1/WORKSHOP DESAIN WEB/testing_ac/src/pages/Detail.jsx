import React , { useEffect, useState} from 'react'
import { MdOutlineAddShoppingCart } from "react-icons/md"
import { useParams } from 'react-router-dom'
import { data } from '../Data';

function Detail() {
    const { slug } = useParams();
    const [detail, setDetail] = useState([]);
    useEffect(()=>{
        const findDetail = data.filter(data => data.slug === slug)
        if(findDetail.length > 0){
            setDetail(findDetail[0]);
        }else{
            window.location.href = '/';
        }
    }, [slug])
  return (
    <div className='container mx-auto'>
        <div className='row my-5'>
            <div className='col-12 col-md-4 d-flex justify-content-center'>
                <img src={detail.image} alt="" className='img-fluid img-thumbnails'/>
            </div>
            <div className='col-12 col-md-8'>
                <h1 className='fs-3 fw-bold mt-5 mt-md-0'>{detail.name}</h1>
                <div className='justify-content-between'>
                   <p className='fw-bold fs-2 '>
                       Rp.{detail.price}.000
                   </p>
                   <h4 className='fs-5 fw-semibold mt-5'>Deskripsi</h4>
                   <p className='fs-6 mt-2'>
                    {detail.description}
                   </p>
                </div>
                <button className='border border-1 rounded-2 py-2 px-4 mt-3'>
                   <MdOutlineAddShoppingCart className='me-3' />  
                    Add to Cart 
                </button>
            </div>
        </div>
    </div>
  )
}

export default Detail