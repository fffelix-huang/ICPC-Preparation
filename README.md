# ICPC-Preparation

## :information_source: Steps to render codebook.pdf

1. Add files/directories to be rendered in `includes.txt`. (Indentation isn't necessary)
2. Call `python3 TEXexporter.py Codebook` in command line. (Change `Codebook` to your code directory) This will output the result to `main.tex`
3. Paste the result in `main.tex` to overleaf, and download the rendered PDF file.

## :warning: Hints/Warnings

1. Don't modify `settings.txt`.
2. To add a file in `includes.txt`, the latest directory should be it's parent directory.
3. Filenames in`includes.txt` are case sensative.
4. $LaTeX$ are available in the code comments when rendered to PDF.

# LICENSE

See `LICENSE.md`
