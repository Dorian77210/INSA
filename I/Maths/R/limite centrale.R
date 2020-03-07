x = seq(1, 20, 1)
x = runif(100) # loi uniforme
x = rexp(100, 1)

# plot(table(x))
n = 20
x[sample.int(length(x), n)]

# on calcule N myenne de n elements
N = 1000
xbar = rep(0, N)

for (i in 1:N)
{
  elements = x[sample.int(length(x), n)]
  avg = mean(elements);
  xbar[i] = avg
}

hist(xbar)
abline(v = mean(x), col = 'red')
