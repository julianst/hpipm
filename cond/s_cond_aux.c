/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High-Performance Interior Point Method.                                                *
* Copyright (C) 2017-2018 by Gianluca Frison.                                                     *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* This program is free software: you can redistribute it and/or modify                            *
* it under the terms of the GNU General Public License as published by                            *
* the Free Software Foundation, either version 3 of the License, or                               *
* (at your option) any later version                                                              *.
*                                                                                                 *
* This program is distributed in the hope that it will be useful,                                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                   *
* GNU General Public License for more details.                                                    *
*                                                                                                 *
* You should have received a copy of the GNU General Public License                               *
* along with this program.  If not, see <https://www.gnu.org/licenses/>.                          *
*                                                                                                 *
* The authors designate this particular file as subject to the "Classpath" exception              *
* as provided by the authors in the LICENSE file that accompained this code.                      *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <blasfeo_target.h>
#include <blasfeo_common.h>
#include <blasfeo_s_blas.h>
#include <blasfeo_s_aux.h>

#include "../include/hpipm_s_ocp_qp.h"
#include "../include/hpipm_s_ocp_qp_sol.h"
#include "../include/hpipm_s_dense_qp.h"
#include "../include/hpipm_s_dense_qp_sol.h"
#include "../include/hpipm_s_cond.h"



#define AXPY_LIBSTR blasfeo_saxpy
#define COND_QP_OCP2DENSE_ARG s_cond_qp_ocp2dense_arg
#define COND_QP_OCP2DENSE_WORKSPACE s_cond_qp_ocp2dense_workspace
#define DENSE_QP_SOL s_dense_qp_sol
#define GEAD_LIBSTR blasfeo_sgead
#define GECP_LIBSTR blasfeo_sgecp
#define GEEX1_LIBSTR blasfeo_sgeex1
#define GESE_LIBSTR blasfeo_sgese
#define GEMM_NN_LIBSTR blasfeo_sgemm_nn
#define GEMV_T_LIBSTR blasfeo_sgemv_t
#define GEMV_N_LIBSTR blasfeo_sgemv_n
#define OCP_QP s_ocp_qp
#define OCP_QP_SOL s_ocp_qp_sol
#define POTRF_L_MN_LIBSTR blasfeo_spotrf_l_mn
#define REAL float
#define ROWAD_LIBSTR blasfeo_srowad
#define ROWEX_LIBSTR blasfeo_srowex
#define ROWIN_LIBSTR blasfeo_srowin
#define STRMAT blasfeo_smat
#define STRVEC blasfeo_svec
#define SYMV_L_LIBSTR blasfeo_ssymv_l
#define SYRK_LN_MN_LIBSTR blasfeo_ssyrk_ln_mn
#define TRCP_L_LIBSTR blasfeo_strcp_l
#define TRMM_RLNN_LIBSTR blasfeo_strmm_rlnn
#define VECCP_LIBSTR blasfeo_sveccp

#define COND_BABT s_cond_BAbt
#define COND_B s_cond_b
#define COND_RSQRQ_N2NX3 s_cond_RSQrq_N2nx3
#define COND_RQ_N2NX3 s_cond_rq_N2nx3
#define COND_DCTD s_cond_DCtd
#define COND_D s_cond_d
#define EXPAND_SOL s_expand_sol
#define EXPAND_PRIMAL_SOL s_expand_primal_sol
#define UPDATE_COND_BABT s_update_cond_BAbt
#define UPDATE_COND_RSQRQ_N2NX3 s_update_cond_RSQrq_N2nx3
#define UPDATE_COND_DCTD s_update_cond_DCtd



#include "x_cond_aux.c"

