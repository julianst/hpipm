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

#ifndef HPIPM_D_TREE_OCP_QP_DIM_H_
#define HPIPM_D_TREE_OCP_QP_DIM_H_



#ifdef __cplusplus
extern "C" {
#endif



struct d_tree_ocp_qp_dim
	{
	struct tree *ttree; // tree describing node conndection
	int *nx; // number of states // Nn
	int *nu; // number of inputs // Nn
	int *nb; // number of box constraints // Nn
	int *nbx; // number of state box constraints // Nn
	int *nbu; // number of input box constraints // Nn
	int *ng; // number of general constraints // Nn
	int *ns; // number of soft constraints // Nn
	int *nsbx; // number of soft state box constraints
	int *nsbu; // number of soft input box constraints
	int *nsg; // number of soft general constraints
	int Nn; // number of nodes
	int memsize;
	};



//
int d_memsize_tree_ocp_qp_dim(int Nn);
//
void d_create_tree_ocp_qp_dim(int Nn, struct d_tree_ocp_qp_dim *qp_dim, void *memory);
//
void d_cvt_int_to_tree_ocp_qp_dim(struct tree *ttree, int *nx, int *nu, int *nbx, int *nbu, int *ng, int *nsbx, int *nsbu, int *nsg, struct d_tree_ocp_qp_dim *dim);



#ifdef __cplusplus
}	// #extern "C"
#endif



#endif // HPIPM_D_TREE_OCP_QP_DIM_H_
