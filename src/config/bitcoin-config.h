/* src/config/bitcoin-config.h.  Generated from bitcoin-config.h.in by configure.  */
/* src/config/bitcoin-config.h.in.  Generated from configure.ac by autoheader.  */

#ifndef BITCOIN_CONFIG_H

#define BITCOIN_CONFIG_H

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define this symbol if experimental features are allowed */
/* #undef ALLOW_DOGECOIN_EXPERIMENTAL */

/* Version Build */
#define CLIENT_VERSION_BUILD 0

/* Version is release */
#define CLIENT_VERSION_IS_RELEASE false

/* Major version */
#define CLIENT_VERSION_MAJOR 1

/* Minor version */
#define CLIENT_VERSION_MINOR 14

/* Build revision */
#define CLIENT_VERSION_REVISION 99

/* Copyright holder(s) before %s replacement */
#define COPYRIGHT_HOLDERS "The %s developers"

/* Copyright holder(s) */
#define COPYRIGHT_HOLDERS_FINAL "The Bitcoin Core and Dogecoin Core developers"

/* Replacement for %s in copyright holders string */
#define COPYRIGHT_HOLDERS_SUBSTITUTION "Bitcoin Core and Dogecoin Core"

/* Copyright year */
#define COPYRIGHT_YEAR 2024

/* Date of the current release */
#define CURRENT_RELEASE_DATE "2024-08-03"

/* Define to 1 to enable wallet functions */
#define ENABLE_WALLET 1

/* Define to 1 to enable ZMQ functions */
#define ENABLE_ZMQ 0

/* Days until the next release is definitely released */
#define EXPECTED_DAYS_TO_NEXT_RELEASE 270

/* parameter and return value type for __fdelt_chk */
/* #undef FDELT_TYPE */

/* define if the Boost library is available */
#define HAVE_BOOST /**/

/* define if the Boost::Chrono library is available */
#define HAVE_BOOST_CHRONO /**/

/* define if the Boost::Filesystem library is available */
#define HAVE_BOOST_FILESYSTEM /**/

/* define if the Boost::PROGRAM_OPTIONS library is available */
#define HAVE_BOOST_PROGRAM_OPTIONS /**/

/* define if the Boost::System library is available */
#define HAVE_BOOST_SYSTEM /**/

/* define if the Boost::Thread library is available */
#define HAVE_BOOST_THREAD /**/

/* define if the Boost::Unit_Test_Framework library is available */
#define HAVE_BOOST_UNIT_TEST_FRAMEWORK /**/

/* Define to 1 if you have the <byteswap.h> header file. */
#define HAVE_BYTESWAP_H 1

/* Define this symbol if the consensus lib has been built */
#define HAVE_CONSENSUS_LIB 1

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* define if the compiler supports basic C++14 syntax */
/* #undef HAVE_CXX14 */

/* define if the compiler supports basic C++17 syntax */
/* #undef HAVE_CXX17 */

/* Define to 1 if you have the declaration of `be16toh', and to 0 if you
   don't. */
#define HAVE_DECL_BE16TOH 1

/* Define to 1 if you have the declaration of `be32toh', and to 0 if you
   don't. */
#define HAVE_DECL_BE32TOH 1

/* Define to 1 if you have the declaration of `be64toh', and to 0 if you
   don't. */
#define HAVE_DECL_BE64TOH 1

/* Define to 1 if you have the declaration of `bswap_16', and to 0 if you
   don't. */
#define HAVE_DECL_BSWAP_16 1

/* Define to 1 if you have the declaration of `bswap_32', and to 0 if you
   don't. */
#define HAVE_DECL_BSWAP_32 1

/* Define to 1 if you have the declaration of `bswap_64', and to 0 if you
   don't. */
#define HAVE_DECL_BSWAP_64 1

/* Define to 1 if you have the declaration of `daemon', and to 0 if you don't.
   */
#define HAVE_DECL_DAEMON 1

/* Define to 1 if you have the declaration of `EVP_MD_CTX_new', and to 0 if
   you don't. */
#define HAVE_DECL_EVP_MD_CTX_NEW 1

/* Define to 1 if you have the declaration of `htobe16', and to 0 if you
   don't. */
