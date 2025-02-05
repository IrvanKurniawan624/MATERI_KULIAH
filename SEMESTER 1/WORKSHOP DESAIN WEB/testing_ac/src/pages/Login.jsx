import React from 'react'


function login() {
  return (
    <div className='bg-dark-subtle'>
      <div className='container mx-auto ' style={{ paddingBottom: '44px', paddingTop: '44px' }}>
        <div className='d-flex justify-content-center '>
          <div className='m-5 border border-2 bg-white'>
            <div className='m-5'>
              <form>
                <h2 className='text-center fs-1 fw-bold mb-5'>Log In</h2>
                <div className="mb-3">
                  <input type="email" className="form-control" style={{ width: '300px' }} id="exampleInputEmail1" aria-describedby="emailHelp" placeholder='Email' />
                </div>
                <div className="mb-1">
                  <input type="password" className="form-control" style={{ width: '300px' }} id="exampleInputPassword1" placeholder='Password' />
                </div>
                <div class="mb-5 form-check">
                  <input type="checkbox" class="form-check-input" id="exampleCheck1"/>
                  <label class="form-check-label" for="exampleCheck1">Remember me</label>
                </div>
                <div className='d-flex justify-content-center my-4'>
                  <button type="submit" className="btn btn-primary" style={{ width: '200px' }}>LOG IN</button>
                </div>
                <div className='d-flex  justify-content-center'>
                  <p>Forget Password?</p>
                  <a href='/'>clickhere</a>
                </div>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}

export default login
