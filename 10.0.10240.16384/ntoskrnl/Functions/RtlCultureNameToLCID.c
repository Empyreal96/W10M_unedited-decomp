// RtlCultureNameToLCID 
 
BOOL __fastcall RtlCultureNameToLCID(unsigned __int16 *a1, int *a2)
{
  BOOL result; // r0
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r0
  unsigned int v8; // r2
  int v9; // r0
  _BYTE v10[184]; // [sp-4h] [bp-B8h] BYREF

  result = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v5 = *a1;
      if ( *a1 )
      {
        v6 = *((_DWORD *)a1 + 1);
        if ( v6 )
        {
          if ( (int)(v5 + 2) <= 85 )
          {
            v7 = memmove((int)v10, v6, v5);
            v8 = 2 * (v5 >> 1);
            if ( v8 >= 0xAA )
              sub_80BFE4(v7);
            *(_WORD *)&v10[v8] = 0;
            v9 = DownLevelLanguageNameToLangID((int)v10, 2);
            *a2 = v9;
            result = v9 != 0;
          }
        }
      }
    }
  }
  return result;
}
