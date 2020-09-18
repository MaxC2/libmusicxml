/*

  Copyright (C) 2003-2008  Grame
  Grame Research Laboratory, 9 rue du Garet, 69001 Lyon - France
  research@grame.fr

  This file is provided as an example of the MusicXML Library use.
*/

#include <iomanip>      // setw()), set::precision(), ...

#ifndef WIN32
#include <signal.h>
#endif

#include "libmusicxml.h"
#include "version.h"

#include "utilities.h"
#include "messagesHandling.h"

#include "setTraceOahIfDesired.h"
#ifdef TRACE_OAH
  #include "traceOah.h"
#endif

#include "oahBasicTypes.h"
#include "generalOah.h"

#include "xml2lyFullViewOahHandler.h"

#include "xml2lyTwoViewOahHandler.h"

#include "musicxml2lilypond.h"
#include "musicxml2musicxml.h"


using namespace std;

using namespace MusicXML2;

//_______________________________________________________________________________
#ifndef WIN32

static void _sigaction(int signal, siginfo_t *si, void *arg)
{
    cerr << "Signal #" << signal << " catched!" << endl;
    exit(-2);
}

static void catchsigs ()
{
	struct sigaction sa;

    memset (&sa, 0, sizeof(struct sigaction));

    sigemptyset (&sa.sa_mask);

    sa.sa_sigaction = _sigaction;
    sa.sa_flags     = SA_SIGINFO;

    sigaction (SIGSEGV, &sa, NULL);
    sigaction (SIGILL, &sa, NULL);
    sigaction (SIGFPE, &sa, NULL);
}

#else
static void catchsigs()	{}
#endif

