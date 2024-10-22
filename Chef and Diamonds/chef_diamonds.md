Total entities in jar now = Q+N
E = number of terms * probability(experiment takes number_of_turns to finish)

Eg 3 D and 4 C
Atleast 3 picks are reqd but at max 7
P(3), P(4), p(5), p(6,), p(7)
E= 3*P(3)+4*P(4)+5*p(5)+6*p(6)+7*p(7)

Q Diam and N Choc
Q <-> Q+N

Objective: P(i) for every i from Q to N+Q
E=max i*P(i) for i from Q to N+Q

we want our exp to finish in K turns
P(k)
           kth
_ _ _ _ _ _ D _ _ _N+Q
count no of ways I can fill other spaces with Q diamonds and remaining K-Q spaces with chocolates.
P = fav outcomes/total number of sceanrio

fav outcomes = C(k-1,Q-1) //remaining position k-1, wanted Q-1
total number = (N+Q) spaces  C(N+Q,Q)

P(k)= C(k-1,Q-1)/C(N+Q,Q)

E = sum k * P(k) k from Q to N+Q
  = sum k * C(k-1,Q-1) / C(N+Q,Q) k from Q to N+Q (we have to use some more thing because it will surpass the test case limit) O(N+Q) (we need to avoid this)
  
C(N,R) = N/R*C(N-1/R-1)
C(N,R) + C(N,R-1) = C(N+1,R)
C(N-1,R) + C(N-1,R-1) = C(N,R)

  = sum k * C(k-1,Q-1) (Q/Q)/ C(N+Q,Q) 
  = sum C(k,Q) k from Q to N+Q   * Q/C(N+Q,Q)
  = C(Q,Q) + C(Q+1,Q) + .... + C(N+Q,Q)
  = C(Q+1,Q+1) + C(Q+1,Q) + .... + C(N+Q,Q)
  = C(Q+2,Q+1) + C(Q+2,Q) + .... + C(N+Q,Q)
  = C(N+Q+1,Q+1) * Q/C(N+Q,Q)
  = (N+Q+1)/(Q+1) C(N+Q,Q) * Q/C(N+Q,Q)
  = Q * (N+Q+1)/(Q+1)
