/// \brief  This files provides complete support for the OpenGL 4.4 core profile API. If SUPPPORT_INTEL_HD is defined and set to 1, then
///         this file will only provide the OpenGL methods found in the drivers for Intel HD2500+ graphics cards (i.e. those that are shipped
///         with 2nd gen core-i3+ CPU's). It should be noted that as of 16/04/14, I can confirm that GLSL version 400 is supported by
///         the Intel Drivers.
/// \author Rob Bateman
/// \note   Some of this header file features modifications to code found in the GL extension wrangler library. To ensure I'm not treading on
///         any legal toes, I've included their requested copyright notices below:

/*
** The OpenGL Extension Wrangler Library
** Copyright (C) 2002-2008, Milan Ikits <milan ikits[]ieee org>
** Copyright (C) 2002-2008, Marcelo E. Magallon <mmagallo[]debian org>
** Copyright (C) 2002, Lev Povalahev
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer in the documentation
**   and/or other materials provided with the distribution.
** * The name of the author may be used to endorse or promote products
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
** ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
** THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
 * Mesa 3-D graphics library
 * Version:  7.0
 *
 * Copyright (C) 1999-2007  Brian Paul   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
** Copyright (c) 2007 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

#pragma once

#include <cstdint>

#define GL_EXPORT

#define CGT_OS_WINDOWS 1
#define CGT_OS_LINUX 0
#define CGT_OS_IOS 0
#define CGT_OS_ANDROID 0
#define CGT_OS_MACOS 0

#if CGT_OS_ANDROID || CGT_OS_IOS
# include "gl/gles31.h"
#endif

#if CGT_OS_WINDOWS || CGT_OS_LINUX || CGT_OS_MACOS
/// \brief  If you want to ensure compatibility with Intel HD2500 / HD3000 graphics cards, set this value to 1. This will ensure that only
///         the OpenGL methods supported by those cards will be supported. If you wish to expose the full OpenGL 4.4 API, then set this
///         value to 0.
#ifndef SUPPPORT_INTEL_HD
# define SUPPPORT_INTEL_HD 0
#endif

/// \brief  Set to 1 to write a list of all OpenGL 4.4 methods found in the GL driver to std::cout
#ifndef GL4_DUMP_FUNCS
# define GL4_DUMP_FUNCS 0
#endif

/// \brief  Set to 1 to write a list of all OpenGL 4.4 ARB extenions found in the GL driver to std::cout
#ifndef GL4_DUMP_EXTENSIONS
# define GL4_DUMP_EXTENSIONS 0
#endif

/// \brief  Set to 1 to write a list of all functions missing from OpenGL 4.4 to std::cout
#ifndef GL4_DUMP_MISSING_FUNCS
# define GL4_DUMP_MISSING_FUNCS 0
#endif

/// \brief  Set to 1 to write a list of all ARB extenions missing from OpenGL 4.4 to std::cout
#ifndef GL4_DUMP_MISSING_EXTENSIONS
# define GL4_DUMP_MISSING_EXTENSIONS 0
#endif

#ifdef __cplusplus
extern "C" {
#endif


/// \brief
extern void initOpenGL();

/// \brief  returns the OpenGL Shading Language Version returned from the driver. 140 == GLSL 1.4, 330 == GLSL 3.3, 500 = GLSL 5.0, etc.
/// \note   This doesn't always mean this is the highest version that can be compiled. In the case of Intel drivers, the max version returned
///         from the driver is 140. The Intel driver however actually compiles GLSL upto version 400. I'd recommend using version 330 as a
///         minimum.
extern uint32_t getGLSLVersion();

/// \brief  returns the minimum OpenGL version from the driver. In some cases, there may be aspects of a newer GL version that are actually supported.
///         If this returns 420+, then all methods in this file are likely to be supported (with some exceptions - such as the vendor specific
///         performance metrics).
extern uint32_t getGLVersion();

/// \brief  bitmask values for all versions of OpenGL from 1.2 to 4.3
enum GLVersion
{
  kVer1_2 = 1 << 0,
  kVer1_3 = 1 << 1,
  kVer1_4 = 1 << 2,
  kVer1_5 = 1 << 3,
  kVer2_0 = 1 << 4,
  kVer2_1 = 1 << 5,
  kVer3_0 = 1 << 6,
  kVer3_1 = 1 << 7,
  kVer3_2 = 1 << 8,
  kVer3_3 = 1 << 9,
  kVer4_0 = 1 << 10,
  kVer4_1 = 1 << 11,
  kVer4_2 = 1 << 12,
  kVer4_3 = 1 << 13,
  kVer4_4 = 1 << 14,
  kVer4_5 = 1 << 15
};

/// \brief  returns a bitmask of the OpenGL versions found
extern uint32_t glVersionBits();

/// \brief  first set of bitmask values for the ARB extensions available. For my needs really...
enum GLExtension1
{
  kGL_ARB_color_buffer_float = 1 << 0,
  kGL_ARB_draw_buffers = 1 << 1,
  kGL_ARB_program_interface_query = 1 << 2,
  kGL_ARB_multisample = 1 << 3,
  kGL_ARB_framebuffer_object = 1 << 4,
  kGL_ARB_map_buffer_range = 1 << 5,
  kGL_ARB_sampler_objects = 1 << 6,
  kGL_ARB_copy_buffer = 1 << 7,
  kGL_ARB_draw_elements_base_vertex = 1 << 8,
  kGL_ARB_uniform_buffer_object = 1 << 9,
  kGL_ARB_provoking_vertex = 1 << 10,
  kGL_ARB_vertex_array_object = 1 << 11,
  kGL_ARB_timer_query = 1 << 12,
  kGL_ARB_clear_texture = 1 << 13,
  kGL_ARB_clear_buffer_object = 1 << 14,
  kGL_ARB_cl_event = 1 << 15,
  kGL_ARB_buffer_storage = 1 << 16,
  kGL_ARB_bindless_texture = 1 << 17,
  kGL_ARB_base_instance = 1 << 18,
  kGL_ARB_sync = 1 << 19,
  kGL_ARB_transform_feedback3 = 1 << 20,
  kGL_ARB_transform_feedback_instanced = 1 << 21,
  kGL_ARB_multi_bind = 1 << 22,
  kGL_ARB_blend_func_extended = 1 << 23,
  kGL_ARB_shader_image_load_store = 1 << 24,
  kGL_ARB_separate_shader_objects = 1 << 25,
  kGL_ARB_vertex_attrib_binding = 1 << 26,
  kGL_ARB_transform_feedback2 = 1 << 27,
  kGL_INTEL_map_texture = 1 << 28,
  kGL_INTEL_performance_queries = 1 << 29,
  kGL_ARB_viewport_array = 1 << 30,
  kGL_ARB_ES2_compatibility = 1 << 31
};

/// \brief  returns a bitmask of the OpenGL ARB extenions found. For my needs really...
extern uint32_t glExtension1Bits();

/// \brief  second set of bitmask values for the ARB extensions available. For my needs really...
enum GLExtension2
{
  kGL_KHR_debug = 1 << 0,
  kGL_ARB_compute_shader = 1 << 1,
  kGL_ARB_framebuffer_no_attachments = 1 << 2,
  kGL_ARB_draw_indirect = 1 << 3,
  kGL_ARB_shader_subroutine = 1 << 4,
  kGL_ARB_shader_atomic_counters = 1 << 5,
  kGL_ARB_internalformat_query = 1 << 6,
  kGL_ARB_internalformat_query2 = 1 << 7,
  kGL_ARB_texture_multisample = 1 << 8,
  kGL_ARB_gpu_shader_fp64 = 1 << 9,
  kGL_ARB_vertex_attrib_64bit = 1 << 10,
  kGL_ARB_invalidate_subdata = 1 << 11,
  kGL_ARB_multi_draw_indirect = 1 << 12,
  kGL_ARB_tessellation_shader = 1 << 13,
  kGL_ARB_shader_storage_buffer_object = 1 << 14,
  kGL_ARB_texture_buffer_range = 1 << 15,
  kGL_ARB_texture_storage = 1 << 16,
  kGL_ARB_texture_view = 1 << 17,
  kGL_ARB_get_program_binary = 1 << 18
};

/// \brief  returns a bitmask of the OpenGL ARB extenions found. For my needs really...
extern uint32_t glExtension2Bits();

#define GLAPI __declspec(dllimport)
#define GLAPIENTRY __stdcall

typedef char GLchar;
typedef struct __GLsync* GLsync;
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
typedef int64_t GLint64;
typedef uint64_t GLuint64;

/* --------------------- WGL_ARB_create_context_profile -------------------- */

#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_CONTEXT_DEBUG_BIT_ARB 0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x0002
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define ERROR_INVALID_VERSION_ARB 0x2095
#define ERROR_INVALID_PROFILE_ARB 0x2096

// The OpenGL 4.4 core API
#ifndef __gl_h_
#ifndef __GL_H__

#define __gl_h_
#define __GL_H__


