# Project libpwquality extended 

This project is based on the original libpwquality project (Library for password quality checking and generating random passwords) and include a few extensions:
- Differents user profiles management.
- Check passwords against trivial substitutions.
- Check passwords against Leet speaks patterns.

The libpwqualityex library purpose is to provide common functions for password quality checking and also scoring them based on their apparent randomness. The library also provides a function for generating random passwords with good pronounceability. The library supports reading and parsing of a configuration file.

In the package there are also very simple utilities that use the library function and PAM module that can be used instead of pam_cracklib.
The module supports all the options of pam_cracklib.

The libpwqualityex is binary compatible (ABI level) with the original library, i.e. it can replace the original ones without having to rebuild all programs that use it.
The supported ABI level is displayed when running the library like a program.

