// MiCheckSecuredVad 
 
int __fastcall MiCheckSecuredVad(_DWORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r1
  int result; // r0
  unsigned int v10; // r5
  _DWORD *i; // r4
  int v12; // r2
  int v13; // r3
  int v15; // r2
  unsigned int v16; // [sp+0h] [bp-20h]

  v5 = a2 + a3 - 1;
  result = 0;
  v16 = v5;
  if ( a4 < 0x55 )
  {
    if ( (a1[7] & 7) == 2 )
      return sub_7F644C(0);
    v10 = a4;
  }
  else
  {
    v10 = 0;
  }
  for ( i = (_DWORD *)a1[9]; i; i = (_DWORD *)*i )
  {
    if ( i[1] == 2 && a2 <= i[3] )
    {
      v12 = i[2];
      if ( v5 >= (v12 & 0xFFFFF000) )
      {
        if ( a4 >= 0x55 && (v12 & 8) != 0 )
          return -1073741755;
        if ( (v12 & 4) != 0 )
        {
          if ( a4 < 0x55 )
          {
            v15 = a1[7];
            if ( (v15 & 7) == 2 )
            {
              result = MiCheckSecuredImageVad(a1, a2, a3, v10);
              if ( result < 0 )
                return result;
              v5 = v16;
            }
            else if ( (unsigned __int8)v15 >> 3 != v10
                   || a1[3] == 524256
                   && (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 736) & 1) == 0 )
            {
              return -1073741755;
            }
          }
        }
        else
        {
          if ( (v10 & 0xFFFFFFF8) == 16 )
            return -1073741755;
          v13 = MiReadWrite[v10 & 7];
          if ( (v12 & 1) != 0 ? v13 < 10 : v13 < 11 )
            return -1073741755;
        }
      }
    }
  }
  return result;
}
