/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___optionsBasicTypes___
#define ___optionsBasicTypes___

#include "list"
#include "vector"
#include "map"
#include "set"

#include "smartpointer.h"
#include "rational.h"

#include "utilities.h"

#include "msrBasicTypes.h"
#include "lpsrBasicTypes.h"

#include "setTraceOptionsIfDesired.h"


using namespace std;

namespace MusicXML2
{

// layout settings
//______________________________________________________________________________
const int K_OPTIONS_ELEMENTS_INDENTER_OFFSET = 3;
  // indent a bit more for readability

const int K_OPTIONS_FIELD_WIDTH = 40;

// PRE-declarations for class dependencies
//______________________________________________________________________________
class oahElement;
typedef SMARTP<oahElement> S_oahElement;

class oahSubGroup;
typedef SMARTP<oahSubGroup> S_oahSubGroup;

class oahGroup;
typedef SMARTP<oahGroup> S_oahGroup;

class EXP oahHandler;
typedef SMARTP<oahHandler> S_oahHandler;

//______________________________________________________________________________
class oahElement : public smartable
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahElement> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahElement (
      string shortName,
      string longName,
      string description);

    virtual ~oahElement ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getShortName () const
                              { return fShortName; }

    string                getLongName () const
                              { return fLongName; }

    string                getDescription () const
                              { return fDescription; }

    void                  setOptionsElementIsHidden ()
                              { fIsHidden = true; }

    bool                  getIsHidden () const
                              { return fIsHidden; }

    // services
    // ------------------------------------------------------

    string                fetchNames () const;
    string                fetchNamesInColumns (
                            int subGroupsShortNameFieldWidth) const;

    string                fetchNamesBetweenParentheses () const;
    string                fetchNamesInColumnsBetweenParentheses (
                            int subGroupsShortNameFieldWidth) const;

    virtual int           fetchVariableNameLength () const
                              { return 0; }

/* JMI ???
    string                operator () () const
                              { return fDescription; }
*/

    S_oahElement          fetchElementByName (
                            string name);

    // print
    // ------------------------------------------------------

    virtual string        asShortNamedElementString () const;
    virtual string        asLongNamedElementString () const;

    string                asString () const;

    virtual void          printHeader (ostream& os) const;

    virtual void          printElementEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    virtual void          print (ostream& os) const;

    virtual void          printHelp (ostream& os) const;

  protected:

    // fields
    // ------------------------------------------------------

    string                fShortName;
    string                fLongName;
    string                fDescription;

    bool                  fIsHidden;
};
typedef SMARTP<oahElement> S_oahElement;
EXP ostream& operator<< (ostream& os, const S_oahElement& elt);

//______________________________________________________________________________
class oahAtom : public oahElement
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahAtom (
      string shortName,
      string longName,
      string description);

    virtual ~oahAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setSubGroupUpLink (
                            S_oahSubGroup subGroup);

    S_oahSubGroup         getSubGroupUpLink () const
                              { return fSubGroupUpLink; }

    // services
    // ------------------------------------------------------

    void                  registerOptionsItemInHandler (
                            S_oahHandler handler);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // fields
    // ------------------------------------------------------

    S_oahSubGroup         fSubGroupUpLink;
};
typedef SMARTP<oahAtom> S_oahAtom;
EXP ostream& operator<< (ostream& os, const S_oahAtom& elt);

/* JMI
// pointers to options items methods
//______________________________________________________________________________
typedef void (oahAtom::*oahAtomMethodPtrType)();

  It's worth noting that, as of C++11, you could write this expression
  as a more legible using statement:
    using oahAtomMethodPtrType = void (oahAtom::*)();
*/

