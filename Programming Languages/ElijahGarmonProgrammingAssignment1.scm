;Programming Assignment 1
;Elijah Garmon
;Spring 2025
;Programming Languages
;COP 4020.03

;Question 1: Determine if num1+10 is greater than num2*2
(define (compare num1 num2)
  (if (> (+ num1 10) (* 2 num2))
      ; Output yes if true
      "yes"
      ; Output no if false
      "no"))

;Function Test
(display (compare 5 6))
(display (compare 7 9))

;Question 2: Recursively add the value from 1 to N
(define (sum1toN N)
  (if (= N 1)
      1
      (+ N (sum1toN (- N 1)))))

;Function Test
(display (sum1toN 4))
(display (sum1toN 6))

;Question 3: Recursively determine the length of a list
(define (len list)
  (if (null? list)
      0
      (+ 1 (len (cdr list)))))

;Function Test
(display (len '()))
(display (len '(a b c d e)))
(display (len '(a b c d e f g h i j k l m n o p)))