//_______________________________________________________________________________
int main (int argc, char *argv[])
{
  // create the signals
  // ------------------------------------------------------

	catchsigs();

  string executableName = argv [0];

//#define USE_TWO_VIEW_HANDLER

#ifdef USE_TWO_VIEW_HANDLER

  // create the OAH twoView handler
  // ------------------------------------------------------
  S_xml2lyOahTwoViewHandler twoViewHandler;

  try {
    twoViewHandler =
      xml2lyOahTwoViewHandler::create (
        executableName,
        gOutputOstream);
  }
  catch (msrOahException& e) {
    return kInvalidOption;
  }
  catch (std::exception& e) {
    return kInvalidFile;
  }

  // analyze the command line options and arguments
  // ------------------------------------------------------

  try {
    oahHandler::oahHelpOptionsHaveBeenUsedKind
      helpOptionsHaveBeenUsedKind =
        twoViewHandler->
          applyOptionsAndArgumentsFromArgcAndArgv (
            argc, argv);

    switch (helpOptionsHaveBeenUsedKind) {
      case oahHandler::kHelpOptionsHaveBeenUsedYes:
        return kNoErr;
        break;
      case oahHandler::kHelpOptionsHaveBeenUsedNo:
        // let's go ahead!
        break;
    } // switch
  }
  catch (msrOahException& e) {
    return kInvalidOption;
  }
  catch (std::exception& e) {
    return kInvalidFile;
  }

#else

  // create the options handler
  // ------------------------------------------------------

  S_xml2lyFullViewOahHandler handler;

  try {
    handler =
      xml2lyFullViewOahHandler::create (
        executableName,
        "xml2ly",
        gOutputOstream);
  }
  catch (msrOahException& e) {
    return kInvalidOption;
  }
  catch (std::exception& e) {
    return kInvalidFile;
  }

  // analyze the command line options and arguments
  // ------------------------------------------------------

  try {
    oahHandler::oahHelpOptionsHaveBeenUsedKind
      helpOptionsHaveBeenUsedKind =
        handler->
          applyOptionsAndArgumentsFromArgcAndArgv (
            argc, argv);

    switch (helpOptionsHaveBeenUsedKind) {
      case oahHandler::kHelpOptionsHaveBeenUsedYes:
        return kNoErr;
        break;
      case oahHandler::kHelpOptionsHaveBeenUsedNo:
        // let's go ahead!
        break;
    } // switch
  }
  catch (msrOahException& e) {
    return kInvalidOption;
  }
  catch (std::exception& e) {
    return kInvalidFile;
  }

#ifdef TRACE_OAH
  if (gGlobalTraceOahGroup->getTraceOah ()) { // JMI
    handler->printKnownPrefixes (gOutputOstream);
    handler->printKnownSingleCharacterOptions (gOutputOstream);
    // handler->printKnownOptions (gOutputOstream);
  }
#endif

#endif

/* JMI
#ifdef TRACE_OAH
  if (gGlobalTraceOahGroup->getTraceOah ()) { // JMI
    handler->printKnownPrefixes (gOutputOstream);
    handler->printKnownSingleCharacterOptions (gOutputOstream);
    // handler->printKnownOptions (gOutputOstream); JMI
  }
#endif
*/

  string
    inputSourceName =
      gGlobalOahOahGroup->fInputSourceName;

  string
    outputFileName =
      gGlobalXml2lyOahGroup->
        getOutputFileNameStringAtom ()->
          getStringVariable ();

#ifdef TRACE_OAH
  if (gGlobalTraceOahGroup->getTracePasses ()) {
    string separator =
      "%--------------------------------------------------------------";

    gLogOstream <<
      executableName << ": " <<
      "inputSourceName = \"" << inputSourceName << "\"" <<
      ", outputFileName = \"" << outputFileName << "\"" <<
      endl <<
      separator <<
      endl;
  }
#endif

  // has quiet mode been requested?
  // ------------------------------------------------------

  if (gGlobalGeneralOahGroup->fQuiet) {
    // disable all trace and display options
    /* JMI
#ifdef USE_TWO_VIEW_HANDLER

      twoViewHandler->
        enforceOahTwoViewHandlerQuietness ();

#else

      handler->
        enforceOahHandlerQuietness ();

#endif
*/

    handler->
      enforceHandlerQuietness ();
  }

  // welcome message
  // ------------------------------------------------------

#ifdef TRACE_OAH
  if (gGlobalTraceOahGroup->getTracePasses ()) {
    int
      outputFileNameSize =
        outputFileName.size ();

    gLogOstream <<
      "This is xml2ly " << currentVersionNumber () <<
      " from libmusicxml2 v" << musicxmllibVersionStr () <<
      endl;

    gLogOstream <<
      "Launching conversion of ";

    if (inputSourceName == "-")
      gLogOstream <<
        "standard input";
    else
      gLogOstream <<
        "\"" << inputSourceName << "\"";

    gLogOstream <<
      " to LilyPond" <<
      endl;

    gLogOstream <<
      "Time is " << gGlobalGeneralOahGroup->fTranslationDateFull <<
      endl;

    gLogOstream <<
      "LilyPond code will be written to ";
    if (outputFileNameSize) {
      gLogOstream <<
        outputFileName;
    }
    else {
      gLogOstream <<
        "standard output";
    }
    gLogOstream <<
      endl <<
      endl;

    gLogOstream <<
      "The command line is:" <<
      endl;

    gIndenter++;

#ifdef USE_TWO_VIEW_HANDLER

    gLogOstream <<
      twoViewHandler->
        commandLineWithShortNamesAsString () <<
      endl;

#else

    gLogOstream <<
      handler->
        commandLineWithShortNamesAsString () <<
      endl;

#endif

    gIndenter--;
    gLogOstream <<
      "or:" <<
      endl;
    gIndenter++;

#ifdef USE_TWO_VIEW_HANDLER

    gLogOstream <<
      twoViewHandler->
        commandLineWithLongNamesAsString () <<
      endl <<
      endl;

#else

    gLogOstream <<
      handler->
        commandLineWithLongNamesAsString () <<
      endl <<
      endl;

#endif

    gIndenter--;
  }
#endif

  // acknoledge end of command line analysis
  // ------------------------------------------------------

#ifdef TRACE_OAH
  if (gGlobalTraceOahGroup->getTracePasses ()) {
    gLogOstream <<
      "The command line options and arguments have been analyzed" <<
      endl;
  }
#endif

  // do the translation, creating MusicXML back from the MSR if requested
  // ------------------------------------------------------

  xmlErr err;

  try {
    err =
      convertMusicXMLToLilypond (
        inputSourceName,
        outputFileName,
        gGlobalXml2lyOahGroup->fLoopBackToMusicXML); // loopBackToMusicXML is used by 'xml2ly -loop'
  }
  catch (std::exception& e) {
    return kInvalidFile;
  }

  // display the input line numbers for which messages have been issued
  // ------------------------------------------------------

  displayWarningsAndErrorsInputLineNumbers ();

  // print timing information
  // ------------------------------------------------------

  if (gGlobalGeneralOahGroup->fDisplayCPUusage)
    timing::gTiming.print (
      gLogOstream);

  // check indentation
  // ------------------------------------------------------

  if (gIndenter != 0) {
    gLogOstream <<
      "### xml2ly gIndenter final value: "<< gIndenter.getIndent () << " ###" <<
      endl <<
      endl;
  }

  // over!
  // ------------------------------------------------------

  if (err != kNoErr) {
    gLogOstream <<
      "### Conversion from MusicXML to LilyPond code failed ###" <<
      endl <<
      endl;

    return 1;
  }

  return 0;
}
