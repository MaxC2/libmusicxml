\version "2.19.83"

% Generated by xml2ly 0.93 from "harmonies/Harmonies.xml"
% on Tuesday 2020-02-11 @ 17:13:34 CET

% The translation command line was:
%   xml2ly '-xi' '-aofn' '-dmsr' '-dpg' '--dlpsr' '-abn' '-lpcd' '-rbracks' '-mssp' '1cm' 'harmonies/Harmonies.xml' '-t=harms,pim' '-iln' '-t=mxmltv,meas' '-dov'
% or, with long option names:
%  xml2ly harmonies/Harmonies.xml -xml2ly-infos -auto-output-file-name -display-msr -display-partgroups -display-lpsr -all-bar-numbers -lilypond-compile-date -repeat-brackets -markup-system-spacing.padding '1 cm' -trace-harmonies -trace-positions-in-measures -input-line-numbers -trace-musicxml-tree-visitors -trace-measures -display-options-values
% or, with short option names:
%   xml2ly harmonies/Harmonies.xml -xi -aofn -dmsr -dpg -dlpsr -abn -lpcd -rbracks -mssp '1 cm' -tharms -tpim -iln -tmxmltv -tmeas -dov

% Comment or adapt next line as needed (default is 20)
#(set-global-staff-size 20.1587)


% Scheme function(s): "date & time"
% A set of functions to obtain a source file's modification time.

#(define comml           (object->string (command-line)))
#(define loc             (+ (string-rindex comml #\space ) 2))
#(define commllen        (- (string-length comml) 2))
#(define filen           (substring comml loc commllen))
#(define siz             (object->string (stat:size (stat filen))))
#(define ver             (object->string (lilypond-version)))
#(define dat             (strftime "%d/%m/%Y" (localtime (current-time))))
#(define tim             (strftime "%H:%M:%S" (localtime (current-time))))
#(define modTime         (stat:mtime (stat filen)))
#(define modTimeAsString (strftime "%d/%m/%Y - %H:%M:%S" (localtime modTime)))


\header {
  title              = "Harmonies"
  software           = "MuseScore 2.0.3.1"
  encodingDate       = "2017-03-06"
}

\paper {
  paper-height                   = 297\mm
  paper-width                    = 210\mm
  
  %left-margin                    = 0.0\mm
  %right-margin                   = 0.0\mm
  %top-margin                     = 0.0\mm
  %bottom-margin                  = 0.0\mm
  
  %horizontal-shift               = 0.0\mm
  %indent                         = 0.0\mm
  %short-indent                   = 0.0\mm
  
  markup-system-spacing.padding  = 1\cm
  %between-system-space           = 0.0\mm
  %page-top-space                 = 0.0\mm
  
  %page-count                     = -1
  %system-count                   = -1
  
  oddHeaderMarkup                = \markup {
    \fill-line {
      \on-the-fly \not-first-page {
        \fromproperty #'page:page-number-string
        " "
        \fromproperty #'header:title
        " "
        \fromproperty #'header:subtitle
      }
    }
  }

  evenHeaderMarkup               = \markup {
    \fill-line {
      \on-the-fly \not-first-page {
        \fromproperty #'page:page-number-string
        " "
        \fromproperty #'header:title
        " "
        \fromproperty #'header:subtitle
      }
    }
  }

  oddFooterMarkup                = \markup {
    \tiny
    \column {
      \fill-line {
        #(string-append
"Music generated from MusicXML by xml2ly 0.93 and engraved by LilyPond " (lilypond-version))
      }
      \fill-line { \italic { \modTimeAsString }}
    }
  }

  evenFooterMarkup               = ""
}

\layout {
  \context {
    \Score
    autoBeaming = ##f % to display tuplets brackets
  }
  \context {
    \Voice
  }
  \context {
    \Score
    % defaultBarType = #"!"
    startRepeatType = #"[|:"
    endRepeatType = #":|]"
    doubleRepeatType = #":|][|:"
  }
}

% Pick your choice from the next two lines as needed
myBreak = { \break }
%myBreak = { }