#define HAVE_DECL_HTOBE16 1

/* Define to 1 if you have the declaration of `htobe32', and to 0 if you
   don't. */
#define HAVE_DECL_HTOBE32 1

/* Define to 1 if you have the declaration of `htobe64', and to 0 if you
   don't. */
#define HAVE_DECL_HTOBE64 1

/* Define to 1 if you have the declaration of `htole16', and to 0 if you
   don't. */
#define HAVE_DECL_HTOLE16 1

/* Define to 1 if you have the declaration of `htole32', and to 0 if you
   don't. */
#define HAVE_DECL_HTOLE32 1

/* Define to 1 if you have the declaration of `htole64', and to 0 if you
   don't. */
#define HAVE_DECL_HTOLE64 1

/* Define to 1 if you have the declaration of `le16toh', and to 0 if you
   don't. */
#define HAVE_DECL_LE16TOH 1

/* Define to 1 if you have the declaration of `le32toh', and to 0 if you
   don't. */
#define HAVE_DECL_LE32TOH 1

/* Define to 1 if you have the declaration of `le64toh', and to 0 if you
   don't. */
#define HAVE_DECL_LE64TOH 1

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the declaration of `strnlen', and to 0 if you
   don't. */
#define HAVE_DECL_STRNLEN 1

/* Define to 1 if you have the declaration of `vsha512su0q_u64', and to 0 if
   you don't. */
/* #undef HAVE_DECL_VSHA512SU0Q_U64 */

/* Define to 1 if you have the declaration of `__builtin_clz', and to 0 if you
   don't. */
#define HAVE_DECL___BUILTIN_CLZ 1

/* Define to 1 if you have the declaration of `__builtin_clzl', and to 0 if
   you don't. */
#define HAVE_DECL___BUILTIN_CLZL 1

/* Define to 1 if you have the declaration of `__builtin_clzll', and to 0 if
   you don't. */
#define HAVE_DECL___BUILTIN_CLZLL 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <endian.h> header file. */
#define HAVE_ENDIAN_H 1

/* Define to 1 if the system has the `dllexport' function attribute */
/* #undef HAVE_FUNC_ATTRIBUTE_DLLEXPORT */

/* Define to 1 if the system has the `dllimport' function attribute */
/* #undef HAVE_FUNC_ATTRIBUTE_DLLIMPORT */

/* Define to 1 if the system has the `visibility' function attribute */
#define HAVE_FUNC_ATTRIBUTE_VISIBILITY 1

/* Define this symbol if the BSD getentropy system call is available */
#define HAVE_GETENTROPY 1

/* Define this symbol if the BSD getentropy system call is available with
   sys/random.h */
#define HAVE_GETENTROPY_RAND 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `advapi32' library (-ladvapi32). */
/* #undef HAVE_LIBADVAPI32 */

/* Define to 1 if you have the `comctl32' library (-lcomctl32). */
/* #undef HAVE_LIBCOMCTL32 */

/* Define to 1 if you have the `comdlg32' library (-lcomdlg32). */
/* #undef HAVE_LIBCOMDLG32 */

/* Define to 1 if you have the `crypt32' library (-lcrypt32). */
/* #undef HAVE_LIBCRYPT32 */

/* Define to 1 if you have the `gdi32' library (-lgdi32). */
/* #undef HAVE_LIBGDI32 */

/* Define to 1 if you have the `imm32' library (-limm32). */
/* #undef HAVE_LIBIMM32 */

/* Define to 1 if you have the `iphlpapi' library (-liphlpapi). */
/* #undef HAVE_LIBIPHLPAPI */

/* Define to 1 if you have the `kernel32' library (-lkernel32). */
/* #undef HAVE_LIBKERNEL32 */

/* Define to 1 if you have the `mingwthrd' library (-lmingwthrd). */
/* #undef HAVE_LIBMINGWTHRD */

/* Define to 1 if you have the `mswsock' library (-lmswsock). */
/* #undef HAVE_LIBMSWSOCK */

/* Define to 1 if you have the `ole32' library (-lole32). */
/* #undef HAVE_LIBOLE32 */

/* Define to 1 if you have the `oleaut32' library (-loleaut32). */
/* #undef HAVE_LIBOLEAUT32 */

