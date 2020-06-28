/*
 * Generated by Bluespec Compiler (build 9f4a447)
 * 
 * On Thu Jun 11 14:05:09 IST 2020
 * 
 */

/* Generation options: keep-fires */
#ifndef __model_mkMult1Tb_h__
#define __model_mkMult1Tb_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkMult1Tb.h"

/* Class declaration for a model of mkMult1Tb */
class MODEL_mkMult1Tb : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkMult1Tb *mkMult1Tb_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkMult1Tb();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(unsigned int *year,
		   unsigned int *month,
		   char const **annotation,
		   char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkMult1Tb();
}

#endif /* ifndef __model_mkMult1Tb_h__ */