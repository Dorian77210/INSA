const nValues = []
for (let i = 1; i <= 12; i++)
{
    nValues.push(i);
}

const dValues = [10,10,10,10,10,10,1,1,1,1,1,1]

const eValues = [5]
const alpha = 0.5

function e(n)
{
    const result = alpha * dValues[n - 1] + (1 - alpha) * eValues[n - 1]
    return result
}

nValues.forEach(n => {
    eValues.push(e(n));
});

console.log(eValues);