const Banner = () => {
    return (
        <div className="jumbotron jumbotron-fluid" id="banner" style={{ backgroundImage: "url('/tugas/img/banner-bk.jpg')" }}>
            <div className="container text-center text-md-left">
                <header>
                    <div className="row justify-content-between">
                        <div className="col-2">
                            <img src="/tugas/img/logo.png" alt="logo"/>
                        </div>
                        <div className="col-6 align-self-center text-right">
                            <a href="#" className="text-white lead">Get Early Access</a>
                        </div>
                    </div>
                </header>
                <h1 className="display-3 text-white font-weight-bold my-5">
                    A New Way<br />
                    To Start Business
                </h1>
                <p className="lead text-white my-4">
                    Lorem ipsum dolor sit amet, id nec enim autem oblique, ei dico mentitum duo.
                    <br /> Illum iusto laoreet his te. Lorem partiendo mel ex. Ad vitae admodum voluptatum per.
                </p>
                <a href="#" className="btn my-4 font-weight-bold atlas-cta cta-green">Get Started</a>
            </div>
        </div>
    );
}

export default Banner;