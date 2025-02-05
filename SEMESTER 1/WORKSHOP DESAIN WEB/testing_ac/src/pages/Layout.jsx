import React from 'react'
import Navbar from '../component/Navbar'
import { Outlet } from 'react-router-dom'

function Layout({ searchQuery, onSearchChange }) {
  return (
    <>
      <Navbar searchQuery={searchQuery} onSearchChange={onSearchChange} />
      <Outlet/>
    </>
  )
}

export default Layout