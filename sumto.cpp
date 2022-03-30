int sumTo(int sumto)
{
    if (sumto <= 0) {
        return 0;
    }
    else if (sumto == 1) {
        return 1;
    }
    else {
        return sumTo(sumto - 1) + sumto; 
    }
}