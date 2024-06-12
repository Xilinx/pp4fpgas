module.exports = {
    rules: {
      'body-max-line-length': [2, 'always', 100], // Default rule
    },
    plugins: [
      {
        rules: {
          'ignore-body-max-line-length-for-release': ({type, body}) => {
            if (type === 'chore' && body.includes('release')) {
              return [0]; // Disable the rule for release commits
            }
            return [2, 'always', 100]; // Default rule for other commits
          }
        }
      }
    ],
    extends: [
      '@commitlint/config-conventional'
    ],
    rules: {
      'ignore-body-max-line-length-for-release': [2, 'always']
    },
  };