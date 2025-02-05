import logo from './logo.svg';
import './App.css';
import './assets/css/bootstrap.min.css';


function App() {
  return (
  <div className="bg-slate-50">
    <div className="container mx-auto py-20 bg-slate-50">
    <div className="grid  grid-cols-2 gap-4">
    
      <div className="grid drop-shadow-2xl bg-teal-300 w-3/5 h-full justify-items-center px-11 py-60">
      <img src="/assets/img/racing.png" className="w-16 md:w-32 lg:w-48 hover:w-52 transition-all duration-700"/>
      <h1 className="text-3xl font-bold italic">
            CleanMyCar
      </h1>
      <p className="text-md font-semibold">Indi'an firts Waterless carr cleaning company</p>
      </div>

      <div className="col-span-1 -ml-80 drop-shadow-2xl bg-slate-50  w-[245]">
        <div  className="float-right mt-4 mr-4 font-medium"><p>Nedd help?</p></div>
          <div className="grid justify-items-center py-44">
          
          <div className="grid pl-14 justify-items-center mt-11">
          <h1 className="text-3xl font-bold">
            Log in
          </h1>
          </div>

        <form className="mt-8 pl-32 w-full">
          <div className="mb-4">
            <div className="mb-4">
            <label className="text-2xl font-bold">Email</label>
            </div>
            <div className="text-left">
            <input type="text" className="bg-slate-50 text-2xl rounded-lg border pl-4 py-4 px4 w-10/12 placeholder-gray-500 outline-none transition-all duration-700 erase-in-out focus:sahdow-outline hover:w-11/12" placeholder="email" />
            </div>
          </div>

          <div className="mb-4">
            <div className="mb-4">
            <label className="text-2xl font-bold">Password</label>
            </div>
            <div className="text-left">
            <input type="password" className="bg-slate-50 text-2xl rounded-lg border pl-4 py-4 px4 w-10/12 placeholder-gray-500 outline-none transition-all duration-700 erase-in-out focus:sahdow-outline hover:w-11/12" placeholder="password" />
            </div>
          </div>
          <div className="grid justify-items-center mt-11">
          <button class="rounded-full bg-teal-300 hover:bg-teal-400 transition-all duration-500 px-24 py-5 text-xl font-bold">Save Changes</button>
          </div>
          </form>

          </div>

          
      </div>
    </div>
    
  </div>
  </div>
  );
}

export default App;


