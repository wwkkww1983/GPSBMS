/* errno.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.1.3 */
/* Copyright (C) Codemist Ltd., 1988                            */
/* Copyright 1991 ARM Limited. All rights reserved.             */
/* version 1 */

/*
 * RCS $Revision: 1.11.2.1 $
 * Checkin $Date: 2001/02/22 16:23:35 $
 * Revising $Author: cadeniyi $
 */

#ifndef __errno_h
#define __errno_h

  #ifndef __ERRNO_DECLS
  #define __ERRNO_DECLS

    #undef __CLIBNS

    #ifdef __cplusplus
      #ifdef __EDG_RUNTIME_USES_NAMESPACES
        namespace std {
        #define __CLIBNS std::
      #else
        #define __CLIBNS ::
      #endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

      extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */


extern __pure volatile int *__rt_errno_addr(void);


    #ifdef __cplusplus
      }  /* extern "C" */
    #endif

    #ifdef __EDG_RUNTIME_USES_NAMESPACES
      }  /* namespace std */
    #endif
  #endif /* __ERRNO_DECLS */

  #ifdef __EDG_RUNTIME_USES_NAMESPACES
    #ifndef __ERRNO_NO_EXPORTS
      using std::__rt_errno_addr;
    #endif 
  #endif

#define errno (*__CLIBNS __rt_errno_addr())

/*
 * expands to a modifiable lvalue that has type volatile int, the value of
 * which is set to a positive error code by several library functions. It is
 * initialised to zero at program startup, but is never set to zero by any
 * library function. The value of errno may be set to nonzero by a library
 * function call whether or not there is an error, provided the use of errno
 * is not documented in the description of the function in the Standard.
 */

#define EDOM    1
/*
 * if a domain error occurs (an input argument is outside the
 * domain over which the mathematical function is defined) the
 * integer expression errno acquires the value of the macro EDOM
 * and HUGE_VAL is returned. EDOM may be used by non-mathematical
 * functions.
 */
#define ERANGE 2
/*
 * a range error occurs if the result of a function can not be
 * represented as a double value. If the result overflows (the
 * magnitude of the result is so large that it cannot be
 * represented in an object of the specified type), the function
 * returns the value of the macro HUGE_VAL, with the same sign as
 * the correct value of the function; the integer expression errno
 * acquires the value of the macro ERANGE. If the result underflows
 * (the magnitude of the result is so small that it cannot be
 * represented in an object of the specified type), the function
 * returns zero; the integer expression errno acquires the value of
 * the macro ERANGE. ERANGE may be used by non-mathematical
 * functions.
 */
#define ESIGNUM 3
/*
 * ESIGNUM is generated by signal() if the user attempts to change
 * the handling of a nonexistent signal. ESIGNUM is not part of the
 * ANSI C standard.
 */
#define EILSEQ  4
/*
 * EILSEQ is notionally generated by multi-byte character
 * processing routines (mbtowc et al), and must be defined for this
 * reason. ARM's libraries do not generate it.
 *
 * EILSEQ is not mentioned in the ANSI C standard itself, but in
 * Normative Addendum 1.
 */

#endif

/* end of errno.h */