; Semester : Spring 2025
; Course Code : COP4020.03
; Course Title : Programming Languages
; Assignment : Programming Assignment 2
; Name : Elijah Garmon
; Question Number : 2
; Programs Purpose : Create a CLIPS program that runs through the family tree and outputs all of Jenny's ancestors

(deftemplate MAIN::parent
   (slot parent-name)
   (slot child-name))

(deftemplate MAIN::ancestor
   (slot ancestor-name)
   (slot descendant-name))

(deffacts MAIN::family-tree
   (parent (parent-name Mike) (child-name Nancy))
   (parent (parent-name Nancy) (child-name Tony))
   (parent (parent-name Tony) (child-name Rose))
   (parent (parent-name Rose) (child-name Henry))
   (parent (parent-name Henry) (child-name Jenny)))

(defrule MAIN::form-ancestor
   (parent (parent-name ?p) (child-name ?c))
   =>
   (assert (ancestor (ancestor-name ?p) (descendant-name ?c))))

(defrule MAIN::find-ancestor
   (ancestor (ancestor-name ?x) (descendant-name ?y))
   (parent (parent-name ?y) (child-name ?z))
   =>
   (assert (ancestor (ancestor-name ?x) (descendant-name ?z))))
   
(defrule MAIN::print-ancestor
   (ancestor (ancestor-name ?x) (descendant-name Jenny))
   =>
   (printout t ?x " is an ancestor of Jenny" crlf))