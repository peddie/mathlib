/*
 * This file is part of mathlib.
 *
 * Copyright (C) 2010-2011 Greg Horn <ghorn@stanford.edu>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/*
 * quat.h
 * Math library for quaternion operations
 */

#ifndef __QUAT_H__
#define __QUAT_H__

#ifndef QUAT_T
#define QUAT_T
typedef struct quat_t {
  double q0;  /* real */
  double q1;  /* i */
  double q2;  /* j */
  double q3;  /* k */
} quat_t;
#endif // QUAT_T

#define quat_printf(quat_in) printf(#quat_in ": [% .6f, % .6f, % .6f, % .6f]\n",\
                                    (quat_in)->q0, (quat_in)->q1, (quat_in)->q2, (quat_in)->q3)

#ifdef __cplusplus
extern "C"{
#endif

  /* Set 'q1' to 'q0'. */
  void quat_memcpy( quat_t * q1, const quat_t * const q0);

  /* Set 'q_out' to the inverse of 'q_in'. */
  void quat_inv(quat_t *q_out, const quat_t * const q_in);

  /* Return the norm of 'q'. */
  double quat_norm(const quat_t * const q);

  /* Normalize 'q' to unit magnitude. */
  void quat_normalize(quat_t * q);

  /* Compose two quaternions 'qa' and 'qb', so that 'qb' happens
   * before 'qa'.  This is analogous to the order that rotation
   * matrices compose; if you want to rotate a vector v by matrix Ra
   * and then by matrix Rb, you get
   *
   *   v' = Rb × Ra × v
   *
   * so similarly, if you want to rotate v by qa and then by qb, you
   * get
   *
   *   v' = rot(qb × qa, v)
   *
   */
  void quat_mult(quat_t *q_out, const quat_t * const qa, const quat_t * const qb);

  /* Compose two quaternions 'qa' and 'qb', so that the inverse of
   * 'qb' happens before 'qa'; i.e.
   *
   * q_out = qa × qb^-1
   *
   */
  void quat_mult_inv(quat_t *q_out, const quat_t * const qa, const quat_t * const qb);

  /* Compose two quaternions 'qa' and 'qb' so that 'qb' happens before
   * the inverse of 'qa'; i.e.
   *
   * q_out = qa^-1 × qb
   *
   */
  void quat_inv_mult(quat_t *q_out, const quat_t * const qa, const quat_t * const qb);

  /* Compose two quaternions 'qa' and 'qb' so that 'qb' happens before
   * 'qa', and return the resulting composite by value on the
   * stack. */
  quat_t quat_mult_ret(const quat_t qa, const quat_t qb);

#ifdef __cplusplus
}
#endif

#endif // __QUAT_H__
