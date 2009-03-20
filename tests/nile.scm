(define $nil '())

(define $print 
  (lambda (arg)
    (display arg)
    $print
    ))

(define $ifTrue
  (lambda (func1)
    (let ((ret (func1)))
      (lambda (func2) func1))))

(define $ifFalse
  (lambda (func1)
    (lambda (func2)
      (func2))))

(define $if
  (lambda (arg)
    (if arg $ifTrue $ifFalse)))

(define $lessthan
  (lambda (arg1)
    (lambda (arg2)
      (< arg1 arg2))))

(define $main $nil)

(define $add
  (lambda (arg1)
