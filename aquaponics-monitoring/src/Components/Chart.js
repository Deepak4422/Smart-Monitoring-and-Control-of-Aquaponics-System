import React from 'react'

const Chart = () => {
  return (
    <div>
      
      <div className="container">
      <div class="row mb-3 mt-3">
      <div class="col-md-6">
        <div class="card" >
          <div id="chart-ammonia"></div>
          <div class="card-body">

          </div>
        </div>

      </div>
      <div class="col-md-6">
        <div class="card" >
          <div id="chart-nitrite"></div>
          <div class="card-body">

          </div>
        </div>
      </div>
    </div>


    <div class="row mb-3" >
      <div class="col-md-6" >
        <div class="card" >
          <div id="chart-nitrate" ></div>
          <div class="card-body" >

          </div>
        </div>
      </div>
      <div class="col-md-6">
        <div class="card" >
          <div id="chart-ph"></div>
          <div class="card-body">

          </div>
        </div>
      </div>
    </div>

    
    <div class="row ">
      <div class="col-md-6">
        <div class="card">
          <div id="chart-temperature"></div>
          <div class="card-body">

          </div>
        </div>
      </div>

    </div>
      </div>
    </div>
  )
}

export default Chart
