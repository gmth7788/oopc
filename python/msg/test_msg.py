import libmsg



# python3 test_msg.py


def test_message():
    '''
    
    >>> libmsg.string_s_asterisk("abcd的撒肥k3j")
    (0, 'success')

    b = bytes("ff ef ab 34 89 aa")
    >>> libmsg.string_y_asterisk(b)
    
    '''
    print(libmsg.string_s_asterisk("abcd的撒肥k3j"))
    
    b = bytes.fromhex("2ef0f1f2324084385dfda102")
    print(libmsg.string_y_asterisk(b))


if __name__=='__main__':
#     import doctest
#     doctest.testmod(verbose=True)
    
    test_message()






