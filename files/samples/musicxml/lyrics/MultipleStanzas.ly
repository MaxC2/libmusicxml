\version "2.19.83"

% Generated by xml2ly 0.92 from "lyrics/SingOutAllYourPraiseToGod.xml"
% on Friday 2020-01-10 @ 11:18:20 CET

% The translation command line was:
%   xml2ly '-xi' '-aofn' '-dmsr' '-dpg' '--dlpsr' '-abn' '-lpcd' 'lyrics/SingOutAllYourPraiseToGod.xml'
% or, with long option names:
%  xml2ly lyrics/SingOutAllYourPraiseToGod.xml -xml2ly-infos -auto-output-file-name -display-msr -display-partgroups -display-lpsr -all-bar-numbers -lilypond-compile-date
% or, with short option names:
%   xml2ly lyrics/SingOutAllYourPraiseToGod.xml -xi -aofn -dmsr -dpg -dlpsr -abn -lpcd

% Comment or adapt next line as needed (default is 20)
#(set-global-staff-size 14.8571)


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
  title              = "Sing out All Your Praise to God!"
  subtitle           = "“He is risen”"
  composer           = "Washed Clean and Forgiven!                           Yirmeya House, BMI
"
  poet               = "HALLELU LELOHI 9.7.9.7.
"
  software           = "MuseScore 2.0.3"
  encodingDate       = "2016-09-05"
}

\paper {
  paper-height                   = 297\mm
  paper-width                    = 210\mm

  %left-margin                    = 0.0\mm
  %right-margin                   = 0.0\mm
  %top-margin                     = 0.0\mm
  %bottom-margin                  = 0.0\mm

  %indent                         = 0.0\mm
  %horizontal-shift               = 0.0\mm
  %short-indent                   = 0.0\mm

  %markup-system-spacing.padding  = 0.0\mm
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
"Music generated from MusicXML by xml2ly 0.92 and engraved by LilyPond " (lilypond-version))
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
}

% Pick your choice from the next two lines as needed
myBreak = { \break }
%myBreak = { }

% Pick your choice from the next two lines as needed
myPageBreak = { \pageBreak }
%myPageBreak = { }

Part_POne_Staff_One_Voice_One = \absolute {
  \language "nederlands"
  \set Score.barNumberVisibility = #all-bar-numbers-visible
  \override Score.BarNumber.break-visibility = ##(#f #t #t)

  \key ees \major
  \numericTimeSignature \time 4/4

  \clef "treble"
  <ees' g' >8 [ <d' bes' > <ees' bes' > <ees' g' > ] <f' aes' >4 <ees' g' > | % 2
  \barNumberCheck #2
  <d' f' >4 <c' g' > <c' ees' >2 | % 3
  \barNumberCheck #3
  <c' g' >8 [ <d' bes' > <ees' bes' > <ees' g' > ] <f' aes' >4 <ees' g' > | % 4
  \barNumberCheck #4
  <d' f' >1 | % 5
  \barNumberCheck #5
  \myBreak | % 5

  <c' c'' >4 <d' d'' >8 [ <ees' ees'' > ] <f' bes' >4 <d' g' > | % 6
  \barNumberCheck #6
  <ees' aes' >4 <f' bes' >8 [ <g' c'' > ] <c' f' >2 | % 7
  \barNumberCheck #7
  <aes f' >8 [ <bes aes' > <c' g' > <d' f' > ] <ees' g' >4 <d' f' > | % 8
  \barNumberCheck #8
  ees'1
  \bar "|."
  | % 1
  \barNumberCheck #9
}

Part_POne_Staff_One_Voice_One_Stanza_One = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "1. Sing"8 out8 all8 your8 prais4 -- es4 to4 the4 "Lord!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1 Lift4 %{ syllableLineBreak, line 858 %} %| % -1
up8 your8 voic4 -- es4 in4 joy8 -- ous8 "psalms!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_One_Stanza_Two = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "2. For"8 the8 Son8 has8 ris4 -- en4 on4 His4 day2 And8 the8 night8 is8 driv4 -- en4 "out!"1 Lift4 %{ syllableLineBreak, line 858 %} %| % -1
your8 -- selves8 from4 that4 slew4 of8 des8 -- "pond!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_One_Stanza_Three = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "3. No"8 more8 let8 the8 voice4 of4 vic4 -- tor4 -- y2 Be8 mut8 -- ed8 with8 -- in4 your4 "heart!"1 Lift4 %{ syllableLineBreak, line 858 %} %| % -1
shout8 -- ing8 prais4 -- es4 un4 -- to8 the8 "King!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_One_Stanza_Four = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "4. For"8 your8 guilt8 is8 nailed4 un4 -- to4 the4 tree2 And8 your8 sin8 un8 -- to4 the4 "cross!"1 No4 %{ syllableLineBreak, line 858 %} %| % -1
more8 let8 de4 -- mon4 chains4 cum8 -- ber8 "thee;"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_One_Stanza_Five = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "5. Death"8 and8 all8 his8 min4 -- ions4 turn4 to4 "flee!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1 Lift4 %{ syllableLineBreak, line 858 %} %| % -1
up8 your8 voic4 -- es4 in4 vic8 -- tor8 -- "y!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_One_Stanza_Six = \lyricmode {
  \set associatedVoice = #"Part_POne_Staff_One_Voice_One"
  \set ignoreMelismata = ##t
    "6. Je"8 -- sus8 Christ8 is8 ris4 -- "en!"4 We4 are4 "free!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1 Guilt4 %{ syllableLineBreak, line 858 %} %| % -1
is8 for8 -- giv4 -- "en,"4 sin4 is8 washed8 "clean!"2 Sing8 out8 all8 your8 praise4 to4 "God!"1
}

