// RtlUnicodeStringCbCopyStringN 
 
int __fastcall RtlUnicodeStringCbCopyStringN(unsigned __int16 *a1, _WORD *a2, unsigned int a3)
{
  unsigned int v5; // r1
  unsigned int v6; // r6
  int result; // r0
  int v8; // lr
  unsigned int v9; // r4
  unsigned int v10; // r2
  __int16 v11; // r1
  int v12; // r4

  v5 = *a1;
  v6 = 0;
  result = 0;
  v8 = 0;
  if ( (v5 & 1) != 0 )
    return -1073741811;
  v9 = a1[1];
  if ( (v9 & 1) != 0 || v5 > v9 || a1[1] == 0xFFFF )
    return -1073741811;
  if ( !*((_DWORD *)a1 + 1) && (v5 || a1[1]) )
  {
    result = -1073741811;
  }
  else
  {
    v8 = *((_DWORD *)a1 + 1);
    v6 = v9 >> 1;
  }
  if ( result >= 0 )
  {
    v10 = a3 >> 1;
    v11 = 0;
    if ( v10 <= 0x7FFF )
    {
      result = 0;
      v11 = 0;
      if ( !v6 )
        goto LABEL_19;
      v12 = v8 - (_DWORD)a2;
      do
      {
        if ( !v10 )
          break;
        if ( !*a2 )
          break;
        *(_WORD *)((char *)a2 + v12) = *a2;
        --v6;
        ++a2;
        --v10;
        ++v11;
      }
      while ( v6 );
      if ( !v6 )
      {
LABEL_19:
        if ( v10 )
        {
          if ( *a2 )
            result = -2147483643;
        }
      }
    }
    else
    {
      result = -1073741811;
    }
    *a1 = 2 * v11;
  }
  return result;
}
