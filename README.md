# WebAdvisorExtractor

A small command line program that breaks up courselists from University of Guelph's website and exports it out as a CSV.

## Usage

Navigate to the University of Guelph's WebAdvisor, select "Students", then "Search for Sections".

Go down to the bottom and select courses at Location "G - Guelph" and Academic Level "UG - Undergraduate" or whichever options you want.

Highlight the whole page by pressing Ctrl-A then press Ctrl-C or right click Copy to copy the contents, then paste it into a text document and save it.

Run the program like below:

`./WebAdvisorExtractor input.txt [-csv|-h]`

Where `input.txt` is the input file you just created, and optional flags below:

-csv                Format output to CSV specification.
-d                  Place headers on top of output.
-h, --help          Show help.

## Motivation

I need to be able to populate an upcoming side project of mine (that may or may not come to fruition :P) with a bunch of test course information data, and I thought what better way to do this than to scrape the text of University of Guelph's WebAdvisor site for the information? The information is then bundled up into a CSV file that I can then plop in to my database for consumption by the application.

## Future Additions
- Integration into other university websites
- Configurability of data ordering and export file formats
