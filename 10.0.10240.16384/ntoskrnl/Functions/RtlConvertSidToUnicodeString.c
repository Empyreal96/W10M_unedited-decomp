// RtlConvertSidToUnicodeString 
 
int __fastcall RtlConvertSidToUnicodeString(unsigned __int16 *a1, _BYTE *a2, int a3)
{
  char *v6; // r4
  int result; // r0
  unsigned int v8; // r6
  unsigned int v9; // r2
  int v10; // r2
  int v11; // r1
  int v12; // [sp+0h] [bp-228h] BYREF
  _WORD *v13; // [sp+4h] [bp-224h]
  _WORD v14[4]; // [sp+8h] [bp-220h] BYREF
  char v15[4]; // [sp+10h] [bp-218h] BYREF
  char v16[496]; // [sp+14h] [bp-214h] BYREF
  char v17[2]; // [sp+204h] [bp-24h] BYREF
  char v18[34]; // [sp+206h] [bp-22h] BYREF

  if ( RtlValidSid(a2, a2) != 1 || *a2 != 1 )
    return sub_7C3E1C();
  wcscpy_s((char *)v14, 256, (char *)L"S-1-");
  v6 = v15;
  if ( a2[2] || a2[3] )
  {
    wcscat_s(v14, 256, (char *)L"0x");
    v6 = v16;
    v10 = (unsigned __int8)a2[4];
    v13 = (_WORD *)((unsigned __int8)a2[3] + ((unsigned __int8)a2[2] << 8));
    v12 = (unsigned __int8)a2[7] + (((unsigned __int8)a2[6] + (((unsigned __int8)a2[5] + (v10 << 8)) << 8)) << 8);
    result = ((int (__fastcall *)(int *, int, int, char *))RtlLargeIntegerToUnicode)(&v12, v11, 250, v16);
  }
  else
  {
    result = RtlIntegerToUnicode(
               (unsigned __int8)a2[7]
             + (((unsigned __int8)a2[6] + (((unsigned __int8)a2[5] + ((unsigned __int8)a2[4] << 8)) << 8)) << 8),
               10,
               252,
               v15);
  }
  if ( result >= 0 )
  {
    v8 = 0;
    if ( a2[1] )
    {
      while ( 1 )
      {
        for ( ; v6 < v17; v6 += 2 )
        {
          if ( !*(_WORD *)v6 )
            break;
        }
        *(_WORD *)v6 = 45;
        v6 += 2;
        result = RtlIntegerToUnicode(*(_DWORD *)&a2[4 * v8 + 8], 10, 256 - ((v6 - (char *)v14) >> 1), v6);
        if ( result < 0 )
          break;
        v8 = (unsigned __int8)(v8 + 1);
        if ( v8 >= (unsigned __int8)a2[1] )
          goto LABEL_13;
      }
    }
    else
    {
LABEL_13:
      if ( a3 )
      {
        if ( !RtlCreateUnicodeString(a1, v14) )
          return -1073741801;
      }
      else
      {
        for ( ; v6 < v18; v6 += 2 )
        {
          if ( !*(_WORD *)v6 )
            break;
        }
        v9 = 2 * ((v6 - (char *)v14) >> 1);
        if ( v9 >= a1[1] )
          return -2147483643;
        HIWORD(v12) = v9 + 2;
        v13 = v14;
        LOWORD(v12) = 2 * ((v6 - (char *)v14) >> 1);
        RtlCopyUnicodeString(a1, (unsigned __int16 *)&v12);
      }
      result = 0;
    }
  }
  return result;
}
