install(
    TARGETS sts_exe
    RUNTIME COMPONENT sts_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
