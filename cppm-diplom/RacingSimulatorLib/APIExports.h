#pragma once

#ifdef RACINGSIMULATORLIB_EXPORTS

	#define RACINGSIMULATORLIB_API __declspec(dllexport)
#else
	#define RACINGSIMULATORLIB_API __declspec(dllimport)
#endif // RACINGSIMULATORLIB_EXPORTS
