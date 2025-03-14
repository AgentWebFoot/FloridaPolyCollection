; Semester : Spring 2025
; Course Code : COP4020.03
; Course Title : Programming Languages
; Assignment : Programming Assignment 2
; Name : Elijah Garmon
; Question Number : 1
; Programs Purpose : Create a CLIPS program that outputs all permutations of the base-fact (base-fact A B C)

(deftemplate MAIN::list
   (slot head)
   (slot middle)
   (slot tail))

(deffacts MAIN::base-fact
   (list (head A) (middle B) (tail C)))

(defrule MAIN::permutation
   (list (head ?h) (middle ?m) (tail ?t))
   =>
   (assert (list (head ?h) (middle ?t) (tail ?m)))
   (assert (list (head ?m) (middle ?h) (tail ?t)))
   (assert (list (head ?m) (middle ?t) (tail ?h)))
   (assert (list (head ?t) (middle ?h) (tail ?m)))
   (assert (list (head ?t) (middle ?m) (tail ?h))))

(defrule MAIN::print-permutations
   (list (head ?h) (middle ?m) (tail ?t))
   =>
   (printout t "Permutation is (" ?h ?m ?t ")" crlf))

