import hashlib

def first_five_zero(hexstring):
    for i in range(5):
        if hexstring[i] != '0':
            return False
    return True


def main():
    i = 0
    while i < 1000000:
        my_string = "iwrupvqb" + str(i)
        m = hashlib.new('md5', bytes(my_string, 'utf8'))
        tmp = m.hexdigest()
        if first_five_zero(tmp):
            print("{} produces {}".format(my_string, tmp))
            break
        i += 1

if __name__ == "__main__":
    main()
