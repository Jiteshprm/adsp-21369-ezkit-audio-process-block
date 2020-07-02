################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SPORTisr.c \
../src/UART_Echo_Back.c \
../src/audio_processing.c \
../src/biquad.c \
../src/blockProcess.c \
../src/init1835viaSPI.c \
../src/initPLL_SDRAM.c \
../src/initSPORT.c \
../src/initSRU.c \
../src/irqprocess.c \
../src/main.c \
../src/reverb_schroeder_stereo.c 

SRC_OBJS += \
./src/SPORTisr.doj \
./src/UART_Echo_Back.doj \
./src/audio_processing.doj \
./src/biquad.doj \
./src/blockProcess.doj \
./src/init1835viaSPI.doj \
./src/initPLL_SDRAM.doj \
./src/initSPORT.doj \
./src/initSRU.doj \
./src/irqprocess.doj \
./src/main.doj \
./src/reverb_schroeder_stereo.doj 

C_DEPS += \
./src/SPORTisr.d \
./src/UART_Echo_Back.d \
./src/audio_processing.d \
./src/biquad.d \
./src/blockProcess.d \
./src/init1835viaSPI.d \
./src/initPLL_SDRAM.d \
./src/initSPORT.d \
./src/initSRU.d \
./src/irqprocess.d \
./src/main.d \
./src/reverb_schroeder_stereo.d 


# Each subdirectory must supply rules for building sources it contributes
src/SPORTisr.doj: ../src/SPORTisr.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/SPORTisr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UART_Echo_Back.doj: ../src/UART_Echo_Back.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/UART_Echo_Back.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/audio_processing.doj: ../src/audio_processing.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/audio_processing.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/biquad.doj: ../src/biquad.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/biquad.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/blockProcess.doj: ../src/blockProcess.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/blockProcess.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/init1835viaSPI.doj: ../src/init1835viaSPI.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/init1835viaSPI.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initPLL_SDRAM.doj: ../src/initPLL_SDRAM.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/initPLL_SDRAM.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initSPORT.doj: ../src/initSPORT.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/initSPORT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initSRU.doj: ../src/initSRU.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/initSRU.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/irqprocess.doj: ../src/irqprocess.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/irqprocess.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.doj: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/reverb_schroeder_stereo.doj: ../src/reverb_schroeder_stereo.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore SHARC C/C++ Compiler'
	cc21k -c -file-attr ProjectName="adsp-21369-ezkit-audio-process-block" -proc ADSP-21369 -flags-compiler --no_wrap_diagnostics -si-revision any -g -D_DEBUG -DCORE0 @includes-ed8b5e3b8cf81530e704911d16916579.txt -structs-do-not-overlap -no-const-strings -no-multiline -warn-protos -double-size-32 -gnu-style-dependencies -MD -Mo "src/reverb_schroeder_stereo.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


