set(FIND_HTTPListener_PATHS
        ~/dbaralt/HTTPListener)

find_path(HTTPListener_INCLUDE_DIR HTTPListener.h
        PATH_SUFFIXES include
        PATHS ${FIND_HTTPListener_PATHS})

find_library(HTTPListener_LIBRARY
        NAMES libHTTPListener
        PATH_SUFFIXES lib
        PATHS ${FIND_HTTPListener_PATHS})