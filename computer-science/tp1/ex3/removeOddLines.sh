nl Sand.msg > SandMsgNumbered
(colrm 1 5 < SandMsgNumbered) > SqndMsgNumberedLqstDigit 
(grep "1\|3\|5\|7\|9" < SqndMsgNumberedLqstDigit) > SandMsgOddNumbered
 (colrm 1 5 < SandMsgOddNumbered) > SandMsgOddLines

# Otrq opcion pero en una sola linea

 #nl Sand.msg | colrm 1 5 | grep "1\|3\|5\|7\|9" | colrm 1 5

#excercise2
cut -f 1 -d " " Musset.rep 
