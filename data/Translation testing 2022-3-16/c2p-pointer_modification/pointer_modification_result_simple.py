def @ gen ( ) :
    input = int ( raw_input ( ) )
    print ( "Please insert an array size: " )
    input = input * 2 + 1
    ptr = [ ]
    for i in range ( input ) :
        ptr.append ( i * 2 + 1 )
    print ( "Initialized values" )
    for i in range ( input ) :
        print ( ptr [ i ] )
    print ( "Done" )


# Translator does not familiar with c++'s input style.

# Translator does understand it is trying to create an array + insert element into the array + print out the array.
