import First from '../Components/First'

function Home({addToCart, cart}){
    return (
        <First addToCart={addToCart} cart={cart}/>
    )
}
export default Home