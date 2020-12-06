syntax on
set number
set ignorecase
set mouse=a

set tabstop=4

vnoremap <C-c> "+y
map <C-v> "+P

autocmd bufnewfile *.cpp so /mnt/c/Users/Anass/Desktop/work/handmade/misc/header_template.txt
autocmd bufnewfile *.cpp exe "1," . 8 . "g/File Name:/s//File Name: " .expand("%")
autocmd bufnewfile *.cpp exe "1," . 8 . "g/Creation Date:/s//Creation Date: " .strftime("%c")
autocmd Bufwritepre,filewritepre *.cpp execute "normal ma"
autocmd Bufwritepre,filewritepre *.cpp exe "1," . 8 . "g/Last Modified:.*/s//Last Modified: " .strftime("%c")
autocmd bufwritepost,filewritepost *.cpp execute "normal `a"
