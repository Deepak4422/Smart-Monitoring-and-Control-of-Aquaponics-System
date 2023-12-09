
import './App.css';
import Navbar from './Components/Navbar';
import Chart from './Components/Chart';

function App() {
  return (
    <div className="container">
   <div className="row" >
    <div className="col-md-5 " style={{margin:"auto"}}>
    <Navbar/>
    </div>
   </div>

    <div className="row">
     <div className="col">
     <Chart/>
     </div>
    </div>
    </div>
  );
}

export default App;
