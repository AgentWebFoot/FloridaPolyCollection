(deffacts MAIN::letters-and-digits
   (letter E)
   (letter H)
   (letter N)
   (letter O)
   (letter W)
   (digit 0)
   (digit 1)
   (digit 2)
   (digit 3)
   (digit 4)
   (digit 5)
   (digit 6))

(defrule MAIN::all-replacements
   (letter ?letter)
   (digit ?digit)
   =>
   (assert (replace ?letter ?digit)))

(defrule MAIN::forward-checking
   (replace E ?e)
   (replace O ?o&~?e)
   (test (= (mod (+ ?e ?e) 10) ?o))
   (replace H ?h&~?e&~?o)
   (replace W ?w&~?e&~?o)
   (replace N ?n&~?w&~?o&~?h)
   (test (and (neq ?e ?o) (neq ?e ?h) (neq ?e ?w) (neq ?e ?n) (neq ?o ?h) (neq ?o ?w) (neq ?o ?n) (neq ?h ?w) (neq ?h ?n) (neq ?w ?n)))
   (test (= (mod (+ ?e ?e (* ?w 10) (* ?h 10)) 100) (+ (* ?n 10) ?o)))
   =>
   (printout t "E=" ?e ", H=" ?h ", N=" ?n ", O=" ?o ", W=" ?w crlf)
   (printout t " " ?w ?e crlf)
   (printout t " + " ?h ?e crlf)
   (printout t " ------" crlf)
   (printout t " " ?n ?o crlf crlf))

