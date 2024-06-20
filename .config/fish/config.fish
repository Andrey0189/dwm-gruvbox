if status is-interactive
    # Commands to run in interactive sessions can go here
    alias v nvim
    alias sv "sudo nvim"
    alias dwmconf "nvim ~/build/dwm/config.h"
    alias ytaudio "yt-dlp -x --audio-format mp3"
end

function fish_greeting
end

function fish_prompt -d "Write out the prompt"
    # This shows up as USER@HOST /home/user/ >, with the directory colored
    # $USER and $hostname are set by fish, so you can just use them
    # instead of using `whoami` and `hostname`
    printf '%s%s%s@%s%s %s%s%s $ ' \
        (set_color $fish_color_quote) $USER \
        (set_color normal) \
        (set_color $fish_color_comment) $hostname \
        (set_color $fish_color_cwd) (prompt_pwd) (set_color normal)
end

starship init fish | source
