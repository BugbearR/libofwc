#ifndef ofw_Error_H_
#define ofw_Error_H_

#ifdef ofw_HAVE_PRAGMA_ONCE
#pragma once
#endif

#include <stdint.h>

#ifndef ofw_Base_H
#include "ofw/bit.h"
#endif

/**
 * Bit structure
 * 0   8 Reason(sub) (free to use in application)
 * 8  12 Reason(main)
 * 20  4 argument number (0: not specified)
 * 24  4 (reserved)
 * 28  1 temporary flag (1:temporary 0:permanent)
 * 29  2 owner (0:errno 1:Ofw 2:user 3:reserved)
 * 31  1 (sign flag)(reserved)
 */

#define ofw_Error_toMask(bit, base) (((1 << (bit)) - 1) << (base))

#define ofw_Error_OWNER_BASE (29)
#define ofw_Error_OWNER_BIT (2)
#define ofw_Error_OWNER_MASK (ofw_Error_toMask(ofw_Error_OWNER_BIT, ofw_Error_OWNER_BASE))
#define ofw_Error_getOwner(e) ((e) & ofw_Error_OWNER_MASK)

#define ofw_Error_OWNER_ERRNO (0)
#define ofw_Error_OWNER_Ofw (1 << ofw_Error_OWNER_BASE)
#define ofw_Error_OWNER_USER (2 << ofw_Error_OWNER_BASE)

#define ofw_Error_isOwnerErrno(e) (((e) & ofw_Error_OWNER_MASK) == ofw_Error_OWNER_ERRNO)
#define ofw_Error_isOwnerOfw(e) (((e) & ofw_Error_OWNER_MASK) == ofw_Error_OWNER_Ofw)
#define ofw_Error_isOwnerUser(e) (((e) & ofw_Error_OWNER_MASK) == ofw_Error_OWNER_USER)

#define ofw_Error_REASON_MAIN_BASE (8)
#define ofw_Error_REASON_MAIN_BIT (12)
#define ofw_Error_REASON_MAIN_MASK (ofw_Error_toMask(ofw_Error_REASON_MAIN_BIT, ofw_Error_REASON_MAIN_BASE))
#define ofw_Error_getReasonMain(e) ((e) & ofw_Error_REASON_MAIN_MASK)

#define ofw_Error_REASON_SUB_BASE (0)
#define ofw_Error_REASON_SUB_BIT (8)
#define ofw_Error_REASON_SUB_MASK (ofw_Error_toMask(ofw_Error_REASON_SUB_BIT,ofw_Error_REASON_SUB_BASE))
#define ofw_Error_getReasonSub(e) ((e) & ofw_Error_REASON_SUB_MASK)

#define ofw_Error_REASON_MASK (ofw_Error_REASON_MAIN_MASK | ofw_Error_REASON_SUB_MASK)
#define ofw_Error_getReason(e) ((e) & ofw_Error_REASON_MASK)

#define ofw_Error_getOwnerReasonMain(e) ((e) & (ofw_Error_OWNER_MASK | ofw_Error_REASON_MAIN_MASK))

#define ofw_Error_PARAM_BASE (20)
#define ofw_Error_PARAM_BIT (4)
#define ofw_Error_PARAM_MASK (ofw_Error_toMask(ofw_Error_PARAM_BIT,ofw_Error_PARAM_BASE))
#define ofw_Error_getParam(e) ((e) & ofw_Error_PARAM_MASK)
#define ofw_Error_setParam(e, param) (((e) & ~ofw_Error_PARAM_MASK) | (param))

#define ofw_Error_PARAM1 (0x1<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM2 (0x2<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM3 (0x3<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM4 (0x4<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM5 (0x5<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM6 (0x6<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM7 (0x7<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM8 (0x8<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM9 (0x9<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM10 (0xa<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM11 (0xb<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM12 (0xc<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM13 (0xd<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM14 (0xe<<ofw_Error_PARAM_BASE)
#define ofw_Error_PARAM15 (0xf<<ofw_Error_PARAM_BASE)

#define ofw_Error_getParam(e) ((e) & ofw_Error_PARAM_MASK)

/** No error. */
#define ofw_Error_NO_ERROR (0)

/**
 * Temporary flag.
 */
#define ofw_Error_TEMPORARY_BASE (28)

#define ofw_Error_TEMPORARY (1<<ofw_Error_TEMPORARY_BASE)

#define ofw_Error_isTemporary(x) (((x) & ofw_Error_TEMPORARY) != 0)

/**
 * Declare error main reason.
 */
#define ofw_Error_declReasonMain(n) (ofw_Error_OWNER_Ofw | ((n)<<ofw_Error_REASON_MAIN_BASE))

/**
 * Error.
 */
#define ofw_Error_ERROR (ofw_Error_declReasonMain(1))

/**
 * Failed.
 * Not error, but failed.
 */
#define ofw_Error_FAILED (ofw_Error_declReasonMain(2))

/**
 * Not implemented.
 */
#define ofw_Error_NOT_IMPLEMENTED (ofw_Error_declReasonMain(3))

/**
 * Invalid parameter.
 */
#define ofw_Error_INVALID_PARAM (ofw_Error_declReasonMain(4))

/**
 * Invalid setting.
 */
#define ofw_Error_INVALID_SETTING (ofw_Error_declReasonMain(5))

/**
 * Not initialized.
 */
#define ofw_Error_NOT_INITALIZED (ofw_Error_declReasonMain(6))

/**
 * Invalid state.
 */
#define ofw_Error_INVALID_STATE (ofw_Error_declReasonMain(7))

