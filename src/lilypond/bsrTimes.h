/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___bsrTimes___
#define ___bsrTimes___

#include "bsrLineElements.h"

#include "bsrCellsLists.h"


using namespace std;

namespace MusicXML2 
{

//______________________________________________________________________________
class bsrTimeItem;
typedef SMARTP<bsrTimeItem> S_bsrTimeItem;

class bsrTime;
typedef SMARTP<bsrTime> S_bsrTime;

//______________________________________________________________________________
class bsrTimeItem : public bsrElement
{
  public:
    
    // creation
    // ------------------------------------------------------

    static SMARTP<bsrTimeItem> create (
      int inputLineNumber);
      
  protected:

    // constructors/destructor
    // ------------------------------------------------------

    bsrTimeItem (
      int inputLineNumber);
            
    virtual ~bsrTimeItem ();

  public:

    // set and get
    // ------------------------------------------------------

    const vector<int>&    getTimeBeatsNumbersVector ()
                              { return fTimeBeatsNumbersVector; }

    void                  setTimeBeatValue (int timeBeatValue);
                              
    int                   getTimeBeatValue () const
                              { return fTimeBeatValue; }

    // services
    // ------------------------------------------------------

    bool                  isEqualTo (S_bsrTimeItem otherTimeItem) const;
                            
    void                  appendBeatsNumber (int beatsNumber);

    int                   getTimeBeatsNumber () const;
                              
  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v);

  public:

    // print
    // ------------------------------------------------------

    string                asString () const;

    virtual void          print (ostream& os);
  
  private:
  
    // fields
    // ------------------------------------------------------

    vector<int>           fTimeBeatsNumbersVector; // 5+3+1 is possible
    int                   fTimeBeatValue;
};
typedef SMARTP<bsrTimeItem> S_bsrTimeItem;
EXP ostream& operator<< (ostream& os, const S_bsrTimeItem& elt);

//______________________________________________________________________________
class bsrTime : public bsrLineElement
{
  public:

    // data types
    // ------------------------------------------------------

    enum bsrTimeKind {
        kTimeNone,
        kTimeCommon,
        kTimeCut,
        kTimeNumerical };
/* JMI
        kTimeNote,
        kTimeDottedNote,
        kTimeSingleNumber,
        kTimeSenzaMisura };
        */

    static string timeKindAsString (
      bsrTimeKind timeKind);
      
  public:
          
    // creation
    // ------------------------------------------------------

    static SMARTP<bsrTime> create (
      int         inputLineNumber,
      bsrTimeKind timeKind);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    bsrTime (
      int         inputLineNumber,
      bsrTimeKind timeKind);
            
    virtual ~bsrTime ();
  
  public:

    // set and get
    // ------------------------------------------------------

    bsrTimeKind           getTimeKind () const
                              { return fTimeKind; }

    const vector<S_bsrTimeItem>&
                          getTimeItemsVector ()
                              { return fTimeItemsVector; }
/* time item are appended after construction,
 * so compute cells list on the fly as needed 
    S_bsrCellsList        getTimeCellsList () const
                              { return fTimeCellsList; }
*/

    // services
    // ------------------------------------------------------
                  
    void                  appendTimeItem (S_bsrTimeItem timeItem);

    S_bsrCellsList        asCellsList () const;    

    int                   fetchCellsNumber () const;

  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v);

  public:

    // print
    // ------------------------------------------------------

    string                asString () const;

    virtual void          print (ostream& os);

  private:

    // fields
    // ------------------------------------------------------

    bsrTimeKind           fTimeKind;
    
    vector<S_bsrTimeItem> fTimeItemsVector;

 // JMI   S_bsrCellsList        fTimeCellsList;
};
typedef SMARTP<bsrTime> S_bsrTime;
EXP ostream& operator<< (ostream& os, const S_bsrTime& elt);


} // namespace MusicXML2


#endif