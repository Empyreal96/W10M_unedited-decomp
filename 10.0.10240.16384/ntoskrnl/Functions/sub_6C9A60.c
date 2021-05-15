// sub_6C9A60 
 
int sub_6C9A60(_WORD *a1, int a2, _WORD *a3, ...)
{
  va_list v3; // lr
  int v4; // r6
  int v6; // r2
  int v7; // r7
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // t1
  int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // t1
  int *v14; // r3
  _WORD *varg_r2; // [sp+20h] [bp+10h]
  va_list varg_r3; // [sp+24h] [bp+14h] BYREF

  va_start(varg_r3, a3);
  va_copy(v3, varg_r3);
  v4 = 0;
  while ( 1 )
  {
    v6 = (unsigned __int16)*a3;
    if ( !*a3 )
      break;
    if ( v6 != 37 || (++a3, v6 = (unsigned __int16)*a3, v6 == 37) )
    {
      if ( !a2 || (unsigned __int16)*a1 != v6 )
        return -1;
      ++a1;
      --a2;
      ++a3;
    }
    else
    {
      v7 = 0;
      v8 = 0;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v10 = (unsigned __int16)*a3++;
            v9 = v10;
            if ( v10 > 0x39 || v9 < 0x30 )
              break;
            v8 = v9 + 10 * v8 - 48;
          }
          if ( v9 != 108 )
            break;
          ++v7;
        }
      }
      while ( v9 != 120 && v9 != 88 );
      v11 = 0;
      for ( varg_r2 = a3; v8; --a2 )
      {
        --v8;
        if ( !a2 )
          return -1;
        v13 = (unsigned __int16)*a1++;
        v12 = v13;
        if ( v13 > 0x39 || v12 < 0x30 )
        {
          if ( v12 < 0x61 || v12 > 0x66 )
          {
            if ( v12 < 0x41 || v12 > 0x46 )
              return -1;
            v11 = v12 + 16 * v11 - 55;
          }
          else
          {
            v11 = v12 + 16 * v11 - 87;
          }
        }
        else
        {
          v11 = v12 + 16 * v11 - 48;
        }
      }
      v3 = (va_list)((char *)v3 + (-(int)v3 & 3) + 4);
      v14 = (int *)*(v3 - 1);
      if ( v7 )
        *v14 = v11;
      else
        *(_WORD *)v14 = v11;
      ++v4;
    }
  }
  if ( a2 && *a1 )
    v4 = -1;
  return v4;
}
