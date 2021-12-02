function [L,U] = mylu(A)
    n=size(A,1);
    m = size(A,2);
    for k = 1:n-1
            p = A(k,k);
            l = k;
            for i = k:n
                if abs(A(i,k)) > p then
                    p = A(i,k);
                    l = i;
                 end
            end

            if l ~= k then 
                for j = k:m
                    temp = A(k,j);
                    A(k,j) = A(l,j);
                    A(l,j) = temp;
                end
             end

            for i = k+1:n
                A(i,k) = A(i,k)/A(k,k);
            end
            for i = k + 1 : n
                 for j = k + 1:n
                      A(i,j) = A(i,j) - (A(i,k)*A(k,j));
                 end
             end
    end
    L =  tril(A) - diag(diag(A)) + eye(n,n);
    U = triu(A);
endfunction
