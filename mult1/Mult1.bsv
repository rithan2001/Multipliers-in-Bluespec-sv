package Mult1; 

// Simple (naive) binary multiplier

import Mult::*;

(* synthesize *)
module mkMult1( Mult_IFC );
   Reg#(Bool)    available <- mkReg(True);
   Reg#(Tout)    product   <- mkReg(?);
   Reg#(Tout)    mcand     <- mkReg(?);
   Reg#(Tin)     mplr      <- mkReg(0);

   rule cycle ( mplr != 0 );
      if (mplr[0] == 1) product <= product + mcand;
      mcand   <= mcand << 1;
      mplr    <= mplr  >> 1;
   endrule

   method Action start(Tin m1, Tin m2) if ((mplr == 0) && available);
       product <= 0;
       mcand   <= {0, m1};
       mplr    <= m2;
       available <= False;
   endmethod

   method Tout result() if (mplr == 0);
      return product;
   endmethod

   method Action acknowledge() if ((mplr == 0) && !available);
      available <= True;
   endmethod
   
endmodule : mkMult1
   
endpackage : Mult1
