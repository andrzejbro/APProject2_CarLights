/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slLogLoadBlocksSfcnBridge.h"
#include <stddef.h>
#include "blas.h"
#include "projekt2_sfun.h"
#include "c3_projekt2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "projekt2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_battery_bad              ((uint8_T)1U)
#define c3_IN_battery_error            ((uint8_T)2U)
#define c3_IN_battery_good             ((uint8_T)3U)
#define c3_IN_Stop_lights_off          ((uint8_T)1U)
#define c3_IN_Stop_lights_on           ((uint8_T)2U)
#define c3_IN_flash_to_pass_on         ((uint8_T)1U)
#define c3_IN_high_beam_off            ((uint8_T)2U)
#define c3_IN_high_beam_on             ((uint8_T)3U)
#define c3_IN_low_beam_off             ((uint8_T)1U)
#define c3_IN_low_beam_on              ((uint8_T)2U)
#define c3_IN_park_light_on            ((uint8_T)3U)
#define c3_IN_reverse_off              ((uint8_T)1U)
#define c3_IN_reverse_on               ((uint8_T)2U)
#define c3_IN_license_off              ((uint8_T)1U)
#define c3_IN_license_on               ((uint8_T)2U)
#define c3_IN_front_fog_off            ((uint8_T)1U)
#define c3_IN_front_fog_on             ((uint8_T)2U)
#define c3_IN_rear_fog_off             ((uint8_T)1U)
#define c3_IN_rear_fog_on              ((uint8_T)2U)
#define c3_IN_hazard_on                ((uint8_T)1U)
#define c3_IN_turn_right_or_left       ((uint8_T)2U)
#define c3_IN_turn_left_on1            ((uint8_T)1U)
#define c3_IN_turn_off1                ((uint8_T)2U)
#define c3_IN_turn_right_on1           ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_w_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_wb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ac_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_dc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ec_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ic_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_jc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_oc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_rc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_tc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_uc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yc_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ad_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_dd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ed_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_id_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_jd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ld_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_md_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_od_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_rd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_me_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void initialize_params_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance);
static void enable_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void disable_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance);
static void set_sim_state_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_projekt2
  (SFc3_projekt2InstanceStruct *chartInstance);