//______________________________________________________________________________
class oahOptionsUsageAtom : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahOptionsUsageAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahOptionsUsageAtom (
      string shortName,
      string longName,
      string description);

    virtual ~oahOptionsUsageAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsUsage (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<oahOptionsUsageAtom> S_oahOptionsUsageAtom;
EXP ostream& operator<< (ostream& os, const S_oahOptionsUsageAtom& elt);

//______________________________________________________________________________
class oahOptionsSummaryAtom : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahOptionsSummaryAtom> create (
      string shortName,
      string longName,
      string description);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahOptionsSummaryAtom (
      string shortName,
      string longName,
      string description);

    virtual ~oahOptionsSummaryAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsSummary (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------
};
typedef SMARTP<oahOptionsSummaryAtom> S_oahOptionsSummaryAtom;
EXP ostream& operator<< (ostream& os, const S_oahOptionsSummaryAtom& elt);

//______________________________________________________________________________
class oahAtomWithVariableName : public oahAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahAtomWithVariableName> create (
      string shortName,
      string longName,
      string description,
      string variableName);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahAtomWithVariableName (
      string shortName,
      string longName,
      string description,
      string variableName);

    virtual ~oahAtomWithVariableName ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getVariableName () const
                              { return fVariableName; }

    // services
    // ------------------------------------------------------

    virtual int           fetchVariableNameLength () const
                              { return fVariableName.size (); }

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // fields
    // ------------------------------------------------------

    string                fVariableName;
};
typedef SMARTP<oahAtomWithVariableName> S_oahAtomWithVariableName;
EXP ostream& operator<< (ostream& os, const S_oahAtomWithVariableName& elt);

