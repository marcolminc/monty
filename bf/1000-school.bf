++++++++++          Set Cell 0 to 10 (used as a loop counter)
[                   Start loop
 > ++++++++         Cell 1: Add 8 (will become 80 for 'S')
 > ++++++++++       Cell 2: Add 10 (will become 100 for 'c', 'h', 'o', 'l')
 > +                Cell 3: Add 1 (will become 10 for New Line)
 <<< -              Return to Cell 0 and decrement
]                   End loop

> +++ .             Cell 1 is 80; add 3 to get 83 ('S') and print
> - .               Cell 2 is 100; subtract 1 to get 99 ('c') and print
+++++ .             Add 5 to get 104 ('h') and print
+++++++ .           Add 7 to get 111 ('o') and print
.                   Print 111 ('o') again
--- .               Subtract 3 to get 108 ('l') and print
> .                 Move to Cell 3 (10) and print (New Line)
