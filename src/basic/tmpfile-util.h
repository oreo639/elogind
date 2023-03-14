/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

int fopen_temporary_at(int dir_fd, const char *path, FILE **ret_file, char **ret_path);
static inline int fopen_temporary(const char *path, FILE **ret_file, char **ret_path) {
        return fopen_temporary_at(AT_FDCWD, path, ret_file, ret_path);
}

#if 0 /// UNNEEDED by elogind
int fopen_temporary_child_at(int dir_fd, const char *path, FILE **ret_file, char **ret_path);
static inline int fopen_temporary_child(const char *path, FILE **ret_file, char **ret_path) {
        return fopen_temporary_child_at(AT_FDCWD, path, ret_file, ret_path);
}
#endif // 0

int mkostemp_safe(char *pattern);
int fmkostemp_safe(char *pattern, const char *mode, FILE**_f);

int tempfn_xxxxxx(const char *p, const char *extra, char **ret);
int tempfn_random(const char *p, const char *extra, char **ret);
#if 0 /// UNNEEDED by elogind
int tempfn_random_child(const char *p, const char *extra, char **ret);
#endif // 0

int open_tmpfile_unlinkable(const char *directory, int flags);
#if 0 /// UNNEEDED by elogind
int open_tmpfile_linkable_at(int dir_fd, const char *target, int flags, char **ret_path);
static inline int open_tmpfile_linkable(const char *target, int flags, char **ret_path) {
        return open_tmpfile_linkable_at(AT_FDCWD, target, flags, ret_path);
}
int fopen_tmpfile_linkable(const char *target, int flags, char **ret_path, FILE **ret_file);

#endif // 0
int link_tmpfile_at(int fd, int dir_fd, const char *path, const char *target, bool replace);
static inline int link_tmpfile(int fd, const char *path, const char *target, bool replace) {
        return link_tmpfile_at(fd, AT_FDCWD, path, target, replace);
}
int flink_tmpfile(FILE *f, const char *path, const char *target, bool replace);

int mkdtemp_malloc(const char *template, char **ret);
int mkdtemp_open(const char *template, int flags, char **ret);