//______________________________________________________________________________
class oahBooleanAtom : public oahAtomWithVariableName
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahBooleanAtom> create (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahBooleanAtom (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable);

    virtual ~oahBooleanAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setBooleanVariable (
                            bool value)
                              { fBooleanVariable = value; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    bool&                 fBooleanVariable;
};
typedef SMARTP<oahBooleanAtom> S_oahBooleanAtom;
EXP ostream& operator<< (ostream& os, const S_oahBooleanAtom& elt);

//______________________________________________________________________________
class oahTwoBooleansAtom : public oahAtomWithVariableName
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahTwoBooleansAtom> create (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable,
      bool&  booleanSecondaryVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahTwoBooleansAtom (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable,
      bool&  booleanSecondaryVariable);

    virtual ~oahTwoBooleansAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setTwoBooleansVariables (
                            bool value)
                              {
                                fBooleanVariable =
                                  value;
                                fBooleanSecondaryVariable =
                                  value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    bool&                 fBooleanVariable;

    bool&                 fBooleanSecondaryVariable;
};
typedef SMARTP<oahTwoBooleansAtom> S_oahTwoBooleansAtom;
EXP ostream& operator<< (ostream& os, const S_oahTwoBooleansAtom& elt);

//______________________________________________________________________________
class oahThreeBooleansAtom : public oahAtomWithVariableName
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahThreeBooleansAtom> create (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable,
      bool&  booleanSecondaryVariable,
      bool&  booleanTertiaryVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahThreeBooleansAtom (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable,
      bool&  booleanSecondaryVariable,
      bool&  booleanTertiaryVariable);

    virtual ~oahThreeBooleansAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setThreeBooleansVariables (
                            bool value)
                              {
                                fBooleanVariable =
                                  value;
                                fBooleanSecondaryVariable =
                                  value;
                                fBooleanTertiaryVariable =
                                  value;
                              }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    bool&                 fBooleanVariable;

    bool&                 fBooleanSecondaryVariable;
    bool&                 fBooleanTertiaryVariable;
};
typedef SMARTP<oahThreeBooleansAtom> S_oahThreeBooleansAtom;
EXP ostream& operator<< (ostream& os, const S_oahThreeBooleansAtom& elt);

//______________________________________________________________________________
class oahCombinedBooleansAtom : public oahAtomWithVariableName
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahCombinedBooleansAtom> create (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahCombinedBooleansAtom (
      string shortName,
      string longName,
      string description,
      string variableName,
      bool&  booleanVariable);

    virtual ~oahCombinedBooleansAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    const list<S_oahBooleanAtom>&
                          getBooleanAtomsList ()
                              { return fBooleanAtomsList; }

    // services
    // ------------------------------------------------------

    void                  addBooleanAtom (
                            S_oahBooleanAtom booleanAtom);

    void                  addBooleanAtomByName (
                            string name);

    void                  setCombinedBooleanVariables (
                            bool value);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    bool&                 fBooleanVariable;

    list<S_oahBooleanAtom>
                          fBooleanAtomsList;
};
typedef SMARTP<oahCombinedBooleansAtom> S_oahCombinedBooleansAtom;
EXP ostream& operator<< (ostream& os, const S_oahCombinedBooleansAtom& elt);

//______________________________________________________________________________
class oahValuedAtom : public oahAtomWithVariableName
{
  public:

    // data types
    // ------------------------------------------------------

    enum oahValuedAtomKind { // JMI ???
      kOptionsItemHasNoArgument,
      kOptionsItemHasARequiredArgument,
      kOptionsItemHasAnOptionsArgument };

    static string oahAtomKindAsString (
      oahValuedAtomKind oahAtomKind);

    // creation
    // ------------------------------------------------------

    static SMARTP<oahValuedAtom> create (
      string shortName,
      string longName,
      string description,
      string valueSpecification,
      string variableName);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahValuedAtom (
      string shortName,
      string longName,
      string description,
      string valueSpecification,
      string variableName);

    virtual ~oahValuedAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    oahValuedAtomKind
                          getValuedAtomKind () const
                              { return fValuedAtomKind; }

    string                getValueSpecification () const
                              { return fValueSpecification; }

    void                  setValueIsOptional ()
                              { fValueIsOptional = true; }

    bool                  getValueIsOptional () const
                              { return fValueIsOptional; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    virtual void          printValuedAtomEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // fields
    // ------------------------------------------------------

    oahValuedAtomKind     fValuedAtomKind; // JMI

    string                fValueSpecification;

    bool                  fValueIsOptional; // not yet supported JMI
};
typedef SMARTP<oahValuedAtom> S_oahValuedAtom;
EXP ostream& operator<< (ostream& os, const S_oahValuedAtom& elt);

//______________________________________________________________________________
class oahElementHelpAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahElementHelpAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahElementHelpAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName);

  protected:


    virtual ~oahElementHelpAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    virtual void          printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;
  private:

    // fields
    // ------------------------------------------------------

    string                fValueSpecification;
};
typedef SMARTP<oahElementHelpAtom> S_oahElementHelpAtom;
EXP ostream& operator<< (ostream& os, const S_oahElementHelpAtom& elt);

//______________________________________________________________________________
class oahIntegerAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahIntegerAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      int&               integerVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahIntegerAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      int&               integerVariable);

  protected:


    virtual ~oahIntegerAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setIntegerVariable (
                            int value)
                              { fIntegerVariable = value; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;
  private:

    // fields
    // ------------------------------------------------------

    int&                  fIntegerVariable;
};
typedef SMARTP<oahIntegerAtom> S_oahIntegerAtom;
EXP ostream& operator<< (ostream& os, const S_oahIntegerAtom& elt);

//______________________________________________________________________________
class oahFloatAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahFloatAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      float&             floatVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahFloatAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      float&             floatVariable);

    virtual ~oahFloatAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setFloatVariable (
                            float value)
                              { fFloatVariable = value; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    float&                fFloatVariable;
};
typedef SMARTP<oahFloatAtom> S_oahFloatAtom;
EXP ostream& operator<< (ostream& os, const S_oahFloatAtom& elt);

//______________________________________________________________________________
class oahStringAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahStringAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      string&            stringVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahStringAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      string&            stringVariable);

    virtual ~oahStringAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setStringVariable (
                            string value)
                              { fStringVariable = value; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    string&               fStringVariable;
};
typedef SMARTP<oahStringAtom> S_oahStringAtom;
EXP ostream& operator<< (ostream& os, const S_oahStringAtom& elt);

