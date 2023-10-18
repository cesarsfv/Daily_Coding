function countDecodings(encodedMessage) {
  const n = encodedMessage.length;
  if (n === 0) return 0;

  const dp = new Array(n + 1).fill(0);
  dp[0] = 1;
  dp[1] = encodedMessage[0] === '0' ? 0 : 1;

  for (let i = 2; i <= n; i++) {
    const oneDigit = parseInt(encodedMessage[i - 1]);
    const twoDigits = parseInt(encodedMessage.substring(i - 2, i));

    if (oneDigit >= 1) {
      dp[i] += dp[i - 1];
    }

    if (twoDigits >= 10 && twoDigits <= 26) {
      dp[i] += dp[i - 2];
    }
  }

  return dp[n];
}

const encodedMessage = "111";
const numberOfWays = countDecodings(encodedMessage);
console.log(`Número de maneiras de decodificar "${encodedMessage}": ${numberOfWays}`);
