# libhttpserver SSL HTTP Server Implementation
# Copyright © 2020 Harsath
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


set(LIB_BIN_NAME libhttp)

set(
	SRC_LIB_FILES
	./helper_functions.hpp
	./internet_domain_http.hpp
	./SSL_selfsigned_internet_domain_http.hpp)

add_library(
	${LIB_BIN_NAME} 
	STATIC ${SRC_LIB_FILES})

set_target_properties(
	${LIB_BIN_NAME}
	PROPERTIES LINKER_LANGUAGE CXX
	)

set(OPENSSL_USE_STATIC_LIBS TRUE)

find_package(OpenSSL REQUIRED)

target_link_libraries(
	${LIB_BIN_NAME} OpenSSL::Crypto)

target_link_libraries(
	${LIB_BIN_NAME} OpenSSL::SSL)

target_compile_options(
	${LIB_BIN_NAME} 
	PRIVATE -g -fsanitize=address)