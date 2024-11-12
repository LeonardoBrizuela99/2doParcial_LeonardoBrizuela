#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef Engine_Exports
#define ENGINE_API __declspec(dllimport) //Specify class for export
#else
#define ENGINE_API __declspec(dllexport) //Specify class for export
#endif

#endif