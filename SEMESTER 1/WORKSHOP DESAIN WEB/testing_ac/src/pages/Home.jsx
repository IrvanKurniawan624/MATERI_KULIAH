import React from 'react'
import { data } from '../Data'
import Product from '../component/Product'

function Home({searchQuery}) {

const filteredData = data.filter((product) => {
    const name = product.name || '';
    const category = product.category || '';
    return (
      name.toLowerCase().includes(searchQuery.toLowerCase()) ||
      category.toLowerCase().includes(searchQuery.toLowerCase())
    );
  });


  return (
    <div className='container mx-auto my-4'>
      <div className='row row-cols-1 row-cols-sm-2 row-cols-md-4 g-3'>
         {filteredData.map((data, key) => <Product key={key} data={data}/>)}
      </div> 
    </div>
  )
}

export default Home