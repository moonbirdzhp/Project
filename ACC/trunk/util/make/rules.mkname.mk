###############################################################################
## @file: 	rules.mkname.mk
## @author:	��·� <johnx@mail.ustc.edu.cn>
## @brief	���ʹ�õ�makefile���Ƶ�rules.
## @version	1.0
###############################################################################

ifeq ($(LOCAL_TOP_DIR),)
	LOCAL_TOP_DIR	:= $(shell pwd)/
endif

.PHONY: makefile_name
makefile_name:
	@echo
	@echo Makefile: $(subst $(LOCAL_TOP_DIR),,$(shell pwd)/$(MAKEFILE))
	@echo
