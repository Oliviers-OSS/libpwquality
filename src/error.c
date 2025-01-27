/*
 * libpwquality main API code for translation of errors
 *
 * See the end of the file for Copyright and License Information
 */
#include "config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pwquality.h"
#include "pwqprivate.h"

/* Create an error message, the auxerror is generated by the library call
 * and so it can be an arbitrary thing - it does not have to be a pointer
 * to string. */
const char *
pwquality_strerror(char *buf, size_t len, int rv, void *auxerror)
{
        static char intbuf[PWQ_MAX_ERROR_MESSAGE_LEN];

        if (buf == NULL) {
                buf = intbuf;
                len = sizeof(intbuf);
        }

        switch(rv) {
        case PWQ_ERROR_MEM_ALLOC:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("Memory allocation error when setting"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Memory allocation error");
        case PWQ_ERROR_SAME_PASSWORD:
                return _("The password is the same as the old one");
        case PWQ_ERROR_PALINDROME:
                return _("The password is a palindrome");
        case PWQ_ERROR_CASE_CHANGES_ONLY:
                return _("The password differs with case changes only");
        case PWQ_ERROR_TOO_SIMILAR:
                return _("The password is too similar to the old one");
        case PWQ_ERROR_USER_CHECK:
                return _("The password contains the user name in some form");
        case PWQ_ERROR_GECOS_CHECK:
                return _("The password contains words from the real name of the user in some form");
        case PWQ_ERROR_BAD_WORDS:
                return _("The password contains forbidden words in some form");
        case PWQ_ERROR_MIN_DIGITS:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains less than %ld digits"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too few digits");
        case PWQ_ERROR_MIN_UPPERS:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains less than %ld uppercase letters"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too few uppercase letters");
        case PWQ_ERROR_MIN_LOWERS:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains less than %ld lowercase letters"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too few lowercase letters");
        case PWQ_ERROR_MIN_OTHERS:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains less than %ld non-alphanumeric characters"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too few non-alphanumeric characters");
        case PWQ_ERROR_MIN_LENGTH:
                if (auxerror) {
                        snprintf(buf, len, _("The password is shorter than %ld characters"), (long)auxerror);
                        return buf;
                }
                return _("The password is too short");
        case PWQ_ERROR_ROTATED:
                return _("The password is just rotated old one");
        case PWQ_ERROR_MIN_CLASSES:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains less than %ld character classes"), (long)auxerror);
                        return buf;
                }
                return _("The password does not contain enough character classes");
        case PWQ_ERROR_MAX_CONSECUTIVE:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains more than %ld same characters consecutively"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too many same characters consecutively");
        case PWQ_ERROR_MAX_CLASS_REPEAT:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains more than %ld characters of the same class consecutively"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too many characters of the same class consecutively");
        case PWQ_ERROR_MAX_SEQUENCE:
                if (auxerror) {
                        snprintf(buf, len, _("The password contains monotonic sequence longer than %ld characters"), (long)auxerror);
                        return buf;
                }
                return _("The password contains too long of a monotonic character sequence");
        case PWQ_ERROR_EMPTY_PASSWORD:
                return _("No password supplied");
        case PWQ_ERROR_RNG:
                return _("Cannot obtain random numbers from the RNG device");
        case PWQ_ERROR_GENERATION_FAILED:
                return _("Password generation failed - required entropy too low for settings");
        case PWQ_ERROR_CRACKLIB_CHECK:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("The password fails the dictionary check"), (const char *)auxerror);
                        return buf;
                }
                return _("The password fails the dictionary check");
        case PWQ_ERROR_UNKNOWN_SETTING:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("Unknown setting"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Unknown setting");
        case PWQ_ERROR_INTEGER:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("Bad integer value of setting"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Bad integer value");
        case PWQ_ERROR_NON_INT_SETTING:
                if (auxerror) {
                        snprintf(buf, len, _("Setting %s is not of integer type"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Setting is not of integer type");
        case PWQ_ERROR_NON_STR_SETTING:
                if (auxerror) {
                        snprintf(buf, len, _("Setting %s is not of string type"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Setting is not of string type");
        case PWQ_ERROR_CFGFILE_OPEN:
                return _("Opening the configuration file failed");
        case PWQ_ERROR_CFGFILE_MALFORMED:
                return _("The configuration file is malformed");
        case PWQ_ERROR_FATAL_FAILURE:
                return _("Fatal failure");
        case PWQ_ERROR_REGEX:
                if (auxerror) {
                        snprintf(buf, len, _("%s is not a valid PERL regular expression"), (const char *)auxerror);
                        free(auxerror);
                        return buf;
                }
                return _("Invalid PERL regular expression");
        case PWQ_ERROR_TRIVIAL_SUBSTITUTION:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("The password fails the trivial substitutions check"), (const char *)auxerror);
                        return buf;
                }
                return _("The password fails the trivial substitutions check");
        case PWQ_ERROR_LEET_SPEAK_DICT:
                if (auxerror) {
                        snprintf(buf, len, "%s - %s", _("The password fails the dictionary check after 1337/leet speak conversions"), (const char *)auxerror);
                        return buf;
                }
                return _("The password fails the dictionary check after 1337/leet speak conversions");
        default:
                return _("Unknown error");
        }
}


/*
 * Copyright (c) Red Hat, Inc, 2011
 * Copyright (c) Tomas Mraz <tm@t8m.info>, 2011
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, and the entire permission notice in its entirety,
 *    including the disclaimer of warranties.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * ALTERNATIVELY, this product may be distributed under the terms of
 * the GNU General Public License version 2 or later, in which case the
 * provisions of the GPL are required INSTEAD OF the above restrictions.
 *
 * THIS SOFTWARE IS PROVIDED `AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