static void finalize_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void sf_gateway_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void mdl_start_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void initSimStructsc3_projekt2(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_enter_internal_battery_good(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_battery_good(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_exit_internal_battery_good(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_stop(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_high_beam_and_flash(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_low_park(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_enter_atomic_low_beam_on(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_enter_atomic_low_beam_off(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_enter_atomic_park_light_on(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_front_fog(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_rear_fog(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_turn(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_enter_internal_turn_right_or_left(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_turn_right_or_left(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_exit_internal_turn_right_or_left(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_turn_right_on1(SFc3_projekt2InstanceStruct *chartInstance);
static void c3_enter_atomic_battery_bad(SFc3_projekt2InstanceStruct
  *chartInstance);
static void c3_enter_atomic_battery_error(SFc3_projekt2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_b_tp_battery_good, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_g_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[12]);
static void c3_h_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[12]);
static const mxArray *c3_i_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_test_point_addr_map(SFc3_projekt2InstanceStruct *chartInstance);
static void **get_test_point_address_map(SFc3_projekt2InstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc3_projekt2InstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector(SFc3_projekt2InstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_projekt2InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_projekt2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_projekt2(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_battery_bad = 0U;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c3_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c3_tp_battery_bad);
  chartInstance->c3_tp_battery_error = 0U;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c3_dataSetLogObjVector[1], 0, _sfTime_, (char_T *)
    &chartInstance->c3_tp_battery_error);
  chartInstance->c3_tp_battery_good = 0U;
  chartInstance->c3_is_active_front_fog = 0U;
  chartInstance->c3_is_front_fog = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_front_fog = 0U;
  chartInstance->c3_tp_front_fog_off = 0U;
  chartInstance->c3_tp_front_fog_on = 0U;
  chartInstance->c3_is_active_high_beam_and_flash = 0U;
  chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_high_beam_and_flash = 0U;
  chartInstance->c3_tp_flash_to_pass_on = 0U;
  chartInstance->c3_tp_high_beam_off = 0U;
  chartInstance->c3_tp_high_beam_on = 0U;
  chartInstance->c3_is_active_license_plate = 0U;
  chartInstance->c3_is_license_plate = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_license_plate = 0U;
  chartInstance->c3_tp_license_off = 0U;
  chartInstance->c3_tp_license_on = 0U;
  chartInstance->c3_is_active_low_park = 0U;
  chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_low_park = 0U;
  chartInstance->c3_tp_low_beam_off = 0U;
  chartInstance->c3_tp_low_beam_on = 0U;
  chartInstance->c3_tp_park_light_on = 0U;
  chartInstance->c3_is_active_rear_fog = 0U;
  chartInstance->c3_is_rear_fog = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_rear_fog = 0U;
  chartInstance->c3_tp_rear_fog_off = 0U;
  chartInstance->c3_tp_rear_fog_on = 0U;
  chartInstance->c3_is_active_reverse = 0U;
  chartInstance->c3_is_reverse = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_reverse = 0U;
  chartInstance->c3_tp_reverse_off = 0U;
  chartInstance->c3_tp_reverse_on = 0U;
  chartInstance->c3_is_active_stop = 0U;
  chartInstance->c3_is_stop = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_stop = 0U;
  chartInstance->c3_tp_Stop_lights_off = 0U;
  chartInstance->c3_tp_Stop_lights_on = 0U;
  chartInstance->c3_is_active_turn = 0U;
  chartInstance->c3_is_turn = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_turn = 0U;
  chartInstance->c3_tp_hazard_on = 0U;
  chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_turn_right_or_left = 0U;
  chartInstance->c3_tp_turn_left_on1 = 0U;
  chartInstance->c3_tp_turn_off1 = 0U;
  chartInstance->c3_tp_turn_right_on1 = 0U;
  chartInstance->c3_is_active_c3_projekt2 = 0U;
  chartInstance->c3_is_c3_projekt2 = c3_IN_NO_ACTIVE_CHILD;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_active_c3_projekt2 = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_c3_projekt2 = c3_IN_battery_bad;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_battery_bad = 1U;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c3_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c3_tp_battery_bad);
  c3_enter_atomic_battery_bad(chartInstance);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_projekt2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_projekt2 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_good) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_stop == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_stop == c3_IN_Stop_lights_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_stop == c3_IN_Stop_lights_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_high_beam_and_flash == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_high_beam_and_flash == c3_IN_high_beam_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_high_beam_and_flash == c3_IN_high_beam_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_high_beam_and_flash == c3_IN_flash_to_pass_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_low_park == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_low_park == c3_IN_low_beam_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_low_park == c3_IN_low_beam_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_low_park == c3_IN_park_light_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_reverse == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_reverse == c3_IN_reverse_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_reverse == c3_IN_reverse_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_license_plate == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_license_plate == c3_IN_license_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_license_plate == c3_IN_license_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_front_fog == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_front_fog == c3_IN_front_fog_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_front_fog == c3_IN_front_fog_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_rear_fog == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_rear_fog == c3_IN_rear_fog_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_rear_fog == c3_IN_rear_fog_off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_active_turn == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_turn == c3_IN_turn_right_or_left) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_left_on1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_off1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_right_on1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_turn == c3_IN_hazard_on) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_bad) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_error) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_projekt2(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_j_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_k_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_l_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_m_y = NULL;
  uint8_T c3_m_hoistedGlobal;
  uint8_T c3_m_u;
  const mxArray *c3_n_y = NULL;
  uint8_T c3_n_hoistedGlobal;
  uint8_T c3_n_u;
  const mxArray *c3_o_y = NULL;
  uint8_T c3_o_hoistedGlobal;
  uint8_T c3_o_u;
  const mxArray *c3_p_y = NULL;
  uint8_T c3_p_hoistedGlobal;
  uint8_T c3_p_u;
  const mxArray *c3_q_y = NULL;
  uint8_T c3_q_hoistedGlobal;
  uint8_T c3_q_u;
  const mxArray *c3_r_y = NULL;
  uint8_T c3_r_hoistedGlobal;
  uint8_T c3_r_u;
  const mxArray *c3_s_y = NULL;
  uint8_T c3_s_hoistedGlobal;
  uint8_T c3_s_u;
  const mxArray *c3_t_y = NULL;
  uint8_T c3_t_hoistedGlobal;
  uint8_T c3_t_u;
  const mxArray *c3_u_y = NULL;
  uint8_T c3_u_hoistedGlobal;
  uint8_T c3_u_u;
  const mxArray *c3_v_y = NULL;
  uint8_T c3_v_hoistedGlobal;
  uint8_T c3_v_u;
  const mxArray *c3_w_y = NULL;
  uint8_T c3_w_hoistedGlobal;
  uint8_T c3_w_u;
  const mxArray *c3_x_y = NULL;
  uint8_T c3_x_hoistedGlobal;
  uint8_T c3_x_u;
  const mxArray *c3_y_y = NULL;
  uint8_T c3_y_hoistedGlobal;
  uint8_T c3_y_u;
  const mxArray *c3_ab_y = NULL;
  uint8_T c3_ab_hoistedGlobal;
  uint8_T c3_ab_u;
  const mxArray *c3_bb_y = NULL;
  uint8_T c3_bb_hoistedGlobal;
  uint8_T c3_bb_u;
  const mxArray *c3_cb_y = NULL;
  uint8_T c3_cb_hoistedGlobal;
  uint8_T c3_cb_u;
  const mxArray *c3_db_y = NULL;
  uint8_T c3_db_hoistedGlobal;
  uint8_T c3_db_u;
  const mxArray *c3_eb_y = NULL;
  uint8_T c3_eb_hoistedGlobal;
  uint8_T c3_eb_u;
  const mxArray *c3_fb_y = NULL;
  uint8_T c3_fb_hoistedGlobal;
  uint8_T c3_fb_u;
  const mxArray *c3_gb_y = NULL;
  const mxArray *c3_hb_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(32, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_b_front_fog;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_h_led;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_high_beam;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *chartInstance->c3_license_plate;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *chartInstance->c3_low_beam;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *chartInstance->c3_park_left;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *chartInstance->c3_park_right;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *chartInstance->c3_b_rear_fog;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *chartInstance->c3_reverse;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *chartInstance->c3_b_stop;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = *chartInstance->c3_turn_left;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = *chartInstance->c3_turn_right;
  c3_l_u = c3_l_hoistedGlobal;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = chartInstance->c3_is_active_c3_projekt2;
  c3_m_u = c3_m_hoistedGlobal;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_n_hoistedGlobal = chartInstance->c3_is_active_reverse;
  c3_n_u = c3_n_hoistedGlobal;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_o_hoistedGlobal = chartInstance->c3_is_active_license_plate;
  c3_o_u = c3_o_hoistedGlobal;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_p_hoistedGlobal = chartInstance->c3_is_active_high_beam_and_flash;
  c3_p_u = c3_p_hoistedGlobal;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_q_hoistedGlobal = chartInstance->c3_is_active_stop;
  c3_q_u = c3_q_hoistedGlobal;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_hoistedGlobal = chartInstance->c3_is_active_rear_fog;
  c3_r_u = c3_r_hoistedGlobal;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_s_hoistedGlobal = chartInstance->c3_is_active_front_fog;
  c3_s_u = c3_s_hoistedGlobal;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_t_hoistedGlobal = chartInstance->c3_is_active_low_park;
  c3_t_u = c3_t_hoistedGlobal;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_u_hoistedGlobal = chartInstance->c3_is_active_turn;
  c3_u_u = c3_u_hoistedGlobal;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_v_hoistedGlobal = chartInstance->c3_is_c3_projekt2;
  c3_v_u = c3_v_hoistedGlobal;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 21, c3_w_y);
  c3_w_hoistedGlobal = chartInstance->c3_is_reverse;
  c3_w_u = c3_w_hoistedGlobal;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 22, c3_x_y);
  c3_x_hoistedGlobal = chartInstance->c3_is_license_plate;
  c3_x_u = c3_x_hoistedGlobal;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_x_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 23, c3_y_y);
  c3_y_hoistedGlobal = chartInstance->c3_is_high_beam_and_flash;
  c3_y_u = c3_y_hoistedGlobal;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_y_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 24, c3_ab_y);
  c3_ab_hoistedGlobal = chartInstance->c3_is_turn_right_or_left;
  c3_ab_u = c3_ab_hoistedGlobal;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_ab_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 25, c3_bb_y);
  c3_bb_hoistedGlobal = chartInstance->c3_is_stop;
  c3_bb_u = c3_bb_hoistedGlobal;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_bb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 26, c3_cb_y);
  c3_cb_hoistedGlobal = chartInstance->c3_is_rear_fog;
  c3_cb_u = c3_cb_hoistedGlobal;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_cb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 27, c3_db_y);
  c3_db_hoistedGlobal = chartInstance->c3_is_front_fog;
  c3_db_u = c3_db_hoistedGlobal;
  c3_eb_y = NULL;
  sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_db_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 28, c3_eb_y);
  c3_eb_hoistedGlobal = chartInstance->c3_is_low_park;
  c3_eb_u = c3_eb_hoistedGlobal;
  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_eb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 29, c3_fb_y);
  c3_fb_hoistedGlobal = chartInstance->c3_is_turn;
  c3_fb_u = c3_fb_hoistedGlobal;
  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_fb_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 30, c3_gb_y);
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c3_y, 31, c3_hb_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[12];
  int32_T c3_i0;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_b_front_fog = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("front_fog", c3_u, 0)), "front_fog");
  *chartInstance->c3_h_led = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("h_led", c3_u, 1)), "h_led");
  *chartInstance->c3_high_beam = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("high_beam", c3_u, 2)), "high_beam");
  *chartInstance->c3_license_plate = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("license_plate", c3_u, 3)), "license_plate");
  *chartInstance->c3_low_beam = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("low_beam", c3_u, 4)), "low_beam");
  *chartInstance->c3_park_left = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("park_left", c3_u, 5)), "park_left");
  *chartInstance->c3_park_right = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("park_right", c3_u, 6)), "park_right");
  *chartInstance->c3_b_rear_fog = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rear_fog", c3_u, 7)), "rear_fog");
  *chartInstance->c3_reverse = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("reverse", c3_u, 8)), "reverse");
  *chartInstance->c3_b_stop = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("stop", c3_u, 9)), "stop");
  *chartInstance->c3_turn_left = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("turn_left", c3_u, 10)), "turn_left");
  *chartInstance->c3_turn_right = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("turn_right", c3_u, 11)), "turn_right");
  chartInstance->c3_is_active_c3_projekt2 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c3_projekt2", c3_u, 12)),
    "is_active_c3_projekt2");
  chartInstance->c3_is_active_reverse = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_reverse", c3_u, 13)),
    "is_active_reverse");
  chartInstance->c3_is_active_license_plate = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_license_plate", c3_u,
       14)), "is_active_license_plate");
  chartInstance->c3_is_active_high_beam_and_flash = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_high_beam_and_flash",
       c3_u, 15)), "is_active_high_beam_and_flash");
  chartInstance->c3_is_active_stop = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_stop", c3_u, 16)), "is_active_stop");
  chartInstance->c3_is_active_rear_fog = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_rear_fog", c3_u, 17)),
    "is_active_rear_fog");
  chartInstance->c3_is_active_front_fog = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_front_fog", c3_u, 18)),
    "is_active_front_fog");
  chartInstance->c3_is_active_low_park = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_low_park", c3_u, 19)),
    "is_active_low_park");
  chartInstance->c3_is_active_turn = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_turn", c3_u, 20)), "is_active_turn");
  chartInstance->c3_is_c3_projekt2 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c3_projekt2", c3_u, 21)), "is_c3_projekt2");
  chartInstance->c3_is_reverse = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_reverse", c3_u, 22)), "is_reverse");
  chartInstance->c3_is_license_plate = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_license_plate", c3_u, 23)), "is_license_plate");
  chartInstance->c3_is_high_beam_and_flash = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_high_beam_and_flash", c3_u, 24)),
    "is_high_beam_and_flash");
  chartInstance->c3_is_turn_right_or_left = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_turn_right_or_left", c3_u, 25)),
    "is_turn_right_or_left");
  chartInstance->c3_is_stop = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_stop", c3_u, 26)), "is_stop");
  chartInstance->c3_is_rear_fog = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_rear_fog", c3_u, 27)), "is_rear_fog");
  chartInstance->c3_is_front_fog = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_front_fog", c3_u, 28)), "is_front_fog");
  chartInstance->c3_is_low_park = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_low_park", c3_u, 29)), "is_low_park");
  chartInstance->c3_is_turn = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("is_turn", c3_u, 30)), "is_turn");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 31)), "dataWrittenToVector", c3_bv0);
  for (c3_i0 = 0; c3_i0 < 12; c3_i0++) {
    chartInstance->c3_dataWrittenToVector[c3_i0] = c3_bv0[c3_i0];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 32)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_projekt2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_projekt2
  (SFc3_projekt2InstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_tp_battery_bad = (uint8_T)
      (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_bad);
    chartInstance->c3_tp_battery_error = (uint8_T)
      (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_error);
    chartInstance->c3_tp_battery_good = (uint8_T)
      (chartInstance->c3_is_c3_projekt2 == c3_IN_battery_good);
    chartInstance->c3_tp_stop = (uint8_T)(chartInstance->c3_is_active_stop == 1U);
    chartInstance->c3_tp_Stop_lights_off = (uint8_T)(chartInstance->c3_is_stop ==
      c3_IN_Stop_lights_off);
    chartInstance->c3_tp_Stop_lights_on = (uint8_T)(chartInstance->c3_is_stop ==
      c3_IN_Stop_lights_on);
    chartInstance->c3_tp_low_park = (uint8_T)
      (chartInstance->c3_is_active_low_park == 1U);
    chartInstance->c3_tp_low_beam_off = (uint8_T)(chartInstance->c3_is_low_park ==
      c3_IN_low_beam_off);
    chartInstance->c3_tp_low_beam_on = (uint8_T)(chartInstance->c3_is_low_park ==
      c3_IN_low_beam_on);
    chartInstance->c3_tp_park_light_on = (uint8_T)(chartInstance->c3_is_low_park
      == c3_IN_park_light_on);
    chartInstance->c3_tp_turn = (uint8_T)(chartInstance->c3_is_active_turn == 1U);
    chartInstance->c3_tp_hazard_on = (uint8_T)(chartInstance->c3_is_turn ==
      c3_IN_hazard_on);
    chartInstance->c3_tp_turn_right_or_left = (uint8_T)
      (chartInstance->c3_is_turn == c3_IN_turn_right_or_left);
    chartInstance->c3_tp_turn_left_on1 = (uint8_T)
      (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_left_on1);
    chartInstance->c3_tp_turn_off1 = (uint8_T)
      (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_off1);
    chartInstance->c3_tp_turn_right_on1 = (uint8_T)
      (chartInstance->c3_is_turn_right_or_left == c3_IN_turn_right_on1);
    chartInstance->c3_tp_front_fog = (uint8_T)
      (chartInstance->c3_is_active_front_fog == 1U);
    chartInstance->c3_tp_front_fog_off = (uint8_T)
      (chartInstance->c3_is_front_fog == c3_IN_front_fog_off);
    chartInstance->c3_tp_front_fog_on = (uint8_T)(chartInstance->c3_is_front_fog
      == c3_IN_front_fog_on);
    chartInstance->c3_tp_rear_fog = (uint8_T)
      (chartInstance->c3_is_active_rear_fog == 1U);
    chartInstance->c3_tp_rear_fog_off = (uint8_T)(chartInstance->c3_is_rear_fog ==
      c3_IN_rear_fog_off);
    chartInstance->c3_tp_rear_fog_on = (uint8_T)(chartInstance->c3_is_rear_fog ==
      c3_IN_rear_fog_on);
    chartInstance->c3_tp_license_plate = (uint8_T)
      (chartInstance->c3_is_active_license_plate == 1U);
    chartInstance->c3_tp_license_off = (uint8_T)
      (chartInstance->c3_is_license_plate == c3_IN_license_off);
    chartInstance->c3_tp_license_on = (uint8_T)
      (chartInstance->c3_is_license_plate == c3_IN_license_on);
    chartInstance->c3_tp_reverse = (uint8_T)(chartInstance->c3_is_active_reverse
      == 1U);
    chartInstance->c3_tp_reverse_off = (uint8_T)(chartInstance->c3_is_reverse ==
      c3_IN_reverse_off);
    chartInstance->c3_tp_reverse_on = (uint8_T)(chartInstance->c3_is_reverse ==
      c3_IN_reverse_on);
    chartInstance->c3_tp_high_beam_and_flash = (uint8_T)
      (chartInstance->c3_is_active_high_beam_and_flash == 1U);
    chartInstance->c3_tp_flash_to_pass_on = (uint8_T)
      (chartInstance->c3_is_high_beam_and_flash == c3_IN_flash_to_pass_on);
    chartInstance->c3_tp_high_beam_off = (uint8_T)
      (chartInstance->c3_is_high_beam_and_flash == c3_IN_high_beam_off);
    chartInstance->c3_tp_high_beam_on = (uint8_T)
      (chartInstance->c3_is_high_beam_and_flash == c3_IN_high_beam_on);
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  int32_T c3_i1;
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c3_set_sim_state_side_effects_c3_projekt2(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 9; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_wej)[c3_i1], 1U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_battery, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_c3_projekt2) {
   case c3_IN_battery_bad:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ed_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard2 = false;
    if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
          *chartInstance->c3_battery, 0.0, -1, 2U, *chartInstance->c3_battery <
          0.0))) {
      guard2 = true;
    } else if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
                 *chartInstance->c3_battery, 26.0, -1, 4U,
                 *chartInstance->c3_battery > 26.0))) {
      guard2 = true;
    } else {
      CV_EML_MCDC(1, 0, 0, false);
      CV_EML_IF(1, 0, 0, false);
      c3_out = false;
    }

    if (guard2 == true) {
      CV_EML_MCDC(1, 0, 0, true);
      CV_EML_IF(1, 0, 0, true);
      c3_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_battery_bad = 0U;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c3_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
        &chartInstance->c3_tp_battery_bad);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_projekt2 = c3_IN_battery_error;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_battery_error = 1U;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c3_dataSetLogObjVector[1], 0, _sfTime_, (char_T *)
        &chartInstance->c3_tp_battery_error);
      c3_enter_atomic_battery_error(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cd_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
            *chartInstance->c3_battery, 6.0, -1, 5U, *chartInstance->c3_battery >=
            6.0))) {
        if (CV_EML_COND(0, 0, 1, CV_RELATIONAL_EVAL(5U, 0U, 1,
              *chartInstance->c3_battery, 18.0, -1, 3U,
              *chartInstance->c3_battery <= 18.0))) {
          CV_EML_MCDC(0, 0, 0, true);
          CV_EML_IF(0, 0, 0, true);
          c3_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(0, 0, 0, false);
        CV_EML_IF(0, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_battery_bad = 0U;
        ssLoggerUpdateTimeseries(chartInstance->S,
          chartInstance->c3_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
          &chartInstance->c3_tp_battery_bad);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_projekt2 = c3_IN_battery_good;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_battery_good = 1U;
        c3_enter_internal_battery_good(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_battery_error:
    CV_CHART_EVAL(0, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_battery_good:
    CV_CHART_EVAL(0, 0, 3);
    c3_battery_good(chartInstance);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_c3_projekt2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_projekt2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_projekt2(SFc3_projekt2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_internal_battery_good(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  chartInstance->c3_is_active_stop = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_stop = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_stop = c3_IN_Stop_lights_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_Stop_lights_off = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_stop = 0.0;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 4U, 24U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c3_is_active_low_park = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_low_park = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_low_park = c3_IN_low_beam_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_low_beam_off = 1U;
  c3_enter_atomic_low_beam_off(chartInstance);
  chartInstance->c3_is_active_turn = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_turn = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_turn = c3_IN_turn_right_or_left;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_turn_right_or_left = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_q_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_h_led = 0.0;
  chartInstance->c3_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 4U, 28U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  c3_enter_internal_turn_right_or_left(chartInstance);
  chartInstance->c3_is_active_front_fog = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_front_fog = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_front_fog = c3_IN_front_fog_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_front_fog_off = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_front_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 4U, 4U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c3_is_active_rear_fog = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_rear_fog = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_rear_fog = c3_IN_rear_fog_on;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_rear_fog_on = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_o_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_rear_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 4U, 19U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c3_is_active_license_plate = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_license_plate = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_license_plate = c3_IN_license_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_license_off = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_license_plate = 0.0;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 4U, 11U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c3_is_active_reverse = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_reverse = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_reverse = c3_IN_reverse_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_reverse_off = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_reverse = 0.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 4U, 21U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c3_is_active_high_beam_and_flash = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_high_beam_and_flash = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_high_beam_and_flash = c3_IN_high_beam_off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_high_beam_off = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_high_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[11U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 8U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_battery_good(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_dd_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  guard4 = false;
  guard5 = false;
  guard6 = false;
  if (CV_EML_COND(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0,
        *chartInstance->c3_battery, 0.0, -1, 5U, *chartInstance->c3_battery >=
        0.0))) {
    if (CV_EML_COND(2, 0, 1, CV_RELATIONAL_EVAL(5U, 2U, 1,
          *chartInstance->c3_battery, 6.0, -1, 2U, *chartInstance->c3_battery <
          6.0))) {
      guard5 = true;
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    if (CV_EML_COND(2, 0, 2, CV_RELATIONAL_EVAL(5U, 2U, 2,
          *chartInstance->c3_battery, 18.0, -1, 4U, *chartInstance->c3_battery >
          18.0))) {
      if (CV_EML_COND(2, 0, 3, CV_RELATIONAL_EVAL(5U, 2U, 3,
            *chartInstance->c3_battery, 26.0, -1, 3U, *chartInstance->c3_battery
            <= 26.0))) {
        guard5 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }
  }

  if (guard5 == true) {
    CV_EML_MCDC(2, 0, 0, true);
    CV_EML_IF(2, 0, 0, true);
    c3_out = true;
  }

  if (guard4 == true) {
    CV_EML_MCDC(2, 0, 0, false);
    CV_EML_IF(2, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    c3_exit_internal_battery_good(chartInstance);
    chartInstance->c3_tp_battery_good = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_projekt2 = c3_IN_battery_bad;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_battery_bad = 1U;
    ssLoggerUpdateTimeseries(chartInstance->S,
      chartInstance->c3_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
      &chartInstance->c3_tp_battery_bad);
    c3_enter_atomic_battery_bad(chartInstance);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_fd_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard3 = false;
    if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
          *chartInstance->c3_battery, 0.0, -1, 2U, *chartInstance->c3_battery <
          0.0))) {
      guard3 = true;
    } else if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
                 *chartInstance->c3_battery, 26.0, -1, 4U,
                 *chartInstance->c3_battery > 26.0))) {
      guard3 = true;
    } else {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c3_b_out = false;
    }

    if (guard3 == true) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c3_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      c3_exit_internal_battery_good(chartInstance);
      chartInstance->c3_tp_battery_good = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_projekt2 = c3_IN_battery_error;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_battery_error = 1U;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c3_dataSetLogObjVector[1], 0, _sfTime_, (char_T *)
        &chartInstance->c3_tp_battery_error);
      c3_enter_atomic_battery_error(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c3_sfEvent);
      c3_stop(chartInstance);
      c3_low_park(chartInstance);
      c3_turn(chartInstance);
      c3_front_fog(chartInstance);
      c3_rear_fog(chartInstance);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c3_sfEvent);
      switch (chartInstance->c3_is_license_plate) {
       case c3_IN_license_off:
        CV_STATE_EVAL(10, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_oc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_c_out = CV_EML_IF(34, 0, 0, CV_RELATIONAL_EVAL(5U, 34U, 0,
          (*chartInstance->c3_wej)[2], 0.0, -1, 1U, (*chartInstance->c3_wej)[2]
          != 0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_license_off = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_license_plate = c3_IN_license_on;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_license_on = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_license_plate = 1.0;
          chartInstance->c3_dataWrittenToVector[6U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 4U, 12U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                       chartInstance->c3_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c3_sfEvent);
        break;

       case c3_IN_license_on:
        CV_STATE_EVAL(10, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 35U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_nc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_d_out = CV_EML_IF(35, 0, 0, CV_RELATIONAL_EVAL(5U, 35U, 0,
          (*chartInstance->c3_wej)[2], 0.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
          0.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_license_on = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_license_plate = c3_IN_license_off;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_license_off = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_license_plate = 0.0;
          chartInstance->c3_dataWrittenToVector[6U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 4U, 11U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                       chartInstance->c3_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c3_sfEvent);
        break;

       default:
        CV_STATE_EVAL(10, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_license_plate = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c3_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c3_sfEvent);
      switch (chartInstance->c3_is_reverse) {
       case c3_IN_reverse_off:
        CV_STATE_EVAL(20, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_lc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(16, 0, 0, CV_RELATIONAL_EVAL(5U, 16U, 0,
              (*chartInstance->c3_wej)[5], 6.0, -1, 0U, (*chartInstance->c3_wej)
              [5] == 6.0))) {
          if (CV_EML_COND(16, 0, 1, CV_RELATIONAL_EVAL(5U, 16U, 1,
                (*chartInstance->c3_wej)[4], 2.0, -1, 0U,
                (*chartInstance->c3_wej)[4] == 2.0))) {
            CV_EML_MCDC(16, 0, 0, true);
            CV_EML_IF(16, 0, 0, true);
            c3_e_out = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(16, 0, 0, false);
          CV_EML_IF(16, 0, 0, false);
          c3_e_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_reverse_off = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_reverse = c3_IN_reverse_on;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_reverse_on = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_reverse = 1.0;
          chartInstance->c3_dataWrittenToVector[2U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 4U, 22U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                       chartInstance->c3_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c3_sfEvent);
        break;

       case c3_IN_reverse_on:
        CV_STATE_EVAL(20, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_mc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(17, 0, 0, CV_RELATIONAL_EVAL(5U, 17U, 0,
              (*chartInstance->c3_wej)[5], 6.0, -1, 1U, (*chartInstance->c3_wej)
              [5] != 6.0))) {
          if (CV_EML_COND(17, 0, 1, CV_RELATIONAL_EVAL(5U, 17U, 1,
                (*chartInstance->c3_wej)[4], 2.0, -1, 1U,
                (*chartInstance->c3_wej)[4] != 2.0))) {
            CV_EML_MCDC(17, 0, 0, true);
            CV_EML_IF(17, 0, 0, true);
            c3_f_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(17, 0, 0, false);
          CV_EML_IF(17, 0, 0, false);
          c3_f_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_reverse_on = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_reverse = c3_IN_reverse_off;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_reverse_off = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_reverse = 0.0;
          chartInstance->c3_dataWrittenToVector[2U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 4U, 21U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                       chartInstance->c3_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c3_sfEvent);
        break;

       default:
        CV_STATE_EVAL(20, 0, 0);

        /* Unreachable state, for coverage only */
        chartInstance->c3_is_reverse = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c3_sfEvent);
      c3_high_beam_and_flash(chartInstance);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_battery_good(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_high_beam_and_flash) {
   case c3_IN_flash_to_pass_on:
    CV_STATE_EVAL(6, 1, 1);
    chartInstance->c3_tp_flash_to_pass_on = 0U;
    chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_high_beam_off:
    CV_STATE_EVAL(6, 1, 2);
    chartInstance->c3_tp_high_beam_off = 0U;
    chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_high_beam_on:
    CV_STATE_EVAL(6, 1, 3);
    chartInstance->c3_tp_high_beam_on = 0U;
    chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_high_beam_and_flash = 0U;
  chartInstance->c3_is_active_high_beam_and_flash = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_reverse) {
   case c3_IN_reverse_off:
    CV_STATE_EVAL(20, 1, 1);
    chartInstance->c3_tp_reverse_off = 0U;
    chartInstance->c3_is_reverse = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_reverse_on:
    CV_STATE_EVAL(20, 1, 2);
    chartInstance->c3_tp_reverse_on = 0U;
    chartInstance->c3_is_reverse = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(20, 1, 0);
    chartInstance->c3_is_reverse = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_reverse = 0U;
  chartInstance->c3_is_active_reverse = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_license_plate) {
   case c3_IN_license_off:
    CV_STATE_EVAL(10, 1, 1);
    chartInstance->c3_tp_license_off = 0U;
    chartInstance->c3_is_license_plate = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_license_on:
    CV_STATE_EVAL(10, 1, 2);
    chartInstance->c3_tp_license_on = 0U;
    chartInstance->c3_is_license_plate = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 1, 0);
    chartInstance->c3_is_license_plate = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_license_plate = 0U;
  chartInstance->c3_is_active_license_plate = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_rear_fog) {
   case c3_IN_rear_fog_off:
    CV_STATE_EVAL(17, 1, 1);
    chartInstance->c3_tp_rear_fog_off = 0U;
    chartInstance->c3_is_rear_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_rear_fog_on:
    CV_STATE_EVAL(17, 1, 2);
    chartInstance->c3_tp_rear_fog_on = 0U;
    chartInstance->c3_is_rear_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 1, 0);
    chartInstance->c3_is_rear_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_rear_fog = 0U;
  chartInstance->c3_is_active_rear_fog = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_front_fog) {
   case c3_IN_front_fog_off:
    CV_STATE_EVAL(3, 1, 1);
    chartInstance->c3_tp_front_fog_off = 0U;
    chartInstance->c3_is_front_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_front_fog_on:
    CV_STATE_EVAL(3, 1, 2);
    chartInstance->c3_tp_front_fog_on = 0U;
    chartInstance->c3_is_front_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 1, 0);
    chartInstance->c3_is_front_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_front_fog = 0U;
  chartInstance->c3_is_active_front_fog = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_turn) {
   case c3_IN_hazard_on:
    CV_STATE_EVAL(26, 1, 1);
    chartInstance->c3_tp_hazard_on = 0U;
    chartInstance->c3_is_turn = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_turn_right_or_left:
    CV_STATE_EVAL(26, 1, 2);
    c3_exit_internal_turn_right_or_left(chartInstance);
    chartInstance->c3_tp_turn_right_or_left = 0U;
    chartInstance->c3_is_turn = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(26, 1, 0);
    chartInstance->c3_is_turn = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_turn = 0U;
  chartInstance->c3_is_active_turn = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_low_park) {
   case c3_IN_low_beam_off:
    CV_STATE_EVAL(13, 1, 1);
    chartInstance->c3_tp_low_beam_off = 0U;
    chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_low_beam_on:
    CV_STATE_EVAL(13, 1, 2);
    chartInstance->c3_tp_low_beam_on = 0U;
    chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_park_light_on:
    CV_STATE_EVAL(13, 1, 3);
    chartInstance->c3_tp_park_light_on = 0U;
    chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(13, 1, 0);
    chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_low_park = 0U;
  chartInstance->c3_is_active_low_park = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_stop) {
   case c3_IN_Stop_lights_off:
    CV_STATE_EVAL(23, 1, 1);
    chartInstance->c3_tp_Stop_lights_off = 0U;
    chartInstance->c3_is_stop = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stop_lights_on:
    CV_STATE_EVAL(23, 1, 2);
    chartInstance->c3_tp_Stop_lights_on = 0U;
    chartInstance->c3_is_stop = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(23, 1, 0);
    chartInstance->c3_is_stop = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
    break;
  }

  chartInstance->c3_tp_stop = 0U;
  chartInstance->c3_is_active_stop = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
}

static void c3_stop(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_stop) {
   case c3_IN_Stop_lights_off:
    CV_STATE_EVAL(23, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
      (*chartInstance->c3_wej)[7], 1.0, -1, 0U, (*chartInstance->c3_wej)[7] ==
      1.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Stop_lights_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_stop = c3_IN_Stop_lights_on;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Stop_lights_on = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_stop = 1.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 4U, 25U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Stop_lights_on:
    CV_STATE_EVAL(23, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_b_out = CV_EML_IF(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
      (*chartInstance->c3_wej)[7], 0.0, -1, 0U, (*chartInstance->c3_wej)[7] ==
      0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Stop_lights_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_stop = c3_IN_Stop_lights_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_Stop_lights_off = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_stop = 0.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 4U, 24U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 25U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(23, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_stop = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, chartInstance->c3_sfEvent);
}

static void c3_high_beam_and_flash(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_high_beam_and_flash) {
   case c3_IN_flash_to_pass_on:
    CV_STATE_EVAL(6, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ec_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard6 = false;
    if (CV_EML_COND(41, 0, 0, CV_RELATIONAL_EVAL(5U, 41U, 0,
          (*chartInstance->c3_wej)[6], 0.0, -1, 0U, (*chartInstance->c3_wej)[6] ==
          0.0))) {
      guard6 = true;
    } else if (CV_EML_COND(41, 0, 1, CV_RELATIONAL_EVAL(5U, 41U, 1,
                 (*chartInstance->c3_wej)[4], 2.0, -1, 1U,
                 (*chartInstance->c3_wej)[4] != 2.0))) {
      guard6 = true;
    } else {
      CV_EML_MCDC(41, 0, 0, false);
      CV_EML_IF(41, 0, 0, false);
      c3_out = false;
    }

    if (guard6 == true) {
      CV_EML_MCDC(41, 0, 0, true);
      CV_EML_IF(41, 0, 0, true);
      c3_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_flash_to_pass_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_high_beam_and_flash = c3_IN_high_beam_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_high_beam_off = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_high_beam = 0.0;
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 8U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard5 = false;
      if (CV_EML_COND(43, 0, 0, CV_RELATIONAL_EVAL(5U, 43U, 0,
            (*chartInstance->c3_wej)[6], 1.0, -1, 0U, (*chartInstance->c3_wej)[6]
            == 1.0))) {
        if (CV_EML_COND(43, 0, 1, CV_RELATIONAL_EVAL(5U, 43U, 1,
              (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)
              [2] == 1.0))) {
          CV_EML_MCDC(43, 0, 0, true);
          CV_EML_IF(43, 0, 0, true);
          c3_b_out = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }

      if (guard5 == true) {
        CV_EML_MCDC(43, 0, 0, false);
        CV_EML_IF(43, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_flash_to_pass_on = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_high_beam_and_flash = c3_IN_high_beam_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_high_beam_on = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_high_beam = 1.0;
        chartInstance->c3_dataWrittenToVector[11U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 9U,
                              chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_high_beam_off:
    CV_STATE_EVAL(6, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_yb_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard3 = false;
    guard4 = false;
    if (CV_EML_COND(14, 0, 0, CV_RELATIONAL_EVAL(5U, 14U, 0,
          (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
          1.0))) {
      if (CV_EML_COND(14, 0, 1, CV_RELATIONAL_EVAL(5U, 14U, 1,
            (*chartInstance->c3_wej)[6], 1.0, -1, 0U, (*chartInstance->c3_wej)[6]
            == 1.0))) {
        if (CV_EML_COND(14, 0, 2, CV_RELATIONAL_EVAL(5U, 14U, 2,
              (*chartInstance->c3_wej)[4], 2.0, -1, 0U, (*chartInstance->c3_wej)
              [4] == 2.0))) {
          CV_EML_MCDC(14, 0, 0, true);
          CV_EML_IF(14, 0, 0, true);
          c3_c_out = true;
        } else {
          guard3 = true;
        }
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }

    if (guard4 == true) {
      guard3 = true;
    }

    if (guard3 == true) {
      CV_EML_MCDC(14, 0, 0, false);
      CV_EML_IF(14, 0, 0, false);
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_high_beam_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_high_beam_and_flash = c3_IN_high_beam_on;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_high_beam_on = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_high_beam = 1.0;
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 9U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_dc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(40, 0, 0, CV_RELATIONAL_EVAL(5U, 40U, 0,
            (*chartInstance->c3_wej)[6], 2.0, -1, 0U, (*chartInstance->c3_wej)[6]
            == 2.0))) {
        if (CV_EML_COND(40, 0, 1, CV_RELATIONAL_EVAL(5U, 40U, 1,
              (*chartInstance->c3_wej)[4], 2.0, -1, 0U, (*chartInstance->c3_wej)
              [4] == 2.0))) {
          CV_EML_MCDC(40, 0, 0, true);
          CV_EML_IF(40, 0, 0, true);
          c3_d_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(40, 0, 0, false);
        CV_EML_IF(40, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_high_beam_off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_high_beam_and_flash = c3_IN_flash_to_pass_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_flash_to_pass_on = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_high_beam = 1.0;
        chartInstance->c3_dataWrittenToVector[11U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 7U,
                              chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_high_beam_on:
    CV_STATE_EVAL(6, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ac_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(15, 0, 0, CV_RELATIONAL_EVAL(5U, 15U, 0,
          (*chartInstance->c3_wej)[6], 0.0, -1, 0U, (*chartInstance->c3_wej)[6] ==
          0.0))) {
      guard1 = true;
    } else if (CV_EML_COND(15, 0, 1, CV_RELATIONAL_EVAL(5U, 15U, 1,
                 (*chartInstance->c3_wej)[4], 2.0, -1, 1U,
                 (*chartInstance->c3_wej)[4] != 2.0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(15, 0, 0, false);
      CV_EML_IF(15, 0, 0, false);
      c3_e_out = false;
    }

    if (guard1 == true) {
      CV_EML_MCDC(15, 0, 0, true);
      CV_EML_IF(15, 0, 0, true);
      c3_e_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_high_beam_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_high_beam_and_flash = c3_IN_high_beam_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_high_beam_off = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_high_beam = 0.0;
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 8U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_f_out = CV_EML_IF(42, 0, 0, CV_RELATIONAL_EVAL(5U, 42U, 0,
        (*chartInstance->c3_wej)[6], 2.0, -1, 0U, (*chartInstance->c3_wej)[6] ==
        2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_high_beam_on = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_high_beam_and_flash = c3_IN_flash_to_pass_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_flash_to_pass_on = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_high_beam = 1.0;
        chartInstance->c3_dataWrittenToVector[11U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 7U,
                              chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_high_beam_and_flash = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
}

static void c3_low_park(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_f_out;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_low_park) {
   case c3_IN_low_beam_off:
    CV_STATE_EVAL(13, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_kc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(30, 0, 0, CV_RELATIONAL_EVAL(5U, 30U, 0,
      (*chartInstance->c3_wej)[2], 2.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
      2.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low_beam_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_low_park = c3_IN_park_light_on;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_park_light_on = 1U;
      c3_enter_atomic_park_light_on(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 31U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_hc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_b_out = CV_EML_IF(31, 0, 0, CV_RELATIONAL_EVAL(5U, 31U, 0,
        (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
        1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low_beam_off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_low_park = c3_IN_low_beam_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low_beam_on = 1U;
        c3_enter_atomic_low_beam_on(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_low_beam_on:
    CV_STATE_EVAL(13, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ic_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_c_out = CV_EML_IF(26, 0, 0, CV_RELATIONAL_EVAL(5U, 26U, 0,
      (*chartInstance->c3_wej)[2], 0.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
      0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low_beam_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_low_park = c3_IN_low_beam_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low_beam_off = 1U;
      c3_enter_atomic_low_beam_off(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_gc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_d_out = CV_EML_IF(25, 0, 0, CV_RELATIONAL_EVAL(5U, 25U, 0,
        (*chartInstance->c3_wej)[2], 2.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
        2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low_beam_on = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_low_park = c3_IN_park_light_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_park_light_on = 1U;
        c3_enter_atomic_park_light_on(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_park_light_on:
    CV_STATE_EVAL(13, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_jc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_e_out = CV_EML_IF(28, 0, 0, CV_RELATIONAL_EVAL(5U, 28U, 0,
      (*chartInstance->c3_wej)[2], 0.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
      0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_park_light_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_low_park = c3_IN_low_beam_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_low_beam_off = 1U;
      c3_enter_atomic_low_beam_off(chartInstance);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_fc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_f_out = CV_EML_IF(29, 0, 0, CV_RELATIONAL_EVAL(5U, 29U, 0,
        (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)[2] ==
        1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_park_light_on = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_low_park = c3_IN_low_beam_on;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_low_beam_on = 1U;
        c3_enter_atomic_low_beam_on(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(13, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_low_park = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_low_beam_on(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_low_beam = 1.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 4U, 15U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_park_left = 1.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 4U, 15U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_park_right = 1.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 4U, 15U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_low_beam_off(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_low_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 4U, 14U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_park_left = 0.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 4U, 14U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_park_right = 0.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 4U, 14U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_park_light_on(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_park_left = 1.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 4U, 16U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_park_right = 1.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 4U, 16U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_low_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 4U, 16U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_front_fog(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_front_fog) {
   case c3_IN_front_fog_off:
    CV_STATE_EVAL(3, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    if (CV_EML_COND(23, 0, 0, CV_RELATIONAL_EVAL(5U, 23U, 0,
          (*chartInstance->c3_wej)[0], 1.0, -1, 0U, (*chartInstance->c3_wej)[0] ==
          1.0))) {
      if (CV_EML_COND(23, 0, 1, CV_RELATIONAL_EVAL(5U, 23U, 1,
            (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)[2]
            == 1.0))) {
        guard7 = true;
      } else if (CV_EML_COND(23, 0, 2, CV_RELATIONAL_EVAL(5U, 23U, 2,
                   (*chartInstance->c3_wej)[2], 2.0, -1, 0U,
                   (*chartInstance->c3_wej)[2] == 2.0))) {
        guard7 = true;
      } else {
        guard6 = true;
      }
    } else {
      guard6 = true;
    }

    if (guard7 == true) {
      if (CV_EML_COND(23, 0, 3, CV_RELATIONAL_EVAL(5U, 23U, 3,
            (*chartInstance->c3_wej)[4], 2.0, -1, 0U, (*chartInstance->c3_wej)[4]
            == 2.0))) {
        guard5 = true;
      } else if (CV_EML_COND(23, 0, 4, CV_RELATIONAL_EVAL(5U, 23U, 4,
                   (*chartInstance->c3_wej)[4], 3.0, -1, 0U,
                   (*chartInstance->c3_wej)[4] == 3.0))) {
        guard5 = true;
      } else {
        guard4 = true;
      }
    }

    if (guard6 == true) {
      guard4 = true;
    }

    if (guard5 == true) {
      CV_EML_MCDC(23, 0, 0, true);
      CV_EML_IF(23, 0, 0, true);
      c3_out = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(23, 0, 0, false);
      CV_EML_IF(23, 0, 0, false);
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_front_fog_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_front_fog = c3_IN_front_fog_on;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_front_fog_on = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_front_fog = 1.0;
      chartInstance->c3_dataWrittenToVector[9U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 4U, 5U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_front_fog_on:
    CV_STATE_EVAL(3, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_qc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(24, 0, 0, CV_RELATIONAL_EVAL(5U, 24U, 0,
          (*chartInstance->c3_wej)[0], 0.0, -1, 0U, (*chartInstance->c3_wej)[0] ==
          0.0))) {
      guard3 = true;
    } else if (CV_EML_COND(24, 0, 1, CV_RELATIONAL_EVAL(5U, 24U, 1,
                 (*chartInstance->c3_wej)[2], 0.0, -1, 0U,
                 (*chartInstance->c3_wej)[2] == 0.0))) {
      guard3 = true;
    } else if (CV_EML_COND(24, 0, 2, CV_RELATIONAL_EVAL(5U, 24U, 2,
                 (*chartInstance->c3_wej)[4], 0.0, -1, 0U,
                 (*chartInstance->c3_wej)[4] == 0.0))) {
      guard2 = true;
    } else if (CV_EML_COND(24, 0, 3, CV_RELATIONAL_EVAL(5U, 24U, 3,
                 (*chartInstance->c3_wej)[4], 1.0, -1, 0U,
                 (*chartInstance->c3_wej)[4] == 1.0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(24, 0, 0, false);
      CV_EML_IF(24, 0, 0, false);
      c3_b_out = false;
    }

    if (guard3 == true) {
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(24, 0, 0, true);
      CV_EML_IF(24, 0, 0, true);
      c3_b_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_front_fog_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_front_fog = c3_IN_front_fog_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_front_fog_off = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_front_fog = 0.0;
      chartInstance->c3_dataWrittenToVector[9U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 4U, 4U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_front_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
}

static void c3_rear_fog(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_rear_fog) {
   case c3_IN_rear_fog_off:
    CV_STATE_EVAL(17, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_sc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard4 = false;
    guard5 = false;
    guard6 = false;
    if (CV_EML_COND(21, 0, 0, CV_RELATIONAL_EVAL(5U, 21U, 0,
          (*chartInstance->c3_wej)[1], 0.0, -1, 0U, (*chartInstance->c3_wej)[1] ==
          0.0))) {
      guard6 = true;
    } else if (CV_EML_COND(21, 0, 1, CV_RELATIONAL_EVAL(5U, 21U, 1,
                 (*chartInstance->c3_wej)[2], 1.0, -1, 1U,
                 (*chartInstance->c3_wej)[2] != 1.0))) {
      guard6 = true;
    } else if (CV_EML_COND(21, 0, 2, CV_RELATIONAL_EVAL(5U, 21U, 2,
                 (*chartInstance->c3_wej)[4], 0.0, -1, 0U,
                 (*chartInstance->c3_wej)[4] == 0.0))) {
      guard5 = true;
    } else if (CV_EML_COND(21, 0, 3, CV_RELATIONAL_EVAL(5U, 21U, 3,
                 (*chartInstance->c3_wej)[4], 1.0, -1, 0U,
                 (*chartInstance->c3_wej)[4] == 1.0))) {
      guard4 = true;
    } else {
      CV_EML_MCDC(21, 0, 0, false);
      CV_EML_IF(21, 0, 0, false);
      c3_out = false;
    }

    if (guard6 == true) {
      guard5 = true;
    }

    if (guard5 == true) {
      guard4 = true;
    }

    if (guard4 == true) {
      CV_EML_MCDC(21, 0, 0, true);
      CV_EML_IF(21, 0, 0, true);
      c3_out = true;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_rear_fog_off = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_rear_fog = c3_IN_rear_fog_on;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_rear_fog_on = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_o_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_rear_fog = 0.0;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 4U, 19U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_rear_fog_on:
    CV_STATE_EVAL(17, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_rc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(20, 0, 0, CV_RELATIONAL_EVAL(5U, 20U, 0,
          (*chartInstance->c3_wej)[1], 1.0, -1, 0U, (*chartInstance->c3_wej)[1] ==
          1.0))) {
      if (CV_EML_COND(20, 0, 1, CV_RELATIONAL_EVAL(5U, 20U, 1,
            (*chartInstance->c3_wej)[2], 1.0, -1, 0U, (*chartInstance->c3_wej)[2]
            == 1.0))) {
        if (CV_EML_COND(20, 0, 2, CV_RELATIONAL_EVAL(5U, 20U, 2,
              (*chartInstance->c3_wej)[4], 2.0, -1, 0U, (*chartInstance->c3_wej)
              [4] == 2.0))) {
          guard2 = true;
        } else if (CV_EML_COND(20, 0, 3, CV_RELATIONAL_EVAL(5U, 20U, 3,
                     (*chartInstance->c3_wej)[4], 3.0, -1, 0U,
                     (*chartInstance->c3_wej)[4] == 3.0))) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      guard1 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(20, 0, 0, true);
      CV_EML_IF(20, 0, 0, true);
      c3_b_out = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(20, 0, 0, false);
      CV_EML_IF(20, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_rear_fog_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_rear_fog = c3_IN_rear_fog_off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_rear_fog_off = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_p_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_b_rear_fog = 1.0;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 4U, 18U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_rear_fog = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c3_sfEvent);
}

static void c3_turn(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c3_sfEvent);
  switch (chartInstance->c3_is_turn) {
   case c3_IN_hazard_on:
    CV_STATE_EVAL(26, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                 chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bd_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    c3_out = CV_EML_IF(37, 0, 0, CV_RELATIONAL_EVAL(5U, 37U, 0,
      (*chartInstance->c3_wej)[8], 0.0, -1, 0U, (*chartInstance->c3_wej)[8] ==
      0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_hazard_on = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_turn = c3_IN_turn_right_or_left;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_turn_right_or_left = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_q_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_h_led = 0.0;
      chartInstance->c3_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 4U, 28U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      c3_enter_internal_turn_right_or_left(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                   chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_turn_right_or_left:
    CV_STATE_EVAL(26, 0, 2);
    c3_turn_right_or_left(chartInstance);
    break;

   default:
    CV_STATE_EVAL(26, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c3_is_turn = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c3_sfEvent);
}

static void c3_enter_internal_turn_right_or_left(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
  chartInstance->c3_is_turn_right_or_left = c3_IN_turn_off1;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
  chartInstance->c3_tp_turn_off1 = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_turn_right = 0.0;
  chartInstance->c3_dataWrittenToVector[10U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 30U,
                        chartInstance->c3_sfEvent, false);
  *chartInstance->c3_turn_left = 0.0;
  chartInstance->c3_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 30U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_turn_right_or_left(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 36U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ad_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_out = CV_EML_IF(36, 0, 0, CV_RELATIONAL_EVAL(5U, 36U, 0,
    (*chartInstance->c3_wej)[8], 1.0, -1, 0U, (*chartInstance->c3_wej)[8] == 1.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c3_sfEvent);
    c3_exit_internal_turn_right_or_left(chartInstance);
    chartInstance->c3_tp_turn_right_or_left = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_turn = c3_IN_hazard_on;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_hazard_on = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_u_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_h_led = 1.0;
    chartInstance->c3_dataWrittenToVector[4U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 4U, 27U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_turn_left = 1.0;
    chartInstance->c3_dataWrittenToVector[7U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 27U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_w_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_turn_right = 1.0;
    chartInstance->c3_dataWrittenToVector[10U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 27U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, chartInstance->c3_sfEvent);
    switch (chartInstance->c3_is_turn_right_or_left) {
     case c3_IN_turn_left_on1:
      CV_STATE_EVAL(28, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_uc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard5 = false;
      guard6 = false;
      if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
            (*chartInstance->c3_wej)[3], 1.0, -1, 0U, (*chartInstance->c3_wej)[3]
            == 1.0))) {
        if (CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
              (*chartInstance->c3_wej)[4], 0.0, -1, 0U, (*chartInstance->c3_wej)
              [4] == 0.0))) {
          guard6 = true;
        } else if (CV_EML_COND(4, 0, 2, CV_RELATIONAL_EVAL(5U, 4U, 2,
                     (*chartInstance->c3_wej)[4], 1.0, -1, 0U,
                     (*chartInstance->c3_wej)[4] == 1.0))) {
          guard6 = true;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }

      if (guard6 == true) {
        CV_EML_MCDC(4, 0, 0, true);
        CV_EML_IF(4, 0, 0, true);
        c3_b_out = true;
      }

      if (guard5 == true) {
        CV_EML_MCDC(4, 0, 0, false);
        CV_EML_IF(4, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_turn_left_on1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_turn_right_or_left = c3_IN_turn_off1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_turn_off1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_turn_right = 0.0;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 30U,
                              chartInstance->c3_sfEvent, false);
        *chartInstance->c3_turn_left = 0.0;
        chartInstance->c3_dataWrittenToVector[7U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 30U,
                              chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_c_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
          (*chartInstance->c3_wej)[3], 2.0, -1, 0U, (*chartInstance->c3_wej)[3] ==
          2.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_turn_left_on1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_turn_right_or_left = c3_IN_turn_right_on1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_turn_right_on1 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_t_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_turn_right = 1.0;
          chartInstance->c3_dataWrittenToVector[10U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 31U,
                                chartInstance->c3_sfEvent, false);
          *chartInstance->c3_turn_left = 0.0;
          chartInstance->c3_dataWrittenToVector[7U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 31U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 29U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_turn_off1:
      CV_STATE_EVAL(28, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_tc_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
            (*chartInstance->c3_wej)[3], 0.0, -1, 0U, (*chartInstance->c3_wej)[3]
            == 0.0))) {
        if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
              (*chartInstance->c3_wej)[4], 2.0, -1, 0U, (*chartInstance->c3_wej)
              [4] == 2.0))) {
          guard4 = true;
        } else if (CV_EML_COND(9, 0, 2, CV_RELATIONAL_EVAL(5U, 9U, 2,
                     (*chartInstance->c3_wej)[4], 3.0, -1, 0U,
                     (*chartInstance->c3_wej)[4] == 3.0))) {
          guard4 = true;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard4 == true) {
        CV_EML_MCDC(9, 0, 0, true);
        CV_EML_IF(9, 0, 0, true);
        c3_d_out = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(9, 0, 0, false);
        CV_EML_IF(9, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_turn_off1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_turn_right_or_left = c3_IN_turn_left_on1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_turn_left_on1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_turn_left = 1.0;
        chartInstance->c3_dataWrittenToVector[7U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 29U,
                              chartInstance->c3_sfEvent, false);
        *chartInstance->c3_turn_right = 0.0;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 29U,
                              chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                     chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xc_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard1 = false;
        guard2 = false;
        if (CV_EML_COND(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0,
              (*chartInstance->c3_wej)[3], 2.0, -1, 0U, (*chartInstance->c3_wej)
              [3] == 2.0))) {
          if (CV_EML_COND(8, 0, 1, CV_RELATIONAL_EVAL(5U, 8U, 1,
                (*chartInstance->c3_wej)[4], 2.0, -1, 0U,
                (*chartInstance->c3_wej)[4] == 2.0))) {
            guard2 = true;
          } else if (CV_EML_COND(8, 0, 2, CV_RELATIONAL_EVAL(5U, 8U, 2,
                       (*chartInstance->c3_wej)[4], 3.0, -1, 0U,
                       (*chartInstance->c3_wej)[4] == 3.0))) {
            guard2 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard2 == true) {
          CV_EML_MCDC(8, 0, 0, true);
          CV_EML_IF(8, 0, 0, true);
          c3_e_out = true;
        }

        if (guard1 == true) {
          CV_EML_MCDC(8, 0, 0, false);
          CV_EML_IF(8, 0, 0, false);
          c3_e_out = false;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_turn_off1 = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_turn_right_or_left = c3_IN_turn_right_on1;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_turn_right_on1 = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_t_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *chartInstance->c3_turn_right = 1.0;
          chartInstance->c3_dataWrittenToVector[10U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 31U,
                                chartInstance->c3_sfEvent, false);
          *chartInstance->c3_turn_left = 0.0;
          chartInstance->c3_dataWrittenToVector[7U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 31U,
                                chartInstance->c3_sfEvent, false);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                       chartInstance->c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_turn_right_on1:
      CV_STATE_EVAL(28, 0, 3);
      c3_turn_right_on1(chartInstance);
      break;

     default:
      CV_STATE_EVAL(28, 0, 0);

      /* Unreachable state, for coverage only */
      chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, chartInstance->c3_sfEvent);
}

static void c3_exit_internal_turn_right_or_left(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_turn_right_or_left) {
   case c3_IN_turn_left_on1:
    CV_STATE_EVAL(28, 1, 1);
    chartInstance->c3_tp_turn_left_on1 = 0U;
    chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_turn_off1:
    CV_STATE_EVAL(28, 1, 2);
    chartInstance->c3_tp_turn_off1 = 0U;
    chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_turn_right_on1:
    CV_STATE_EVAL(28, 1, 3);
    chartInstance->c3_tp_turn_right_on1 = 0U;
    chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(28, 1, 0);
    chartInstance->c3_is_turn_right_or_left = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_turn_right_on1(SFc3_projekt2InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_vc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  c3_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0,
    (*chartInstance->c3_wej)[3], 0.0, -1, 0U, (*chartInstance->c3_wej)[3] == 0.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_turn_right_on1 = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_turn_right_or_left = c3_IN_turn_left_on1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_turn_left_on1 = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_turn_left = 1.0;
    chartInstance->c3_dataWrittenToVector[7U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 29U,
                          chartInstance->c3_sfEvent, false);
    *chartInstance->c3_turn_right = 0.0;
    chartInstance->c3_dataWrittenToVector[10U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 29U,
                          chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_yc_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0,
          (*chartInstance->c3_wej)[3], 1.0, -1, 0U, (*chartInstance->c3_wej)[3] ==
          1.0))) {
      if (CV_EML_COND(6, 0, 1, CV_RELATIONAL_EVAL(5U, 6U, 1,
            (*chartInstance->c3_wej)[4], 0.0, -1, 0U, (*chartInstance->c3_wej)[4]
            == 0.0))) {
        guard2 = true;
      } else if (CV_EML_COND(6, 0, 2, CV_RELATIONAL_EVAL(5U, 6U, 2,
                   (*chartInstance->c3_wej)[4], 1.0, -1, 0U,
                   (*chartInstance->c3_wej)[4] == 1.0))) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(6, 0, 0, true);
      CV_EML_IF(6, 0, 0, true);
      c3_b_out = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(6, 0, 0, false);
      CV_EML_IF(6, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_turn_right_on1 = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_turn_right_or_left = c3_IN_turn_off1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_turn_off1 = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_turn_right = 0.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 30U,
                            chartInstance->c3_sfEvent, false);
      *chartInstance->c3_turn_left = 0.0;
      chartInstance->c3_dataWrittenToVector[7U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 30U,
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_battery_bad(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_x_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_h_led = 0.0;
  chartInstance->c3_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_y_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_front_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ab_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_high_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[11U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_low_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_park_left = 0.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_db_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_park_right = 0.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_eb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_license_plate = 0.0;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_fb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_stop = 0.0;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_gb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_rear_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_hb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_reverse = 0.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ib_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_turn_left = 0.0;
  chartInstance->c3_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_jb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_turn_right = 0.0;
  chartInstance->c3_dataWrittenToVector[10U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 0U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_battery_error(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_kb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_h_led = 0.0;
  chartInstance->c3_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_h_led, 6U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_lb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_front_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_front_fog, 11U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_mb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_high_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[11U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_high_beam, 13U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_nb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_low_beam = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_low_beam, 2U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ob_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_park_left = 0.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_left, 10U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_pb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_park_right = 0.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_park_right, 7U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_license_plate = 0.0;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_license_plate, 8U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_rb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_stop = 0.0;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_stop, 3U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_sb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_b_rear_fog = 0.0;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_b_rear_fog, 5U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_reverse = 0.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_reverse, 4U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ub_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_turn_left = 0.0;
  chartInstance->c3_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_left, 9U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_vb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_turn_right = 0.0;
  chartInstance->c3_dataWrittenToVector[10U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_turn_right, 12U, 4U, 1U,
                        chartInstance->c3_sfEvent, false);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_projekt2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i2, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_b_tp_battery_good, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_battery_good),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_battery_good);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_battery_good;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_b_tp_battery_good = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_battery_good),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_battery_good);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i3;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_projekt2InstanceStruct *chartInstance;
  chartInstance = (SFc3_projekt2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i3 = 0; c3_i3 < 9; c3_i3++) {
    c3_u[c3_i3] = (*(real_T (*)[9])c3_inData)[c3_i3];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_g_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[12])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_h_emlrt_marshallIn(SFc3_projekt2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[12])
{
  boolean_T c3_bv1[12];
  int32_T c3_i4;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 12);
  for (c3_i4 = 0; c3_i4 < 12; c3_i4++) {
    c3_y[c3_i4] = c3_bv1[c3_i4];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_i_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallIn(SFc3_projekt2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_test_point_addr_map(SFc3_projekt2InstanceStruct *chartInstance)
{
  chartInstance->c3_testPointAddrMap[0] = &chartInstance->c3_tp_battery_bad;
  chartInstance->c3_testPointAddrMap[1] = &chartInstance->c3_tp_battery_error;
}

static void **get_test_point_address_map(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  return &chartInstance->c3_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc3_projekt2InstanceStruct *chartInstance)
{
  return &chartInstance->c3_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector(SFc3_projekt2InstanceStruct
  *chartInstance)
{
  return &chartInstance->c3_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc3_projekt2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_projekt2InstanceStruct *chartInstance)
{
  chartInstance->c3_battery = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_low_beam = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_b_stop = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_reverse = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_b_rear_fog = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_h_led = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_park_right = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_license_plate = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_turn_left = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_park_left = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_b_front_fog = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_turn_right = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c3_high_beam = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c3_wej = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void init_test_point_mapping_info(SimStruct *S);
void sf_c3_projekt2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1562367619U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(47426051U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(762689549U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3292486444U);
}

mxArray* sf_c3_projekt2_get_post_codegen_info(void);
mxArray *sf_c3_projekt2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YZMEDVyfEujt9xTlyaMZLH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_projekt2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_projekt2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_projekt2_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("logging");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("battery_bad");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_projekt2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_projekt2_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_projekt2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[63],T\"front_fog\",},{M[1],M[58],T\"h_led\",},{M[1],M[65],T\"high_beam\",},{M[1],M[60],T\"license_plate\",},{M[1],M[53],T\"low_beam\",},{M[1],M[62],T\"park_left\",},{M[1],M[59],T\"park_right\",},{M[1],M[57],T\"rear_fog\",},{M[1],M[55],T\"reverse\",},{M[1],M[54],T\"stop\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[61],T\"turn_left\",},{M[1],M[64],T\"turn_right\",},{M[8],M[0],T\"is_active_c3_projekt2\",},{M[8],M[150],T\"is_active_reverse\",},{M[8],M[173],T\"is_active_license_plate\",},{M[8],M[179],T\"is_active_high_beam_and_flash\",},{M[8],M[236],T\"is_active_stop\",},{M[8],M[252],T\"is_active_rear_fog\",},{M[8],M[262],T\"is_active_front_fog\",},{M[8],M[289],T\"is_active_low_park\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[348],T\"is_active_turn\",},{M[9],M[0],T\"is_c3_projekt2\",},{M[9],M[150],T\"is_reverse\",},{M[9],M[173],T\"is_license_plate\",},{M[9],M[179],T\"is_high_beam_and_flash\",},{M[9],M[210],T\"is_turn_right_or_left\",},{M[9],M[236],T\"is_stop\",},{M[9],M[252],T\"is_rear_fog\",},{M[9],M[262],T\"is_front_fog\",},{M[9],M[289],T\"is_low_park\",}}",
    "100 S1x2'type','srcId','name','auxInfo'{{M[9],M[348],T\"is_turn\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 32, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_projekt2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_projekt2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_projekt2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _projekt2MachineNumber_,
           3,
           32,
           44,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_projekt2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_projekt2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _projekt2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"battery");
          _SFD_SET_DATA_PROPS(1,1,1,0,"wej");
          _SFD_SET_DATA_PROPS(2,2,0,1,"low_beam");
          _SFD_SET_DATA_PROPS(3,2,0,1,"stop");
          _SFD_SET_DATA_PROPS(4,2,0,1,"reverse");
          _SFD_SET_DATA_PROPS(5,2,0,1,"rear_fog");
          _SFD_SET_DATA_PROPS(6,2,0,1,"h_led");
          _SFD_SET_DATA_PROPS(7,2,0,1,"park_right");
          _SFD_SET_DATA_PROPS(8,2,0,1,"license_plate");
          _SFD_SET_DATA_PROPS(9,2,0,1,"turn_left");
          _SFD_SET_DATA_PROPS(10,2,0,1,"park_left");
          _SFD_SET_DATA_PROPS(11,2,0,1,"front_fog");
          _SFD_SET_DATA_PROPS(12,2,0,1,"turn_right");
          _SFD_SET_DATA_PROPS(13,2,0,1,"high_beam");
          _SFD_STATE_INFO(0,1,0);
          _SFD_STATE_INFO(1,1,0);
          _SFD_STATE_INFO(2,1,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,1);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,1);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,1);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,1);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,1);
          _SFD_STATE_INFO(24,0,0);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,1);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,0);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,8);
          _SFD_ST_SUBSTATE_INDEX(2,0,23);
          _SFD_ST_SUBSTATE_INDEX(2,1,13);
          _SFD_ST_SUBSTATE_INDEX(2,2,26);
          _SFD_ST_SUBSTATE_INDEX(2,3,3);
          _SFD_ST_SUBSTATE_INDEX(2,4,17);
          _SFD_ST_SUBSTATE_INDEX(2,5,10);
          _SFD_ST_SUBSTATE_INDEX(2,6,20);
          _SFD_ST_SUBSTATE_INDEX(2,7,6);
          _SFD_ST_SUBSTATE_COUNT(23,2);
          _SFD_ST_SUBSTATE_INDEX(23,0,24);
          _SFD_ST_SUBSTATE_INDEX(23,1,25);
          _SFD_ST_SUBSTATE_COUNT(24,0);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(13,3);
          _SFD_ST_SUBSTATE_INDEX(13,0,14);
          _SFD_ST_SUBSTATE_INDEX(13,1,15);
          _SFD_ST_SUBSTATE_INDEX(13,2,16);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(26,2);
          _SFD_ST_SUBSTATE_INDEX(26,0,27);
          _SFD_ST_SUBSTATE_INDEX(26,1,28);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(28,3);
          _SFD_ST_SUBSTATE_INDEX(28,0,29);
          _SFD_ST_SUBSTATE_INDEX(28,1,30);
          _SFD_ST_SUBSTATE_INDEX(28,2,31);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(17,2);
          _SFD_ST_SUBSTATE_INDEX(17,0,18);
          _SFD_ST_SUBSTATE_INDEX(17,1,19);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(10,2);
          _SFD_ST_SUBSTATE_INDEX(10,0,11);
          _SFD_ST_SUBSTATE_INDEX(10,1,12);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(20,2);
          _SFD_ST_SUBSTATE_INDEX(20,0,21);
          _SFD_ST_SUBSTATE_INDEX(20,1,22);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(6,3);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,8);
          _SFD_ST_SUBSTATE_INDEX(6,2,9);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,8,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(24,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(15,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(28,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(12,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(14,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(14,0,0,1,38,1,38);

        {
          static int condStart[] = { 1, 15, 29 };

          static int condEnd[] = { 12, 26, 38 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(14,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(14,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(14,0,1,15,26,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(14,0,2,29,38,-1,0);
        _SFD_CV_INIT_EML(15,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(15,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 24 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(15,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(15,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(15,0,1,15,24,-1,1);
        _SFD_CV_INIT_EML(43,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(43,0,0,1,26,1,26);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 26 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(43,0,0,1,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(43,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(43,0,1,15,26,-1,0);
        _SFD_CV_INIT_EML(42,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(42,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(42,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(40,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(40,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(40,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(40,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(40,0,1,15,24,-1,0);
        _SFD_CV_INIT_EML(41,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(41,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 24 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(41,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(41,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(41,0,1,15,24,-1,1);
        _SFD_CV_INIT_EML(29,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(29,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(25,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(25,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(31,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(31,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(31,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(26,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(26,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(26,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(28,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(28,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(28,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(30,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(30,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(30,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(16,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(16,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(16,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(16,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(16,0,1,15,24,-1,0);
        _SFD_CV_INIT_EML(17,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(17,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(17,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(17,0,0,1,12,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(17,0,1,15,24,-1,1);
        _SFD_CV_INIT_EML(35,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(35,0,0,1,10,1,10);
        _SFD_CV_INIT_EML_RELATIONAL(35,0,0,1,10,-1,0);
        _SFD_CV_INIT_EML(34,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(34,0,0,1,10,1,10);
        _SFD_CV_INIT_EML_RELATIONAL(34,0,0,1,10,-1,1);
        _SFD_CV_INIT_EML(23,0,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(23,0,0,1,68,1,48);

        {
          static int condStart[] = { 1, 16, 30, 46, 58 };

          static int condEnd[] = { 12, 27, 41, 55, 67 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3, 3, 4, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(23,0,0,1,68,5,0,&(condStart[0]),&(condEnd[0]),9,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(23,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(23,0,1,16,27,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(23,0,2,30,41,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(23,0,3,46,55,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(23,0,4,58,67,-1,0);
        _SFD_CV_INIT_EML(24,0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(24,0,0,1,50,1,48);

        {
          static int condStart[] = { 1, 15, 29, 41 };

          static int condEnd[] = { 12, 26, 38, 50 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(24,0,0,1,50,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(24,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(24,0,1,15,26,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(24,0,2,29,38,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(24,0,3,41,50,-1,0);
        _SFD_CV_INIT_EML(20,0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(20,0,0,1,51,1,48);

        {
          static int condStart[] = { 1, 15, 29, 41 };

          static int condEnd[] = { 12, 25, 38, 50 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(20,0,0,1,51,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(20,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(20,0,1,15,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(20,0,2,29,38,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(20,0,3,41,50,-1,0);
        _SFD_CV_INIT_EML(21,0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(21,0,0,1,51,1,48);

        {
          static int condStart[] = { 1, 15, 30, 42 };

          static int condEnd[] = { 12, 27, 39, 51 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(21,0,0,1,51,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(21,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(21,0,1,15,27,-1,1);
        _SFD_CV_INIT_EML_RELATIONAL(21,0,2,30,39,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(21,0,3,42,51,-1,0);
        _SFD_CV_INIT_EML(9,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,38,1,38);

        {
          static int condStart[] = { 1, 16, 28 };

          static int condEnd[] = { 12, 25, 37 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,1,16,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,2,28,37,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,38,1,38);

        {
          static int condStart[] = { 1, 16, 28 };

          static int condEnd[] = { 12, 25, 37 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,1,16,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,2,28,37,-1,0);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML(8,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,38,1,38);

        {
          static int condStart[] = { 1, 16, 28 };

          static int condEnd[] = { 12, 25, 37 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,1,16,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,2,28,37,-1,0);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,38,1,38);

        {
          static int condStart[] = { 1, 16, 28 };

          static int condEnd[] = { 12, 25, 37 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,38,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,12,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,1,16,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,2,28,37,-1,0);
        _SFD_CV_INIT_EML(36,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(36,0,0,1,10,1,10);
        _SFD_CV_INIT_EML_RELATIONAL(36,0,0,1,10,-1,0);
        _SFD_CV_INIT_EML(37,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(37,0,0,1,10,1,10);
        _SFD_CV_INIT_EML_RELATIONAL(37,0,0,1,10,-1,0);
        _SFD_CV_INIT_EML(0,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(0,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 14 };

          static int condEnd[] = { 11, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,11,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,1,14,25,-1,3);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,54,1,48);

        {
          static int condStart[] = { 2, 15, 29, 42 };

          static int condEnd[] = { 12, 24, 39, 53 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,54,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,2,12,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,1,15,24,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,2,29,39,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,3,42,53,-1,3);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 13 };

          static int condEnd[] = { 10, 23 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,10,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,13,23,-1,4);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,26,1,26);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 12, 26 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,26,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,12,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,15,26,-1,4);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _projekt2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_projekt2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_projekt2InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_battery);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_low_beam);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_b_stop);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_reverse);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_b_rear_fog);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_h_led);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_park_right);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_license_plate);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_turn_left);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_park_left);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_b_front_fog);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c3_turn_right);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c3_high_beam);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c3_wej);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sXTbBxt3WKKgLFlmGHdtTgF";
}

static void sf_opaque_initialize_c3_projekt2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_projekt2InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
  initialize_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_projekt2(void *chartInstanceVar)
{
  enable_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_projekt2(void *chartInstanceVar)
{
  disable_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_projekt2(void *chartInstanceVar)
{
  sf_gateway_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_projekt2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_projekt2((SFc3_projekt2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_projekt2(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_projekt2((SFc3_projekt2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_projekt2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_projekt2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_projekt2_optimization_info();
    }

    finalize_c3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_projekt2((SFc3_projekt2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_projekt2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_projekt2((SFc3_projekt2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_projekt2(SimStruct *S)
{
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_projekt2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,12);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=12; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  if (sim_mode_is_modelref_sim(S)) {
    mxArray *prhs[4];
    mxArray *plhs[1];
    uint32_T newChkSum[4];
    double *inPr, *outPr;
    int i;
    int firstSlashIdx = 0;
    for (i = 0; i < 999 && S->path[i] != '\0' ; ++i) {
      if (S->path[i] == '/') {
        firstSlashIdx = i;
        break;
      }
    }

    prhs[0] = mxCreateString("Private");
    prhs[1] = mxCreateString("md5");
    prhs[2] = mxCreateDoubleMatrix(1, 4, mxREAL);
    prhs[3] = mxCreateString(S->path + firstSlashIdx + 1);
    inPr = mxGetPr(prhs[2]);
    inPr[0] = 739617768U;
    inPr[1] = 2906876831U;
    inPr[2] = 3569638254U;
    inPr[3] = 3775960846U;
    mexCallMATLAB(1, plhs, 4, prhs, "sf");
    outPr = mxGetPr(plhs[0]);
    for (i = 0; i < 4; ++i) {
      newChkSum[i] = (uint32_T) outPr[i];
    }

    ssSetChecksum0(S, newChkSum[0]);
    ssSetChecksum1(S, newChkSum[1]);
    ssSetChecksum2(S, newChkSum[2]);
    ssSetChecksum3(S, newChkSum[3]);
    mxDestroyArray(plhs[0]);
    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);
    mxDestroyArray(prhs[3]);
  } else {
    ssSetChecksum0(S,(739617768U));
    ssSetChecksum1(S,(2906876831U));
    ssSetChecksum2(S,(3569638254U));
    ssSetChecksum3(S,(3775960846U));
  }

  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_projekt2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_projekt2(SimStruct *S)
{
  SFc3_projekt2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_projekt2InstanceStruct *)utMalloc(sizeof
    (SFc3_projekt2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_projekt2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_projekt2;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_projekt2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_projekt2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_projekt2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_projekt2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_projekt2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_projekt2;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_projekt2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_projekt2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_projekt2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_projekt2;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->isEnhancedMooreMachine = 0;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->fCheckOverflow = sf_runtime_overflow_check_is_on(S);
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
}

void c3_projekt2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_projekt2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_projekt2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_projekt2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_projekt2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/battery_bad", "battery_bad", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/battery_error", "battery_error", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    2,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    739617768U,
    2906876831U,
    3569638254U,
    3775960846U
  }
};

static void init_signal_logging_objects(SimStruct *S, rtwCAPI_ModelMappingInfo
  *testPointMappingInfo)
{
  void ** chartDatasetLoggingObjs;
  void *pSetDescr;
  int i;
  char chartPath[1000];
  size_t lastSlashIdx = 0;
  SFc3_projekt2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  chartInstance = (SFc3_projekt2InstanceStruct *) chartInfo->chartInstance;
  chartDatasetLoggingObjs = get_dataset_logging_obj_vector(chartInstance);

  /* compute the chart path */
  for (i = 0; i < 999 && S->path[i]; i++) {
    if (S->path[i] == '/') {
      lastSlashIdx = i;
    }
  }

  strncpy(chartPath, S->path, lastSlashIdx);
  chartPath[lastSlashIdx] = '\0';

  /* Initialize signal log vector */
  for (i = 0; i < 2; ++i) {
    chartDatasetLoggingObjs[i] = NULL;
  }

  _ssLoggerCreateDatasetDescriptWithMMI(S, testPointMappingInfo, 0, NULL,
    NULL, &pSetDescr);
  if (pSetDescr) {
    {
      void *pElementDescr;
      int_T dimArray[] = { 1 };

      ssLoggerAddStateflowElementDescription(S, &pSetDescr,
        "Stateflow.SimulationData.State",
        "battery_bad",
        chartPath,
        "StateflowChart/battery_bad",
        NULL,
        &pElementDescr);
      ssLoggerAddTimeseriesDescriptionWithInterpolation(S, &pSetDescr,
        &pElementDescr,
        "battery_bad",
        1,
        dimArray,
        SS_UINT8,
        0,
        SS_ZOH_INTERPOLATION);
    }

    {
      void *pElementDescr;
      int_T dimArray[] = { 1 };

      ssLoggerAddStateflowElementDescription(S, &pSetDescr,
        "Stateflow.SimulationData.State",
        "battery_error",
        chartPath,
        "StateflowChart/battery_error",
        NULL,
        &pElementDescr);
      ssLoggerAddTimeseriesDescriptionWithInterpolation(S, &pSetDescr,
        &pElementDescr,
        "battery_error",
        1,
        dimArray,
        SS_UINT8,
        0,
        SS_ZOH_INTERPOLATION);
    }

    ssLoggerCreateElementFromDescription(S, &pSetDescr,
      chartDatasetLoggingObjs);
    if (chartDatasetLoggingObjs[0] != NULL) {
      mxArray *pVal = mxCreateDoubleScalar(39);
      ssLoggerAddElementProperty(S,
        chartDatasetLoggingObjs[0],
        "SSIdNumber",
        pVal);
    }

    if (chartDatasetLoggingObjs[1] != NULL) {
      mxArray *pVal = mxCreateDoubleScalar(166);
      ssLoggerAddElementProperty(S,
        chartDatasetLoggingObjs[1],
        "SSIdNumber",
        pVal);
    }
  }
}

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc3_projekt2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  chartInstance = (SFc3_projekt2InstanceStruct *) chartInfo->chartInstance;
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
  init_signal_logging_objects(S, testPointMappingInfo);
}
