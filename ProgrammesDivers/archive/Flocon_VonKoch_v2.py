import math
import numpy as np
import matplotlib.pyplot as plt
import time



coef1=2/3
coef2=1/3
coef3=1/2
coef4=(math.sqrt(3)/6)
n=0
xa=0
ya=8660
xb=10000
yb=8660
xc=5000
yc=0
xi=0
yi=0
xj=0
yj=0
xk=0
yk=0
Xmax=10100
Ymax=11750




plt.axis([-200,Xmax,-200,Ymax])
plt.axis('scaled')


def pointsIJK(xa,ya,xb,yb):
        xi=coef1*xa+coef2*xb
        yi=coef1*ya+coef2*yb
        
        xk=coef2*xa+coef1*xb
        yk=coef2*ya+coef1*yb
        
        xj=coef3*(xa+xb)-coef4*(yb-ya)
        yj=coef3*(ya+yb)+coef4*(xb-xa) 
        
        return(xi,yi,xj,yj,xk,yk)


 
     




def div_segment(xa,ya,xb,yb,n):
     if(n==0):
       
         
       
       plt.plot([xa,xb],[ya,yb]) 
       return(1)
   
    
   
     else:
         
         (xi,yi,xj,yj,xk,yk)=pointsIJK(xa, ya, xb, yb)
         Xi=xi
         Yi=yi
         Xj=xj
         Yj=yj
         Xk=xk
         Yk=yk
         plt.plot([xa,Xi,Xj,Xk,xb],[ya,Yi,Yj,Yk,yb])
         plt.plot([Xi,Xk],[Yi,Yk],color='white')
         
         plt.show(False)
         
         div_segment(xa, ya, Xi, Yi, n-1)
         div_segment(Xi, Yi, Xj, Yj, n-1)
         div_segment(Xj, Yj, Xk, Yk, n-1)
         div_segment(Xk, Yk, xb, yb, n-1)
         
         
while(n<4):        
   div_segment(xa,ya,xb,yb,n)
   div_segment(xb,yb,xc,yc,n) 
   div_segment(xc,yc,xa,ya,n)
   n=n+1

