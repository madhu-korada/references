---
layout: default
title: Tmux
lang-ref: chapter1.0
---
### TMUX

#### MY CONFUGARATION

Followed this <https://www.hamvocke.com/blog/a-guide-to-customizing-your-tmux-conf/>.

bind key C-a

split panes using | and - instead of " and % 

switch panes using M-<arrow_key> (remember: M is for Meta, which is usually your Alt key)


##### Working with TMUX Windows

###### Rename the current window :- ```C-b ,``` 

###### Rename your existing session :- ```tmux rename-session -t 0 database```

###### Create a new session with the name “database” :- ```tmux new -s database```

###### Attach to tmux session 0 :- ```tmux attach -t 0``` or to tmux session database :- ```tmux attach -t database```

###### To detach your current session use :- ```C-b d```

###### To have tmux give you a choice which of your sessions you want to detach :- ```C-b D```

###### Create new window :- ```C-b c```

###### To switch to the next window :- ```C-b n```

###### To switch to the previous window (according to the order in your status bar) :- ```C-b p``` 

##### Working with TMUX Panes

###### Start new session :- ```tmux```

###### Splitting panes into a left and a right pane :- ```C-b %``` (This means you press Ctrl and b followed by the % key)

###### Splitting panes into a top and a bottom pane :- ```C-b "```

###### Navigating panes :- ```C-b <arrow key>```

###### Close panes :- ```exit``` or hit ```Ctrl-d```

###### Make a pane go full screen or back to it's previous size :- ```C-b z```


