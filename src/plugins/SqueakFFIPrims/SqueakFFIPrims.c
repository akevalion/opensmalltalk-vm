/* Automatically generated by
	ThreadedFFIPlugin VMMaker.oscog-nice.2693 uuid: 645642cf-46fa-4505-85fb-019e1f91c68e
 */

#if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_7__) || defined(__arm32__) || defined(ARM32) || defined(_M_ARM)

# define ARM32FFIPlugin_exports SqueakFFIPrims_exports
# include "ARM32FFIPlugin.c"

#elif defined(__ARM_ARCH_ISA_A64) || defined(__aarch64__) || defined(__arm64__) || defined(ARM64) || defined(_M_ARM64)

# define ARM64FFIPlugin_exports SqueakFFIPrims_exports
# include "ARM64FFIPlugin.c"

#elif defined(_M_I386) || defined(_M_IX86) || defined(_X86_) || defined(i386) || defined(i486) || defined(i586) || defined(i686) || defined(__i386__) || defined(__386__) || defined(X86) || defined(I386)

# define IA32FFIPlugin_exports SqueakFFIPrims_exports
# include "IA32FFIPlugin.c"

#elif !defined(_WIN64) && (defined(x86_64) || defined(__amd64) || defined(__x86_64) || defined(__amd64__) || defined(__x86_64__))

# define X64SysVFFIPlugin_exports SqueakFFIPrims_exports
# include "X64SysVFFIPlugin.c"

#elif defined(_WIN64) && (defined(x86_64) || defined(__amd64) || defined(__x86_64) || defined(__amd64__) || defined(__x86_64__) || defined(_M_AMD64) || defined(_M_X64))

# define X64Win64FFIPlugin_exports SqueakFFIPrims_exports
# include "X64Win64FFIPlugin.c"

#else
# error As yet no FFI implementation appears to exist for your platform.
# error Consider implementing it, starting by adding a subclass of ThreadedFFIPlugin.
#endif
