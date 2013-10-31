################################################################################
## @file: 	template.bin.mk
## @author:	��·� <johnx@mail.ustc.edu.cn>
## @brief	���ɿ�ִ���ļ���makefileģ��.
## @version	1.0
###############################################################################

## NOTE: ������Ϊһ������Ŀ���Ӧһ������. '��ǰĿ¼'ָ$(MAKEFILE)����Ŀ¼.

## makefile �ļ�����Ĭ��Ϊ 'Makefile'. ����ļ�����Ϊ'Makefile', �����趨.
MAKEFILE	:=

## ����Ŀ������. ���ɵ�Ŀ���ļ���Ϊ$(TARGET).$(VERSION), ��release��Ҫ���ϵ�
## ǰ'������'. �����趨.
TARGET		:=

## ����Ŀ������Ŀ¼, Ĭ��Ϊ��ǰĿ¼.
#OUTDIR		:=

## �汾�ţ�Ĭ��Ϊ��ǰ'������'��'make release'ʱΪ'r������'. 
## ��һ�������Ϊ VERSION=svn, ��ʱ�����ǰMakefile����Ŀ¼��svn�����£���ʹ
## ��svn��reversion��VERSION�Զ���ΪVERSION=svn.__THE_SVN_REVERSION__.
## ��ʱ���������SVN_VERSION_MAJOR, ���Ϊ
##	VERSION=$(SVN_VERSION_MAJOR).__THE_SVN_REVERSION__.
## SVN_VERSION_MAJOR������ΪMAJOR VERSION NUMBERʹ��.
## Ĭ��debugʱ��������ں�׺, ����Ӿ͵���NVERSION_DATE, Ĭ��NVERSION_DATE:=0.
#VERSION	:=
#SVN_VERSION_MAJOR :=
#NVERSION_DATE  := 1

## �Ƿ���Ҫ�汾�ţ�Ĭ������Ҫ��ֵ0/1: 0, ��Ҫ; 1, ����Ҫ.
#NVERSION	:= 1

## �������Ŀ¼, ��ʽΪ'-I_THE_DIR_', ÿ��'-I'һ��Ŀ¼, �ö��'-I'��ָ�����
## ����Ŀ¼.
#INCLUDES	:=

## ָ���������Ŀ�. ��������Ŀ������Ϊ'libLIBNAME.so', ����'-lLIBNAME'ָ��
## ����'_THE_DIR_WHERE_LIB_LIES_/libLIBNAME.so'. �ڵ�һ�з�ʽ��, ���������
## ��Ŀ¼����ϵͳĬ�ϵ�Ŀ¼, Ҳû����/etc/ld.so.conf�г���, ��'-L'ָ��, ��,
## '-L_THE_DIR_WHERE_LIB_LIES_'. ÿһ��'-l'��'-L'ָ��һ��, �ö��'-l'/'-L'ָ
## ������.
#LIBS		:=

## ����Ŀ�����ڹ��̵�ͷ�ļ��ĺ�׺��, Ĭ��Ϊ'.h'. ����趨��'FILES_H', ������
## �趨'FILE_H_SUFFIX', Ҳ��������.
#FILE_H_SUFFIX	:= .h

## ����Ŀ�����ڹ��̵�Դ�ļ��ĺ�׺��, Ĭ��Ϊ'.cpp'. ����趨��'FILES', ������
## �趨'FILES', Ҳ��������.
#FILE_SUFFIX	:= .cpp

## ͷ�ļ��б�. Ĭ��Ϊ'FILES_H=$(wildcard *$(FILE_H_SUFFIX))', ����ǰĿ¼�µ�
## ������'$(FILE_H_SUFFIX)'Ϊ��׺���ļ�.
#FILES_H	:=

## Դ�ļ��б�. Ĭ��Ϊ'FILES=$(wildcard *$(FILE_SUFFIX))', ����ǰĿ¼�µ�����
## ��'$(FILE_SUFFIX)'Ϊ��׺����. 
#FILES		:=

## DOXYGEN�����ļ���(�����·��), Ĭ��Ϊ'Doxyfile'.
#DOXYFILE	:= Doxyfile

## �Զ�����(doxygen)�ĵ����Ŀ¼. 'make distclean'��������Ŀ¼,�����ĵ���Ҫ
## ����ڴ�Ŀ¼.
#DOCSDIR	:=

## �Ƿ�ʹ��Ĭ�ϵı������. Ĭ�ϱ������, 
##	debug: 		CFLAGS=-Wall -g -D_DEBUG, LDFLAGS= 
##	release:	CFLAGS=-Wall -O3, LDFLAGS=-Wl,-O3 
## ��ʹ��Ĭ�ϲ����������, ������ʹ�������CFLAGS, LDFLAGS, DCFLAGS, DLDFLAGS
## ���ӱ������, ��������. Ĭ��Ϊʹ�ñ������
#DEFAULT_FLAGS	:= 0

## ��������Ӳ����趨. ����C����C++��ʹ��CFLAGS LDFLAGS, ��CPPFLAGS or CXXFLAGS
## û�б�ʹ��. ע��: �����ǲ�֧��C��C++���������Ի���, ��ȻC������Ե���C++��
## ����. ����Ǹ�����Ŀ, ʹ�ø���Ŀ�ı������, ע�͵���Ӧ����. ���Ҫ�ڸ���Ŀ��
## ��������Ļ��������ӻ򸲸�, ��"CFLAGS := $(CFLAGS_PASS) OUR_OWN_FLAGS".
## �������ʹ�ø���Ŀ�򻷾������Ĳ���, ʹ���� "CFLAGS := "�����ķ�ʽ. CFLAGS��
## LDFLAGS����release�������; DCFLAGS��DLDFLAGS����debug�������.
CFLAGS		:= $(CFLAGS_PASS)
DCFLAGS		:= $(DCFLAGS_PASS)
LDFLAGS		:= $(LDFLAGS_PASS)
DLDFLAGS	:= $(DLDFLAGS_PASS)

## ����. See 'common.cmd.mk' for more.
#CC		:= cc
#CXX		:= c++
#CPP		:= cpp
#LD		:= $(CC) 

## �趨make��make all��Ĭ�ϱ������Ϊrelease����debug. Ĭ��Ϊdebug, ��release=0
#release	:= 1

## ��Ҫ�趨��������'MAKE_RULES_DIR'.
## ������趨�������������ڴ��趨�����·��
#MAKE_RULES_DIR := ../../make.rules
include $(MAKE_RULES_DIR)/rules.bin.mk
