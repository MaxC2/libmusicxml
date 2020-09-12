/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <iostream>

#include "xml.h"
#include "xmlfile.h"
#include "xmlreader.h"

#include "versions.h"

#include "messagesHandling.h"

#include "generalOah.h"

#include "setTraceOahIfDesired.h"
#ifdef TRACE_OAH
  #include "traceOah.h"
#endif

#include "mxmlTree2MsrSkeletonBuilderInterface.h"

#include "mxmlTree2MsrSkeletonBuilder.h"

#include "msr2Summary.h"

using namespace std;

namespace MusicXML2
{

//_______________________________________________________________________________
S_msrScore buildMsrSkeletonFromElementsTree (
  S_msrOah&   msrOpts,
  Sxmlelement mxmlTree,
  ostream&    logOstream,
  string      passNumber)
{
  // sanity check
  msgAssert (
    mxmlTree != 0,
    "mxmlTree is null");

  clock_t startClock = clock ();

#ifdef TRACE_OAH
  if (gGlobalTraceOah->getTracePasses ()) {
    string separator =
      "%--------------------------------------------------------------";

    logOstream <<
      endl <<
      separator <<
      endl <<
      gTab <<
      "Pass 2a: translating the mxmlElement tree into an MSR skeleton" <<
      endl;

    logOstream <<
      separator <<
      endl;
  }
#endif

  // create an mxmlTree2MsrSkeletonBuilder
  mxmlTree2MsrSkeletonBuilder
    skeletonBuilder (
      logOstream);

  // build the MSR score
  skeletonBuilder.browseMxmlTree (
    mxmlTree);

  // fetch the score skeleton
  S_msrScore
    scoreSkeleton =
      skeletonBuilder.getMsrScore ();

  clock_t endClock = clock ();

  // register time spent
  timing::gTiming.appendTimingItem (
    "Pass 2a",
    "build the MSR skeleton",
    timingItem::kMandatory,
    startClock,
    endClock);


  if (msrOpts->fDisplayMsr) {
    // display the MSR skeleton
    displayMsrSkeleton (
      msrOpts,
      scoreSkeleton,
      logOstream,
      passNumber);
  }

  return scoreSkeleton;
}

//_______________________________________________________________________________
void displayMsrSkeleton (
  S_msrOah&  msrOpts,
  S_msrScore mScore,
  ostream&   logOstream,
  string     passNumber)
{
  // sanity check
  msgAssert (
    mScore != 0,
    "mScore is null");

  clock_t startClock = clock ();

  string separator =
    "%--------------------------------------------------------------";

  logOstream <<
    endl <<
    separator <<
    endl <<
    gTab <<
    "Optional pass: displaying the MSR skeleton as text" <<
    endl <<
    separator <<
    endl <<
    endl <<
    mScore;

  clock_t endClock = clock ();

  // register time spent
  timing::gTiming.appendTimingItem (
    "",
    "display the MSR skeleton as text",
    timingItem::kOptional,
    startClock,
    endClock);
}

/* JMI
//_______________________________________________________________________________
void displayMsrSkeletonSummary (
  S_msrOah&  msrOpts,
  S_msrScore mScore,
  ostream&   logOstream)
{
  // sanity check
  msgAssert (
    mScore != 0,
    "mScore is null");

  clock_t startClock = clock ();

#ifdef TRACE_OAH
  if (gGlobalTraceOah->getTracePasses ()) {
    string separator =
      "%--------------------------------------------------------------";

    logOstream <<
      endl <<
      separator <<
      endl <<
      gTab <<
      "Optional pass: outputting a summary of the MSR" <<
      endl <<
      separator <<
      endl;
  }
#endif

  // create an msr2SummaryVisitor visitor
  msr2SummaryVisitor
    summaryVisitor (
      msrOpts,
      logOstream);

  summaryVisitor.printSummaryFromMsrScore (
    mScore);

  clock_t endClock = clock ();

  // register time spent
  timing::gTiming.appendTimingItem (
    "",
    "display MSR skeleton summary",
    timingItem::kOptional,
    startClock,
    endClock);
}
*/

//_______________________________________________________________________________
S_msrScore convertMxmlTreeToMsrScoreSkeleton (
  Sxmlelement mxmlTree,
  string      passNumber)
{
  S_msrScore
    mScore =
      buildMsrSkeletonFromElementsTree (
        gGlobalMsrOah,
        mxmlTree,
        gLogOstream,
        passNumber);

  if (gIndenter != 0) {
    if (! gGlobalGeneralOah->fQuiet) {
      stringstream s;

      s <<
        "gIndenter value after " << passNumber << ": "<<
        gIndenter.getIndent ();

      msrMusicXMLWarning (
        gGlobalOahOah->fInputSourceName,
        1, // JMI inputLineNumber,
        s.str ());
    }

    gIndenter.resetToZero ();
  }

  if (! mScore) {
    string message =
      "### Conversion from mxmlTree to an MSR skeleton failed ###";

    gLogOstream <<
      message <<
      endl <<
      endl;

    throw msrScoreToBsrScoreException (message);
  }

  return mScore;
}


}
