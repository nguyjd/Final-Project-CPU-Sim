# ECGR 2104 Final Project - Simpletron Computer Simulator

This is our verison of the Simpletron Computer Simulator.
This is a virtual computer that runs programs written in Simpletron Machine Language (SML).
This is a assignment for our ECGR 2104 class at UNCC.

<b>Project Members</b>
<ul>  
  <li>Jonathon Nguyen</li>
  <li>Jarrett long</li>
  <li>Marvin Kilgore</li>
  <li>Matthew Green</li>
</ul>

# Computer Features

<ul>  
  <li>Accumlator</li>
  <li>Data -> Words -> signed four digit number</li>
  <li>100 Word Memory</li>
  <li>First two digits -> operation code</li>
  <li>Last two digits -> address</li>
  <li>Input/Output System -> using terminal</li>
  <li>Instructions Sets</li>
  <li>Interface for inputing instruction</li>
  <li>Visualizing with Bridges</li>
</ul>

<b>Operation code</b>
<table style="width:100%">
  <tr>
    <th>Operation code</th>
    <th>Meaning</th>
  </tr>
  <tr>
    <th colspan="2">Input/output operations</th>
  </tr>
  <tr>
    <th>Read: 10</th>
    <th>Read a word from the keyboard into a specific location in memory.</th>
  </tr>
  <tr>
    <th>Write: 11</th>
    <th>Write a word from a specific location in memory to the screen.</th>
  </tr>
    <tr>
    <th colspan="2">Load/store operations</th>
  </tr>
  <tr>
    <th>Load: 20</th>
    <th>Load a word from a specific location in memory into the accumulator.</th>
  </tr>
  <tr>
    <th>Store: 21</th>
    <th>Store a word from the accumulator into a specific location in memory.</th>
  </tr>
    <tr>
    <th colspan="2">Arithmetic operations</th>
  </tr>
  <tr>
    <th>Add: 30</th>
    <th>Add a word from a specific location in memory to the word in the accumulator (leave the result in the accumulator).</th>
  </tr>
  <tr>
    <th>Subtract: 31</th>
    <th>Subtract a word from a specific location in memory from the word in the accumulator (leave the result in the accumulator).</th>
  </tr>
  <tr>
    <th>Divide: 32</th>
    <th>Divide a word from a specific location in memory into the word in the accumulator (leave result in the accumulator).</th>
  </tr>
  <tr>
    <th>Multiply: 33</th>
    <th>Multiply a word from a specific location in memory by the word in the accumulator (leave the result in the accumulator).</th>
  </tr>
    <tr>
    <th colspan="2">Transfer of control operations</th>
  </tr>
  <tr>
    <th>Branch: 40</th>
    <th>Branch to a specific location in memory.</th>
  </tr>
  <tr>
    <th>Branchneg: 41</th>
    <th>Branch to a specific location in memory if the accumulator is negative.</th>
  </tr>
  <tr>
    <th>Branchzero: 42</th>
    <th>Branch to a specific location in memory if the accumulator is zero.</th>
  </tr>
  <tr>
    <th>Halt: 43</th>
    <th>Halt. The program has completed its task.</th>
  </tr>
</table>
