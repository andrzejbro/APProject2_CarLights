#ifndef __c3_projekt2_h__
#define __c3_projekt2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc3_projekt2InstanceStruct
#define typedef_SFc3_projekt2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_battery_good;
  uint8_T c3_tp_stop;
  uint8_T c3_tp_Stop_lights_on;
  uint8_T c3_tp_Stop_lights_off;
  uint8_T c3_tp_high_beam_and_flash;
  uint8_T c3_tp_high_beam_on;
  uint8_T c3_tp_high_beam_off;
  uint8_T c3_tp_flash_to_pass_on;
  uint8_T c3_tp_low_park;
  uint8_T c3_tp_low_beam_on;
  uint8_T c3_tp_low_beam_off;
  uint8_T c3_tp_park_light_on;
  uint8_T c3_tp_reverse;
  uint8_T c3_tp_reverse_off;
  uint8_T c3_tp_reverse_on;
  uint8_T c3_tp_license_plate;
  uint8_T c3_tp_license_on;
  uint8_T c3_tp_license_off;
  uint8_T c3_tp_front_fog;
  uint8_T c3_tp_front_fog_off;
  uint8_T c3_tp_front_fog_on;
  uint8_T c3_tp_rear_fog;
  uint8_T c3_tp_rear_fog_on;
  uint8_T c3_tp_rear_fog_off;
  uint8_T c3_tp_turn;
  uint8_T c3_tp_turn_right_or_left;
  uint8_T c3_tp_turn_left_on1;
  uint8_T c3_tp_turn_off1;
  uint8_T c3_tp_turn_right_on1;
  uint8_T c3_tp_hazard_on;
  uint8_T c3_tp_battery_bad;
  uint8_T c3_tp_battery_error;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_projekt2;
  uint8_T c3_is_c3_projekt2;
  uint8_T c3_is_stop;
  uint8_T c3_is_active_stop;
  uint8_T c3_is_high_beam_and_flash;
  uint8_T c3_is_active_high_beam_and_flash;
  uint8_T c3_is_low_park;
  uint8_T c3_is_active_low_park;
  uint8_T c3_is_reverse;
  uint8_T c3_is_active_reverse;
  uint8_T c3_is_license_plate;
  uint8_T c3_is_active_license_plate;
  uint8_T c3_is_front_fog;
  uint8_T c3_is_active_front_fog;
  uint8_T c3_is_rear_fog;
  uint8_T c3_is_active_rear_fog;
  uint8_T c3_is_turn;
  uint8_T c3_is_active_turn;
  uint8_T c3_is_turn_right_or_left;
  boolean_T c3_dataWrittenToVector[12];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_dataSetLogObjVector[2];
  rtwCAPI_ModelMappingInfo c3_testPointMappingInfo;
  void *c3_testPointAddrMap[2];
  real_T *c3_battery;
  real_T *c3_low_beam;
  real_T *c3_b_stop;
  real_T *c3_reverse;
  real_T *c3_b_rear_fog;
  real_T *c3_h_led;
  real_T *c3_park_right;
  real_T *c3_license_plate;
  real_T *c3_turn_left;
  real_T *c3_park_left;
  real_T *c3_b_front_fog;
  real_T *c3_turn_right;
  real_T *c3_high_beam;
  real_T (*c3_wej)[9];
} SFc3_projekt2InstanceStruct;

#endif                                 /*typedef_SFc3_projekt2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_projekt2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_projekt2_get_check_sum(mxArray *plhs[]);
extern void c3_projekt2_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
