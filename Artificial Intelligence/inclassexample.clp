(deftemplate MAIN::path
   (slot from)
   (slot to))

(deffacts MAIN::the-given-paths
   (path (from 1) (to 2))
   (path (from 2) (to 3))
   (path (from 3) (to 4))
   (path (from 4) (to 5))
   (path (from 3) (to 6))
   (path (from 6) (to 5)))

(defrule MAIN::infer-indirect-paths
   (path (from ?begin) (to ?temp))
   (path (from ?temp) (to ?end))
   =>
   (assert (path (from ?begin) (to ?end))))

(defrule MAIN::print-paths
   (path (from ?begin) (to ?end))
   =>
   (printout t "There is a path from " ?begin " to " ?end crlf))

