#ifndef __LOG_H__
#define __LOG_H__

#include <inttypes.h>

#ifndef LOG_NOGLIBC

#include <string.h>
#include <errno.h>
#include <stdarg.h>

#endif /* LOG_NOGLIBC */

#define LOG_UNSET (-1)
#define LOG_MSG	  (0) /* Print message regardless of log level */
#define LOG_ERROR (1) /* Errors only, when we're in trouble */
#define LOG_WARN  (2) /* Warnings, dazen and confused but trying to continue */
#define LOG_INFO  (3) /* Informative, everything is fine */
#define LOG_DEBUG (4) /* Debug only */

#define DEFAULT_LOGLEVEL LOG_WARN

/*
 * This is low-level printing helper, try hard not to use it directly
 * and use the pr_foo() helpers below.
 */
extern void print_on_level(unsigned int loglevel, const char *format, ...)
	__attribute__((__format__(__printf__, 2, 3)));

#ifndef LOG_PREFIX
#define LOG_PREFIX
#endif

void flush_early_log_buffer(int fd);

#define print_once(loglevel, fmt, ...)                                \
	do {                                                          \
		static bool __printed;                                \
		if (!__printed) {                                     \
			print_on_level(loglevel, fmt, ##__VA_ARGS__); \
			__printed = 1;                                \
		}                                                     \
	} while (0)

#define pr_msg(fmt, ...) print_on_level(LOG_MSG, fmt, ##__VA_ARGS__)

#define pr_info(fmt, ...) print_on_level(LOG_INFO, LOG_PREFIX fmt, ##__VA_ARGS__)

#define pr_err(fmt, ...) print_on_level(LOG_ERROR, "Error (%s:%d): " LOG_PREFIX fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#define pr_err_once(fmt, ...) print_once(LOG_ERROR, fmt, ##__VA_ARGS__)

#define pr_warn(fmt, ...) print_on_level(LOG_WARN, "Warn  (%s:%d): " LOG_PREFIX fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#define pr_warn_once(fmt, ...) print_once(LOG_WARN, "Warn  (%s:%d): " LOG_PREFIX fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#define pr_debug(fmt, ...) print_on_level(LOG_DEBUG, LOG_PREFIX fmt, ##__VA_ARGS__)

#ifndef LOG_NOGLIBC

#define pr_perror(fmt, ...) pr_err(fmt ": %s\n", ##__VA_ARGS__, strerror(errno))

#define pr_pwarn(fmt, ...) pr_warn(fmt ": %s\n", ##__VA_ARGS__, strerror(errno))

#endif /* LOG_NOGLIBC */

#endif /* __LOG_H__ */

