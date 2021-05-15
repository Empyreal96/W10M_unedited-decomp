// KeFreeInitializationCode 
 
_DWORD *__fastcall KeFreeInitializationCode(int a1, int a2, int a3, unsigned int a4)
{
  _DWORD *result; // r0
  _DWORD *i; // r6
  int v6; // r3
  int *v7; // r2
  int *v8; // r4
  int v9; // t1
  _DWORD *v10; // r2
  unsigned int v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a4;
  result = (_DWORD *)MmStrongCodeGuaranteesEnforced();
  if ( !result )
  {
    result = (_DWORD *)RtlImageDirectoryEntryToData(0x400000, 1, 6, (int)v11);
    if ( result )
    {
      for ( i = &result[7 * (v11[0] / 0x1C)]; result < i; result += 7 )
      {
        v6 = result[3];
        if ( v6 == 10 )
        {
          v7 = (int *)(result[5] + 0x400000);
          v8 = &v7[result[4] >> 2];
          while ( v7 < v8 )
          {
            v9 = *v7++;
            if ( v9 == 1346849024 )
              return result;
          }
        }
        else if ( v6 == 13 )
        {
          v10 = (_DWORD *)(result[5] + 0x400000);
          if ( v10 != &v10[result[4] >> 2] && *v10 == 1346849024 )
            return result;
        }
      }
    }
    result = (_DWORD *)MmDiscardDriverSection(sub_5FDC6C);
  }
  return result;
}
