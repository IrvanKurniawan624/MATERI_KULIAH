import './App.css';
import './assets/css/bootstrap.min.css';
import './assets/css/custom.css';
import './assets/css/aos.css';
import Banner from './components/Banner';
import Protection from './components/Protection';
import Price from './components/Price';
import Contact from './components/Contact';
function App() {
  return (
    <div>
      <Banner/>
      <Protection/>
      <Price/>
      <Contact/>
    </div>
  );
}


export default App;
