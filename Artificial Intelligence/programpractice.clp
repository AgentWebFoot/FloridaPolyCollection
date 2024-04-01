(deftemplate MAIN::path
   (multislot nodes)
   (slot cost))

(deffacts MAIN::direct-link
   (path (nodes f e) (cost 2))
   (path (nodes e b) (cost 2))
   (path (nodes b a) (cost 3))
   (path (nodes a d) (cost 2))
   (path (nodes d c) (cost 1))
   (path (nodes c a) (cost 1))
   (path (nodes b c) (cost 2))
   (path (nodes f c) (cost 3)))

(defrule MAIN::infer-indirect-paths
   (path (nodes ?begin ?temp) (cost ?cost1))
   (path (nodes ?temp ?end) (cost ?cost2))
   =>
   (assert (path (nodes ?begin ?temp ?end) (cost (+ ?cost1 ?cost2)))))

(defrule MAIN::print-paths
   (path (nodes ?nodes) (cost ?cost))
   =>
   (printout t "The cost of the path ( " ?nodes " ) is " ?cost))

