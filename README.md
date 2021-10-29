Code Limitations:

1. Does not support for loops and if statements that do not use curly braces. The following code:
        
        if (w = x)
            y = z;

    Will be indented improperly resulting in:

        if (w = x)
        y = z;

2. Does not indent comments/commented out regions ( // and /* */ ) that may have curly braces within them.

3. Curly braces within strings and char will be improperly indented. The following code:

        if (w = x) {
            y = "{{";
            z = "123";
        }

    Will be indented improperly resulting in:

        if (w = x) {
            y = "{{";
                    z = "123";
                }
