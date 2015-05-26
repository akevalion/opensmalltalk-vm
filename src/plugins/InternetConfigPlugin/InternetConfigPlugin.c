/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0
   from
	InternetConfigPlugin VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0
 */
static char __buildInfo[] = "InternetConfigPlugin VMMaker.oscog-eem.1325 uuid: a0bb0f7f-5e6e-48a7-bf73-fa5d135e06c0 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "InternetConfigPlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveGetMacintoshFileTypeAndCreatorFrom(void);
EXPORT(sqInt) primitiveGetStringKeyedBy(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"InternetConfigPlugin VMMaker.oscog-eem.1325 (i)"
#else
	"InternetConfigPlugin VMMaker.oscog-eem.1325 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* InternetConfigPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return sqInternetConfigurationInit();
}

	/* InternetConfigPlugin>>#primitiveGetMacintoshFileTypeAndCreatorFrom */
EXPORT(sqInt)
primitiveGetMacintoshFileTypeAndCreatorFrom(void)
{
	char *aFileName;
	char creator[8];
	sqInt i;
	sqInt keyLength;
	sqInt oop;
	char *ptr;

	success(isBytes(stackValue(0)));
	aFileName = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	keyLength = byteSizeOf(((sqInt)(long)(aFileName) - BaseHeaderSize));
	sqInternetGetMacintoshFileTypeAndCreatorFromkeySizeinto(aFileName, keyLength, creator);
	oop = instantiateClassindexableSize(classString(), 8);
	ptr = firstIndexableField(oop);
	for (i = 0; i <= 7; i += 1) {
		ptr[i] = (creator[i]);
	}
	if (failed()) {
		return null;
	}
	popthenPush(2, oop);
	return null;
}

	/* InternetConfigPlugin>>#primitiveGetStringKeyedBy */
EXPORT(sqInt)
primitiveGetStringKeyedBy(void)
{
	char *aKey;
	char aString[1025];
	sqInt i;
	sqInt keyLength;
	sqInt oop;
	char *ptr;
	sqInt size;

	success(isBytes(stackValue(0)));
	aKey = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	keyLength = byteSizeOf(((sqInt)(long)(aKey) - BaseHeaderSize));
	size = sqInternetConfigurationGetStringKeyedBykeySizeinto(aKey, keyLength, aString);
	oop = instantiateClassindexableSize(classString(), size);
	ptr = firstIndexableField(oop);
	for (i = 0; i < size; i += 1) {
		ptr[i] = (aString[i]);
	}
	if (failed()) {
		return null;
	}
	popthenPush(2, oop);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		popthenPush = interpreterProxy->popthenPush;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* InternetConfigPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return sqInternetConfigurationShutdown();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* InternetConfigPlugin_exports[][3] = {
	{"InternetConfigPlugin", "getModuleName", (void*)getModuleName},
	{"InternetConfigPlugin", "initialiseModule", (void*)initialiseModule},
	{"InternetConfigPlugin", "primitiveGetMacintoshFileTypeAndCreatorFrom\000\377", (void*)primitiveGetMacintoshFileTypeAndCreatorFrom},
	{"InternetConfigPlugin", "primitiveGetStringKeyedBy\000\377", (void*)primitiveGetStringKeyedBy},
	{"InternetConfigPlugin", "setInterpreter", (void*)setInterpreter},
	{"InternetConfigPlugin", "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */


#endif /* ifdef SQ_BUILTIN_PLUGIN */
