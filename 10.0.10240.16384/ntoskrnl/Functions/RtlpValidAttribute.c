// RtlpValidAttribute 
 
int __fastcall RtlpValidAttribute(int a1, int a2, int a3, int a4)
{
  unsigned __int16 *v5; // r0
  unsigned int v6; // r2
  int v7; // r3
  unsigned int v8; // r0
  _DWORD *v9; // r1
  int v10; // r3
  int v12; // r0
  _QWORD *j; // r1
  int v14; // r0
  _DWORD *i; // r1
  int v16; // r1
  _DWORD *v17; // r0
  int v19[4]; // [sp+0h] [bp-10h] BYREF

  v19[1] = a4;
  v19[0] = 0;
  if ( !a1 )
    return 0;
  v5 = *(unsigned __int16 **)a1;
  if ( !*(_DWORD *)a1 )
    return 0;
  if ( RtlStringCchLengthW(v5, 0xFFFFu, v19) < 0 )
    return 0;
  if ( !v19[0] )
    return 0;
  if ( *(_WORD *)(a1 + 6) )
    return 0;
  if ( (*(_DWORD *)(a1 + 8) & 0xFFC0) != 0 )
    return 0;
  v6 = *(_DWORD *)(a1 + 12);
  if ( !v6 )
    return 0;
  if ( !*(_DWORD *)(a1 + 16) )
    return 0;
  v7 = *(unsigned __int16 *)(a1 + 4);
  if ( !*(_WORD *)(a1 + 4) )
    return 0;
  if ( *(unsigned __int16 *)(a1 + 4) > 2u )
  {
    switch ( v7 )
    {
      case 3:
        v16 = 0;
        v17 = *(_DWORD **)(a1 + 16);
        while ( *v17++ )
        {
          if ( ++v16 >= v6 )
            return 1;
        }
        break;
      case 5:
        v14 = 0;
        for ( i = *(_DWORD **)(a1 + 16); *i && i[1]; i += 2 )
        {
          if ( ++v14 >= v6 )
            return 1;
        }
        break;
      case 6:
        v12 = 0;
        for ( j = *(_QWORD **)(a1 + 16); !*j || *j == 1i64; ++j )
        {
          if ( ++v12 >= v6 )
            return 1;
        }
        break;
      case 16:
        v8 = 0;
        v9 = *(_DWORD **)(a1 + 16);
        do
        {
          v10 = v9[1];
          if ( *v9 )
          {
            if ( !v10 )
              return 0;
          }
          else if ( v10 )
          {
            return 0;
          }
          ++v8;
          v9 += 2;
        }
        while ( v8 < v6 );
        return 1;
    }
    return 0;
  }
  return 1;
}
