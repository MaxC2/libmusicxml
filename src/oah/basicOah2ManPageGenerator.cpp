/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <iomanip>      // setw, setprecision, ...
#include <cmath>
#include <string>

#include <regex>

#include "basicOah2ManPageGenerator.h"

#include "setTraceOahIfDesired.h"
#ifdef TRACE_OAH
  #include "traceOah.h"
#endif

#include "version.h"

#include "generalOah.h"

using namespace std;

namespace MusicXML2
{

//________________________________________________________________________
basicOah2ManPageGenerator::basicOah2ManPageGenerator (
  const S_oahHandler handler,
  ostream&           logOstream,
  ostream&           manPageOutputStream)
    : oah2ManPageGenerator (
        handler,
        logOstream,
        manPageOutputStream)
{}

basicOah2ManPageGenerator::~basicOah2ManPageGenerator ()
{}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahHandler& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahHandler" <<
      " \"" << elt->getHandlerHeader () << "\"" <<
      endl;
  }
#endif

  // initial comment
  fOah2ManPageOutputStream <<
    ".\\\" DO NOT MODIFY THIS MAN PAGE DATA FILE!  It was generated by " <<
    gGlobalOahOah->fHandlerExecutableName <<
    currentVersionNumber () <<
    " on " <<
    gGlobalGeneralOah->fTranslationDateFull <<
    endl;

  // the man page header
  fOah2ManPageOutputStream <<
    ".TH " <<
    gGlobalOahOah->fHandlerExecutableName <<
    " \"" <<
    "1" << // JMI section ???
    "\" \"" <<
    gGlobalGeneralOah->fTranslationDateFull <<
    "\" " <<
    gGlobalOahOah->fHandlerExecutableName <<
    " \"" <<
    "User Commands" <<
    "\"" <<
    endl <<

    ".SH NAME" <<
    endl <<
    ".NM " <<
    gGlobalOahOah->fHandlerExecutableName <<
    endl <<
    ".ND " <<
    "manual page for " <<
    gGlobalOahOah->fHandlerExecutableName <<
    endl <<

    ".SH DESCRIPTION" <<
    endl <<
    ".IP" <<
    endl <<
    elt->getHandlerPreamble () <<
    endl <<

    ".SH \"USAGE\"" <<
    endl <<
    ".IP" <<
    endl <<
    elt->getHandlerUsage () <<
    endl;
}

void basicOah2ManPageGenerator::visitEnd (S_oahHandler& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahHandler" <<
      " \"" << elt->getHandlerHeader () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahPrefix& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahPrefix" <<
      " \"" << elt->getPrefixName () << "\"" <<
      endl;
  }
#endif

  fOah2ManPageOutputStream <<
    ".IT FL " <<
 //   endl <<
    elt->getPrefixErsatz () <<
    " " <<
    elt->getPrefixDescription () <<
    endl;
}

void basicOah2ManPageGenerator::visitEnd (S_oahPrefix& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahPrefix" <<
      " \"" << elt->getPrefixName () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahGroup& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahGroup" <<
      " \"" << elt->getGroupHeader () << "\"" <<
      endl;
  }
#endif

  fOah2ManPageOutputStream <<
    ".SH " <<
    elt->getGroupHeader () <<
    endl <<
    "(\\fB\\-" <<
    regex_replace (elt->getShortName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    regex_replace (elt->getLongName (), regex ("-"), "\\-") <<
    "\\fR): " <<
    endl;
}

void basicOah2ManPageGenerator::visitEnd (S_oahGroup& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahGroup" <<
      " \"" << elt->getGroupHeader () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahSubGroup& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahSubGroup" <<
      " \"" << elt->getSubGroupHeader () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".TP" <<
    endl <<
    elt->getSubGroupHeader () <<
    endl <<
    ".BL -tag -width indent" <<
    endl <<
    "(\\fB\\-" <<
    regex_replace (elt->getShortName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    regex_replace (elt->getLongName (), regex ("-"), "\\-") <<
    "\\fR): " <<
    endl;
*/
}

void basicOah2ManPageGenerator::visitEnd (S_oahSubGroup& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahSubGroup" <<
      " \"" << elt->getSubGroupHeader () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting S_oahAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting S_oahAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahAtomWithVariableName& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahAtomWithVariableName" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

}

void basicOah2ManPageGenerator::visitEnd (S_oahAtomWithVariableName& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahAtomWithVariableName" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahAtomSynonym& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahAtomSynonym" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

}

void basicOah2ManPageGenerator::visitEnd (S_oahAtomSynonym& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahAtomSynonym" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahOptionsUsageAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahOptionsUsageAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

}

void basicOah2ManPageGenerator::visitEnd (S_oahOptionsUsageAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahOptionsUsageAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahOptionsSummaryAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahOptionsSummaryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

}

void basicOah2ManPageGenerator::visitEnd (S_oahOptionsSummaryAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahOptionsSummaryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahOptionNameHelpAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahOptionNameHelpAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahOptionNameHelpAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahOptionNameHelpAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahBooleanAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahBooleanAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    regex_replace (elt->getShortName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    regex_replace (elt->getLongName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void basicOah2ManPageGenerator::visitEnd (S_oahBooleanAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahBooleanAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahTwoBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahTwoBooleansAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    regex_replace (elt->getShortName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    regex_replace (elt->getLongName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void basicOah2ManPageGenerator::visitEnd (S_oahTwoBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahTwoBooleansAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahThreeBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahThreeBooleansAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    regex_replace (elt->getShortName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    regex_replace (elt->getLongName (), regex ("-"), "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void basicOah2ManPageGenerator::visitEnd (S_oahThreeBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahThreeBooleansAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahCombinedBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahCombinedBooleansAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahCombinedBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahCombinedBooleansAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahMultiplexBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahMultiplexBooleansAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahMultiplexBooleansAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahMultiplexBooleansAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahValuedAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahValuedAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahValuedAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahValuedAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahIntegerAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahIntegerAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahIntegerAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahIntegerAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahTwoIntegersAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahTwoIntegersAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahTwoIntegersAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahTwoIntegersAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahFloatAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahFloatAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahFloatAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahFloatAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahRationalAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahRationalAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahRationalAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahRationalAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahMonoplexStringAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahMonoplexStringAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahMonoplexStringAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahMonoplexStringAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringWithDefaultValueAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringWithDefaultValueAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringWithDefaultValueAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringWithDefaultValueAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif

}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahNaturalNumbersSetAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahNaturalNumbersSetAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahNaturalNumbersSetAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahNaturalNumbersSetAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

/* JMI
//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringsSetElementAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringsSetElementAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringsSetElementAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringsSetElementAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}
*/

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringSetAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringSetAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringSetAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringSetAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahRGBColorAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahRGBColorAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahRGBColorAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahRGBColorAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringAndIntegerAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringAndIntegerAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringAndIntegerAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringAndIntegerAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void basicOah2ManPageGenerator::visitStart (S_oahStringAndTwoIntegersAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahStringAndTwoIntegersAtom '" <<
      elt->asString () <<
      "'" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

void basicOah2ManPageGenerator::visitEnd (S_oahStringAndTwoIntegersAtom& elt)
{
#ifdef TRACE_OAH
  if (gGlobalOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahStringAndTwoIntegersAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}


} // namespace