//______________________________________________________________________________
class oahRationalAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahRationalAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      rational&          rationalVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahRationalAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      rational&          rationalVariable);

    virtual ~oahRationalAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setRationalVariable (
                            rational value)
                              { fRationalVariable = value;  }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    rational&             fRationalVariable;
};
typedef SMARTP<oahRationalAtom> S_oahRationalAtom;
EXP ostream& operator<< (ostream& os, const S_oahRationalAtom& elt);

//______________________________________________________________________________
class oahNumbersSetAtom : public oahValuedAtom
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahNumbersSetAtom> create (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      set<int>&          numbersSetVariable);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahNumbersSetAtom (
      string             shortName,
      string             longName,
      string             description,
      string             valueSpecification,
      string             variableName,
      set<int>&          numbersSetVariable);

    virtual ~oahNumbersSetAtom ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setNumbersSetVariable (
                            set<int> value)
                              { fNumbersSetVariable = value; }

    // services
    // ------------------------------------------------------

    // print
    // ------------------------------------------------------

    string                asShortNamedElementString () const;
    string                asLongNamedElementString () const;

    void                  print (ostream& os) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    set<int>&             fNumbersSetVariable;
};
typedef SMARTP<oahNumbersSetAtom> S_oahNumbersSetAtom;
EXP ostream& operator<< (ostream& os, const S_oahNumbersSetAtom& elt);

//_______________________________________________________________________________
class oahSubGroup : public oahElement
{
  public:

    // data types
    // ------------------------------------------------------

    enum oahSubGroupVisibilityKind {
      kSubGroupVisibilityAlways,
      kSubGroupVisibilityHiddenByDefault };

    static string subGroupVisibilityKindAsString (
      oahSubGroupVisibilityKind subGroupVisibilityKind);

  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahSubGroup> create (
      string                    header,
      string                    shortName,
      string                    longName,
      string                    description,
      oahSubGroupVisibilityKind subGroupVisibilityKind,
      S_oahGroup                groupUpLink);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahSubGroup (
      string                    header,
      string                    shortName,
      string                    longName,
      string                    description,
      oahSubGroupVisibilityKind subGroupVisibilityKind,
      S_oahGroup                groupUpLink);

    virtual ~oahSubGroup ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setGroupUpLink (
                            S_oahGroup oahGroup)
                              { fGroupUpLink = oahGroup; }

    S_oahGroup            getGroupUpLink () const
                              { return fGroupUpLink; }

    string                getHeader () const
                              { return fHeader; }

    oahSubGroupVisibilityKind
                          getSubGroupVisibilityKind () const
                              { return fSubGroupVisibilityKind; }

    // services
    // ------------------------------------------------------

    void                  underlineHeader (ostream& os) const;

    void                  registerSubGroupInHandler (
                            S_oahHandler handler);

    void                  appendAtom (
                            S_oahAtom oahAtom);

    S_oahElement          fetchElementByName (
                            string name);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printSubGroupForcedHelp (
                            ostream& os) const;

    void                  printAtomForcedHelp (
                            ostream&  os,
                            S_oahAtom targetAtom) const;

    void                  printOptionsSummary (ostream& os) const;

    void                  printSpecificSubGroupHelp (
                            ostream&      os,
                            S_oahSubGroup subGroup) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  private:

    // fields
    // ------------------------------------------------------

    S_oahGroup            fGroupUpLink;

    string                fHeader;

    oahSubGroupVisibilityKind
                          fSubGroupVisibilityKind;

    list<S_oahAtom>       fAtomsList;
};
typedef SMARTP<oahSubGroup> S_oahSubGroup;
EXP ostream& operator<< (ostream& os, const S_oahSubGroup& elt);

