// CmpCompareCompressedName 
 
int __fastcall CmpCompareCompressedName(unsigned __int16 *a1, unsigned __int8 *a2, unsigned __int16 a3, char a4)
{
  unsigned __int16 *v4; // r7
  int v6; // r8
  int v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // t1
  unsigned int v10; // r4
  unsigned int v11; // t1
  int v12; // r10
  int result; // r0
  char v14; // [sp+0h] [bp-20h]

  v4 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v14 = a4;
  v6 = *a1 >> 1;
  v7 = a3;
  if ( v6 )
  {
    while ( v7 )
    {
      v9 = *v4++;
      v8 = v9;
      v11 = *a2++;
      v10 = v11;
      if ( v8 != v11 )
      {
        if ( (a4 & 1) == 0 && v8 >= 0x61 )
        {
          if ( v8 > 0x7A )
          {
            LOWORD(v8) = RtlUpcaseUnicodeChar(v8);
            a4 = v14;
          }
          else
          {
            LOWORD(v8) = v8 - 32;
          }
        }
        v12 = (unsigned __int16)v8;
        if ( (a4 & 2) == 0 && v10 >= 0x61 )
        {
          if ( v10 > 0x7A )
            LOWORD(v10) = RtlUpcaseUnicodeChar(v10);
          else
            LOWORD(v10) = v10 - 32;
        }
        result = v12 - (unsigned __int16)v10;
        if ( v12 != (unsigned __int16)v10 )
          return result;
      }
      v6 = (unsigned __int16)(v6 - 1);
      v7 = (unsigned __int16)(v7 - 1);
      if ( !v6 )
        return v6 - v7;
      a4 = v14;
    }
  }
  return v6 - v7;
}
