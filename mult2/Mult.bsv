package Mult; 

// Multiplier using Booth encoding

typedef Bit#(16) Tin;
typedef Bit#(32) Tout;

typedef Bit#(17) TinPlusOne;

interface Mult_IFC;
    method Action  start (Tin m1, Tin m2);
    method ActionValue#(Tout) result();
endinterface
        
endpackage
