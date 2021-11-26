project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h CustomMachine.cpp CustomMachine.h ActualMachine.cpp ActualMachine.h Component.cpp Component.h MachineAFactory.cpp MachineAFactory.h Polygon.cpp Polygon.h Motor.cpp Motor.h RotationSource.cpp RotationSource.h RotationSink.cpp RotationSink.h Shape.cpp Shape.h Gear.cpp Gear.h Piston.cpp Piston.h Arm.cpp Arm.h MachineBFactory.cpp MachineBFactory.h Rod.cpp Rod.h RodEndSource.cpp RodEndSource.h RodEndSink.cpp RodEndSink.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)