/**
 * NULL Pointer detected.
 */
#define ofw_Error_NULL_POINTER (ofw_Error_declReasonMain(8))

/**
 * Invalid object.
 */
#define ofw_Error_INVALID_OBJECT (ofw_Error_declReasonMain(9))

/**
 * Invalid request.
 */
#define ofw_Error_INVALID_REQUEST (ofw_Error_declReasonMain(10))

/**
 * Processing denied.
 * (No processing has been done yet.)
 */
#define ofw_Error_DENIED (ofw_Error_declReasonMain(11))

/**
 * Not authorized.
 */
#define ofw_Error_NO_AUTH (ofw_Error_declReasonMain(12))

/**
 * Not permitted.
 * The requested operation is not allowed.
 */
#define ofw_Error_NO_PERMIT (ofw_Error_declReasonMain(13))

/**
 * You aren't owner.
 */
#define ofw_Error_NOT_OWNER (ofw_Error_declReasonMain(14))

/**
 * In use by others.
 */
#define ofw_Error_IN_USE (ofw_Error_declReasonMain(15))

/**
 * Not supported.
 * Functionality is there, but the required capabilities are not.
 */
#define ofw_Error_NOT_SUPPORTED (ofw_Error_declReasonMain(16))

/**
 * Not in service.
 */
#define ofw_Error_NOT_IN_SERVICE (ofw_Error_declReasonMain(17))

/**
 * Device offline.
 */
#define ofw_Error_OFFLINE (ofw_Error_declReasonMain(18))

/**
 * Not ready.
 */
#define ofw_Error_NOT_READY (ofw_Error_declReasonMain(19))

/**
 * Busy.
 */
#define ofw_Error_BUSY (ofw_Error_declReasonMain(20))

/**
 * Already closed.
 */
#define ofw_Error_ALREADY_CLOSED (ofw_Error_declReasonMain(21))

/**
 * Function error.
 * There was an unrepairable error on the lower level function.
 */
#define ofw_Error_FUNCTION_ERROR (ofw_Error_declReasonMain(22))

/**
 * Out of resource.
 */
#define ofw_Error_OUT_OF_RESOURCE (ofw_Error_declReasonMain(23))

/**
 * Out of slot.
 */
#define ofw_Error_OUT_OF_SLOT (ofw_Error_declReasonMain(24))

/**
 * Out of memory.
 */
#define ofw_Error_OUT_OF_MEMORY (ofw_Error_declReasonMain(25))

/**
 * Out of storage space.
 */
#define ofw_Error_OUT_OF_STORAGE_SPACE (ofw_Error_declReasonMain(26))

/**
 * Canceled.
 * (User cancel the process. the process is not started.)
 */
#define ofw_Error_CANCELED (ofw_Error_declReasonMain(27))

/**
 * Aborted.
 * (User aborted the process. the process has started.)
 */
#define ofw_Error_ABORTED (ofw_Error_declReasonMain(28))

/**
 * Interrupted.
 * (Signal received.)
 */
#define ofw_Error_INTERRUPTED (ofw_Error_declReasonMain(29))

/**
 * Timed out.
 */
#define ofw_Error_TIMEDOUT (ofw_Error_declReasonMain(30))

/**
 * Disconnected.
 */
#define ofw_Error_DISCONNECTED (ofw_Error_declReasonMain(31))

/**
 * Termination requested.
 * (The user requested termination.)
 */
#define ofw_Error_TERMINATE_REQUESTED (ofw_Error_declReasonMain(32))

/**
 * Not exists.
 */
#define ofw_Error_NOT_EXISTS (ofw_Error_declReasonMain(33))

/**
 * Already exists.
 */
#define ofw_Error_ALREADY_EXISTS (ofw_Error_declReasonMain(34))

/**
 * Already in that state
 */
#define ofw_Error_ALREADY_STATE (ofw_Error_declReasonMain(35))

/**
 * Invalid format.
 */
#define ofw_Error_INVALID_FORMAT (ofw_Error_declReasonMain(36))

/**
 * Out of range.
 */
#define ofw_Error_OUT_OF_RANGE (ofw_Error_declReasonMain(37))

/**
 * Too big.
 */
#define ofw_Error_TOO_BIG (ofw_Error_declReasonMain(38))

/**
 * Too small.
 */
#define ofw_Error_TOO_SMALL (ofw_Error_declReasonMain(39))

/**
 * Overflow.
 */
#define ofw_Error_OVERFLOW (ofw_Error_declReasonMain(40))

/**
 * Underflow.
 */
#define ofw_Error_UNDERFLOW (ofw_Error_declReasonMain(41))

/**
 * Empty.
 */
#define ofw_Error_EMPTY (ofw_Error_declReasonMain(42))

/**
 * Full.
 */
#define ofw_Error_FULL (ofw_Error_declReasonMain(43))

/**
 * Start of data.
 */
#define ofw_Error_START_OF_DATA (ofw_Error_declReasonMain(44))

/**
 * End of data.
 */
#define ofw_Error_END_OF_DATA (ofw_Error_declReasonMain(45))

/**
 * Deadlock detected.
 */
#define ofw_Error_DEADLOCK (ofw_Error_declReasonMain(46))

/**
 * Interface inconsistency.
 */
#define ofw_Error_INTERFACE_INCONSISTENCY (ofw_Error_declReasonMain(47))


/**
 * convert errno to ofw_Errno_t.
 */
#define ofw_Error_convErrno(errno) (errno)

#endif /* ofw_Error_H_ */