% Pick your choice from the next two lines as needed
myPageBreak = { \pageBreak }
%myPageBreak = { }

Part_POne_HARMONY_Staff_Voice_Eleven_HARMONY = \chordmode {
  \language "nederlands"
  \set Score.barNumberVisibility = #all-bar-numbers-visible
  \override Score.BarNumber.break-visibility = ##(#f #t #t)
  
  \key c \major
  \numericTimeSignature \time 4/4
  
  \clef "treble"
  c4:m %{ line 87 %} f8:m7 %{ line 103 %} s%{44%} %{ line 131 %} g4:maj7 %{ line 131 %} cis:aug/gis %{ line 147 %} | % 2
  \barNumberCheck #2
  a2:m7 %{ line 171 %} b:5.3 %{ line 209 %} | % 1
  \barNumberCheck #3
}

Part_POne_Staff_One_Voice_One = \absolute {
  \language "nederlands"
  \set Score.barNumberVisibility = #all-bar-numbers-visible
  \override Score.BarNumber.break-visibility = ##(#f #t #t)
  
  \key c \major
  \numericTimeSignature \time 4/4
  
  \clef "treble"
  f'4 %{ line 93 %} e'8 %{ line 109 %} [ c' %{ line 120 %} ] d'4 %{ line 137 %} g' %{ line 158 %} | % 2
  \barNumberCheck #2
  <a' %{ line 177 %} c'' %{ line 187 %} e'' %{ line 198 %} >2 a' %{ line 215 %}
  \bar "|." %{ 225 %}
   %{ 225 %}| % 3
  \barNumberCheck #3
}

\book {
  \header {
  }
  
  \score {
    <<
      
      \new PianoStaff
      \with {
      }
      <<
      \context ChordNames = "Part_POne_HARMONY_Staff_Voice_Eleven_HARMONY"
      \Part_POne_HARMONY_Staff_Voice_Eleven_HARMONY
      
      \new Staff = "Part_POne_Staff_One"
      \with {
      }
      <<
        \context Voice = "Part_POne_Staff_One_Voice_One" <<
          \Part_POne_Staff_One_Voice_One
        >>
      >>
      
      >>
      
    >>
    
    \layout {
      \context {
        \Score
        autoBeaming = ##f % to display tuplets brackets
      }
      \context {
        \Voice
      }
      \context {
        \Score
        % defaultBarType = #"!"
        startRepeatType = #"[|:"
        endRepeatType = #":|]"
        doubleRepeatType = #":|][|:"
      }
    }
    
    \midi {
      \tempo 4 = 90
    }
  }
  
  \paper {
    paper-height                   = 297\mm
    paper-width                    = 210\mm
    
    %left-margin                    = 0.0\mm
    %right-margin                   = 0.0\mm
    %top-margin                     = 0.0\mm
    %bottom-margin                  = 0.0\mm
    
    %horizontal-shift               = 0.0\mm
    %indent                         = 0.0\mm
    %short-indent                   = 0.0\mm
    
    markup-system-spacing.padding  = 1\cm
    %between-system-space           = 0.0\mm
    %page-top-space                 = 0.0\mm
    
    %page-count                     = -1
    %system-count                   = -1
    
    oddHeaderMarkup                = \markup {
    \fill-line {
      \on-the-fly \not-first-page {
        \fromproperty #'page:page-number-string
        " "
        \fromproperty #'header:title
        " "
        \fromproperty #'header:subtitle
      }
    }
  }

    evenHeaderMarkup               = \markup {
    \fill-line {
      \on-the-fly \not-first-page {
        \fromproperty #'page:page-number-string
        " "
        \fromproperty #'header:title
        " "
        \fromproperty #'header:subtitle
      }
    }
  }

    oddFooterMarkup                = \markup {
    \tiny
    \column {
      \fill-line {
        #(string-append
"Music generated from MusicXML by xml2ly 0.93 and engraved by LilyPond " (lilypond-version))
      }
      \fill-line { \italic { \modTimeAsString }}
    }
  }

    evenFooterMarkup               = ""
  }
  
}
