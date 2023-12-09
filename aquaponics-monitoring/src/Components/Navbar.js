import React from 'react'

const Navbar = () => {
  return (
    <div>
       <nav className="navbar navbar-expand-lg bg-body-tertiary">
      <div className="container-fluid">

        <img width="64" height="64"
          src="https://img.icons8.com/external-flaticons-lineal-color-flat-icons/64/000000/external-fish-vacation-planning-diving-tour-flaticons-lineal-color-flat-icons.png"
          alt="external-fish-vacation-planning-diving-tour-flaticons-lineal-color-flat-icons" />
        <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent"
          aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className="collapse navbar-collapse " id="navbarSupportedContent">
          <ul className="navbar-nav me-auto ml-5 mb-2 mb-lg-0">
            <li className="nav-item">
              <a className="nav-link active" aria-current="page" href="/">Monitoring</a>
            </li>
            <li className="nav-item">
              <a className="nav-link" href="/">Control</a>
            </li>
              </ul>

        </div>
      </div>
    </nav>

    </div>
  )
}

export default Navbar