//_______________________________________________________________________________
class oahGroup : public oahElement
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahGroup> create (
      string       header,
      string       shortName,
      string       longName,
      string       description,
      S_oahHandler handlerUpLink);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahGroup (
      string       header,
      string       shortName,
      string       longName,
      string       description,
      S_oahHandler handlerUpLink);

    virtual ~oahGroup ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setHandlerUpLink (
                            S_oahHandler handler);

    S_oahHandler          getHandlerUpLink () const
                              { return fHandlerUpLink; }

    string                getHeader () const
                              { return fHeader; }

  public:

    // consistency check
    // ------------------------------------------------------

    void                  checkOptionsConsistency ();

  public:

    // services
    // ------------------------------------------------------

    void                  underlineHeader (ostream& os) const;

    void                  registerOptionsGroupInHandler (
                            S_oahHandler handler);

    void                  appendSubGroup (
                            S_oahSubGroup subGroup);

    S_oahElement          fetchElementByName (
                            string name);

    virtual S_oahValuedAtom
                          handleAtom (
                            ostream&  os,
                            S_oahAtom item);

    virtual void          handleAtomValue (
                            ostream&  os,
                            S_oahAtom atom,
                            string    theString);

    // print
    // ------------------------------------------------------

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printSubGroupForcedHelp (
                            ostream&      os,
                            S_oahSubGroup targetSubGroup) const;

    void                  printGroupForcedHelp (
                            ostream&      os,
                            S_oahSubGroup targetSubGroup,
                            S_oahAtom     targetAtom) const;

    void                  printOptionsSummary (ostream& os) const;

    void                  printSpecificSubGroupHelp (
                            ostream&      os,
                            S_oahSubGroup subGroup) const;

    void                  printOptionsValues (
                            ostream& os,
                            int      valueFieldWidth) const;

  protected:

    // upLink
    // ------------------------------------------------------

    S_oahHandler          fHandlerUpLink;

  private:

    // fields
    // ------------------------------------------------------

    string                fHeader;

    list<S_oahSubGroup>   fSubGroupsList;
};
typedef SMARTP<oahGroup> S_oahGroup;
EXP ostream& operator<< (ostream& os, const S_oahGroup& elt);

//______________________________________________________________________________
class oahPrefix;
typedef SMARTP<oahPrefix> S_oahPrefix;

class oahPrefix : public smartable
/*
An options prefix 'trace' --> 'trace-' allows:
  -trace=abc,def,gh
to be developped into :
  -trace-abc -trace-def -trace-gh
*/
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<oahPrefix> create (
      string prefixName,
      string prefixErsatz,
      string prefixDescription);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahPrefix (
      string prefixName,
      string prefixErsatz,
      string prefixDescription);

    virtual ~oahPrefix ();

  public:

    // set and get
    // ------------------------------------------------------

    string                getPrefixName () const
                              { return fPrefixName; }

    string                getPrefixErsatz () const
                              { return fPrefixErsatz; }

    string                getPrefixDescription () const
                              { return fPrefixDescription; }

  public:

    // public services
    // ------------------------------------------------------

  private:

    // private services
    // ------------------------------------------------------

    string                prefixNames () const;
    string                prefixNamesInColumns (
                            int subGroupsShortNameFieldWidth) const;

    string                prefixNamesBetweenParentheses () const;
    string                prefixNamesInColumnsBetweenParentheses (
                            int subGroupsShortNameFieldWidth) const;

    string                operator () () const
                              { return fPrefixErsatz; }

  public:

    // print
    // ------------------------------------------------------

    virtual void          printHeader (ostream& os) const;

    virtual void          printElementEssentials (
                            ostream& os,
                            int      fieldWidth) const;

    virtual void          print (ostream& os) const;

    virtual void          printHelp (ostream& os) const;

  protected:

    // fields
    // ------------------------------------------------------

    string                fPrefixName;
    string                fPrefixErsatz;
    string                fPrefixDescription;
};
EXP ostream& operator<< (ostream& os, const S_oahPrefix& elt);

//_______________________________________________________________________________
class EXP oahHandler : public oahElement
{
  public:

