// WheapCountBadPageExtents 
 
int __fastcall WheapCountBadPageExtents(__int64 *a1, unsigned int a2)
{
  int result; // r0
  __int64 v4; // r4
  __int64 *v5; // r2
  unsigned int v6; // r1
  __int64 v7; // r6

  result = 0;
  if ( a2 )
  {
    v4 = *a1;
    result = 1;
    if ( a2 > 1 )
    {
      v5 = a1 + 1;
      v6 = a2 - 1;
      do
      {
        v7 = *v5;
        if ( *v5 > (unsigned __int64)(v4 + 1) )
          ++result;
        ++v5;
        --v6;
        v4 = v7;
      }
      while ( v6 );
    }
  }
  return result;
}
