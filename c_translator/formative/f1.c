int x = 0;

void recFunc(int a){
    // Tests: RECURSION OOOOooOOO
    if(a == 0)
        return;
    else
    {
        x = x+1;
        recFunc(a-1);
    }
}

int main()
{
    //Tests recursive functions
    recFunc(5);
    return x; 
}