x = 0

def recFunc(a):
    global x
    if(a == 0):
        return
    else:
        x = x+1
        recFunc(a-1)

def main():
    global x
    recFunc(5)
    return x 

# Boilerplate
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)