(deftemplate MAIN::link
   (slot start)
   (slot end)
   (slot cost))

(deftemplate MAIN::path
   (slot start)
   (slot end)
   (multislot nodes)
   (slot total-cost))

(deffacts MAIN::network-topology
   (link (start "Node 1") (end "Node 2") (cost 4))
   (link (start "Node 1") (end "Node 3") (cost 2))
   (link (start "Node 2") (end "Node 3") (cost 5))
   (link (start "Node 2") (end "Node 4") (cost 10))
   (link (start "Node 3") (end "Node 4") (cost 3)))

(defrule MAIN::convert-links
   (link (start ?begin) (end ?end) (cost ?cost))
   =>
   (assert (path (start ?begin) (end ?end) (nodes ?begin ?end) (total-cost ?cost))))

(defrule MAIN::extend-paths
   ?existing-path <- (path (start ?start) (end ?temp) (nodes $?nodes) (total-cost ?total-cost))
   (link (start ?temp) (end ?end) (cost ?cost))
   (test (not (member$ ?end ?nodes)))
   =>
   (assert (path (start ?start) (end ?end) (nodes ?nodes ?end) (total-cost (+ ?total-cost ?cost)))))

(defrule MAIN::best-paths
   (path (start "Node 1") (end "Node 4") (nodes $?nodes) (total-cost ?total-cost))
   (not (path (start "Node 1") (end "Node 4") (nodes $?other-nodes) (total-cost ?other-cost&:(< ?other-cost ?total-cost))))
   =>
   (printout t "The most cost-efficient path from Node 1 to Node 4: " ?nodes ", with total cost of: " ?total-cost crlf))

