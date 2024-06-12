module.exports = {
  rules: {
    'body-max-line-length': ({body}) => {
      if (body && body.startsWith('chore(release):')) {
        return [0]; // Disable the rule for release commits
      }
      return [2, 'always', 100]; // Default rule for other commits
    }
  },
};