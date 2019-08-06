/*
 * UNG's Not GNU
 *
 * Copyright (c) 2011-2019, Jakob Kaivo <jkk@ung.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _POSIX_C_SOURCE 2
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	while (getopt(argc, argv, "") != -1) {
		return 1;
	}

	if (argc - optind > 2) {
		fprintf(stderr, "link: extra operands\n");
		return 1;
	}

	if (argc - optind < 2) {
		fprintf(stderr, "link: missing operands\n");
		return 1;
	}

	if (link(argv[optind], argv[optind + 1]) != 0) {
		fprintf(stderr, "link: %s -> %s: %s\n", argv[optind],
			argv[optind + 1], strerror(errno));
		return 1;
	}

	return 0;
}
