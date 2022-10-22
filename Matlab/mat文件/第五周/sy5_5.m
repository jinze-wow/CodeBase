s = 0;
     a = [12,13,14;15,16,17;18,19,20;21,22,23];
     for k = a
        for j = 1:4
           if rem(k(j),2)~=0
               s = s +k(j);
           end
         end
      end
s
