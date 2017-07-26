alias 42sh='sh ~/projects/autres/42FileChecker/42FileChecker.sh'
alias push='git push'
alias pull='git pull'
alias fast='git add --a && git commit -m "fast commit" && git push && echo "    \n\n\n\n//////// YOUHOU \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n\n\n"'
# Load Homebrew config script
#source $HOME/.brewconfig.zsh
alias brew='/usr/local/bin/brew'
alias node='/usr/local/bin/node'
alias npm='/usr/local/bin/npm'
#enables colorin the terminal bash shell export
export CLICOLOR=1

#sets up thecolor scheme for list export
export LSCOLORS=gxfxcxdxbxegedabagacad

#sets up theprompt color (currently a green similar to linux terminal)
#export PS1='\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;36m\]\w\[\033[00m\]\$ '
zstyle ':completion:*' list-colors "${(@s.:.)LS_COLORS}"
autoload -Uz compinit
#compinit

#enables colorfor iTerm
export TERM=xterm-color
#eval $(thefuck --alias)
set completion-ignore-case on

set MENU_COMPLETE 
