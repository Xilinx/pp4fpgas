// release.config.js

module.exports = {
  branches: ['mp-hls_book_update_effort'],
  repositoryUrl: 'git@gitenterprise.xilinx.com:mpettigr/pp4fpgas.git',
  plugins: [
    '@semantic-release/commit-analyzer',
    '@semantic-release/release-notes-generator',
    '@semantic-release/changelog',
    '@semantic-release/git'
  ],
  verifyConditions: [
    '@semantic-release/changelog',
    '@semantic-release/git'
  ],
  analyzeCommits: {
    preset: 'conventionalcommits',
    ignore: (commit) => commit.includes('chore(release)')
  }
};