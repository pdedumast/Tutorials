cmake_minimum_required(VERSION 2.6)

project(MyFilter)

# Liens pour ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


# Find SlicerExecutionModel (CLI)
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

# Fichiers
file( GLOB
	source_files
	*.[ch]xx
)

# Executable
set( MyFilter ${source_files})


SEMMacroBuildCLI(
		NAME MyFilter
		EXECUTABLE_ONLY
		TARGET_LIBRARIES ${ITK_LIBRARIES}
)
