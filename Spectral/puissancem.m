function [w,listW,lambda,iter]=puissancem(A,x0,tol,itermax)

w=x0/(x0'*x0);
x=A*w;
lambOld=1;
lambda=0;
[V,D]=eig(A);
u1=V(:,2);
for iter=1:itermax
    if(abs(lambOld-lambda)<tol)
        break
    end
    lambOld=lambda;
    w=x/sqrt((x'*x));
    listW(iter)=sqrt((w-u1)'*(w-u1));
    x=A*w;
    lambda=sqrt(x'*x);
end

plot([1:iter-1],listW,'o-')
hold on

for k=1:(iter-1)
conv(k)=(1/2)^k;
end
plot([1:iter-1],conv,'ro-')
