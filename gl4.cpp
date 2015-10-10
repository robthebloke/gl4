#include "gl/gl4.h"

#if !TEST_GLES
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#if (GL4_DUMP_EXTENSIONS || GL4_DUMP_FUNCS || GL4_DUMP_MISSING_FUNCS || GL4_DUMP_MISSING_EXTENSIONS)
# include <iostream>
# include <set>
# include <string>
#endif

#if GL4_DUMP_FUNCS
static std::set<std::string> g_funcs;
# define __GL4_DUMP_FUNCS(X) else { g_funcs.insert( #X ); } 
#else
# define __GL4_DUMP_FUNCS(X)
#endif

#if GL4_DUMP_MISSING_FUNCS
static std::set<std::string> g_missing_funcs;
# define __GL4_DUMP_MISSING_FUNCS(X) g_missing_funcs.insert( #X ); 
#else
# define __GL4_DUMP_MISSING_FUNCS(X)  
#endif

#if GL4_DUMP_MISSING_EXTENSIONS
static std::set<std::string> g_ext_funcs;
# define __GL4_DUMP_MISSING_EXTENSIONS(GL) g_ext_funcs.insert( GL ); 
#else
# define __GL4_DUMP_MISSING_EXTENSIONS(GL)  
#endif

#define GL4_CHECK(X, GL) \
  if(!X) \
  { \
    __available = false; \
    __GL4_DUMP_MISSING_FUNCS(X) \
    __GL4_DUMP_MISSING_EXTENSIONS(GL) \
  } \
  __GL4_DUMP_FUNCS(X) 

#define GL4_FUNC(T, F, GL)  { F = (T)wglGetProcAddress(#F); GL4_CHECK(F, GL); }

static uint32_t g_ext2 = 0;
static uint32_t g_ext = 0;
static uint32_t g_version = 0;

//----------------------------------------------------------------------------------------------------------------------
uint32_t glVersionBits()
{
  return g_version;
}

//----------------------------------------------------------------------------------------------------------------------
uint32_t glExtension1Bits()
{
  return g_ext;
}

//----------------------------------------------------------------------------------------------------------------------
uint32_t glExtension2Bits()
{
  return g_ext2;
}

//----------------------------------------------------------------------------------------------------------------------
uint32_t getGLSLVersion()
{
  const GLubyte* c = glGetString(GL_SHADING_LANGUAGE_VERSION);
  return (c[0] * 100) + (c[2] * 10);
}

//----------------------------------------------------------------------------------------------------------------------
uint32_t getGLVersion()
{
  const GLubyte* c = glGetString(GL_VERSION);
  return (c[0] * 100) + (c[2] * 10);
}



//----------------------------------------------------------------------------------------------------------------------
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = 0;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = 0;
PFNGLTEXIMAGE3DPROC glTexImage3D = 0;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = 0;