// typedefs
typedef uint32_t GLenum;
typedef uint8_t GLboolean;
typedef uint32_t GLbitfield;
typedef signed char GLbyte;
typedef int16_t GLshort;
typedef int32_t GLint;
typedef int32_t GLsizei;
typedef uint8_t GLubyte;
typedef uint16_t GLushort;
typedef uint32_t GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

// Some magic numbers for OpenGL constants

/* ----------------------------- GL_VERSION_1_1 ---------------------------- */

#define GL_ZERO 0
#define GL_FALSE 0
#define GL_LOGIC_OP 0x0BF1
#define GL_NONE 0
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_NO_ERROR 0
#define GL_POINTS 0x0000
#define GL_CURRENT_BIT 0x00000001
#define GL_TRUE 1
#define GL_ONE 1
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_POINT_BIT 0x00000002
#define GL_LINE_STRIP 0x0003
#define GL_LINE_BIT 0x00000004
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON 0x0009
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_OUT_OF_MEMORY 0x0505
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_VIEWPORT_BIT 0x00000800
#define GL_EXP2 0x0801
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_POINT_SMOOTH 0x0B10
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_EDGE_FLAG 0x0B43
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_VIEWPORT 0x0BA2
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_AUTO_NORMAL 0x0D80
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TRANSFORM_BIT 0x00001000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_BORDER 0x1005
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_POSITION 0x1203
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_DOUBLE 0x140A
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_COLOR_INDEXES 0x1603
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_COLOR_INDEX 0x1900
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_ENABLE_BIT 0x00002000
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_HINT_BIT 0x00008000
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003