/* Define to 1 if you have the `rpcrt4' library (-lrpcrt4). */
/* #undef HAVE_LIBRPCRT4 */

/* Define to 1 if you have the `shell32' library (-lshell32). */
/* #undef HAVE_LIBSHELL32 */

/* Define to 1 if you have the `shlwapi' library (-lshlwapi). */
/* #undef HAVE_LIBSHLWAPI */

/* Define to 1 if you have the `ssp' library (-lssp). */
/* #undef HAVE_LIBSSP */

/* Define to 1 if you have the `user32' library (-luser32). */
/* #undef HAVE_LIBUSER32 */

/* Define to 1 if you have the `uuid' library (-luuid). */
/* #undef HAVE_LIBUUID */

/* Define to 1 if you have the `winmm' library (-lwinmm). */
/* #undef HAVE_LIBWINMM */

/* Define to 1 if you have the `winspool' library (-lwinspool). */
/* #undef HAVE_LIBWINSPOOL */

/* Define to 1 if you have the `ws2_32' library (-lws2_32). */
/* #undef HAVE_LIBWS2_32 */

/* Define to 1 if you have the `z ' library (-lz ). */
/* #undef HAVE_LIBZ_ */

/* Define this symbol if you have mallopt with M_ARENA_MAX */
#define HAVE_MALLOPT_ARENA_MAX 1

/* Define to 1 if you have the <miniupnpc/miniupnpc.h> header file. */
#define HAVE_MINIUPNPC_MINIUPNPC_H 1

/* Define to 1 if you have the <miniupnpc/miniwget.h> header file. */
#define HAVE_MINIUPNPC_MINIWGET_H 1

/* Define to 1 if you have the <miniupnpc/upnpcommands.h> header file. */
#define HAVE_MINIUPNPC_UPNPCOMMANDS_H 1

/* Define to 1 if you have the <miniupnpc/upnperrors.h> header file. */
#define HAVE_MINIUPNPC_UPNPERRORS_H 1

/* Define this symbol if you have MSG_NOSIGNAL */
#define HAVE_MSG_NOSIGNAL 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
#define HAVE_PTHREAD_PRIO_INHERIT 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define if you have `strerror_r'. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define this symbol if the BSD sysctl(KERN_ARND) is available */
/* #undef HAVE_SYSCTL_ARND */

/* Define to 1 if you have the <sys/endian.h> header file. */
/* #undef HAVE_SYS_ENDIAN_H */

/* Define this symbol if the Linux getrandom system call is available */
#define HAVE_SYS_GETRANDOM 1

/* Define to 1 if you have the <sys/prctl.h> header file. */
#define HAVE_SYS_PRCTL_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if the visibility attribute is supported. */
#define HAVE_VISIBILITY_ATTRIBUTE 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "https://github.com/dogecoin/dogecoin/issues"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Dogecoin Core"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Dogecoin Core 1.14.99"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "dogecoin"

/* Define to the home page for this package. */
#define PACKAGE_URL "https://dogecoin.com/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.14.99"

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Define this symbol if the qt platform is cocoa */
/* #undef QT_QPA_PLATFORM_COCOA */

/* Define this symbol if the qt platform is windows */
/* #undef QT_QPA_PLATFORM_WINDOWS */

/* Define this symbol if the qt platform is xcb */
/* #undef QT_QPA_PLATFORM_XCB */

/* Define this symbol if qt plugins are static */
/* #undef QT_STATICPLUGIN */

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
#define STRERROR_R_CHAR_P 1

/* Define this symbol if armv8 crypto works */
/* #undef USE_ARMV8 */

/* Define this symbol if armv8.2 crypto works */
/* #undef USE_ARMV82 */

/* Define this symbol if intel axv2 works */
/* #undef USE_AVX2 */

/* Define if dbus support should be compiled in */
/* #undef USE_DBUS */

/* Define if QR support should be compiled in */
/* #undef USE_QRCODE */

/* Define this symbol if SSE2 works */
/* #undef USE_SSE2 */

/* UPnP support not compiled if undefined, otherwise value (0 or 1) determines
   default state */
#define USE_UPNP 0

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

#endif //BITCOIN_CONFIG_H