    // creation
    // ------------------------------------------------------
/* JMI this a pure virtual class
    static SMARTP<oahHandler> create (
      string           handlerHeader,
      string           handlerValuesHeader,
      string           optionHoahHandlerandlerHelpShortName,
      string           handlerLongName,
      string           handlerSummaryShortName,
      string           handlerSummaryLongName,
      string           handlerPreamble,
      string           handlerDescription,
      indentedOstream& handlerlogIOstream);
*/

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    oahHandler (
      string           HandlerHeader,
      string           handlerValuesHeader,
      string           handlerShortName,
      string           handlerLongName,
      string           handlerSummaryShortName,
      string           handlerSummaryLongName,
      string           handlerPreamble,
      string           handlerDescription,
      indentedOstream& handlerlogIOstream);

    virtual ~oahHandler ();

  private:

    // initialization
    // ------------------------------------------------------

    virtual void          initializeOptionsHandler (
                            string executableName) = 0;

  public:

    // set and get
    // ------------------------------------------------------

    string                getHandlerHeader () const
                              { return fHandlerHeader; }

    string                getOptionsHandlerValuesHeader () const
                              { return fHandlerValuesHeader; }

    string                getHandlerSummaryShortName () const
                              { return fHandlerSummaryShortName; }

    string                getHandlerSummaryLongName () const
                              { return fHandlerSummaryLongName; }

    string                getHandlerPreamble () const
                              { return fHandlerPreamble; }

    const indentedOstream&
                          getOptionsHandlerlogIOstream ()
                              { return fHandlerLogIOstream; }

    string                getExecutableName () const
                              { return fHandlerExecutableName; }

    const list<S_oahElement>&
                          getHandlerElementsList () const
                              { return fHandlerElementsList; }

    int                   getMaximumShortNameWidth () const
                              { return fMaximumShortNameWidth; }

    int                   getMaximumLongNameWidth () const
                              { return fMaximumLongNameWidth; }

    int                   getMaximumSubGroupsHeadersSize () const
                              { return fMaximumSubGroupsHeadersSize; }

  public:

    // public services
    // ------------------------------------------------------

    void                  appendPrefixToHandler (
                            S_oahPrefix prefix);

    void                  appendGroupToHandler (
                            S_oahGroup oahGroup);

    void                  registerElementInHandler (
                            S_oahElement element);

    void                  registerHandlerInItself ();

    S_oahPrefix           fetchPrefixFromMap (
                            string name) const;

    S_oahElement          fetchElementFromMap (
                            string name) const;

    const vector<string>  decipherOptionsAndArguments (
                            int   argc,
                            char* argv[]);

  public:

    // print
    // ------------------------------------------------------

    string                commandLineWithShortNamesAsString () const;
    string                commandLineWithLongNamesAsString () const;

    void                  print (ostream& os) const;

    void                  printHelp (ostream& os) const;

    void                  printOptionsSummary (ostream& os) const;
    void                  printOptionsSummary () const
                              { printOptionsSummary (fHandlerLogIOstream); }

    void                  printSpecificSubGroupHelp (
                            ostream&      os,
                            S_oahSubGroup subGroup) const;

    void                  printSpecificElementHelp (
                            ostream& os,
                            string   name) const;

    void                  printAllOptionsValues (
                            ostream& os) const;

    void                  setOptionsHandlerFoundAHelpItem ()
                              { fHandlerFoundAHelpItem = true; }

    bool                  getOptionsHandlerFoundAHelpItem () const
                              { return fHandlerFoundAHelpItem; }

  private:

    // private services
    // ------------------------------------------------------

    string                helpNamesBetweenParentheses () const; // JMI ???

    void                  registerNamesInHandler (
                            string       optionShortName,
                            string       optionLongName,
                            S_oahElement element);

    void                  printKnownPrefixes () const;
    void                  printKnownElements () const;

    S_oahElement          fetchElementByName (
                            string name);

    void                  handleElementName (
                            string name);

    void                  handleHandlerName (
                            S_oahHandler handler,
                            string       name);

    void                  handleGroupName (
                            S_oahGroup group,
                            string     groupName);

    void                  handleSubGroupName (
                            S_oahSubGroup subGroup,
                            string        subGroupName);