void gl_1_2()
{
  bool __available = true;
  GL4_FUNC(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D, "1.2");
  GL4_FUNC(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements, "1.2");
  GL4_FUNC(PFNGLTEXIMAGE3DPROC, glTexImage3D, "1.2");
  GL4_FUNC(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D, "1.2");
  if(__available) g_version |= kVer1_2;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLACTIVETEXTUREPROC glActiveTexture = 0;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture = 0;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = 0;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = 0;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = 0;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = 0;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = 0;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = 0;

void gl_1_3()
{
  bool __available = true;
  GL4_FUNC(PFNGLACTIVETEXTUREPROC, glActiveTexture, "1.3");
  GL4_FUNC(PFNGLCLIENTACTIVETEXTUREPROC, glClientActiveTexture, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D, "1.3");
  GL4_FUNC(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D, "1.3");
  GL4_FUNC(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage, "1.3");
  GL4_FUNC(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage, "1.3");
  if(__available) g_version |= kVer1_3;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBLENDCOLORPROC glBlendColor = 0;
PFNGLBLENDEQUATIONPROC glBlendEquation = 0;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = 0;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = 0;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = 0;
PFNGLPOINTPARAMETERFPROC glPointParameterf = 0;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = 0;
PFNGLPOINTPARAMETERIPROC glPointParameteri = 0;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = 0;

void gl_1_4()
{
  bool __available = true;
  GL4_FUNC(PFNGLBLENDCOLORPROC, glBlendColor, "1.4");
  GL4_FUNC(PFNGLBLENDEQUATIONPROC, glBlendEquation, "1.4");
  GL4_FUNC(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate, "1.4");
  GL4_FUNC(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays, "1.4");
  GL4_FUNC(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements, "1.4");
  GL4_FUNC(PFNGLPOINTPARAMETERFPROC, glPointParameterf, "1.4");
  GL4_FUNC(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv, "1.4");
  GL4_FUNC(PFNGLPOINTPARAMETERIPROC, glPointParameteri, "1.4");
  GL4_FUNC(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv, "1.4");
  if(__available) g_version |= kVer1_4;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBEGINQUERYPROC glBeginQuery = 0;
PFNGLBINDBUFFERPROC _glBindBuffer = 0;
PFNGLBUFFERDATAPROC glBufferData = 0;
PFNGLBUFFERSUBDATAPROC glBufferSubData = 0;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = 0;
PFNGLDELETEQUERIESPROC glDeleteQueries = 0;
PFNGLENDQUERYPROC glEndQuery = 0;
PFNGLGENBUFFERSPROC glGenBuffers = 0;
PFNGLGENQUERIESPROC glGenQueries = 0;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = 0;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = 0;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = 0;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = 0;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = 0;
PFNGLGETQUERYIVPROC glGetQueryiv = 0;
PFNGLISBUFFERPROC glIsBuffer = 0;
PFNGLISQUERYPROC glIsQuery = 0;
PFNGLMAPBUFFERPROC glMapBuffer = 0;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = 0;

//----------------------------------------------------------------------------------------------------------------------
uint32_t g_bufferBound[] =
{
  0, // kVertexBuffer 
  0, // kIndexBuffer
  0, // kConstantBuffer
  0, // kShaderStorageBuffer
  0, // kTransformFeedbackBuffer
  0, // kTextureBuffer
  0, // kDepthBuffer
  0, // kPixelPackBuffer
  0, // kPixelUnpackBuffer
  0
};


//----------------------------------------------------------------------------------------------------------------------
// yeah, this is a bit fugly. I'm optimising the code specifically for GL4.5 named support, so I'm willing to take 
// a triaival performance hit for the old versions. It should (theoretically) be slightly nicer on GLES3. Hopefully. 
GL_EXPORT void glBindBuffer(GLenum flag, GLuint buffer)
{
  switch(flag)
  {
  case GL_ARRAY_BUFFER: if(g_bufferBound[0] != buffer) { g_bufferBound[0] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_ELEMENT_ARRAY_BUFFER: if(g_bufferBound[1] != buffer) { g_bufferBound[1] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_UNIFORM_BUFFER: if(g_bufferBound[2] != buffer) { g_bufferBound[2] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_SHADER_STORAGE_BUFFER: if(g_bufferBound[3] != buffer) { g_bufferBound[3] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_TRANSFORM_FEEDBACK_BUFFER: if(g_bufferBound[4] != buffer) { g_bufferBound[4] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_TEXTURE_BUFFER: if(g_bufferBound[5] != buffer) { g_bufferBound[5] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_DEPTH_BUFFER: if(g_bufferBound[6] != buffer) { g_bufferBound[6] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_PIXEL_PACK_BUFFER: if(g_bufferBound[7] != buffer) { g_bufferBound[7] = buffer; _glBindBuffer(flag, buffer); } break;
  case GL_PIXEL_UNPACK_BUFFER: if(g_bufferBound[8] != buffer) { g_bufferBound[8] = buffer; _glBindBuffer(flag, buffer); } break;
  default: if(g_bufferBound[9] != buffer) { g_bufferBound[9] = buffer; _glBindBuffer(flag, buffer); } break;
  }
}


void gl_1_5()
{
  bool __available = true;
  GL4_FUNC(PFNGLBEGINQUERYPROC, glBeginQuery, "1.5");
  { _glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer"); GL4_CHECK(_glBindBuffer, "1.5"); }
  GL4_FUNC(PFNGLBUFFERDATAPROC, glBufferData, "1.5");
  GL4_FUNC(PFNGLBUFFERSUBDATAPROC, glBufferSubData, "1.5");
  GL4_FUNC(PFNGLDELETEBUFFERSPROC, glDeleteBuffers, "1.5");
  GL4_FUNC(PFNGLDELETEQUERIESPROC, glDeleteQueries, "1.5");
  GL4_FUNC(PFNGLENDQUERYPROC, glEndQuery, "1.5");
  GL4_FUNC(PFNGLGENBUFFERSPROC, glGenBuffers, "1.5");
  GL4_FUNC(PFNGLGENQUERIESPROC, glGenQueries, "1.5");
  GL4_FUNC(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv, "1.5");
  GL4_FUNC(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv, "1.5");
  GL4_FUNC(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData, "1.5");
  GL4_FUNC(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv, "1.5");
  GL4_FUNC(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv, "1.5");
  GL4_FUNC(PFNGLGETQUERYIVPROC, glGetQueryiv, "1.5");
  GL4_FUNC(PFNGLISBUFFERPROC, glIsBuffer, "1.5");
  GL4_FUNC(PFNGLISQUERYPROC, glIsQuery, "1.5");
  GL4_FUNC(PFNGLMAPBUFFERPROC, glMapBuffer, "1.5");
  GL4_FUNC(PFNGLUNMAPBUFFERPROC, glUnmapBuffer, "1.5");
  if(__available) g_version |= kVer1_5;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLATTACHSHADERPROC glAttachShader = 0;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = 0;
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = 0;
PFNGLCOMPILESHADERPROC glCompileShader = 0;
PFNGLCREATEPROGRAMPROC glCreateProgram = 0;
PFNGLCREATESHADERPROC glCreateShader = 0;
PFNGLDELETEPROGRAMPROC glDeleteProgram = 0;
PFNGLDELETESHADERPROC glDeleteShader = 0;
PFNGLDETACHSHADERPROC glDetachShader = 0;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = 0;
PFNGLDRAWBUFFERSPROC glDrawBuffers = 0;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = 0;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = 0;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = 0;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = 0;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = 0;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = 0;
PFNGLGETPROGRAMIVPROC glGetProgramiv = 0;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = 0;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = 0;
PFNGLGETSHADERIVPROC glGetShaderiv = 0;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = 0;
PFNGLGETUNIFORMFVPROC glGetUniformfv = 0;
PFNGLGETUNIFORMIVPROC glGetUniformiv = 0;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = 0;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = 0;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = 0;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = 0;
PFNGLISPROGRAMPROC glIsProgram = 0;
PFNGLISSHADERPROC glIsShader = 0;
PFNGLLINKPROGRAMPROC glLinkProgram = 0;
PFNGLSHADERSOURCEPROC glShaderSource = 0;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = 0;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = 0;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = 0;
PFNGLUNIFORM1FPROC glUniform1f = 0;
PFNGLUNIFORM1FVPROC glUniform1fv = 0;
PFNGLUNIFORM1IPROC glUniform1i = 0;
PFNGLUNIFORM1IVPROC glUniform1iv = 0;
PFNGLUNIFORM2FPROC glUniform2f = 0;
PFNGLUNIFORM2FVPROC glUniform2fv = 0;
PFNGLUNIFORM2IPROC glUniform2i = 0;
PFNGLUNIFORM2IVPROC glUniform2iv = 0;
PFNGLUNIFORM3FPROC glUniform3f = 0;
PFNGLUNIFORM3FVPROC glUniform3fv = 0;
PFNGLUNIFORM3IPROC glUniform3i = 0;
PFNGLUNIFORM3IVPROC glUniform3iv = 0;
PFNGLUNIFORM4FPROC glUniform4f = 0;
PFNGLUNIFORM4FVPROC glUniform4fv = 0;
PFNGLUNIFORM4IPROC glUniform4i = 0;
PFNGLUNIFORM4IVPROC glUniform4iv = 0;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = 0;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = 0;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = 0;
PFNGLUSEPROGRAMPROC glUseProgram = 0;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = 0;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = 0;

void gl_2_0()
{
  bool __available = true;
  GL4_FUNC(PFNGLATTACHSHADERPROC, glAttachShader, "2.0");
  GL4_FUNC(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation, "2.0");
  GL4_FUNC(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate, "2.0");
  GL4_FUNC(PFNGLCOMPILESHADERPROC, glCompileShader, "2.0");
  GL4_FUNC(PFNGLCREATEPROGRAMPROC, glCreateProgram, "2.0");
  GL4_FUNC(PFNGLCREATESHADERPROC, glCreateShader, "2.0");
  GL4_FUNC(PFNGLDELETEPROGRAMPROC, glDeleteProgram, "2.0");
  GL4_FUNC(PFNGLDELETESHADERPROC, glDeleteShader, "2.0");
  GL4_FUNC(PFNGLDETACHSHADERPROC, glDetachShader, "2.0");
  GL4_FUNC(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray, "2.0");
  GL4_FUNC(PFNGLDRAWBUFFERSPROC, glDrawBuffers, "2.0");
  GL4_FUNC(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray, "2.0");
  GL4_FUNC(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib, "2.0");
  GL4_FUNC(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform, "2.0");
  GL4_FUNC(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders, "2.0");
  GL4_FUNC(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation, "2.0");
  GL4_FUNC(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog, "2.0");
  GL4_FUNC(PFNGLGETPROGRAMIVPROC, glGetProgramiv, "2.0");
  GL4_FUNC(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog, "2.0");
  GL4_FUNC(PFNGLGETSHADERSOURCEPROC, glGetShaderSource, "2.0");
  GL4_FUNC(PFNGLGETSHADERIVPROC, glGetShaderiv, "2.0");
  GL4_FUNC(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation, "2.0");
  GL4_FUNC(PFNGLGETUNIFORMFVPROC, glGetUniformfv, "2.0");
  GL4_FUNC(PFNGLGETUNIFORMIVPROC, glGetUniformiv, "2.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv, "2.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv, "2.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv, "2.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv, "2.0");
  GL4_FUNC(PFNGLISPROGRAMPROC, glIsProgram, "2.0");
  GL4_FUNC(PFNGLISSHADERPROC, glIsShader, "2.0");
  GL4_FUNC(PFNGLLINKPROGRAMPROC, glLinkProgram, "2.0");
  GL4_FUNC(PFNGLSHADERSOURCEPROC, glShaderSource, "2.0");
  GL4_FUNC(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate, "2.0");
  GL4_FUNC(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate, "2.0");
  GL4_FUNC(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate, "2.0");
  GL4_FUNC(PFNGLUNIFORM1FPROC, glUniform1f, "2.0");
  GL4_FUNC(PFNGLUNIFORM1FVPROC, glUniform1fv, "2.0");
  GL4_FUNC(PFNGLUNIFORM1IPROC, glUniform1i, "2.0");
  GL4_FUNC(PFNGLUNIFORM1IVPROC, glUniform1iv, "2.0");
  GL4_FUNC(PFNGLUNIFORM2FPROC, glUniform2f, "2.0");
  GL4_FUNC(PFNGLUNIFORM2FVPROC, glUniform2fv, "2.0");
  GL4_FUNC(PFNGLUNIFORM2IPROC, glUniform2i, "2.0");
  GL4_FUNC(PFNGLUNIFORM2IVPROC, glUniform2iv, "2.0");
  GL4_FUNC(PFNGLUNIFORM3FPROC, glUniform3f, "2.0");
  GL4_FUNC(PFNGLUNIFORM3FVPROC, glUniform3fv, "2.0");
  GL4_FUNC(PFNGLUNIFORM3IPROC, glUniform3i, "2.0");
  GL4_FUNC(PFNGLUNIFORM3IVPROC, glUniform3iv, "2.0");
  GL4_FUNC(PFNGLUNIFORM4FPROC, glUniform4f, "2.0");
  GL4_FUNC(PFNGLUNIFORM4FVPROC, glUniform4fv, "2.0");
  GL4_FUNC(PFNGLUNIFORM4IPROC, glUniform4i, "2.0");
  GL4_FUNC(PFNGLUNIFORM4IVPROC, glUniform4iv, "2.0");
  GL4_FUNC(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv, "2.0");
  GL4_FUNC(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv, "2.0");
  GL4_FUNC(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv, "2.0");
  GL4_FUNC(PFNGLUSEPROGRAMPROC, glUseProgram, "2.0");
  GL4_FUNC(PFNGLVALIDATEPROGRAMPROC, glValidateProgram, "2.0");
  GL4_FUNC(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer, "2.0");
  if(__available) g_version |= kVer2_0;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = 0;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = 0;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = 0;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = 0;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = 0;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = 0;

void gl_2_1()
{
  bool __available = true;
  GL4_FUNC(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv, "2.1");
  GL4_FUNC(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv, "2.1");
  GL4_FUNC(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv, "2.1");
  GL4_FUNC(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv, "2.1");
  GL4_FUNC(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv, "2.1");
  GL4_FUNC(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv, "2.1");
  if(__available) g_version |= kVer2_1;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = 0;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = 0;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = 0;
PFNGLCLAMPCOLORPROC glClampColor = 0;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = 0;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = 0;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = 0;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = 0;
PFNGLCOLORMASKIPROC glColorMaski = 0;
PFNGLDISABLEIPROC glDisablei = 0;
PFNGLENABLEIPROC glEnablei = 0;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = 0;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = 0;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = 0;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = 0;
PFNGLGETSTRINGIPROC glGetStringi = 0;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = 0;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = 0;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = 0;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = 0;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = 0;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = 0;
PFNGLISENABLEDIPROC glIsEnabledi = 0;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = 0;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = 0;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = 0;
PFNGLUNIFORM1UIPROC glUniform1ui = 0;
PFNGLUNIFORM1UIVPROC glUniform1uiv = 0;
PFNGLUNIFORM2UIPROC glUniform2ui = 0;
PFNGLUNIFORM2UIVPROC glUniform2uiv = 0;
PFNGLUNIFORM3UIPROC glUniform3ui = 0;
PFNGLUNIFORM3UIVPROC glUniform3uiv = 0;
PFNGLUNIFORM4UIPROC glUniform4ui = 0;
PFNGLUNIFORM4UIVPROC glUniform4uiv = 0;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i = 0;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv = 0;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui = 0;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv = 0;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i = 0;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv = 0;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui = 0;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv = 0;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i = 0;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv = 0;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui = 0;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv = 0;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv = 0;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i = 0;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv = 0;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv = 0;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv = 0;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui = 0;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv = 0;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv = 0;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = 0;

void gl_3_0()
{
  bool __available = true;
  GL4_FUNC(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender, "3.0");
  GL4_FUNC(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback, "3.0");
  GL4_FUNC(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation, "3.0");
  GL4_FUNC(PFNGLCLAMPCOLORPROC, glClampColor, "3.0");
  GL4_FUNC(PFNGLCLEARBUFFERFIPROC, glClearBufferfi, "3.0");
  GL4_FUNC(PFNGLCLEARBUFFERFVPROC, glClearBufferfv, "3.0");
  GL4_FUNC(PFNGLCLEARBUFFERIVPROC, glClearBufferiv, "3.0");
  GL4_FUNC(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv, "3.0");
  GL4_FUNC(PFNGLCOLORMASKIPROC, glColorMaski, "3.0");
  GL4_FUNC(PFNGLDISABLEIPROC, glDisablei, "3.0");
  GL4_FUNC(PFNGLENABLEIPROC, glEnablei, "3.0");
  GL4_FUNC(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender, "3.0");
  GL4_FUNC(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback, "3.0");
  GL4_FUNC(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v, "3.0");
  GL4_FUNC(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation, "3.0");
  GL4_FUNC(PFNGLGETSTRINGIPROC, glGetStringi, "3.0");
  GL4_FUNC(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv, "3.0");
  GL4_FUNC(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv, "3.0");
  GL4_FUNC(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying, "3.0");
  GL4_FUNC(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv, "3.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv, "3.0");
  GL4_FUNC(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv, "3.0");
  GL4_FUNC(PFNGLISENABLEDIPROC, glIsEnabledi, "3.0");
  GL4_FUNC(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv, "3.0");
  GL4_FUNC(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv, "3.0");
  GL4_FUNC(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings, "3.0");
  GL4_FUNC(PFNGLUNIFORM1UIPROC, glUniform1ui, "3.0");
  GL4_FUNC(PFNGLUNIFORM1UIVPROC, glUniform1uiv, "3.0");
  GL4_FUNC(PFNGLUNIFORM2UIPROC, glUniform2ui, "3.0");
  GL4_FUNC(PFNGLUNIFORM2UIVPROC, glUniform2uiv, "3.0");
  GL4_FUNC(PFNGLUNIFORM3UIPROC, glUniform3ui, "3.0");
  GL4_FUNC(PFNGLUNIFORM3UIVPROC, glUniform3uiv, "3.0");
  GL4_FUNC(PFNGLUNIFORM4UIPROC, glUniform4ui, "3.0");
  GL4_FUNC(PFNGLUNIFORM4UIVPROC, glUniform4uiv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv, "3.0");
  GL4_FUNC(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer, "3.0");
  if(__available) g_version |= kVer3_0;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = 0;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = 0;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = 0;
PFNGLTEXBUFFERPROC glTexBuffer = 0;

void gl_3_1()
{
  bool __available = true;
  GL4_FUNC(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced, "3.1");
  GL4_FUNC(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced, "3.1");
  GL4_FUNC(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex, "3.1");
  GL4_FUNC(PFNGLTEXBUFFERPROC, glTexBuffer, "3.1");
  if(__available) g_version |= kVer3_1;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = 0;
#if !SUPPPORT_INTEL_HD
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = 0;
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = 0;
#endif

void gl_3_2()
{
  bool __available = true;
  GL4_FUNC(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture, "3.2");
  #if !SUPPPORT_INTEL_HD
  GL4_FUNC(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v, "3.2");
  GL4_FUNC(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v, "3.2");
  #endif
  if(__available) g_version |= kVer3_2;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = 0;

void gl_3_3()
{
  bool __available = true;
  GL4_FUNC(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor, "3.3");
  if(__available) g_version |= kVer3_3;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = 0;
PFNGLBLENDEQUATIONIPROC glBlendEquationi = 0;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = 0;
PFNGLBLENDFUNCIPROC glBlendFunci = 0;
#if !SUPPPORT_INTEL_HD
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = 0;
#endif

void gl_4_0()
{
  bool __available = true;
  GL4_FUNC(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei, "4.0");
  GL4_FUNC(PFNGLBLENDEQUATIONIPROC, glBlendEquationi, "4.0");
  GL4_FUNC(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei, "4.0");
  GL4_FUNC(PFNGLBLENDFUNCIPROC, glBlendFunci, "4.0");
  #if !SUPPPORT_INTEL_HD
  GL4_FUNC(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading, "4.0");
  #endif
  if(__available) g_version |= kVer4_0;
}

//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
GL_EXPORT PFNGLNAMEDBUFFERDATAPROC glNamedBufferData = 0;
GL_EXPORT PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage = 0;
GL_EXPORT PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData = 0;
GL_EXPORT PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer = 0;
GL_EXPORT PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture = 0;
GL_EXPORT PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage = 0;
GL_EXPORT PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample = 0;
GL_EXPORT PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv = 0;
GL_EXPORT PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer = 0;
GL_EXPORT PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv = 0;
GL_EXPORT PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv = 0;
GL_EXPORT PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus = 0;
GL_EXPORT PFNGLNAMEDTEXSTORAGE1DPROC glNamedTexStorage1D = 0;
GL_EXPORT PFNGLNAMEDTEXSTORAGE2DPROC glNamedTexStorage2D = 0;
GL_EXPORT PFNGLNAMEDTEXSTORAGE3DPROC glNamedTexStorage3D = 0;
GL_EXPORT PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange = 0;
GL_EXPORT PFNGLUNMAPNAMEDBUFFERRANGEPROC glUnmapNamedBuffer = 0;
GL_EXPORT PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData = 0;
GL_EXPORT PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange = 0;
#endif

void gl_4_5()
{
  #if !SUPPPORT_INTEL_HD
  bool __available = true;
  GL4_FUNC(PFNGLNAMEDBUFFERDATAPROC, glNamedBufferData, "4.5");
  GL4_FUNC(PFNGLNAMEDBUFFERSTORAGEPROC, glNamedBufferStorage, "4.5");
  GL4_FUNC(PFNGLNAMEDBUFFERSUBDATAPROC, glNamedBufferSubData, "4.5");
  GL4_FUNC(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, glNamedFramebufferRenderbuffer, "4.5");
  GL4_FUNC(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture, "4.5");
  GL4_FUNC(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, glNamedRenderbufferStorage, "4.5");
  GL4_FUNC(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, glNamedRenderbufferStorageMultisample, "4.5");
  GL4_FUNC(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, glGetNamedRenderbufferParameteriv, "4.5");
  GL4_FUNC(PFNGLBLITNAMEDFRAMEBUFFERPROC, glBlitNamedFramebuffer, "4.5");
  GL4_FUNC(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, glGetNamedFramebufferParameteriv, "4.5");
  GL4_FUNC(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetNamedFramebufferAttachmentParameteriv, "4.5");
  GL4_FUNC(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, glCheckNamedFramebufferStatus, "4.5");
  GL4_FUNC(PFNGLNAMEDTEXSTORAGE1DPROC, glNamedTexStorage1D, "4.5");
  GL4_FUNC(PFNGLNAMEDTEXSTORAGE2DPROC, glNamedTexStorage2D, "4.5");
  GL4_FUNC(PFNGLNAMEDTEXSTORAGE3DPROC, glNamedTexStorage3D, "4.5");
  GL4_FUNC(PFNGLMAPNAMEDBUFFERRANGEPROC, glMapNamedBufferRange, "4.5");
  GL4_FUNC(PFNGLUNMAPNAMEDBUFFERRANGEPROC, glUnmapNamedBuffer, "4.5");
  GL4_FUNC(PFNGLGETNAMEDBUFFERSUBDATAPROC, glGetNamedBufferSubData, "4.5");
  GL4_FUNC(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, glFlushMappedNamedBufferRange, "4.5");
  if(__available) g_version |= kVer4_5;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLCLAMPCOLORARBPROC glClampColorARB = 0;

void gl_GL_ARB_color_buffer_float()
{
  bool __available = true;
  GL4_FUNC(PFNGLCLAMPCOLORARBPROC, glClampColorARB, "GL_ARB_color_buffer_float");
  if(__available) g_ext |= kGL_ARB_color_buffer_float;
}

//----------------------------------------------------------------------------------------------------------------------

PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = 0;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex = 0;

void gl_GL_ARB_blend_func_extended()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed, "GL_ARB_blend_func_extended");
  GL4_FUNC(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex, "GL_ARB_blend_func_extended");
  if(__available) g_ext |= kGL_ARB_blend_func_extended;
}

//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv = 0;
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex = 0;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation = 0;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex = 0;
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName = 0;
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv = 0;

void gl_GL_ARB_program_interface_query()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv, "GL_ARB_program_interface_query");
  GL4_FUNC(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex, "GL_ARB_program_interface_query");
  GL4_FUNC(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation, "GL_ARB_program_interface_query");
  GL4_FUNC(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex, "GL_ARB_program_interface_query");
  GL4_FUNC(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName, "GL_ARB_program_interface_query");
  GL4_FUNC(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv, "GL_ARB_program_interface_query");
  if(__available) g_ext |= kGL_ARB_program_interface_query;
}
#endif

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = 0;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = 0;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = 0;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = 0;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = 0;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = 0;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = 0;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = 0;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = 0;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = 0;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = 0;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = 0;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = 0;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = 0;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = 0;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = 0;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = 0;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = 0;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = 0;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = 0;

void gl_GL_ARB_framebuffer_object()
{
  bool __available = true;
  GL4_FUNC(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer, "GL_ARB_framebuffer_object");
  GL4_FUNC(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage, "GL_ARB_framebuffer_object")
  GL4_FUNC(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample, "GL_ARB_framebuffer_object")
  if(__available) g_ext |= kGL_ARB_framebuffer_object;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = 0;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = 0;

void gl_GL_ARB_map_buffer_range()
{
  bool __available = true;
  GL4_FUNC(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange, "GL_ARB_map_buffer_range");
  GL4_FUNC(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange, "GL_ARB_map_buffer_range");
  if(__available) g_ext |= kGL_ARB_map_buffer_range;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDSAMPLERPROC glBindSampler = 0;
PFNGLDELETESAMPLERSPROC glDeleteSamplers = 0;
PFNGLGENSAMPLERSPROC glGenSamplers = 0;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv = 0;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv = 0;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv = 0;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv = 0;
PFNGLISSAMPLERPROC glIsSampler = 0;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv = 0;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv = 0;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf = 0;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv = 0;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri = 0;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv = 0;

void gl_GL_ARB_sampler_objects()
{
  bool __available = true;
  GL4_FUNC(PFNGLBINDSAMPLERPROC, glBindSampler, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLDELETESAMPLERSPROC, glDeleteSamplers, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLGENSAMPLERSPROC, glGenSamplers, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLISSAMPLERPROC, glIsSampler, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri, "GL_ARB_sampler_objects");
  GL4_FUNC(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv, "GL_ARB_sampler_objects");
  if(__available) g_ext |= kGL_ARB_sampler_objects;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = 0;

void gl_GL_ARB_copy_buffer()
{
  bool __available = true;
  GL4_FUNC(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData, "GL_ARB_copy_buffer");
  if(__available) g_ext |= kGL_ARB_copy_buffer;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = 0;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = 0;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = 0;

void gl_GL_ARB_draw_elements_base_vertex()
{
  bool __available = true;
  GL4_FUNC(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex, "GL_ARB_draw_elements_base_vertex");
  GL4_FUNC(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex, "GL_ARB_draw_elements_base_vertex");
  GL4_FUNC(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex, "GL_ARB_draw_elements_base_vertex");
  GL4_FUNC(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex, "GL_ARB_draw_elements_base_vertex");
  if(__available) g_ext |= kGL_ARB_draw_elements_base_vertex;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDBUFFERBASEPROC glBindBufferBase = 0;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = 0;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = 0;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = 0;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = 0;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = 0;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = 0;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = 0;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = 0;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = 0;

void gl_GL_ARB_uniform_buffer_object()
{
  bool __available = true;
  GL4_FUNC(PFNGLBINDBUFFERBASEPROC, glBindBufferBase, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices, "GL_ARB_uniform_buffer_object");
  GL4_FUNC(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding, "GL_ARB_uniform_buffer_object");
  if(__available) g_ext |= kGL_ARB_uniform_buffer_object;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLPROVOKINGVERTEXPROC glProvokingVertex = 0;

void gl_GL_ARB_provoking_vertex()
{
  bool __available = true;
  GL4_FUNC(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex, "GL_ARB_provoking_vertex");
  if(__available) g_ext |= kGL_ARB_provoking_vertex;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLISVERTEXARRAYPROC glBindVertexArray = 0;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = 0;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = 0;
PFNGLISVERTEXARRAYPROC glIsVertexArray = 0;

void gl_GL_ARB_vertex_array_object()
{
  bool __available = true;
  GL4_FUNC(PFNGLISVERTEXARRAYPROC, glBindVertexArray, "GL_ARB_vertex_array_object");
  GL4_FUNC(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays, "GL_ARB_vertex_array_object");
  GL4_FUNC(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays, "GL_ARB_vertex_array_object");
  GL4_FUNC(PFNGLISVERTEXARRAYPROC, glIsVertexArray, "GL_ARB_vertex_array_object");
  if(__available) g_ext |= kGL_ARB_vertex_array_object;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v = 0;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v = 0;
PFNGLQUERYCOUNTERPROC glQueryCounter = 0;

void gl_GL_ARB_timer_query()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v, "GL_ARB_timer_query");
  GL4_FUNC(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v, "GL_ARB_timer_query");
  GL4_FUNC(PFNGLQUERYCOUNTERPROC, glQueryCounter, "GL_ARB_timer_query");
  if(__available) g_ext |= kGL_ARB_timer_query;
}

//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLCLEARTEXIMAGEPROC glClearTexImage = 0;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage = 0;

void gl_GL_ARB_clear_texture()
{
  bool __available = true;
  GL4_FUNC(PFNGLCLEARTEXIMAGEPROC, glClearTexImage, "GL_ARB_clear_texture");
  GL4_FUNC(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage, "GL_ARB_clear_texture");
  if(__available) g_ext |= kGL_ARB_clear_texture;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLCLEARBUFFERDATAPROC glClearBufferData = 0;
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData = 0;
PFNGLCLEARNAMEDBUFFERDATAEXTPROC glClearNamedBufferDataEXT = 0;
PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glClearNamedBufferSubDataEXT = 0;

void gl_GL_ARB_clear_buffer_object()
{
  bool __available = true;
  GL4_FUNC(PFNGLCLEARBUFFERDATAPROC, glClearBufferData, "GL_ARB_clear_buffer_object");
  GL4_FUNC(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData, "GL_ARB_clear_buffer_object");
  GL4_FUNC(PFNGLCLEARNAMEDBUFFERDATAEXTPROC, glClearNamedBufferDataEXT, "GL_ARB_clear_buffer_object");
  GL4_FUNC(PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC, glClearNamedBufferSubDataEXT, "GL_ARB_clear_buffer_object");
  if(__available) g_ext |= kGL_ARB_clear_buffer_object;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB = 0;

void gl_GL_ARB_cl_event()
{
  bool __available = true;
  GL4_FUNC(PFNGLCREATESYNCFROMCLEVENTARBPROC, glCreateSyncFromCLeventARB, "GL_ARB_cl_event");
  if(__available) g_ext |= kGL_ARB_cl_event;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBUFFERSTORAGEPROC glBufferStorage = 0;
PFNGLNAMEDBUFFERSTORAGEEXTPROC glNamedBufferStorageEXT = 0;

void gl_GL_ARB_buffer_storage()
{
  bool __available = true;
  GL4_FUNC(PFNGLBUFFERSTORAGEPROC, glBufferStorage, "GL_ARB_buffer_storage");
  GL4_FUNC(PFNGLNAMEDBUFFERSTORAGEEXTPROC, glNamedBufferStorageEXT, "GL_ARB_buffer_storage");
  if(__available) g_ext |= kGL_ARB_buffer_storage;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLGETIMAGEHANDLEARBPROC glGetImageHandleARB = 0;
PFNGLGETTEXTUREHANDLEARBPROC glGetTextureHandleARB = 0;
PFNGLGETTEXTURESAMPLERHANDLEARBPROC glGetTextureSamplerHandleARB = 0;
PFNGLGETVERTEXATTRIBLUI64VARBPROC glGetVertexAttribLui64vARB = 0;
PFNGLISIMAGEHANDLERESIDENTARBPROC glIsImageHandleResidentARB = 0;
PFNGLISTEXTUREHANDLERESIDENTARBPROC glIsTextureHandleResidentARB = 0;
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC glMakeImageHandleNonResidentARB = 0;
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC glMakeImageHandleResidentARB = 0;
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC glMakeTextureHandleNonResidentARB = 0;
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC glMakeTextureHandleResidentARB = 0;
PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC glProgramUniformHandleui64ARB = 0;
PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC glProgramUniformHandleui64vARB = 0;
PFNGLUNIFORMHANDLEUI64ARBPROC glUniformHandleui64ARB = 0;
PFNGLUNIFORMHANDLEUI64VARBPROC glUniformHandleui64vARB = 0;
PFNGLVERTEXATTRIBL1UI64ARBPROC glVertexAttribL1ui64ARB = 0;
PFNGLVERTEXATTRIBL1UI64VARBPROC glVertexAttribL1ui64vARB = 0;

void gl_GL_ARB_bindless_texture()
{
  bool __available = true;  
  GL4_FUNC(PFNGLGETIMAGEHANDLEARBPROC, glGetImageHandleARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLGETTEXTUREHANDLEARBPROC, glGetTextureHandleARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLGETTEXTURESAMPLERHANDLEARBPROC, glGetTextureSamplerHandleARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLGETVERTEXATTRIBLUI64VARBPROC, glGetVertexAttribLui64vARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLISIMAGEHANDLERESIDENTARBPROC, glIsImageHandleResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLISTEXTUREHANDLERESIDENTARBPROC, glIsTextureHandleResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC, glMakeImageHandleNonResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLMAKEIMAGEHANDLERESIDENTARBPROC, glMakeImageHandleResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC, glMakeTextureHandleNonResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLMAKETEXTUREHANDLERESIDENTARBPROC, glMakeTextureHandleResidentARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC, glProgramUniformHandleui64ARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC, glProgramUniformHandleui64vARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLUNIFORMHANDLEUI64ARBPROC, glUniformHandleui64ARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLUNIFORMHANDLEUI64VARBPROC, glUniformHandleui64vARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLVERTEXATTRIBL1UI64ARBPROC, glVertexAttribL1ui64ARB, "GL_ARB_bindless_texture");
  GL4_FUNC(PFNGLVERTEXATTRIBL1UI64VARBPROC, glVertexAttribL1ui64vARB, "GL_ARB_bindless_texture");
  if(__available) g_ext |= kGL_ARB_bindless_texture;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance = 0;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance = 0;

void gl_GL_ARB_base_instance()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance, "GL_ARB_base_instance");
  GL4_FUNC(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance, "GL_ARB_base_instance");
  GL4_FUNC(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance, "GL_ARB_base_instance");
  if(__available) g_ext |= kGL_ARB_base_instance;
}
#endif

//----------------------------------------------------------------------------------------------------------------------
PFNGLCLIENTWAITSYNCPROC glClientWaitSync = 0;
PFNGLDELETESYNCPROC glDeleteSync = 0;
PFNGLFENCESYNCPROC glFenceSync = 0;
PFNGLGETINTEGER64VPROC glGetInteger64v = 0;
PFNGLGETSYNCIVPROC glGetSynciv = 0;
PFNGLISSYNCPROC glIsSync = 0;
PFNGLWAITSYNCPROC glWaitSync = 0;

void gl_GL_ARB_sync()
{
  bool __available = true;
  GL4_FUNC(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync, "GL_ARB_sync");
  GL4_FUNC(PFNGLDELETESYNCPROC, glDeleteSync, "GL_ARB_sync");
  GL4_FUNC(PFNGLFENCESYNCPROC, glFenceSync, "GL_ARB_sync");
  GL4_FUNC(PFNGLGETINTEGER64VPROC, glGetInteger64v, "GL_ARB_sync");
  GL4_FUNC(PFNGLGETSYNCIVPROC, glGetSynciv, "GL_ARB_sync");
  GL4_FUNC(PFNGLISSYNCPROC, glIsSync, "GL_ARB_sync");
  GL4_FUNC(PFNGLWAITSYNCPROC, glWaitSync, "GL_ARB_sync");
  if(__available) g_version |= kGL_ARB_sync;
}

//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream = 0;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed = 0;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv = 0;

void gl_GL_ARB_transform_feedback3()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed, "GL_ARB_transform_feedback3");
  GL4_FUNC(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream, "GL_ARB_transform_feedback3");
  GL4_FUNC(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed, "GL_ARB_transform_feedback3");
  GL4_FUNC(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv, "GL_ARB_transform_feedback3");
  if(__available) g_ext |= kGL_ARB_sync;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced = 0;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced = 0;

void gl_GL_ARB_transform_feedback_instanced()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced, "GL_ARB_transform_feedback_instanced");
  GL4_FUNC(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced, "GL_ARB_transform_feedback_instanced");
  if(__available) g_ext |= kGL_ARB_transform_feedback_instanced;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase = 0;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange = 0;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures = 0;
PFNGLBINDSAMPLERSPROC glBindSamplers = 0;
PFNGLBINDTEXTURESPROC glBindTextures = 0;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers = 0;

void gl_GL_ARB_multi_bind()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase, "GL_ARB_multi_bind");
  GL4_FUNC(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange, "GL_ARB_multi_bind");
  GL4_FUNC(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures, "GL_ARB_multi_bind");
  GL4_FUNC(PFNGLBINDSAMPLERSPROC, glBindSamplers, "GL_ARB_multi_bind");
  GL4_FUNC(PFNGLBINDTEXTURESPROC, glBindTextures, "GL_ARB_multi_bind");
  GL4_FUNC(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers, "GL_ARB_multi_bind");
  if(__available) g_ext |= kGL_ARB_multi_bind;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDIMAGETEXTUREPROC glBindImageTexture = 0;
PFNGLMEMORYBARRIERPROC glMemoryBarrier = 0;

void gl_GL_ARB_shader_image_load_store()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture, "GL_ARB_shader_image_load_store");
  GL4_FUNC(PFNGLMEMORYBARRIERPROC, glMemoryBarrier, "GL_ARB_shader_image_load_store");
  if(__available) g_ext |= kGL_ARB_shader_image_load_store;
}
#endif

//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram = 0;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline = 0;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv = 0;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines = 0;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines = 0;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog = 0;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv = 0;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline = 0;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d = 0;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv = 0;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f = 0;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv = 0;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i = 0;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv = 0;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui = 0;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv = 0;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d = 0;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv = 0;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f = 0;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv = 0;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i = 0;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv = 0;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui = 0;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv = 0;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d = 0;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv = 0;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f = 0;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv = 0;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i = 0;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv = 0;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui = 0;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv = 0;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d = 0;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv = 0;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f = 0;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv = 0;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i = 0;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv = 0;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui = 0;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv = 0;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv = 0;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv = 0;
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages = 0;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline = 0;

void gl_GL_ARB_separate_shader_objects()
{
  bool __available = true;  
  GL4_FUNC(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1DPROC, glProgramUniform1d, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1DVPROC, glProgramUniform1dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1FPROC, glProgramUniform1f, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1FVPROC, glProgramUniform1fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1IPROC, glProgramUniform1i, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1IVPROC, glProgramUniform1iv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1UIPROC, glProgramUniform1ui, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2DPROC, glProgramUniform2d, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2DVPROC, glProgramUniform2dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2FPROC, glProgramUniform2f, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2FVPROC, glProgramUniform2fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2IPROC, glProgramUniform2i, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2IVPROC, glProgramUniform2iv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2UIPROC, glProgramUniform2ui, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3DPROC, glProgramUniform3d, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3DVPROC, glProgramUniform3dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3FPROC, glProgramUniform3f, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3FVPROC, glProgramUniform3fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3IPROC, glProgramUniform3i, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3IVPROC, glProgramUniform3iv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3UIPROC, glProgramUniform3ui, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4DPROC, glProgramUniform4d, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4DVPROC, glProgramUniform4dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4FPROC, glProgramUniform4f, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4FVPROC, glProgramUniform4fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4IPROC, glProgramUniform4i, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4IVPROC, glProgramUniform4iv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4UIPROC, glProgramUniform4ui, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2DVPROC, glProgramUniformMatrix2dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, glProgramUniformMatrix2fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3DVPROC, glProgramUniformMatrix3dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, glProgramUniformMatrix3fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4DVPROC, glProgramUniformMatrix4dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, glProgramUniformMatrix4fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages, "GL_ARB_separate_shader_objects");
  GL4_FUNC(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline, "GL_ARB_separate_shader_objects");
  if(__available) g_ext |= kGL_ARB_separate_shader_objects;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer = 0;
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding = 0;
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat = 0;
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat = 0;
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat = 0;
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor = 0;

void gl_GL_ARB_vertex_attrib_binding()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer, "GL_ARB_vertex_attrib_binding");
  GL4_FUNC(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding, "GL_ARB_vertex_attrib_binding");
  GL4_FUNC(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat, "GL_ARB_vertex_attrib_binding");
  GL4_FUNC(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat, "GL_ARB_vertex_attrib_binding");
  GL4_FUNC(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat, "GL_ARB_vertex_attrib_binding");
  GL4_FUNC(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor, "GL_ARB_vertex_attrib_binding");
  if(__available) g_ext |= kGL_ARB_vertex_attrib_binding;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback = 0;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks = 0;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback = 0;
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks = 0;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback = 0;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback = 0;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback = 0;

void gl_GL_ARB_transform_feedback2()
{
  bool __available = true;  
  GL4_FUNC(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback, "GL_ARB_transform_feedback2");
  GL4_FUNC(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback, "GL_ARB_transform_feedback2");
  if(__available) g_ext |= kGL_ARB_transform_feedback2;
}
#endif

//----------------------------------------------------------------------------------------------------------------------
PFNGLMAPTEXTURE2DINTELPROC glMapTexture2DINTEL = 0;
PFNGLSYNCTEXTUREINTELPROC glSyncTextureINTEL = 0;
PFNGLUNMAPTEXTURE2DINTELPROC glUnmapTexture2DINTEL = 0;

void gl_GL_INTEL_map_texture()
{
  bool __available = true;  
  GL4_FUNC(PFNGLMAPTEXTURE2DINTELPROC, glMapTexture2DINTEL, "GL_INTEL_map_texture");
  GL4_FUNC(PFNGLSYNCTEXTUREINTELPROC, glSyncTextureINTEL, "GL_INTEL_map_texture");
  GL4_FUNC(PFNGLUNMAPTEXTURE2DINTELPROC, glUnmapTexture2DINTEL, "GL_INTEL_map_texture");
  if(__available) g_ext |= kGL_INTEL_map_texture;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLGETFIRSTPERFQUERYIDINTELPROC glGetFirstPerfQueryIdINTEL = 0;
PFNGLGETNEXTPERFQUERYIDINTELPROC glGetNextPerfQueryIdINTEL = 0;
PFNGLGETPERFQUERYIDBYNAMEINTELPROC glGetPerfQueryIdByNameINTEL = 0;
PFNGLGETPERFQUERYINFOINTELPROC glGetPerfQueryInfoINTEL = 0;
PFNGLGETPERFCOUNTERINFOINTELPROC glGetPerfCounterInfoINTEL = 0;
PFNGLCREATEPERFQUERYINTELPROC glCreatePerfQueryINTEL = 0;
PFNGLDELETEPERFQUERYINTELPROC glDeletePerfQueryINTEL = 0;
PFNGLBEGINPERFQUERYINTELPROC glBeginPerfQueryINTEL = 0;
PFNGLENDPERFQUERYINTELPROC glEndPerfQueryINTEL = 0;
PFNGLGETPERFQUERYDATAINTELPROC glGetPerfQueryDataINTEL = 0;

void gl_GL_INTEL_performance_queries()
{
  bool __available = true;  
  GL4_FUNC(PFNGLGETFIRSTPERFQUERYIDINTELPROC, glGetFirstPerfQueryIdINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLGETNEXTPERFQUERYIDINTELPROC, glGetNextPerfQueryIdINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLGETPERFQUERYIDBYNAMEINTELPROC, glGetPerfQueryIdByNameINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLGETPERFQUERYINFOINTELPROC, glGetPerfQueryInfoINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLGETPERFCOUNTERINFOINTELPROC, glGetPerfCounterInfoINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLCREATEPERFQUERYINTELPROC, glCreatePerfQueryINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLDELETEPERFQUERYINTELPROC, glDeletePerfQueryINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLBEGINPERFQUERYINTELPROC, glBeginPerfQueryINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLENDPERFQUERYINTELPROC, glEndPerfQueryINTEL, "GL_INTEL_performance_queries");
  GL4_FUNC(PFNGLGETPERFQUERYDATAINTELPROC, glGetPerfQueryDataINTEL, "GL_INTEL_performance_queries");
  if(__available) g_ext |= kGL_INTEL_performance_queries;
}


//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv = 0;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed = 0;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v = 0;
PFNGLGETFLOATI_VPROC glGetFloati_v = 0;
PFNGLSCISSORARRAYVPROC glScissorArrayv = 0;
PFNGLSCISSORINDEXEDPROC glScissorIndexed = 0;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv = 0;
PFNGLVIEWPORTARRAYVPROC glViewportArrayv = 0;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf = 0;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv = 0;

void gl_GL_ARB_viewport_array()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLGETFLOATI_VPROC, glGetFloati_v, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLSCISSORARRAYVPROC, glScissorArrayv, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLSCISSORINDEXEDPROC, glScissorIndexed, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf, "GL_ARB_viewport_array");
  GL4_FUNC(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv, "GL_ARB_viewport_array");
  if(__available) g_ext |= kGL_ARB_viewport_array;
}
#endif


//----------------------------------------------------------------------------------------------------------------------
PFNGLCLEARDEPTHFPROC glClearDepthf = 0;
PFNGLDEPTHRANGEFPROC glDepthRangef = 0;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat = 0;
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler = 0;
PFNGLSHADERBINARYPROC glShaderBinary = 0;

void gl_GL_ARB_ES2_compatibility()
{
  bool __available = true;  
  GL4_FUNC(PFNGLCLEARDEPTHFPROC, glClearDepthf, "GL_ARB_ES2_compatibility");
  GL4_FUNC(PFNGLDEPTHRANGEFPROC, glDepthRangef, "GL_ARB_ES2_compatibility");
  GL4_FUNC(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat, "GL_ARB_ES2_compatibility");
  GL4_FUNC(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler, "GL_ARB_ES2_compatibility");
  GL4_FUNC(PFNGLSHADERBINARYPROC, glShaderBinary, "GL_ARB_ES2_compatibility");
  if(__available) g_ext |= kGL_ARB_ES2_compatibility;
}


//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback = 0;
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl = 0;
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert = 0;
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog = 0;
PFNGLGETOBJECTLABELPROC glGetObjectLabel = 0;
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel = 0;
PFNGLOBJECTLABELPROC glObjectLabel = 0;
PFNGLOBJECTPTRLABELPROC glObjectPtrLabel = 0;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup = 0;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup = 0;

void gl_GL_KHR_debug()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback, "GL_KHR_debug");
  GL4_FUNC(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl, "GL_KHR_debug");
  GL4_FUNC(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert, "GL_KHR_debug");
  GL4_FUNC(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog, "GL_KHR_debug");
  GL4_FUNC(PFNGLGETOBJECTLABELPROC, glGetObjectLabel, "GL_KHR_debug");
  GL4_FUNC(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel, "GL_KHR_debug");
  GL4_FUNC(PFNGLOBJECTLABELPROC, glObjectLabel, "GL_KHR_debug");
  GL4_FUNC(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel, "GL_KHR_debug");
  GL4_FUNC(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup, "GL_KHR_debug");
  GL4_FUNC(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup, "GL_KHR_debug");
  if(__available) g_ext2 |= kGL_KHR_debug;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute = 0;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect = 0;

void gl_GL_ARB_compute_shader()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute, "GL_ARB_compute_shader");
  GL4_FUNC(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect, "GL_ARB_compute_shader");
  if(__available) g_ext2 |= kGL_ARB_compute_shader;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect = 0;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect = 0;

void gl_GL_ARB_draw_indirect()
{
  bool __available = true;  
  GL4_FUNC(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect, "GL_ARB_draw_indirect");
  GL4_FUNC(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect, "GL_ARB_draw_indirect");
  if(__available) g_ext2 |= kGL_ARB_draw_indirect;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri = 0;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv = 0;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC glGetNamedFramebufferParameterivEXT = 0;
PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC glNamedFramebufferParameteriEXT = 0;

void gl_GL_ARB_framebuffer_no_attachments()
{
  bool __available = true;  
  GL4_FUNC(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri, "GL_ARB_framebuffer_no_attachments");
  GL4_FUNC(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv, "GL_ARB_framebuffer_no_attachments");
  GL4_FUNC(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT, "GL_ARB_framebuffer_no_attachments");
  GL4_FUNC(PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC, glNamedFramebufferParameteriEXT, "GL_ARB_framebuffer_no_attachments");
  if(__available) g_ext2 |= kGL_ARB_framebuffer_no_attachments;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName = 0;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv = 0;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv = 0;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex = 0;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation = 0;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv = 0;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv = 0;

void gl_GL_ARB_shader_subroutine()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv, "GL_ARB_shader_subroutine");
  GL4_FUNC(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv, "GL_ARB_shader_subroutine");
  if(__available) g_ext2 |= kGL_ARB_shader_subroutine;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv = 0;

void gl_GL_ARB_shader_atomic_counters()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv, "GL_ARB_shader_atomic_counters");
  if(__available) g_ext2 |= kGL_ARB_shader_atomic_counters;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ = 0;

void gl_GL_ARB_internalformat_query()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ, "GL_ARB_internalformat_query");
  if(__available) g_ext2 |= kGL_ARB_internalformat_query;
}


//----------------------------------------------------------------------------------------------------------------------
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v = 0;

void gl_GL_ARB_internalformat_query2()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v, "GL_ARB_internalformat_query2");
  if(__available) g_ext2 |= kGL_ARB_internalformat_query2;
}
#endif


//----------------------------------------------------------------------------------------------------------------------
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = 0;
PFNGLSAMPLEMASKIPROC glSampleMaski = 0;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = 0;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = 0;

void gl_GL_ARB_texture_multisample()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv, "GL_ARB_texture_multisample");
  GL4_FUNC(PFNGLSAMPLEMASKIPROC, glSampleMaski, "GL_ARB_texture_multisample");
  GL4_FUNC(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample, "GL_ARB_texture_multisample");
  GL4_FUNC(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample, "GL_ARB_texture_multisample");
  if(__available) g_ext2 |= kGL_ARB_texture_multisample;
}


//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = 0;
#endif
PFNGLPATCHPARAMETERIPROC glPatchParameteri = 0;

void gl_GL_ARB_tessellation_shader()
{
  bool __available = true;
  #if !SUPPPORT_INTEL_HD
  GL4_FUNC(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv, "GL_ARB_tessellation_shader");
  #endif
  GL4_FUNC(PFNGLPATCHPARAMETERIPROC, glPatchParameteri, "GL_ARB_tessellation_shader");
  if(__available) g_ext2 |= kGL_ARB_tessellation_shader;
}


//----------------------------------------------------------------------------------------------------------------------
#if !SUPPPORT_INTEL_HD
PFNGLGETUNIFORMDVPROC glGetUniformdv = 0;
PFNGLUNIFORM1DPROC glUniform1d = 0;
PFNGLUNIFORM1DVPROC glUniform1dv = 0;
PFNGLUNIFORM2DPROC glUniform2d = 0;
PFNGLUNIFORM2DVPROC glUniform2dv = 0;
PFNGLUNIFORM3DPROC glUniform3d = 0;
PFNGLUNIFORM3DVPROC glUniform3dv = 0;
PFNGLUNIFORM4DPROC glUniform4d = 0;
PFNGLUNIFORM4DVPROC glUniform4dv = 0;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv = 0;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv = 0;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv = 0;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv = 0;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv = 0;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv = 0;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv = 0;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv = 0;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv = 0;

void gl_GL_ARB_gpu_shader_fp64()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETUNIFORMDVPROC, glGetUniformdv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM1DPROC, glUniform1d, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM1DVPROC, glUniform1dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM2DPROC, glUniform2d, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM2DVPROC, glUniform2dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM3DPROC, glUniform3d, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM3DVPROC, glUniform3dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM4DPROC, glUniform4d, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORM4DVPROC, glUniform4dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX2DVPROC, glUniformMatrix2dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv, "GL_ARB_gpu_shader_fp64");
  GL4_FUNC(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv, "GL_ARB_gpu_shader_fp64");
  if(__available) g_ext2 |= kGL_ARB_gpu_shader_fp64;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv = 0;
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d = 0;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv = 0;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d = 0;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv = 0;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d = 0;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv = 0;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d = 0;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv = 0;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer = 0;

void gl_GL_ARB_vertex_attrib_64bit()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv, "GL_ARB_vertex_attrib_64bit");
  GL4_FUNC(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer, "GL_ARB_vertex_attrib_64bit");
  if(__available) g_ext2 |= kGL_ARB_vertex_attrib_64bit;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData = 0;
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData = 0;
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer = 0;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer = 0;
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage = 0;
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage = 0;

void gl_GL_ARB_invalidate_subdata()
{
  bool __available = true;
  GL4_FUNC(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData, "GL_ARB_invalidate_subdata");
  GL4_FUNC(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData, "GL_ARB_invalidate_subdata");
  GL4_FUNC(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer, "GL_ARB_invalidate_subdata");
  GL4_FUNC(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer, "GL_ARB_invalidate_subdata");
  GL4_FUNC(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage, "GL_ARB_invalidate_subdata");
  GL4_FUNC(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage, "GL_ARB_invalidate_subdata");
  if(__available) g_ext2 |= kGL_ARB_invalidate_subdata;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect = 0;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect = 0;

void gl_GL_ARB_multi_draw_indirect()
{
  bool __available = true;
  GL4_FUNC(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect, "GL_ARB_multi_draw_indirect");
  GL4_FUNC(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect, "GL_ARB_multi_draw_indirect");
  if(__available) g_ext2 |= kGL_ARB_multi_draw_indirect;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding = 0;

void gl_GL_ARB_shader_storage_buffer_object()
{
  bool __available = true;
  GL4_FUNC(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding, "GL_ARB_shader_storage_buffer_object");
  if(__available) g_ext2 |= kGL_ARB_shader_storage_buffer_object;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLTEXBUFFERRANGEPROC glTexBufferRange = 0;
PFNGLTEXTUREBUFFERRANGEEXTPROC glTextureBufferRangeEXT = 0;

void gl_GL_ARB_texture_buffer_range()
{
  bool __available = true;
  GL4_FUNC(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXTUREBUFFERRANGEEXTPROC, glTextureBufferRangeEXT, "GL_ARB_texture_buffer_range");
  if(__available) g_ext2 |= kGL_ARB_texture_buffer_range;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLTEXSTORAGE1DPROC glTexStorage1D = 0;
PFNGLTEXSTORAGE2DPROC glTexStorage2D = 0;
PFNGLTEXSTORAGE3DPROC glTexStorage3D = 0;
PFNGLTEXTURESTORAGE1DEXTPROC glTextureStorage1DEXT = 0;
PFNGLTEXTURESTORAGE2DEXTPROC glTextureStorage2DEXT = 0;
PFNGLTEXTURESTORAGE3DEXTPROC glTextureStorage3DEXT = 0;

void gl_GL_ARB_texture_storage()
{
  bool __available = true;
  GL4_FUNC(PFNGLTEXSTORAGE1DPROC, glTexStorage1D, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXSTORAGE2DPROC, glTexStorage2D, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXSTORAGE3DPROC, glTexStorage3D, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXTURESTORAGE1DEXTPROC, glTextureStorage1DEXT, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXTURESTORAGE2DEXTPROC, glTextureStorage2DEXT, "GL_ARB_texture_buffer_range");
  GL4_FUNC(PFNGLTEXTURESTORAGE3DEXTPROC, glTextureStorage3DEXT, "GL_ARB_texture_buffer_range");
  if(__available) g_ext2 |= kGL_ARB_texture_storage;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLTEXTUREVIEWPROC glTextureView = 0;

void gl_GL_ARB_texture_view()
{
  bool __available = true;
  GL4_FUNC(PFNGLTEXTUREVIEWPROC, glTextureView, "GL_ARB_texture_view");
  if(__available) g_ext2 |= kGL_ARB_texture_view;
}

//----------------------------------------------------------------------------------------------------------------------
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary = 0;
PFNGLPROGRAMBINARYPROC glProgramBinary = 0;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = 0;

void gl_GL_ARB_get_program_binary()
{
  bool __available = true;
  GL4_FUNC(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary, "GL_ARB_get_program_binary");
  GL4_FUNC(PFNGLPROGRAMBINARYPROC, glProgramBinary, "GL_ARB_get_program_binary");
  GL4_FUNC(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri, "GL_ARB_get_program_binary");
  if(__available) g_ext2 |= kGL_ARB_get_program_binary;
}
#endif


//----------------------------------------------------------------------------------------------------------------------
void initOpenGL()
{
  gl_1_2();
  gl_1_3();
  gl_1_4();
  gl_1_5();
  gl_2_0();
  gl_2_1();
  gl_3_0();
  gl_3_1();
  gl_3_2();
  gl_3_3();
  gl_4_0();
  gl_4_5();
  gl_GL_ARB_color_buffer_float();
  gl_GL_ARB_framebuffer_object();
  gl_GL_ARB_map_buffer_range();
  gl_GL_ARB_sampler_objects();
  gl_GL_ARB_copy_buffer();
  gl_GL_ARB_draw_elements_base_vertex();
  gl_GL_ARB_uniform_buffer_object();
  gl_GL_ARB_provoking_vertex();
  gl_GL_ARB_vertex_array_object();
  gl_GL_ARB_timer_query();
  gl_GL_ARB_sync();
  gl_GL_INTEL_map_texture();
  gl_GL_INTEL_performance_queries();
  gl_GL_ARB_ES2_compatibility();
  gl_GL_ARB_texture_multisample();
  gl_GL_ARB_blend_func_extended();
  gl_GL_ARB_tessellation_shader();
  #if !SUPPPORT_INTEL_HD
  gl_GL_ARB_program_interface_query();
  gl_GL_ARB_clear_texture();
  gl_GL_ARB_clear_buffer_object();
  gl_GL_ARB_cl_event();
  gl_GL_ARB_buffer_storage();
  gl_GL_ARB_bindless_texture();
  gl_GL_ARB_base_instance();
  gl_GL_ARB_transform_feedback3();
  gl_GL_ARB_transform_feedback_instanced();
  gl_GL_ARB_multi_bind();
  gl_GL_ARB_shader_image_load_store();
  gl_GL_ARB_separate_shader_objects();
  gl_GL_ARB_vertex_attrib_binding();
  gl_GL_ARB_transform_feedback2();
  gl_GL_ARB_viewport_array();
  gl_GL_KHR_debug();
  gl_GL_ARB_compute_shader();
  gl_GL_ARB_framebuffer_no_attachments();
  gl_GL_ARB_draw_indirect();
  gl_GL_ARB_shader_subroutine();
  gl_GL_ARB_shader_atomic_counters();
  gl_GL_ARB_internalformat_query();
  gl_GL_ARB_internalformat_query2();
  gl_GL_ARB_gpu_shader_fp64();
  gl_GL_ARB_vertex_attrib_64bit();
  gl_GL_ARB_invalidate_subdata();
  gl_GL_ARB_multi_draw_indirect();
  gl_GL_ARB_shader_storage_buffer_object();
  gl_GL_ARB_texture_buffer_range();
  gl_GL_ARB_texture_storage();
  gl_GL_ARB_texture_view();
  gl_GL_ARB_get_program_binary();
  #endif
  
#if (GL4_DUMP_MISSING_FUNCS)
  {
    std::cerr << "MISSING_FUNCS:" << std::endl;
    std::set<std::string>::const_iterator it = g_missing_funcs.begin();
    for(;it != g_missing_funcs.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
    std::cerr << std::endl;
  }
#endif
  
#if (GL4_DUMP_MISSING_EXTENSIONS)
  {
    std::cerr << "MISSING_EXTENSIONS:" << std::endl;
    std::set<std::string>::const_iterator it = g_ext_funcs.begin();
    for(;it != g_ext_funcs.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
    std::cerr << std::endl;
  }
#endif

#if (GL4_DUMP_FUNCS)
  {
    std::cerr << "AVAILABLE_FUNCS:" << std::endl;
    std::set<std::string>::const_iterator it = g_funcs.begin();
    for(;it != g_funcs.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
    std::cerr << std::endl;
  }
#endif

#if (GL4_DUMP_EXTENSIONS)
  {
    std::set<std::string> ext;
    const char* c = (const char*)glGetString(GL_EXTENSIONS);
    while(*c)
    {
      // skip whitespace
      while(*c == ' ')
      {
        ++c;
      }
      // build next EXT string
      std::string s;
      while(*c && (*c != ' ' && *c != '\0'))
      {
        s += *c; 
        ++c;
      }
      // add into set
      if(!s.empty())
      {
        ext.insert(s);
      }
    }
    
    std::cerr << "DRIVER EXTENSION STRINGS:" << std::endl;
    std::set<std::string>::const_iterator it = ext.begin();
    for(;it != ext.end(); ++it)
    {
      std::cout << *it << std::endl;
    }
    std::cerr << std::endl;
  }
#endif
}

#endif

