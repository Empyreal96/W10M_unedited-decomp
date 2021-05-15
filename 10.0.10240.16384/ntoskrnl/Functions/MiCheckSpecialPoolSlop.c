// MiCheckSpecialPoolSlop 
 
_DWORD *__fastcall MiCheckSpecialPoolSlop(_DWORD *result, unsigned int a2, int a3)
{
  int v4; // r5
  int v6; // r1
  unsigned __int8 *v7; // r2
  int v8; // t1

  v4 = *(unsigned __int8 *)(a3 + 2);
  while ( (unsigned int)result < a2 )
  {
    if ( *result != (v4 | (v4 << 8) | ((v4 | (v4 << 8)) << 16)) )
    {
      v6 = 0;
      v7 = 0;
      if ( (unsigned int)result < a2 )
      {
        do
        {
          v8 = *(unsigned __int8 *)result;
          result = (_DWORD *)((char *)result + 1);
          if ( v8 != v4 )
          {
            if ( ++v6 != 1 )
              goto LABEL_14;
            v7 = (unsigned __int8 *)result - 1;
          }
        }
        while ( (unsigned int)result < a2 );
        if ( v6 == 1 && (((*v7 ^ v4) + 255) & (*v7 ^ v4)) == 0 )
          KeBugCheckEx(193, a2, (int)v7, *(_DWORD *)a3, 50);
      }
LABEL_14:
      KeBugCheckEx(193, a2, (int)v7, *(_DWORD *)a3, 35);
    }
    ++result;
  }
  return result;
}
