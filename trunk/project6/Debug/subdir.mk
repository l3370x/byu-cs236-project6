################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Attribute.cpp \
../Database.cpp \
../Relation.cpp \
../Schema.cpp \
../Tuple.cpp \
../TupleSet.cpp \
../Value.cpp \
../datalogprogram.cpp \
../domain.cpp \
../fact.cpp \
../factlist.cpp \
../main.cpp \
../parameter.cpp \
../parameterlist.cpp \
../predicate.cpp \
../predicatelist.cpp \
../query.cpp \
../querylist.cpp \
../rule.cpp \
../rulelist.cpp \
../saver.cpp \
../scanner.cpp \
../scheme.cpp \
../schemelist.cpp \
../stream.cpp \
../token.cpp \
../tokenholder.cpp 

OBJS += \
./Attribute.o \
./Database.o \
./Relation.o \
./Schema.o \
./Tuple.o \
./TupleSet.o \
./Value.o \
./datalogprogram.o \
./domain.o \
./fact.o \
./factlist.o \
./main.o \
./parameter.o \
./parameterlist.o \
./predicate.o \
./predicatelist.o \
./query.o \
./querylist.o \
./rule.o \
./rulelist.o \
./saver.o \
./scanner.o \
./scheme.o \
./schemelist.o \
./stream.o \
./token.o \
./tokenholder.o 

CPP_DEPS += \
./Attribute.d \
./Database.d \
./Relation.d \
./Schema.d \
./Tuple.d \
./TupleSet.d \
./Value.d \
./datalogprogram.d \
./domain.d \
./fact.d \
./factlist.d \
./main.d \
./parameter.d \
./parameterlist.d \
./predicate.d \
./predicatelist.d \
./query.d \
./querylist.d \
./rule.d \
./rulelist.d \
./saver.d \
./scanner.d \
./scheme.d \
./schemelist.d \
./stream.d \
./token.d \
./tokenholder.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


