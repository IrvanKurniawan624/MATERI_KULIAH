import React from 'react'
import {useNavigate} from 'react-router-dom'
import { AiOutlineShoppingCart,AiOutlineUserAdd } from "react-icons/ai";


function Navbar({ searchQuery, onSearchChange }) {
  const navigate = useNavigate()

  return (
    <div className='continainer-fluid bg-dark-subtle'>
      <div className='row mx-5 py-3'>
        <div className='col-12 col-md-3 d-flex align-items-center'>
          <a href='/'className='text-black link-underline link-underline-opacity-0 ms-4 fs-2 fw-bold'>KedeBOOK</a>
        </div>
        <div className='col-12 col-md-7 d-flex align-items-center align-self-center'>
          <input type="text" class="form" className='border border-1 rounded-1 ps-4' style={{width:'800px', height:'40px'}} placeholder="Cari judul buku apa?" aria-label="Username" aria-describedby="basic-addon1" value={searchQuery} onChange={onSearchChange}/>
        </div>
        <div className='col-12 col-md-2 d-flex justify-content-center justify-content-md-center align-items-center'>
          <a href='/'>
          <AiOutlineShoppingCart style={{width:'20px', height:'30px', color:'black'}} />
          </a>
          <a href='/login' onClick={() => navigate('/login')}>
          <AiOutlineUserAdd className='m-3' style={{ width: '20px', height: '30px', color: 'black' }} />
          </a>
        </div>
      </div>
    </div>
  )
}

export default Navbar