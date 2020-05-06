#-*-coding=utf-8-*-
import encodings
encodings.normalize_encoding('utf_8')
from tkinter import tix
f=open("result.txt", "rt")
x=f.read()
f.close()
x=x.split()
num=len(x)
root=tix.Tk()
frame=tix.Frame(root)
frame.pack()
scrolledwin=tix.ScrolledWindow(frame)
scrolledwin.pack(side="right",fill="y")
scr=scrolledwin.window
col=0
line_mark=0
row_=0
bigfont=("Helvetica", "50", 'bold')
for i in range(num):
	if col==9:
		col=0
		row_+=1
	txt=x[i]
	globals()['btn{}'.format(i)]=tix.Button(scr, text="%s" % txt,bg="ivory", fg="brown" , activebackground='yellow', activeforeground="blue")
	globals()['btn{}'.format(i)].config(font=bigfont)
	globals()['btn{}'.format(i)].grid(row=row_,column=col)
	if(line_mark%2==1):
		globals()["line_lbl{}".format(i)]=tix.Label(scr,text="     ")
		globals()["line_lbl{}".format(i)].config(font=bigfont)
		col+=1
		globals()["line_lbl{}".format(i)].grid(row=row_,column=col)
	col+=1
	line_mark+=1
root.mainloop()