Part_POne_Staff_One_Voice_Two = \absolute {
  \language "nederlands"
  \set Score.barNumberVisibility = #all-bar-numbers-visible
  \override Score.BarNumber.break-visibility = ##(#f #t #t)

  R%{6%}1 |
  \key ees \major
  \numericTimeSignature \time 4/4

  \clef "treble"
  %{ emptyMeasureKind, line 86 %} | % 2
  R%{6%}1 |
  %{ emptyMeasureKind, line 392 %} | % 3
  R%{6%}1 |
  %{ emptyMeasureKind, line 530 %} | % 4
  R%{6%}1 |
  %{ emptyMeasureKind, line 812 %} | % 5
  R%{6%}1 |
  %{ emptyMeasureKind, line 857 %} | % 6
  R%{6%}1 |
  %{ emptyMeasureKind, line 1098 %} | % 7
  R%{6%}1 |
  %{ emptyMeasureKind, line 1285 %} | % 8
  ees'1
  \bar "|."
  | % 1
  \barNumberCheck #9
}

Part_PTwo_Staff_One_Voice_One = \absolute {
  \language "nederlands"
  \set Score.barNumberVisibility = #all-bar-numbers-visible
  \override Score.BarNumber.break-visibility = ##(#f #t #t)

  \key ees \major
  \numericTimeSignature \time 4/4

  \clef "bass"
  <c g >8 [ <bes, g > <c g > <c g > ] <d aes >4 <ees bes > | % 2
  \barNumberCheck #2
  <d aes >4 <ees g > <ees aes >2 | % 3
  \barNumberCheck #3
  <ees g >8 [ <f bes > <g bes > <g c' > ] <aes d' >4 <g c' > | % 4
  \barNumberCheck #4
  <f bes >1 | % 5
  \barNumberCheck #5
  \myBreak | % 5

  <aes, f >4 <aes, f >8 [ <bes, g > ] <d bes >4 <g bes > | % 6
  \barNumberCheck #6
  <aes c' >4 <d bes >8 [ <ees c' > ] <f aes >2 | % 7
  \barNumberCheck #7
  <c f >8 [ <d f > <ees g > <f aes > ] <g bes >4 <f bes > | % 8
  \barNumberCheck #8
  <g bes >1
  \bar "|."
  | % 9
  \barNumberCheck #9
}

\book {
  \header {
  }

  \score {
    <<

        \new Staff = "Part_POne_Staff_One"
        \with {
          instrumentName = "Violins 1"
        }
        <<
          \context Voice = "Part_POne_Staff_One_Voice_One" <<
            \voiceOne % out of 2 regular voices
            \Part_POne_Staff_One_Voice_One
          >>
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_One
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_Two
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_Three
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_Four
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_Five
          \new Lyrics
            \with {
            }
            \Part_POne_Staff_One_Voice_One_Stanza_Six
          \context Voice = "Part_POne_Staff_One_Voice_Two" <<
            \voiceTwo % out of 2 regular voices
            \Part_POne_Staff_One_Voice_Two
          >>
        >>
        \new Staff = "Part_PTwo_Staff_One"
        \with {
          instrumentName = "Violoncellos"
        }
        <<
          \context Voice = "Part_PTwo_Staff_One_Voice_One" <<
            \Part_PTwo_Staff_One_Voice_One
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

    %indent                         = 0.0\mm
    %horizontal-shift               = 0.0\mm
    %short-indent                   = 0.0\mm

    %markup-system-spacing.padding  = 0.0\mm
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
"Music generated from MusicXML by xml2ly 0.92 and engraved by LilyPond " (lilypond-version))
      }
      \fill-line { \italic { \modTimeAsString }}
    }
  }

    evenFooterMarkup               = ""
  }

}
