import {React, useState } from 'react'
import Home from './pages/Home'
import Login from './pages/Login'
import Layout from './pages/Layout'
import Detail from './pages/Detail'
import {BrowserRouter as Router, Routes, Route} from 'react-router-dom'

function App() {
  const [searchQuery, setSearchQuery] = useState('');

  const handleSearchChange = (event) => {
    setSearchQuery(event.target.value);
  };

  return (
    <Router>
      <Routes>
        <Route path="/" element={<Layout searchQuery={searchQuery} onSearchChange={handleSearchChange} />}>
          <Route index element={<Home searchQuery={searchQuery} />} />
          <Route path="/:slug" element={<Detail/>}/>
        </Route>
        <Route path="/login" element={<Login />}/>
      </Routes>
    </Router>
  )
}

export default App