    void                  handleAtomName (
                            S_oahAtom atom,
                            string    atomName);

    void                  handleOptionsUsageAtomName (
                            S_oahOptionsUsageAtom optionsUsageAtom,
                            string                atomName);

    void                  handleOptionsSummaryAtomName (
                            S_oahOptionsSummaryAtom optionsSummaryAtom,
                            string                  atomName);

    void                  handleCombinedBooleansAtomName (
                            S_oahCombinedBooleansAtom combinedBooleansAtom,
                            string                    atomName);

    void                  handleBooleanAtomName (
                            S_oahBooleanAtom booleanAtom,
                            string           atomName);

    void                  handleTwoBooleansAtomName (
                            S_oahTwoBooleansAtom twoBooleansAtom,
                            string               atomName);

    void                  handleThreeBooleansAtomName (
                            S_oahThreeBooleansAtom threeBooleansAtom,
                            string                 atomName);

    void                  handleElementHelpAtomName (
                            S_oahElementHelpAtom itemHelpAtom,
                            string               atomName);

    void                  handleIntegerAtomName (
                            S_oahIntegerAtom integerAtom,
                            string           atomName);

    void                  handleFloatAtomName (
                            S_oahFloatAtom floatAtom,
                            string         atomName);

    void                  handleStringAtomName (
                            S_oahStringAtom stringAtom,
                            string          atomName);

    void                  handleRationalAtomName (
                            S_oahRationalAtom rationalAtom,
                            string            atomName);

    void                  handleNumbersSetAtomName (
                            S_oahNumbersSetAtom numbersSetAtom,
                            string              atomName);

    void                  handleOptionValueOrArgument (
                            string theString);

    void                  checkMissingPendingValuedAtomValue (
                            string context);

    void                  handleElementHelpAtomValue (
                            S_oahElementHelpAtom elementHelpAtom,
                            string               theString);

    void                  handleIntegerAtomValue (
                            S_oahIntegerAtom integerAtom,
                            string           theString);

    void                  handleFloatAtomValue (
                            S_oahFloatAtom floatAtom,
                            string         theString);

    void                  handleStringAtomValue (
                            S_oahStringAtom stringAtom,
                            string          theString);

    void                  handleRationalAtomValue (
                            S_oahRationalAtom rationalAtom,
                            string            theString);

    void                  handleNumbersSetAtomValue (
                            S_oahNumbersSetAtom numbersSetAtom,
                            string              theString);

    virtual void          checkOptionsAndArguments () = 0;

  protected:

    // fields
    // ------------------------------------------------------

    string                fHandlerHeader;
    string                fHandlerValuesHeader;

    string                fHandlerSummaryShortName;
    string                fHandlerSummaryLongName;

    string                fHandlerPreamble;

    map<string, S_oahPrefix>
                          fHandlerPrefixesMap;

    list<S_oahGroup>      fHandlerGroupsList;

    map<string, S_oahElement>
                          fHandlerElementsMap;

    vector<string>        fHandlerArgumentsVector;

    string                fHandlerExecutableName;

    list<S_oahElement>    fHandlerElementsList;

    indentedOstream&      fHandlerLogIOstream;

    // this is needed to exit if the executable is launched
    // with one or more help options,
    // i.e. items that are only used to display help to the user
    bool                  fHandlerFoundAHelpItem;

  private:

    // private services
    // ------------------------------------------------------

    int                   getMaximumVariableNameWidth () const
                              { return fMaximumVariableNameWidth; }


  private:

    // private fields
    // ------------------------------------------------------

    int                   fMaximumSubGroupsHeadersSize;

    int                   fMaximumShortNameWidth;
    int                   fMaximumLongNameWidth;

    int                   fMaximumVariableNameWidth;

    S_oahValuedAtom       fPendingValuedAtom;
};
typedef SMARTP<oahHandler> S_oahHandler;
EXP ostream& operator<< (ostream& os, const S_oahHandler& elt);


}


#endif