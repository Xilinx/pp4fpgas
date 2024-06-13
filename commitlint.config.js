module.exports = {
  extends: ['@commitlint/config-conventional'],
  rules: {
    'body-max-line-length': [2, 'always', 100], // Enable the rule with a max length of 100 for all commits
  },
  plugins: [
    {
      rules: {
        'body-max-line-length': ({subject}) => {
          if (subject.startsWith('chore(release):')) {
            return [0]; // Disable the rule for release commits
          }
          return [2, 'always', 100]; // Enable the rule with a max length of 100 for other commits
        }
      },
    }
  ],
};