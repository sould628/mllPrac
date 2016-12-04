#include <stdio.h>

#include <maya/MString.h>
#include <maya/MArgList.h>
#include <maya/MFnPlugin.h>
#include <maya/MPxCommand.h>
#include <maya/MIOStream.h>

class hello : public MPxCommand
{
public:
	MStatus doIt(const MArgList& args);
	static void* creator();
};

MStatus hello::doIt(const MArgList& args)
{
	printf("hello123\n");
	return MS::kSuccess;
}

void* hello::creator()
{
	return new hello;
}

MStatus initializePlugin(MObject obj)
{
	MFnPlugin plugin(obj, "Autodesk", "2016", "Any");
	plugin.registerCommand("hello", hello::creator);
	return MS::kSuccess;
}
MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin plugin(obj);
	plugin.deregisterCommand("hello");
	return MS::kSuccess;

}