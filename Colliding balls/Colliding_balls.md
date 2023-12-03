time = d/s
t(y) = x/v(y)
t(x) = y/v(x)

x/v(y) = y/v(x)

x*v(x) = y*v(y)

There are n balls on x axis 
x[i] v(x)[i]
valx[i] = x[i]*v(x)[i]
There are m balls on y axis
y[i] v(y)[i]
valy[i] = y[i]*v(y)[i]

valx[i] = valy[j]

val = 5
3 balls on x axis with valx[i] = 5
and 5 balls on y axis valy[i] = 5

min(number of such balls on x axis, no of such balls on y axis) = Number of intersection

for every value val
    res += min(number of such balls on x axis, no of such balls on y axis)