GLAPI void GLAPIENTRY glBindTexture (GLenum target, GLuint texture);
GLAPI void GLAPIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
GLAPI void GLAPIENTRY glClear (GLbitfield mask);
GLAPI void GLAPIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GLAPI void GLAPIENTRY glClearDepth (GLclampd depth);
GLAPI void GLAPIENTRY glClearStencil (GLint s);
GLAPI void GLAPIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void GLAPIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void GLAPIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void GLAPIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void GLAPIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glCullFace (GLenum mode);
GLAPI void GLAPIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void GLAPIENTRY glDepthFunc (GLenum func);
GLAPI void GLAPIENTRY glDepthMask (GLboolean flag);
GLAPI void GLAPIENTRY glDepthRange (GLclampd zNear, GLclampd zFar);
GLAPI void GLAPIENTRY glDisable (GLenum cap);
GLAPI void GLAPIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GLAPI void GLAPIENTRY glDrawBuffer (GLenum mode);
GLAPI void GLAPIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
GLAPI void GLAPIENTRY glEnable (GLenum cap);
GLAPI void GLAPIENTRY glFinish (void);
GLAPI void GLAPIENTRY glFlush (void);
GLAPI void GLAPIENTRY glFrontFace (GLenum mode);
GLAPI void GLAPIENTRY glGenTextures (GLsizei n, GLuint *textures);
GLAPI void GLAPIENTRY glGetBooleanv (GLenum pname, GLboolean *params);
GLAPI void GLAPIENTRY glGetDoublev (GLenum pname, GLdouble *params);
GLAPI GLenum GLAPIENTRY glGetError (void);
GLAPI void GLAPIENTRY glGetFloatv (GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetIntegerv (GLenum pname, GLint *params);
GLAPI const GLubyte * GLAPIENTRY glGetString (GLenum name);
GLAPI void GLAPIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
GLAPI void GLAPIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void GLAPIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void GLAPIENTRY glHint (GLenum target, GLenum mode);
GLAPI GLboolean GLAPIENTRY glIsEnabled (GLenum cap);
GLAPI GLboolean GLAPIENTRY glIsTexture (GLuint texture);
GLAPI void GLAPIENTRY glLineWidth (GLfloat width);
GLAPI void GLAPIENTRY glLogicOp (GLenum opcode);
GLAPI void GLAPIENTRY glPixelStoref (GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glPixelStorei (GLenum pname, GLint param);
GLAPI void GLAPIENTRY glPointSize (GLfloat size);
GLAPI void GLAPIENTRY glPolygonMode (GLenum face, GLenum mode);
GLAPI void GLAPIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
GLAPI void GLAPIENTRY glReadBuffer (GLenum mode);
GLAPI void GLAPIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
GLAPI void GLAPIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void GLAPIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
GLAPI void GLAPIENTRY glStencilMask (GLuint mask);
GLAPI void GLAPIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void GLAPIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GLAPI void GLAPIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void GLAPIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void GLAPIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void GLAPIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
GLAPI void GLAPIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);

#endif
#endif

/* ----------------------------- GL_VERSION_1_2 ---------------------------- */
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_RESCALE_NORMAL 0x803A
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E

typedef void (GLAPIENTRY* PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (GLAPIENTRY* PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (GLAPIENTRY* PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);

GL_EXPORT extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;
GL_EXPORT extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
GL_EXPORT extern PFNGLTEXIMAGE3DPROC glTexImage3D;
GL_EXPORT extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;

/* ----------------------------- GL_VERSION_1_3 ---------------------------- */
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_SUBTRACT 0x84E7
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_MULTISAMPLE_BIT 0x20000000

typedef void (GLAPIENTRY* PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (GLAPIENTRY* PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
typedef void (GLAPIENTRY* PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLvoid *img);
typedef void (GLAPIENTRY* PFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);

GL_EXPORT extern PFNGLACTIVETEXTUREPROC glActiveTexture;
GL_EXPORT extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
GL_EXPORT extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
GL_EXPORT extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
GL_EXPORT extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
GL_EXPORT extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
GL_EXPORT extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
GL_EXPORT extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
GL_EXPORT extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;

/* ----------------------------- GL_VERSION_1_4 ---------------------------- */
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_COMPARE_R_TO_TEXTURE 0x884E

typedef void (GLAPIENTRY* PFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (GLAPIENTRY* PFNGLBLENDEQUATIONPROC) (GLenum mode);
typedef void (GLAPIENTRY* PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (GLAPIENTRY* PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
typedef void (GLAPIENTRY* PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const GLvoid **indices, GLsizei drawcount);
typedef void (GLAPIENTRY* PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (GLAPIENTRY* PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
typedef void (GLAPIENTRY* PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (GLAPIENTRY* PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);

GL_EXPORT extern PFNGLBLENDCOLORPROC glBlendColor;
GL_EXPORT extern PFNGLBLENDEQUATIONPROC glBlendEquation;
GL_EXPORT extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
GL_EXPORT extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
GL_EXPORT extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
GL_EXPORT extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
GL_EXPORT extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
GL_EXPORT extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
GL_EXPORT extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;

/* ----------------------------- GL_VERSION_1_5 ---------------------------- */
#define GL_FOG_COORD_SRC GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD GL_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY GL_FOG_COORDINATE_ARRAY
#define GL_SRC0_RGB GL_SOURCE0_RGB
#define GL_FOG_COORD_ARRAY_POINTER GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY_TYPE GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_SRC1_ALPHA GL_SOURCE1_ALPHA
#define GL_CURRENT_FOG_COORD GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_STRIDE GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_SRC0_ALPHA GL_SOURCE0_ALPHA
#define GL_SRC1_RGB GL_SOURCE1_RGB
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC2_ALPHA GL_SOURCE2_ALPHA
#define GL_SRC2_RGB GL_SOURCE2_RGB
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914

typedef void (GLAPIENTRY* PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (GLAPIENTRY* PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (GLAPIENTRY* PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRY* PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef void (GLAPIENTRY* PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint* buffers);
typedef void (GLAPIENTRY* PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint* ids);
typedef void (GLAPIENTRY* PFNGLENDQUERYPROC) (GLenum target);
typedef void (GLAPIENTRY* PFNGLGENBUFFERSPROC) (GLsizei n, GLuint* buffers);
typedef void (GLAPIENTRY* PFNGLGENQUERIESPROC) (GLsizei n, GLuint* ids);
typedef void (GLAPIENTRY* PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, GLvoid** params);
typedef void (GLAPIENTRY* PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid* data);
typedef void (GLAPIENTRY* PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint* params);
typedef void (GLAPIENTRY* PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRY* PFNGLISBUFFERPROC) (GLuint buffer);
typedef GLboolean (GLAPIENTRY* PFNGLISQUERYPROC) (GLuint id);
typedef GLvoid* (GLAPIENTRY* PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean (GLAPIENTRY* PFNGLUNMAPBUFFERPROC) (GLenum target);

GL_EXPORT extern PFNGLBEGINQUERYPROC glBeginQuery;
GL_EXPORT extern PFNGLBINDBUFFERPROC _glBindBuffer;
GL_EXPORT void glBindBuffer(GLenum target, GLuint buffer);
GL_EXPORT extern PFNGLBUFFERDATAPROC glBufferData;
GL_EXPORT extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
GL_EXPORT extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
GL_EXPORT extern PFNGLDELETEQUERIESPROC glDeleteQueries;
GL_EXPORT extern PFNGLENDQUERYPROC glEndQuery;
GL_EXPORT extern PFNGLGENBUFFERSPROC glGenBuffers;
GL_EXPORT extern PFNGLGENQUERIESPROC glGenQueries;
GL_EXPORT extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
GL_EXPORT extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
GL_EXPORT extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
GL_EXPORT extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
GL_EXPORT extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
GL_EXPORT extern PFNGLGETQUERYIVPROC glGetQueryiv;
GL_EXPORT extern PFNGLISBUFFERPROC glIsBuffer;
GL_EXPORT extern PFNGLISQUERYPROC glIsQuery;
GL_EXPORT extern PFNGLMAPBUFFERPROC glMapBuffer;
GL_EXPORT extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;

/* ----------------------------- GL_VERSION_2_0 ---------------------------- */
#define GL_BLEND_EQUATION_RGB GL_BLEND_EQUATION
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

typedef void (GLAPIENTRY* PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (GLAPIENTRY* PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar* name);
typedef void (GLAPIENTRY* PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum, GLenum);
typedef void (GLAPIENTRY* PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint (GLAPIENTRY* PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint (GLAPIENTRY* PFNGLCREATESHADERPROC) (GLenum type);
typedef void (GLAPIENTRY* PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRY* PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (GLAPIENTRY* PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (GLAPIENTRY* PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint);
typedef void (GLAPIENTRY* PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum* bufs);
typedef void (GLAPIENTRY* PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint);
typedef void (GLAPIENTRY* PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef void (GLAPIENTRY* PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei maxLength, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef GLint (GLAPIENTRY* PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (GLAPIENTRY* PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint* param);
typedef void (GLAPIENTRY* PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (GLAPIENTRY* PFNGLGETSHADERSOURCEPROC) (GLuint obj, GLsizei maxLength, GLsizei* length, GLchar* source);
typedef void (GLAPIENTRY* PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* param);
typedef GLint (GLAPIENTRY* PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (GLAPIENTRY* PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat* params);
typedef void (GLAPIENTRY* PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint, GLenum, GLvoid**);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBDVPROC) (GLuint, GLenum, GLdouble*);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBFVPROC) (GLuint, GLenum, GLfloat*);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBIVPROC) (GLuint, GLenum, GLint*);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint, GLenum, GLvoid**);
typedef GLboolean (GLAPIENTRY* PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean (GLAPIENTRY* PFNGLISSHADERPROC) (GLuint shader);
typedef void (GLAPIENTRY* PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRY* PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar** strings, const GLint* lengths);
typedef void (GLAPIENTRY* PFNGLSTENCILFUNCSEPARATEPROC) (GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
typedef void (GLAPIENTRY* PFNGLSTENCILMASKSEPARATEPROC) (GLenum, GLuint);
typedef void (GLAPIENTRY* PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (GLAPIENTRY* PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (GLAPIENTRY* PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (GLAPIENTRY* PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAPIENTRY* PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (GLAPIENTRY* PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAPIENTRY* PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAPIENTRY* PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAPIENTRY* PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAPIENTRY* PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRY* PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBPOINTERPROC) (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*);

GL_EXPORT extern PFNGLATTACHSHADERPROC glAttachShader;
GL_EXPORT extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
GL_EXPORT extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
GL_EXPORT extern PFNGLCOMPILESHADERPROC glCompileShader;
GL_EXPORT extern PFNGLCREATEPROGRAMPROC glCreateProgram;
GL_EXPORT extern PFNGLCREATESHADERPROC glCreateShader;
GL_EXPORT extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
GL_EXPORT extern PFNGLDELETESHADERPROC glDeleteShader;
GL_EXPORT extern PFNGLDETACHSHADERPROC glDetachShader;
GL_EXPORT extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
GL_EXPORT extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
GL_EXPORT extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
GL_EXPORT extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
GL_EXPORT extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
GL_EXPORT extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
GL_EXPORT extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
GL_EXPORT extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
GL_EXPORT extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
GL_EXPORT extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
GL_EXPORT extern PFNGLGETSHADERSOURCEPROC glGetShaderSource;
GL_EXPORT extern PFNGLGETSHADERIVPROC glGetShaderiv;
GL_EXPORT extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
GL_EXPORT extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
GL_EXPORT extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
GL_EXPORT extern PFNGLISPROGRAMPROC glIsProgram;
GL_EXPORT extern PFNGLISSHADERPROC glIsShader;
GL_EXPORT extern PFNGLLINKPROGRAMPROC glLinkProgram;
GL_EXPORT extern PFNGLSHADERSOURCEPROC glShaderSource;
GL_EXPORT extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
GL_EXPORT extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
GL_EXPORT extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
GL_EXPORT extern PFNGLUNIFORM1FPROC glUniform1f;
GL_EXPORT extern PFNGLUNIFORM1FVPROC glUniform1fv;
GL_EXPORT extern PFNGLUNIFORM1IPROC glUniform1i;
GL_EXPORT extern PFNGLUNIFORM1IVPROC glUniform1iv;
GL_EXPORT extern PFNGLUNIFORM2FPROC glUniform2f;
GL_EXPORT extern PFNGLUNIFORM2FVPROC glUniform2fv;
GL_EXPORT extern PFNGLUNIFORM2IPROC glUniform2i;
GL_EXPORT extern PFNGLUNIFORM2IVPROC glUniform2iv;
GL_EXPORT extern PFNGLUNIFORM3FPROC glUniform3f;
GL_EXPORT extern PFNGLUNIFORM3FVPROC glUniform3fv;
GL_EXPORT extern PFNGLUNIFORM3IPROC glUniform3i;
GL_EXPORT extern PFNGLUNIFORM3IVPROC glUniform3iv;
GL_EXPORT extern PFNGLUNIFORM4FPROC glUniform4f;
GL_EXPORT extern PFNGLUNIFORM4FVPROC glUniform4fv;
GL_EXPORT extern PFNGLUNIFORM4IPROC glUniform4i;
GL_EXPORT extern PFNGLUNIFORM4IVPROC glUniform4iv;
GL_EXPORT extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
GL_EXPORT extern PFNGLUSEPROGRAMPROC glUseProgram;
GL_EXPORT extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
GL_EXPORT extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

/* ----------------------------- GL_VERSION_2_1 ---------------------------- */
#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B

typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

GL_EXPORT extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

/* ----------------------------- GL_VERSION_3_0 ---------------------------- */
#define GL_MAX_CLIP_DISTANCES GL_MAX_CLIP_PLANES
#define GL_CLIP_DISTANCE5 GL_CLIP_PLANE5
#define GL_CLIP_DISTANCE1 GL_CLIP_PLANE1
#define GL_CLIP_DISTANCE3 GL_CLIP_PLANE3
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 GL_CLIP_PLANE0
#define GL_CLIP_DISTANCE4 GL_CLIP_PLANE4
#define GL_CLIP_DISTANCE2 GL_CLIP_PLANE2
#define GL_MAX_VARYING_COMPONENTS GL_MAX_VARYING_FLOATS
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_DEPTH_BUFFER 0x8223
#define GL_STENCIL_BUFFER 0x8224
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_ALPHA_INTEGER 0x8D97
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16

typedef void (GLAPIENTRY* PFNGLBEGINCONDITIONALRENDERPROC) (GLuint, GLenum);
typedef void (GLAPIENTRY* PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum);
typedef void (GLAPIENTRY* PFNGLBINDFRAGDATALOCATIONPROC) (GLuint, GLuint, const GLchar*);
typedef void (GLAPIENTRY* PFNGLCLAMPCOLORPROC) (GLenum, GLenum);
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERFIPROC) (GLenum, GLint, GLfloat, GLint);
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERFVPROC) (GLenum, GLint, const GLfloat*);
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERIVPROC) (GLenum, GLint, const GLint*);
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERUIVPROC) (GLenum, GLint, const GLuint*);
typedef void (GLAPIENTRY* PFNGLCOLORMASKIPROC) (GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
typedef void (GLAPIENTRY* PFNGLDISABLEIPROC) (GLenum, GLuint);
typedef void (GLAPIENTRY* PFNGLENABLEIPROC) (GLenum, GLuint);
typedef void (GLAPIENTRY* PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (GLAPIENTRY* PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (GLAPIENTRY* PFNGLGETBOOLEANI_VPROC) (GLenum, GLuint, GLboolean*);
typedef GLint (GLAPIENTRY* PFNGLGETFRAGDATALOCATIONPROC) (GLuint, const GLchar*);
typedef const GLubyte* (GLAPIENTRY* PFNGLGETSTRINGIPROC) (GLenum, GLuint);
typedef void (GLAPIENTRY* PFNGLGETTEXPARAMETERIIVPROC) (GLenum, GLenum, GLint*);
typedef void (GLAPIENTRY* PFNGLGETTEXPARAMETERIUIVPROC) (GLenum, GLenum, GLuint*);
typedef void (GLAPIENTRY* PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
typedef void (GLAPIENTRY* PFNGLGETUNIFORMUIVPROC) (GLuint, GLint, GLuint*);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBIIVPROC) (GLuint, GLenum, GLint*);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint, GLenum, GLuint*);
typedef GLboolean (GLAPIENTRY* PFNGLISENABLEDIPROC) (GLenum, GLuint);
typedef void (GLAPIENTRY* PFNGLTEXPARAMETERIIVPROC) (GLenum, GLenum, const GLint*);
typedef void (GLAPIENTRY* PFNGLTEXPARAMETERIUIVPROC) (GLenum, GLenum, const GLuint*);
typedef void (GLAPIENTRY* PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint, GLsizei, const GLchar **, GLenum);
typedef void (GLAPIENTRY* PFNGLUNIFORM1UIPROC) (GLint, GLuint);
typedef void (GLAPIENTRY* PFNGLUNIFORM1UIVPROC) (GLint, GLsizei, const GLuint*);
typedef void (GLAPIENTRY* PFNGLUNIFORM2UIPROC) (GLint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLUNIFORM2UIVPROC) (GLint, GLsizei, const GLuint*);
typedef void (GLAPIENTRY* PFNGLUNIFORM3UIPROC) (GLint, GLuint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLUNIFORM3UIVPROC) (GLint, GLsizei, const GLuint*);
typedef void (GLAPIENTRY* PFNGLUNIFORM4UIPROC) (GLint, GLuint, GLuint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLUNIFORM4UIVPROC) (GLint, GLsizei, const GLuint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI1IPROC) (GLuint, GLint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI1IVPROC) (GLuint, const GLint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI1UIPROC) (GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI1UIVPROC) (GLuint, const GLuint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI2IPROC) (GLuint, GLint, GLint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI2IVPROC) (GLuint, const GLint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI2UIPROC) (GLuint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI2UIVPROC) (GLuint, const GLuint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI3IPROC) (GLuint, GLint, GLint, GLint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI3IVPROC) (GLuint, const GLint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI3UIPROC) (GLuint, GLuint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI3UIVPROC) (GLuint, const GLuint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4BVPROC) (GLuint, const GLbyte*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4IPROC) (GLuint, GLint, GLint, GLint, GLint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4IVPROC) (GLuint, const GLint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4SVPROC) (GLuint, const GLshort*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4UBVPROC) (GLuint, const GLubyte*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4UIPROC) (GLuint, GLuint, GLuint, GLuint, GLuint);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4UIVPROC) (GLuint, const GLuint*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBI4USVPROC) (GLuint, const GLushort*);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint, GLint, GLenum, GLsizei, const GLvoid*);

GL_EXPORT extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
GL_EXPORT extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
GL_EXPORT extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
GL_EXPORT extern PFNGLCLAMPCOLORPROC glClampColor;
GL_EXPORT extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
GL_EXPORT extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
GL_EXPORT extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
GL_EXPORT extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
GL_EXPORT extern PFNGLCOLORMASKIPROC glColorMaski;
GL_EXPORT extern PFNGLDISABLEIPROC glDisablei;
GL_EXPORT extern PFNGLENABLEIPROC glEnablei;
GL_EXPORT extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
GL_EXPORT extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
GL_EXPORT extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
GL_EXPORT extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
GL_EXPORT extern PFNGLGETSTRINGIPROC glGetStringi;
GL_EXPORT extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
GL_EXPORT extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
GL_EXPORT extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
GL_EXPORT extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
GL_EXPORT extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
GL_EXPORT extern PFNGLISENABLEDIPROC glIsEnabledi;
GL_EXPORT extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
GL_EXPORT extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
GL_EXPORT extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
GL_EXPORT extern PFNGLUNIFORM1UIPROC glUniform1ui;
GL_EXPORT extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
GL_EXPORT extern PFNGLUNIFORM2UIPROC glUniform2ui;
GL_EXPORT extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
GL_EXPORT extern PFNGLUNIFORM3UIPROC glUniform3ui;
GL_EXPORT extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
GL_EXPORT extern PFNGLUNIFORM4UIPROC glUniform4ui;
GL_EXPORT extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
GL_EXPORT extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
GL_EXPORT extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
GL_EXPORT extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
GL_EXPORT extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
GL_EXPORT extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
GL_EXPORT extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
GL_EXPORT extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
GL_EXPORT extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
GL_EXPORT extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
GL_EXPORT extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
GL_EXPORT extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
GL_EXPORT extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
GL_EXPORT extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
GL_EXPORT extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
GL_EXPORT extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
GL_EXPORT extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;

/* ----------------------------- GL_VERSION_3_1 ---------------------------- */
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121

typedef void (GLAPIENTRY* PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum, GLint, GLsizei, GLsizei);
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum, GLsizei, GLenum, const GLvoid*, GLsizei);
typedef void (GLAPIENTRY* PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint);
typedef void (GLAPIENTRY* PFNGLTEXBUFFERPROC) (GLenum, GLenum, GLuint);

GL_EXPORT extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
GL_EXPORT extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
GL_EXPORT extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
GL_EXPORT extern PFNGLTEXBUFFERPROC glTexBuffer;

/* ----------------------------- GL_VERSION_3_2 ---------------------------- */
#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126

typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum, GLenum, GLuint, GLint);
GL_EXPORT extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;

#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum, GLenum, GLint64 *);
typedef void (GLAPIENTRY* PFNGLGETINTEGER64I_VPROC) (GLenum, GLuint, GLint64 *);
GL_EXPORT extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
GL_EXPORT extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
#endif

/* ----------------------------- GL_VERSION_3_3 ---------------------------- */
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_RGB10_A2UI 0x906F

typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);

GL_EXPORT extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;

/* ----------------------------- GL_VERSION_4_0 ---------------------------- */
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

typedef void (GLAPIENTRY* PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAPIENTRY* PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (GLAPIENTRY* PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (GLAPIENTRY* PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);

GL_EXPORT extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
GL_EXPORT extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
GL_EXPORT extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
GL_EXPORT extern PFNGLBLENDFUNCIPROC glBlendFunci;

#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLMINSAMPLESHADINGPROC) (GLclampf value);
GL_EXPORT extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
#endif

/* ----------------------------- GL_VERSION_4_1 ---------------------------- */

/* ----------------------------- GL_VERSION_4_2 ---------------------------- */
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F

/* ----------------------------- GL_VERSION_4_3 ---------------------------- */
#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E

/* ----------------------------- GL_VERSION_4_4 ---------------------------- */
#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5

/* ----------------------------- GL_VERSION_4_5 ---------------------------- */

typedef void (GLAPIENTRY* PFNGLNAMEDBUFFERDATAPROC)(GLuint buffer, GLsizeiptr size, const GLvoid* data, GLenum usage);
typedef void (GLAPIENTRY* PFNGLNAMEDBUFFERSTORAGEPROC)(GLuint buffer, GLsizei size, const void* data, GLbitfield flags);
typedef void (GLAPIENTRY* PFNGLNAMEDBUFFERSUBDATAPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, const GLvoid* data);
typedef GLvoid* (GLAPIENTRY* PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLvoid* (GLAPIENTRY* PFNGLUNMAPNAMEDBUFFERRANGEPROC) (GLuint buffer);
typedef void (GLAPIENTRY* PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid* data);
typedef void (GLAPIENTRY* PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);

// named framebuffer
typedef void (GLAPIENTRY* PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint, GLenum, GLuint, GLint);
typedef void (GLAPIENTRY* PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRY* PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint read, GLuint draw, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (GLAPIENTRY* PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef GLenum (GLAPIENTRY* PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);

// named framebuffer
typedef void (GLAPIENTRY* PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint buffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint buffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint* params);

typedef void (GLAPIENTRY* PFNGLNAMEDTEXSTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (GLAPIENTRY* PFNGLNAMEDTEXSTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLNAMEDTEXSTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);

GL_EXPORT extern PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
GL_EXPORT extern PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
GL_EXPORT extern PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
GL_EXPORT extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
GL_EXPORT extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
GL_EXPORT extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
GL_EXPORT extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
GL_EXPORT extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
GL_EXPORT extern PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
GL_EXPORT extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
GL_EXPORT extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
GL_EXPORT extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
GL_EXPORT extern PFNGLNAMEDTEXSTORAGE1DPROC glNamedTexStorage1D;
GL_EXPORT extern PFNGLNAMEDTEXSTORAGE2DPROC glNamedTexStorage2D;
GL_EXPORT extern PFNGLNAMEDTEXSTORAGE3DPROC glNamedTexStorage3D;
GL_EXPORT extern PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
GL_EXPORT extern PFNGLUNMAPNAMEDBUFFERRANGEPROC glUnmapNamedBuffer;
GL_EXPORT extern PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
GL_EXPORT extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;

/* --------------------------- GL_ARB_sync (GL3.2) ------------------------- */
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF

typedef GLenum (GLAPIENTRY* PFNGLCLIENTWAITSYNCPROC) (GLsync GLsync,GLbitfield flags,GLuint64 timeout);
typedef void (GLAPIENTRY* PFNGLDELETESYNCPROC) (GLsync GLsync);
typedef GLsync (GLAPIENTRY* PFNGLFENCESYNCPROC) (GLenum condition,GLbitfield flags);
typedef void (GLAPIENTRY* PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64* params);
typedef void (GLAPIENTRY* PFNGLGETSYNCIVPROC) (GLsync GLsync,GLenum pname,GLsizei bufSize,GLsizei* length, GLint *values);
typedef GLboolean (GLAPIENTRY* PFNGLISSYNCPROC) (GLsync GLsync);
typedef void (GLAPIENTRY* PFNGLWAITSYNCPROC) (GLsync GLsync,GLbitfield flags,GLuint64 timeout);
        
GL_EXPORT extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
GL_EXPORT extern PFNGLDELETESYNCPROC glDeleteSync;
GL_EXPORT extern PFNGLFENCESYNCPROC glFenceSync;
GL_EXPORT extern PFNGLGETINTEGER64VPROC glGetInteger64v;
GL_EXPORT extern PFNGLGETSYNCIVPROC glGetSynciv;
GL_EXPORT extern PFNGLISSYNCPROC glIsSync;
GL_EXPORT extern PFNGLWAITSYNCPROC glWaitSync;

/* -------------------------- GL_ARB_base_instance ------------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance);
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLuint baseinstance);
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance);

GL_EXPORT extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
GL_EXPORT extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
GL_EXPORT extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
#endif

/* ------------------------ GL_ARB_bindless_texture ------------------------ */
#if !SUPPPORT_INTEL_HD
#define GL_UNSIGNED_INT64_ARB 0x140F

typedef GLuint64 (GLAPIENTRY* PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef GLuint64 (GLAPIENTRY* PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64 (GLAPIENTRY* PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64* params);
typedef GLboolean (GLAPIENTRY* PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean (GLAPIENTRY* PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (GLAPIENTRY* PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (GLAPIENTRY* PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (GLAPIENTRY* PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (GLAPIENTRY* PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* values);
typedef void (GLAPIENTRY* PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (GLAPIENTRY* PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64 x);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64* v);

GL_EXPORT extern PFNGLGETIMAGEHANDLEARBPROC glGetImageHandleARB;
GL_EXPORT extern PFNGLGETTEXTUREHANDLEARBPROC glGetTextureHandleARB;
GL_EXPORT extern PFNGLGETTEXTURESAMPLERHANDLEARBPROC glGetTextureSamplerHandleARB;
GL_EXPORT extern PFNGLGETVERTEXATTRIBLUI64VARBPROC glGetVertexAttribLui64vARB;
GL_EXPORT extern PFNGLISIMAGEHANDLERESIDENTARBPROC glIsImageHandleResidentARB;
GL_EXPORT extern PFNGLISTEXTUREHANDLERESIDENTARBPROC glIsTextureHandleResidentARB;
GL_EXPORT extern PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC glMakeImageHandleNonResidentARB;
GL_EXPORT extern PFNGLMAKEIMAGEHANDLERESIDENTARBPROC glMakeImageHandleResidentARB;
GL_EXPORT extern PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC glMakeTextureHandleNonResidentARB;
GL_EXPORT extern PFNGLMAKETEXTUREHANDLERESIDENTARBPROC glMakeTextureHandleResidentARB;
GL_EXPORT extern PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC glProgramUniformHandleui64ARB;
GL_EXPORT extern PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC glProgramUniformHandleui64vARB;
GL_EXPORT extern PFNGLUNIFORMHANDLEUI64ARBPROC glUniformHandleui64ARB;
GL_EXPORT extern PFNGLUNIFORMHANDLEUI64VARBPROC glUniformHandleui64vARB;
GL_EXPORT extern PFNGLVERTEXATTRIBL1UI64ARBPROC glVertexAttribL1ui64ARB;
GL_EXPORT extern PFNGLVERTEXATTRIBL1UI64VARBPROC glVertexAttribL1ui64vARB;
#endif

/* ------------------------- GL_ARB_buffer_storage ------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_PERSISTENT_BIT 0x00000040
#define GL_MAP_COHERENT_BIT 0x00000080
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220

typedef void (GLAPIENTRY* PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const GLvoid* data, GLbitfield flags);
typedef void (GLAPIENTRY* PFNGLNAMEDBUFFERSTORAGEEXTPROC) (GLuint buffer, GLsizeiptr size, const GLvoid* data, GLbitfield flags);

GL_EXPORT extern PFNGLBUFFERSTORAGEPROC glBufferStorage;
GL_EXPORT extern PFNGLNAMEDBUFFERSTORAGEEXTPROC glNamedBufferStorageEXT;
#endif

/* ---------------------------- GL_ARB_cl_event ---------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241

typedef struct _cl_context* cl_context;
typedef struct _cl_event* cl_event;
typedef GLsync (GLAPIENTRY* PFNGLCREATESYNCFROMCLEVENTARBPROC) (cl_context context, cl_event event, GLbitfield flags);

GL_EXPORT extern PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB;
#endif

/* ----------------------- GL_ARB_clear_buffer_object ---------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRY* PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRY* PFNGLCLEARNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRY* PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const GLvoid* data);

GL_EXPORT extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
GL_EXPORT extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
GL_EXPORT extern PFNGLCLEARNAMEDBUFFERDATAEXTPROC glClearNamedBufferDataEXT;
GL_EXPORT extern PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glClearNamedBufferSubDataEXT;
#endif

/* -------------------------- GL_ARB_clear_texture ------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_CLEAR_TEXTURE 0x9365

typedef void (GLAPIENTRY* PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const GLvoid* data);
typedef void (GLAPIENTRY* PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid* data);

GL_EXPORT extern PFNGLCLEARTEXIMAGEPROC glClearTexImage;
GL_EXPORT extern PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
#endif

/* --------------------------- GL_ARB_copy_buffer -------------------------- */
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37

typedef void (GLAPIENTRY* PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readtarget, GLenum writetarget, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);

GL_EXPORT extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;

/* ----------------------- GL_ARB_texture_rgb10_a2ui ----------------------- */
#define GL_RGB10_A2UI 0x906F

/* ------------------- GL_ARB_vertex_type_2_10_10_10_rev ------------------- */
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_INT_2_10_10_10_REV 0x8D9F

/* --------------------------- GL_ARB_timer_query -------------------------- */
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28

typedef void (GLAPIENTRY* PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64* params);
typedef void (GLAPIENTRY* PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64* params);
typedef void (GLAPIENTRY* PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);

GL_EXPORT extern PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
GL_EXPORT extern PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
GL_EXPORT extern PFNGLQUERYCOUNTERPROC glQueryCounter;

/* ----------------------- GL_ARB_vertex_array_object ---------------------- */
#define GL_VERTEX_ARRAY_BINDING 0x85B5

typedef void (GLAPIENTRY* PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (GLAPIENTRY* PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint* arrays);
typedef void (GLAPIENTRY* PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
typedef GLboolean (GLAPIENTRY* PFNGLISVERTEXARRAYPROC) (GLuint array);

GL_EXPORT extern PFNGLISVERTEXARRAYPROC glBindVertexArray;
GL_EXPORT extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
GL_EXPORT extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
GL_EXPORT extern PFNGLISVERTEXARRAYPROC glIsVertexArray;

/* ------------------------ GL_ARB_provoking_vertex ------------------------ */
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F

typedef void (GLAPIENTRY* PFNGLPROVOKINGVERTEXPROC) (GLenum mode);

GL_EXPORT extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;

/* ------------------------ GL_ARB_seamless_cube_map ----------------------- */
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F

/* ---------------------- GL_ARB_uniform_buffer_object --------------------- */
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF

typedef void (GLAPIENTRY* PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (GLAPIENTRY* PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRY* PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (GLAPIENTRY* PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef void (GLAPIENTRY* PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint* data);
typedef GLuint (GLAPIENTRY* PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar* uniformBlockName);
typedef void (GLAPIENTRY* PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar** uniformNames, GLuint* uniformIndices);
typedef void (GLAPIENTRY* PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

GL_EXPORT extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
GL_EXPORT extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
GL_EXPORT extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
GL_EXPORT extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
GL_EXPORT extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
GL_EXPORT extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
GL_EXPORT extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
GL_EXPORT extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
GL_EXPORT extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
GL_EXPORT extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

/* --------------------------- GL_ARB_depth_clamp -------------------------- */
#define GL_DEPTH_CLAMP 0x864F

/* ------------------------ GL_ARB_vertex_array_bgra ----------------------- */
#define GL_BGRA 0x80E1

/* ----------------------- GL_ARB_shader_bit_encoding ---------------------- */

/* ------------------------ GL_ARB_texture_query_lod ----------------------- */

/* -------------------- GL_ARB_explicit_attrib_location -------------------- */

/* -------------------- GL_ARB_draw_elements_base_vertex ------------------- */
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei primcount, GLint basevertex);
typedef void (GLAPIENTRY* PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex);
typedef void (GLAPIENTRY* PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei* count, GLenum type, const GLvoid* const *indices, GLsizei primcount, const GLint *basevertex);

GL_EXPORT extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
GL_EXPORT extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
GL_EXPORT extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
GL_EXPORT extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;

/* ----------------------- GL_ARB_shader_bit_encoding ---------------------- */

/* ------------------- GL_ARB_fragment_coord_conventions ------------------- */

/* ------------------------- GL_ARB_sampler_objects ------------------------ */
#define GL_SAMPLER_BINDING 0x8919

typedef void (GLAPIENTRY* PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (GLAPIENTRY* PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint * samplers);
typedef void (GLAPIENTRY* PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint* samplers);
typedef void (GLAPIENTRY* PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint* params);
typedef void (GLAPIENTRY* PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat* params);
typedef void (GLAPIENTRY* PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRY* PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint* params);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint* params);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat* params);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (GLAPIENTRY* PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint* params);

GL_EXPORT extern PFNGLBINDSAMPLERPROC glBindSampler;
GL_EXPORT extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
GL_EXPORT extern PFNGLGENSAMPLERSPROC glGenSamplers;
GL_EXPORT extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
GL_EXPORT extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
GL_EXPORT extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
GL_EXPORT extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
GL_EXPORT extern PFNGLISSAMPLERPROC glIsSampler;
GL_EXPORT extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
GL_EXPORT extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
GL_EXPORT extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
GL_EXPORT extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
GL_EXPORT extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
GL_EXPORT extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;

/* ------------------------ GL_ARB_map_buffer_range ------------------------ */
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020

typedef void (GLAPIENTRY* PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef GLvoid* (GLAPIENTRY* PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);

GL_EXPORT extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
GL_EXPORT extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;

/* ----------------------- GL_ARB_framebuffer_object ----------------------- */
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_INDEX 0x8222
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_SRGB 0x8C40
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57

typedef void (GLAPIENTRY* PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (GLAPIENTRY* PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (GLAPIENTRY* PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (GLAPIENTRY* PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (GLAPIENTRY* PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint* framebuffers);
typedef void (GLAPIENTRY* PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint* renderbuffers);
typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint layer);
typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target,GLenum attachment, GLuint texture,GLint level,GLint layer);
typedef void (GLAPIENTRY* PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint* framebuffers);
typedef void (GLAPIENTRY* PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint* renderbuffers);
typedef void (GLAPIENTRY* PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (GLAPIENTRY* PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRY* PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef GLboolean (GLAPIENTRY* PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (GLAPIENTRY* PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);

GL_EXPORT extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
GL_EXPORT extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
GL_EXPORT extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
GL_EXPORT extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
GL_EXPORT extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
GL_EXPORT extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
GL_EXPORT extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
GL_EXPORT extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
GL_EXPORT extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
GL_EXPORT extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
GL_EXPORT extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
GL_EXPORT extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
GL_EXPORT extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
GL_EXPORT extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
GL_EXPORT extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
GL_EXPORT extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
GL_EXPORT extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
GL_EXPORT extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
GL_EXPORT extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
GL_EXPORT extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;

/* ----------------------- GL_ARB_depth_buffer_float ----------------------- */
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD

/* ------------------------ GL_ARB_framebuffer_sRGB ------------------------ */
#define GL_FRAMEBUFFER_SRGB 0x8DB9

/* --------------------------- GL_ARB_texture_rg --------------------------- */
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C

/* -------------------- GL_ARB_texture_compression_rgtc -------------------- */
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE

/* -------------------------- GL_ARB_point_sprite -------------------------- */
// In GL2.0

/* --------------------- GL_ARB_program_interface_query -------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_IS_PER_PATCH 0x92E7
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F

typedef void (GLAPIENTRY* PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint* params);
typedef GLuint (GLAPIENTRY* PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint (GLAPIENTRY* PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint (GLAPIENTRY* PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar *name);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei bufSize, GLsizei *length, GLint *params);

GL_EXPORT extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
GL_EXPORT extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
GL_EXPORT extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
GL_EXPORT extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
GL_EXPORT extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
GL_EXPORT extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
#endif

/* --------------------- GL_ARB_fragment_program_shadow -------------------- */

/* -------------------------- GL_ARB_depth_texture ------------------------- */
#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B

/* ------------------------ GL_ARB_texture_rectangle ----------------------- */
#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64

/* ----------------------- GL_ARB_draw_buffers_blend ----------------------- */
// In GL4.0

/* ----------------------- GL_ARB_color_buffer_float ----------------------- */
#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_FIXED_ONLY_ARB 0x891D

typedef void (GLAPIENTRY* PFNGLCLAMPCOLORARBPROC) (GLenum target, GLenum clamp);

GL_EXPORT extern PFNGLCLAMPCOLORARBPROC glClampColorARB;

/* -------------------------- GL_ARB_compatibility ------------------------- */

/* ------------------------ GL_ARB_half_float_pixel ------------------------ */
#define GL_HALF_FLOAT_ARB 0x140B

/* -------------------------- GL_ARB_texture_float ------------------------- */
#define GL_RGBA32F_ARB 0x8814
#define GL_RGB32F_ARB 0x8815
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGBA16F_ARB 0x881A
#define GL_RGB16F_ARB 0x881B
#define GL_ALPHA16F_ARB 0x881C
#define GL_INTENSITY16F_ARB 0x881D
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F
#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17

/* ----------------------- GL_ARB_pixel_buffer_object ---------------------- */
#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF

/* ------------------------- GL_ARB_draw_instanced ------------------------- */

/* ------------------------ GL_ARB_half_float_vertex ----------------------- */
#define GL_HALF_FLOAT 0x140B

/* ------------------------ GL_ARB_occlusion_query2 ------------------------ */
#define GL_ANY_SAMPLES_PASSED 0x8C2F

/* ------------------------ GL_ARB_fragment_program ------------------------ */
#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872

/* ------------------------- GL_ARB_fragment_shader ------------------------ */
#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B

/* ------------------------ GL_ARB_instanced_arrays ------------------------ */
// In GL3.1

/* ------------------------- GL_ARB_occlusion_query ------------------------ */
// In GL1.5

/* ------------------------ GL_ARB_point_parameters ------------------------ */
// In GL1.4

/* ------------------------- GL_ARB_shader_objects ------------------------- */
// In GL2.0

/* ----------------------------- GL_ARB_shadow ----------------------------- */
// In GL1.4

/* ----------------------- GL_ARB_transform_feedback3 ---------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#define GL_MAX_VERTEX_STREAMS 0x8E71

typedef void (GLAPIENTRY* PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (GLAPIENTRY* PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (GLAPIENTRY* PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (GLAPIENTRY* PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint* params);

GL_EXPORT extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
GL_EXPORT extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
GL_EXPORT extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
GL_EXPORT extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;
#endif

/* ------------------ GL_ARB_transform_feedback_instanced ------------------ */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei primcount);
typedef void (GLAPIENTRY* PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei primcount);

GL_EXPORT extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
GL_EXPORT extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;
#endif

/* --------------------------- GL_ARB_multi_bind --------------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (GLAPIENTRY* PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
typedef void (GLAPIENTRY* PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRY* PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint* samplers);
typedef void (GLAPIENTRY* PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint* textures);
typedef void (GLAPIENTRY* PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizei *strides);

GL_EXPORT extern PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
GL_EXPORT extern PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
GL_EXPORT extern PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
GL_EXPORT extern PFNGLBINDSAMPLERSPROC glBindSamplers;
GL_EXPORT extern PFNGLBINDTEXTURESPROC glBindTextures;
GL_EXPORT extern PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;
#endif

/* ----------------------- GL_ARB_blend_func_extended ---------------------- */
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC

typedef void (GLAPIENTRY* PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar * name);
typedef GLint (GLAPIENTRY* PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar * name);

GL_EXPORT extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
GL_EXPORT extern PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;

/* --------------------- GL_ARB_shader_image_load_store -------------------- */
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF

typedef void (GLAPIENTRY* PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (GLAPIENTRY* PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);

GL_EXPORT extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
GL_EXPORT extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;

/* --------------------- GL_ARB_separate_shader_objects -------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_ALL_SHADER_BITS 0xFFFFFFFF

typedef void (GLAPIENTRY* PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef void (GLAPIENTRY* PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef GLuint (GLAPIENTRY* PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar ** strings);
typedef void (GLAPIENTRY* PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint* pipelines);
typedef void (GLAPIENTRY* PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint* pipelines);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar *infoLog);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint* params);
typedef GLboolean (GLAPIENTRY* PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble x);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat x);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint x);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint x);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat x, GLfloat y);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint x, GLint y);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint x, GLuint y);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint x, GLint y, GLint z);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint x, GLuint y, GLuint z);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (GLAPIENTRY* PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (GLAPIENTRY* PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);

GL_EXPORT extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
GL_EXPORT extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
GL_EXPORT extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
GL_EXPORT extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
GL_EXPORT extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
GL_EXPORT extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
GL_EXPORT extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
GL_EXPORT extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
GL_EXPORT extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
GL_EXPORT extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
GL_EXPORT extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
GL_EXPORT extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
GL_EXPORT extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
GL_EXPORT extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
GL_EXPORT extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
#endif

/* ---------------------- GL_ARB_vertex_attrib_binding --------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA

typedef void (GLAPIENTRY* PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (GLAPIENTRY* PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);

GL_EXPORT extern PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
GL_EXPORT extern PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
GL_EXPORT extern PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
GL_EXPORT extern PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
GL_EXPORT extern PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
GL_EXPORT extern PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
#endif

/* ----------------------- GL_ARB_transform_feedback2 ---------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25

typedef void (GLAPIENTRY* PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (GLAPIENTRY* PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint* ids);
typedef void (GLAPIENTRY* PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (GLAPIENTRY* PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint* ids);
typedef GLboolean (GLAPIENTRY* PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (GLAPIENTRY* PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (GLAPIENTRY* PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);

GL_EXPORT extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
GL_EXPORT extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
GL_EXPORT extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
GL_EXPORT extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
GL_EXPORT extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
GL_EXPORT extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
GL_EXPORT extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
#endif

/* -------------------------- GL_INTEL_map_texture ------------------------- */
#define GL_LAYOUT_DEFAULT_INTEL 0
#define GL_LAYOUT_LINEAR_INTEL 1
#define GL_LAYOUT_LINEAR_CPU_CACHED_INTEL 2
#define GL_TEXTURE_MEMORY_LAYOUT_INTEL 0x83FF

typedef GLvoid * (GLAPIENTRY* PFNGLMAPTEXTURE2DINTELPROC) (GLuint texture, GLint level, GLbitfield access, GLint* stride, GLenum *layout);
typedef void (GLAPIENTRY* PFNGLSYNCTEXTUREINTELPROC) (GLuint texture);
typedef void (GLAPIENTRY* PFNGLUNMAPTEXTURE2DINTELPROC) (GLuint texture, GLint level);

GL_EXPORT extern PFNGLMAPTEXTURE2DINTELPROC glMapTexture2DINTEL;
GL_EXPORT extern PFNGLSYNCTEXTUREINTELPROC glSyncTextureINTEL;
GL_EXPORT extern PFNGLUNMAPTEXTURE2DINTELPROC glUnmapTexture2DINTEL;

/* ---------------------- GL_INTEL_performance_queries --------------------- */
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x0000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x0001
#define GL_PERFQUERY_WAIT_INTEL 0x83FB
#define GL_PERFQUERY_FLUSH_INTEL 0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL 0x83F9
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL 0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500

typedef void (GLAPIENTRY* PFNGLGETFIRSTPERFQUERYIDINTELPROC) (GLuint* queryId);
typedef void (GLAPIENTRY* PFNGLGETNEXTPERFQUERYIDINTELPROC) (GLuint queryId, GLuint* nextQueryId);
typedef void (GLAPIENTRY* PFNGLGETPERFQUERYIDBYNAMEINTELPROC) (const GLchar* queryName, GLuint* queryId);
typedef void (GLAPIENTRY* PFNGLGETPERFQUERYINFOINTELPROC) (GLuint queryId, GLuint queryNameLength, GLchar* queryName, GLuint* dataSize, GLuint* noCounters, GLuint* noInstances, GLuint* capsMask);
typedef void (GLAPIENTRY* PFNGLGETPERFCOUNTERINFOINTELPROC) (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar* counterName, GLuint counterDsecLength, GLchar* counterDesc,
                                                   GLuint* counterOffset, GLuint* counterDataSize, GLuint* counterTypeEnum, GLuint* counterDataTypeEnum, GLuint64* rawCounterMaxValue);
typedef void (GLAPIENTRY* PFNGLCREATEPERFQUERYINTELPROC) (GLuint queryId, GLuint* queryHandle);
typedef void (GLAPIENTRY* PFNGLDELETEPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (GLAPIENTRY* PFNGLBEGINPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (GLAPIENTRY* PFNGLENDPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (GLAPIENTRY* PFNGLGETPERFQUERYDATAINTELPROC) (GLuint queryHandle, GLuint flags, GLsizei dataSize, GLvoid* data, GLuint* bytesWritten);

GL_EXPORT extern PFNGLGETFIRSTPERFQUERYIDINTELPROC glGetFirstPerfQueryIdINTEL;
GL_EXPORT extern PFNGLGETNEXTPERFQUERYIDINTELPROC glGetNextPerfQueryIdINTEL;
GL_EXPORT extern PFNGLGETPERFQUERYIDBYNAMEINTELPROC glGetPerfQueryIdByNameINTEL;
GL_EXPORT extern PFNGLGETPERFQUERYINFOINTELPROC glGetPerfQueryInfoINTEL;
GL_EXPORT extern PFNGLGETPERFCOUNTERINFOINTELPROC glGetPerfCounterInfoINTEL;
GL_EXPORT extern PFNGLCREATEPERFQUERYINTELPROC glCreatePerfQueryINTEL;
GL_EXPORT extern PFNGLDELETEPERFQUERYINTELPROC glDeletePerfQueryINTEL;
GL_EXPORT extern PFNGLBEGINPERFQUERYINTELPROC glBeginPerfQueryINTEL;
GL_EXPORT extern PFNGLENDPERFQUERYINTELPROC glEndPerfQueryINTEL;
GL_EXPORT extern PFNGLGETPERFQUERYDATAINTELPROC glGetPerfQueryDataINTEL;

/* -------------------- GL_3DFX_texture_compression_FXT1 ------------------- */
#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1

/* ---------------------------- GL_WIN_swap_hint --------------------------- */
typedef void (GLAPIENTRY* PFNGLADDSWAPHINTRECTWINPROC) (GLint x, GLint y, GLsizei width, GLsizei height);

extern PFNGLADDSWAPHINTRECTWINPROC glAddSwapHintRectWIN;

/* ------------------------- GL_ARB_viewport_array ------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_DEPTH_RANGE 0x0B70
#define GL_VIEWPORT 0x0BA2
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F

typedef void (GLAPIENTRY* PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLclampd * v);
typedef void (GLAPIENTRY* PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLclampd n, GLclampd f);
typedef void (GLAPIENTRY* PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble* data);
typedef void (GLAPIENTRY* PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat* data);
typedef void (GLAPIENTRY* PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint * v);
typedef void (GLAPIENTRY* PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint * v);
typedef void (GLAPIENTRY* PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat * v);
typedef void (GLAPIENTRY* PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (GLAPIENTRY* PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat * v);

GL_EXPORT extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
GL_EXPORT extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
GL_EXPORT extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;
GL_EXPORT extern PFNGLGETFLOATI_VPROC glGetFloati_v;
GL_EXPORT extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
GL_EXPORT extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
GL_EXPORT extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
GL_EXPORT extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
GL_EXPORT extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
GL_EXPORT extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
#endif

/* ------------------------ GL_ARB_ES2_compatibility ----------------------- */
#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_RGB565 0x8D62
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_SHADER_COMPILER 0x8DFA
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD

typedef int GLfixed;

typedef void (GLAPIENTRY* PFNGLCLEARDEPTHFPROC) (GLclampf d);
typedef void (GLAPIENTRY* PFNGLDEPTHRANGEFPROC) (GLclampf n, GLclampf f);
typedef void (GLAPIENTRY* PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint *precision);
typedef void (GLAPIENTRY* PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (GLAPIENTRY* PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint* shaders, GLenum binaryformat, const GLvoid*binary, GLsizei length);

GL_EXPORT extern PFNGLCLEARDEPTHFPROC glClearDepthf;
GL_EXPORT extern PFNGLDEPTHRANGEFPROC glDepthRangef;
GL_EXPORT extern PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
GL_EXPORT extern PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
GL_EXPORT extern PFNGLSHADERBINARYPROC glShaderBinary;

/* ------------------------ GL_ARB_ES3_compatibility ----------------------- */
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279

/* ------------------------------ GL_KHR_debug ----------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_SAMPLER 0x82E6
#define GL_DISPLAY_LIST 0x82E7
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_OUTPUT 0x92E0

typedef void (GLAPIENTRY *GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, GLvoid* userParam);

typedef void (GLAPIENTRY* PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const GLvoid *userParam);
typedef void (GLAPIENTRY* PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (GLAPIENTRY* PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef GLuint (GLAPIENTRY* PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (GLAPIENTRY* PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar *label);
typedef void (GLAPIENTRY* PFNGLGETOBJECTPTRLABELPROC) (void* ptr, GLsizei bufSize, GLsizei* length, GLchar *label);
typedef void (GLAPIENTRY* PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRY* PFNGLOBJECTPTRLABELPROC) (void* ptr, GLsizei length, const GLchar* label);
typedef void (GLAPIENTRY* PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (GLAPIENTRY* PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar * message);

GL_EXPORT extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
GL_EXPORT extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
GL_EXPORT extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
GL_EXPORT extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
GL_EXPORT extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
GL_EXPORT extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
GL_EXPORT extern PFNGLOBJECTLABELPROC glObjectLabel;
GL_EXPORT extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
GL_EXPORT extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
GL_EXPORT extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
#endif

/* ------------------------- GL_ARB_compute_shader ------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF

typedef void (GLAPIENTRY* PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (GLAPIENTRY* PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);

GL_EXPORT extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
GL_EXPORT extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
#endif

/* -------------------------- GL_ARB_draw_indirect ------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43

typedef void (GLAPIENTRY* PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const GLvoid *indirect);
typedef void (GLAPIENTRY* PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const GLvoid *indirect);

GL_EXPORT extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
GL_EXPORT extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
#endif

/* ------------------- GL_ARB_framebuffer_no_attachments ------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318

typedef void (GLAPIENTRY* PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (GLAPIENTRY* PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint* params);
typedef void (GLAPIENTRY* PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) (GLuint framebuffer, GLenum pname, GLint param);

GL_EXPORT extern PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
GL_EXPORT extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
GL_EXPORT extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC glGetNamedFramebufferParameterivEXT;
GL_EXPORT extern PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC glNamedFramebufferParameteriEXT;
#endif

/* ------------------------ GL_ARB_shader_subroutine ----------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B

typedef void (GLAPIENTRY* PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar *name);
typedef void (GLAPIENTRY* PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei* length, GLchar *name);
typedef void (GLAPIENTRY* PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
typedef void (GLAPIENTRY* PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint* values);
typedef GLuint (GLAPIENTRY* PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef GLint (GLAPIENTRY* PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef void (GLAPIENTRY* PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint* params);
typedef void (GLAPIENTRY* PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint* indices);

GL_EXPORT extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
GL_EXPORT extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
GL_EXPORT extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
GL_EXPORT extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
GL_EXPORT extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
GL_EXPORT extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
GL_EXPORT extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
GL_EXPORT extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
#endif

/* --------------------- GL_ARB_shader_atomic_counters --------------------- */
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC

typedef void (GLAPIENTRY* PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);

GL_EXPORT extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;

/* ---------------------- GL_ARB_internalformat_query ---------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_NUM_SAMPLE_COUNTS 0x9380

typedef void (GLAPIENTRY* PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint* params);

GL_EXPORT extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
#endif

/* ---------------------- GL_ARB_internalformat_query2 --------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_SRGB_DECODE_ARB 0x8299
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3

typedef void (GLAPIENTRY* PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64* params);

GL_EXPORT extern PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
#endif

/* ----------------------- GL_ARB_texture_multisample ---------------------- */
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110

typedef void (GLAPIENTRY* PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat* val);
typedef void (GLAPIENTRY* PFNGLSAMPLEMASKIPROC) (GLuint index, GLbitfield mask);
typedef void (GLAPIENTRY* PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (GLAPIENTRY* PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);

GL_EXPORT extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
GL_EXPORT extern PFNGLSAMPLEMASKIPROC glSampleMaski;
GL_EXPORT extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
GL_EXPORT extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;

/* ------------------------- GL_ARB_gpu_shader_fp64 ------------------------ */
#if !SUPPPORT_INTEL_HD
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE

typedef void (GLAPIENTRY* PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble* params);
typedef void (GLAPIENTRY* PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (GLAPIENTRY* PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (GLAPIENTRY* PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRY* PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRY* PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (GLAPIENTRY* PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);

GL_EXPORT extern PFNGLGETUNIFORMDVPROC glGetUniformdv;
GL_EXPORT extern PFNGLUNIFORM1DPROC glUniform1d;
GL_EXPORT extern PFNGLUNIFORM1DVPROC glUniform1dv;
GL_EXPORT extern PFNGLUNIFORM2DPROC glUniform2d;
GL_EXPORT extern PFNGLUNIFORM2DVPROC glUniform2dv;
GL_EXPORT extern PFNGLUNIFORM3DPROC glUniform3d;
GL_EXPORT extern PFNGLUNIFORM3DVPROC glUniform3dv;
GL_EXPORT extern PFNGLUNIFORM4DPROC glUniform4d;
GL_EXPORT extern PFNGLUNIFORM4DVPROC glUniform4dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
GL_EXPORT extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
#endif

/* ----------------------- GL_ARB_vertex_attrib_64bit ---------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble* params);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble* v);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble* v);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble* v);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble* v);
typedef void (GLAPIENTRY* PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);

GL_EXPORT extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
GL_EXPORT extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
GL_EXPORT extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
GL_EXPORT extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
GL_EXPORT extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
GL_EXPORT extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
GL_EXPORT extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
GL_EXPORT extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
GL_EXPORT extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
GL_EXPORT extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
#endif

/* ----------------------- GL_ARB_invalidate_subdata ----------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (GLAPIENTRY* PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (GLAPIENTRY* PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
typedef void (GLAPIENTRY* PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (GLAPIENTRY* PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);

GL_EXPORT extern PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
GL_EXPORT extern PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
GL_EXPORT extern PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
GL_EXPORT extern PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
GL_EXPORT extern PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
GL_EXPORT extern PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
#endif 

/* ----------------------- GL_ARB_multi_draw_indirect ---------------------- */
#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const GLvoid *indirect, GLsizei primcount, GLsizei stride);
typedef void (GLAPIENTRY* PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const GLvoid *indirect, GLsizei primcount, GLsizei stride);

GL_EXPORT extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
GL_EXPORT extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
#endif

/* ----------------------- GL_ARB_tessellation_shader ---------------------- */
#define GL_PATCHES 0xE
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A

#if !SUPPPORT_INTEL_HD
typedef void (GLAPIENTRY* PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat* values);
#endif
typedef void (GLAPIENTRY* PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);

#if !SUPPPORT_INTEL_HD
GL_EXPORT extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
#endif
GL_EXPORT extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;

/* ------------------ GL_ARB_shader_storage_buffer_object ------------------ */
#if !SUPPPORT_INTEL_HD
#define GL_SHADER_STORAGE_BARRIER_BIT 0x2000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF

typedef void (GLAPIENTRY* PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);

GL_EXPORT extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
#endif

/* ---------------------- GL_ARB_texture_buffer_range ---------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F

typedef void (GLAPIENTRY* PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAPIENTRY* PFNGLTEXTUREBUFFERRANGEEXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);

GL_EXPORT extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
GL_EXPORT extern PFNGLTEXTUREBUFFERRANGEEXTPROC glTextureBufferRangeEXT;
#endif

/* ------------------------- GL_ARB_texture_storage ------------------------ */
#if !SUPPPORT_INTEL_HD
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

typedef void (GLAPIENTRY* PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (GLAPIENTRY* PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAPIENTRY* PFNGLTEXTURESTORAGE1DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (GLAPIENTRY* PFNGLTEXTURESTORAGE2DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAPIENTRY* PFNGLTEXTURESTORAGE3DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);

GL_EXPORT extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
GL_EXPORT extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
GL_EXPORT extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;
GL_EXPORT extern PFNGLTEXTURESTORAGE1DEXTPROC glTextureStorage1DEXT;
GL_EXPORT extern PFNGLTEXTURESTORAGE2DEXTPROC glTextureStorage2DEXT;
GL_EXPORT extern PFNGLTEXTURESTORAGE3DEXTPROC glTextureStorage3DEXT;
#endif

/* -------------------------- GL_ARB_texture_view -------------------------- */
#if !SUPPPORT_INTEL_HD
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF

typedef void (GLAPIENTRY* PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);

GL_EXPORT extern PFNGLTEXTUREVIEWPROC glTextureView;
#endif

/* ----------------------- GL_ARB_get_program_binary ----------------------- */

#if !SUPPPORT_INTEL_HD
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF

typedef void (GLAPIENTRY* PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum *binaryFormat, GLvoid*binary);
typedef void (GLAPIENTRY* PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const GLvoid *binary, GLsizei length);
typedef void (GLAPIENTRY* PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);

GL_EXPORT extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
GL_EXPORT extern PFNGLPROGRAMBINARYPROC glProgramBinary;
GL_EXPORT extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
#endif

/* ------------------- GL_EXT_texture_filter_anisotropic ------------------- */

#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

#ifdef __cplusplus
}
#endif
#endif

