/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include "msrMutualDependencies.h"

#include "msrOptions.h"


using namespace std;

namespace MusicXML2 
{

//______________________________________________________________________________
S_msrSpanner msrSpanner::create (
  int                inputLineNumber,
  int                spannerNumber,
  msrSpannerKind     spannerKind,
  msrSpannerTypeKind spannerTypeKind,
  msrPlacementKind   spannerPlacementKind,
  S_msrNote          spannerNoteUplink)
{
  msrSpanner* o =
    new msrSpanner (
      inputLineNumber,
      spannerNumber,
      spannerKind,
      spannerTypeKind,
      spannerPlacementKind,
      spannerNoteUplink);
  assert (o!=0);
  return o;
}

msrSpanner::msrSpanner (
  int                inputLineNumber,
  int                spannerNumber,
  msrSpannerKind     spannerKind,
  msrSpannerTypeKind spannerTypeKind,
  msrPlacementKind   spannerPlacementKind,
  S_msrNote          spannerNoteUplink)
    : msrElement (inputLineNumber)
{
  fSpannerNoteUplink = spannerNoteUplink;

  fSpannerNumber = spannerNumber;
  
  fSpannerKind = spannerKind;
  
  fSpannerTypeKind = spannerTypeKind;

  fSpannerPlacementKind = spannerPlacementKind;
}

msrSpanner::~msrSpanner ()
{}

void msrSpanner::setSpannerOtherEndSidelink (
  S_msrSpanner otherEndSideLink)
{
  // sanity check
  msrAssert (
    otherEndSideLink != nullptr,
    "otherEndSideLink is null");
    
  // set the two-way sidelink between both ends of the spanner
  fSpannerOtherEndSidelink =
    otherEndSideLink;
    
  otherEndSideLink->fSpannerOtherEndSidelink =
    this;
}

void msrSpanner::acceptIn (basevisitor* v)
{
  if (gMsrOptions->fTraceMsrVisitors) {
    glogIOstream <<
      "% ==> msrSpanner::acceptIn ()" <<
      endl;
  }
      
  if (visitor<S_msrSpanner>*
    p =
      dynamic_cast<visitor<S_msrSpanner>*> (v)) {
        S_msrSpanner elem = this;
        
        if (gMsrOptions->fTraceMsrVisitors) {
          glogIOstream <<
            "% ==> Launching msrSpanner::visitStart ()" <<
            endl;
        }
        p->visitStart (elem);
  }
}

void msrSpanner::acceptOut (basevisitor* v)
{
  if (gMsrOptions->fTraceMsrVisitors) {
    glogIOstream <<
      "% ==> msrSpanner::acceptOut ()" <<
      endl;
  }

  if (visitor<S_msrSpanner>*
    p =
      dynamic_cast<visitor<S_msrSpanner>*> (v)) {
        S_msrSpanner elem = this;
      
        if (gMsrOptions->fTraceMsrVisitors) {
          glogIOstream <<
            "% ==> Launching msrSpanner::visitEnd ()" <<
            endl;
        }
        p->visitEnd (elem);
  }
}

void msrSpanner::browseData (basevisitor* v)
{}

string msrSpanner::spannerKindAsString (
  msrSpannerKind spannerKind)
{
  string result;
  
  switch (spannerKind) {
    case msrSpanner::kSpannerDashes:
      result = "spannerDashes";
      break;
    case msrSpanner::kSpannerWavyLine:
      result = "spannerWavyLine";
      break;
  } // switch

  return result;
}

string msrSpanner::spannerTypeKindAsString () const
{
  return
    msrSpannerTypeKindAsString (
      fSpannerTypeKind);
}

string msrSpanner::spannerKindAsString () const
{
  return
    spannerKindAsString (
      fSpannerKind);
}

string msrSpanner::spannerPlacementKindAsString () const
{
  return
    msrPlacementKindAsString (
      fSpannerPlacementKind);
}

string msrSpanner::asShortString () const
{
  stringstream s;
  
  s <<
    "Spanner" <<
    ", spannerNumber = " << fSpannerNumber <<
    ", " << spannerKindAsString () <<
    ", line " << fInputLineNumber <<
    ", spannerPlacementKind" << " : " <<
    spannerPlacementKindAsString () <<
    ", spannerTypeKind" << " : " <<
    spannerTypeKindAsString ();

  return s.str ();
}

void msrSpanner::print (ostream& os)
{
  os <<
    "Spanner" <<
    ", spannerNumber = " << fSpannerNumber <<
    ", " << spannerKindAsString () <<
    ", line " << fInputLineNumber <<
    endl;

  gIndenter++;

  const int fieldWidth = 24;
  
  os << left <<
    setw (fieldWidth) <<
    "spannerPlacementKind" << " : " <<
    spannerPlacementKindAsString () <<
    endl <<
    setw (fieldWidth) <<
    "spannerTypeKind" << " : " <<
    spannerTypeKindAsString () <<
    endl <<
    setw (fieldWidth) <<
    "spannerNoteUplink" << " : " <<
    endl;

  gIndenter++;
    os <<
      fSpannerNoteUplink->asString () <<
      endl;
  gIndenter--;

  os << left <<
    setw (fieldWidth) <<
    "spannerOtherEndSidelink";
  if (fSpannerOtherEndSidelink) {
    os <<
      endl <<
      fSpannerOtherEndSidelink->asShortString ();
  }
  else {
    os <<
    " : " << "***none***" <<
    endl;
  }
  
  gIndenter--;
}

ostream& operator<< (ostream& os, const S_msrSpanner& elt)
{
  elt->print (os);
  return os;
}


}
