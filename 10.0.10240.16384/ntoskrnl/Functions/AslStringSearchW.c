// AslStringSearchW 
 
_WORD *__fastcall AslStringSearchW(_WORD *a1, unsigned int a2, unsigned __int16 *a3, unsigned int a4)
{
  unsigned __int16 *v5; // r3
  _WORD *result; // r0
  unsigned int v8; // r4
  _WORD *i; // r7
  unsigned int v10; // lr
  unsigned int v11; // r6
  unsigned __int16 *v12; // r10
  _WORD *v13; // r8
  int v14; // r2
  int v15; // t1
  int v16; // t1

  v5 = a3;
  result = 0;
  if ( a2 && a4 <= a2 )
  {
    v8 = 0;
    for ( i = a1; ; ++i )
    {
      v10 = 0;
      v11 = v8;
      if ( a4 )
      {
        v12 = v5;
        v13 = i;
        while ( v11 < a2 )
        {
          if ( !*v13 )
          {
            ++v11;
            ++v13;
            if ( v11 >= a2 )
              return result;
          }
          v15 = *v12++;
          v14 = v15;
          v16 = (unsigned __int16)*v13++;
          if ( v16 == v14 )
          {
            ++v10;
            ++v11;
            if ( v10 < a4 )
              continue;
          }
          break;
        }
      }
      if ( v10 == a4 )
        break;
      ++v8;
      v5 = a3;
      if ( v8 + a4 > a2 )
        return result;
    }
    result = &a1[v8];
  }
  return result;
}
