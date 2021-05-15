// CmpCompareUnicodeString 
 
int __fastcall CmpCompareUnicodeString(unsigned __int16 *a1, unsigned __int16 *a2, char a3)
{
  unsigned __int16 *v3; // r10
  int v5; // r7
  unsigned __int16 *v6; // r2
  int v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // t1
  unsigned int v10; // r4
  unsigned int v11; // t1
  int v12; // r6
  int result; // r0
  unsigned __int16 *v14; // [sp+0h] [bp-20h]

  v3 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v5 = *a1 >> 1;
  v6 = (unsigned __int16 *)*((_DWORD *)a2 + 1);
  v7 = *a2 >> 1;
  if ( v5 )
  {
    while ( v7 )
    {
      v9 = *v3++;
      v8 = v9;
      v11 = *v6++;
      v10 = v11;
      v14 = v6;
      if ( v8 != v11 )
      {
        if ( (a3 & 1) == 0 && v8 >= 0x61 )
        {
          if ( v8 <= 0x7A )
            LOWORD(v8) = v8 - 32;
          else
            LOWORD(v8) = RtlUpcaseUnicodeChar(v8);
        }
        v12 = (unsigned __int16)v8;
        if ( (a3 & 2) == 0 && v10 >= 0x61 )
        {
          if ( v10 <= 0x7A )
            LOWORD(v10) = v10 - 32;
          else
            LOWORD(v10) = RtlUpcaseUnicodeChar(v10);
        }
        result = v12 - (unsigned __int16)v10;
        if ( v12 != (unsigned __int16)v10 )
          return result;
        v6 = v14;
      }
      v5 = (unsigned __int16)(v5 - 1);
      v7 = (unsigned __int16)(v7 - 1);
      if ( !v5 )
        return v5 - v7;
    }
  }
  return v5 - v7;
}
