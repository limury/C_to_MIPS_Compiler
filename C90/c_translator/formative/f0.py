
def logicFunc(a, b, c, d):
    return a+b - c*d + 1


def loopFunc(a,b):
    while b < 5:
        if(b==10):
            a = 50
        else:
            b = b + 1
    return a


def main():
    var = 0
    result = logicFunc(var,var,var,var) and loopFunc(var,0)
    return logicFunc(var, var, 1, 1) or result

# Boilerplate
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)

