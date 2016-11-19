"My vimrc"
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'

syntax on

" [3]
" " Several plugins to help work with Tmux
Plugin 'christoomey/vim-tmux-navigator'
Plugin 'christoomey/vim-tmux-runner.git'
Plugin 'christoomey/vim-run-interactive'

" whitespace plugin
Plugin 'ntpeters/vim-better-whitespace'

let g:airline#extensions#tabline#enabled = 1
" Show just the filename
let g:airline#extensions#tabline#fnamemod = ':t'"

Plugin 'jiangmiao/auto-pairs' "MANY features, but mostly closes ([{' etc
Plugin 'vim-scripts/HTML-AutoCloseTag' "close tags after >
Plugin 'vim-scripts/tComment' "Comment easily with gcc
Plugin 'tpope/vim-repeat' "allow plugins to utilize . command
Plugin 'vim-scripts/matchit.zip' " % also matches HTML tags / words / etc

set laststatus=2
set ttimeoutlen=50

let g:airline#extensions#tabline#enabled = 1


Plugin 'mattn/webapi-vim' | Plugin 'mattn/gist-vim'
Plugin 'vimwiki/vimwiki'
Plugin 'scrooloose/nerdtree'
Plugin 'scrooloose/syntastic'
Plugin 'tpope/vim-fugitive'
Plugin 'bling/vim-airline'
Plugin 'kien/ctrlp.vim'
set number
set ts=2
set autoindent
noremap <S-Tab> <Tab>
set expandtab
set shiftwidth=2
set showmatch
set backspace=2
map <silent> <leader>V :source ~/.vimrc<CR>:filetype detect<CR>:exe ":echo 'vimrc reloaded'"<CR>
set hlsearch
set smartcase		" Do smart case matching
set mouse=a		" Enable mouse usage (all modes)
source ~/.vim/cscope_maps.vim

let &colorcolumn=91
xnoremap p pgvy

call vundle#end()
filetype plugin indent on
map <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
map <F2> :w<cr> :!pylint --rcfile=/home1/local64/vfgithook/config/vfpylintrc %<cr>
let g:syntastic_python_checkers = ['pylint']
let g:syntastic_python_pylint_args = '--rcfile=/home1/local64/vfgithook/config/vfpylintrc'
let g:syntastic_always_populate_loc_list = 1
