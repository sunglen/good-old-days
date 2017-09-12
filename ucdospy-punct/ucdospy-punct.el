;; quail/ucdospy-punct.el 
;; Quail packages for Chinese (ucdospy + extra symbols)
(require 'quail)

(load "quail/UCDOSPY")
(load "quail/Punct")

(quail-define-package
 "chinese-ucdospy-punct" "Chinese-GB" "UCDOS拼符"
 t
 "UCDOS汉字输入 拼音方案 and `v' for 标点符号输入

This is the combination of Quail packages \"chinese-ucdospy\" and \"chinese-punct\".
You can enter normal Chinese characters by the same way as \"chinese-ucdospy\".
And, you can enter symbols by typing `v' followed by any key sequences
defined in \"chinese-punct\".

For instance, typing `v' and `%' insert `％'.
")

(setcar (nthcdr 2 quail-current-package)
        (nth 2 (assoc "chinese-ucdospy" quail-package-alist)))

(quail-defrule "v" (nth 2 (assoc "chinese-punct" quail-package-alist)))
