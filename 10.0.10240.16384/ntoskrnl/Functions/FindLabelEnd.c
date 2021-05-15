// FindLabelEnd 
 
unsigned __int16 *__fastcall FindLabelEnd(unsigned __int16 *a1, unsigned int a2, int a3)
{
  unsigned __int16 *v3; // r2
  int v4; // t1
  int v5; // t1

  if ( a3 )
  {
    v3 = (unsigned __int16 *)(a2 - 2);
    while ( v3 >= a1 )
    {
      v4 = *v3--;
      if ( v4 == 64 )
        return v3 + 1;
    }
  }
  else
  {
    while ( (unsigned int)a1 < a2 )
    {
      v5 = *a1++;
      if ( v5 == 46 )
        return a1 - 1;
    }
  }
  return (unsigned __int16 *)a2;
}
