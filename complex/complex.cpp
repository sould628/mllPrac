#include <iostream>
#include <maya/MSimple.h>
#include <maya/MIOStream.h>

#include <maya/MGlobal.h>
DeclareSimpleCommand(myPlugin, "Autodesk", "2016");
MStatus myPlugin::doIt(const MArgList&)
{
	MGlobal::executeCommand("print(\"pluginExecuted\\n\")");
	MGlobal::sourceFile("C:\\scripts\\script.mel");
	return MS::kSuccess;
}