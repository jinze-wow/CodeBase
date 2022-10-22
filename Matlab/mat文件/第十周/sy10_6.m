syms a b c d e f g h i;
P1=[0 1 0;1 0 0;0 0 1];
P2=[1 0 0;0 1 0; 1 0 1];
A=[a b c;d e f;g h i];
B=P1*P2*A
C=inv(B)
D=B*C