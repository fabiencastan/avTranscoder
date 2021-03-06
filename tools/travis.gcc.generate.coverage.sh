# capture coverage info
lcov --capture --directory ${AVTRANSCODER_BUILD} --output-file coverage.info

# filter out system and test code
lcov --remove coverage.info '/usr/*' '*/*PYTHON_wrap.*' --output-file coverage.info

# debug before upload
lcov --list coverage.info

# uploads to coveralls
coveralls-lcov --repo-token e7jYJJrojzWYfmdUgkDvwVNGqJgh6yCH7 coverage.info
