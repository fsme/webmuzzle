#

lib_LTLIBRARIES = mod_webmuzzle.la

mod_webmuzzle_la_SOURCES = src/mod_webmuzzle.cc
mod_webmuzzle_la_SOURCES+= src/mod_webmuzzle.h
mod_webmuzzle_la_SOURCES+= src/cookie.h
mod_webmuzzle_la_SOURCES+= src/cookie.cc
mod_webmuzzle_la_SOURCES+= src/request.h
mod_webmuzzle_la_SOURCES+= src/request.cc
mod_webmuzzle_la_SOURCES+= src/dbpool.h
mod_webmuzzle_la_SOURCES+= src/dbpool.cc
mod_webmuzzle_la_SOURCES+= src/dbconnect.h
mod_webmuzzle_la_SOURCES+= src/dbconnect.cc

mod_webmuzzle_la_LDFLAGS = `@apache_dir@/bin/apr-1-config --link-ld --libs`

mod_webmuzzle_la_LDFLAGS += -module

INCLUDES = -I./src -I/usr/local/include -I`apxs -q INCLUDEDIR` `@apache_dir@/bin/apr-1-config --includes`
