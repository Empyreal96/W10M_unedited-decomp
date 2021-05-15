// -RtlStringCbCopyUnicodeString@@YAJPAGIPBU_UNICODE_STRING@@@Z 
 
int __fastcall RtlStringCbCopyUnicodeString(unsigned __int16 *a1, unsigned int a2, const struct _UNICODE_STRING *a3)
{
  int result; // r0
  unsigned int v5; // r5
  int v6; // r2
  int v7; // r1
  int v8; // [sp+8h] [bp-18h] BYREF
  int v9[5]; // [sp+Ch] [bp-14h] BYREF

  result = 0;
  v5 = a2 >> 1;
  if ( !(a2 >> 1) || v5 > 0x7FFF )
    result = -1073741811;
  if ( result >= 0 )
  {
    result = sub_5B3D20(a3, v9, &v8);
    if ( result >= 0 )
    {
      result = 0;
      if ( !v5 )
        goto LABEL_11;
      v6 = v8 - v5;
      v7 = v9[0] - (_DWORD)a1;
      do
      {
        if ( !(v6 + v5) )
          break;
        *a1 = *(unsigned __int16 *)((char *)a1 + v7);
        ++a1;
        --v5;
      }
      while ( v5 );
      if ( !v5 )
      {
LABEL_11:
        --a1;
        result = -2147483643;
      }
    }
    *a1 = 0;
  }
  return result;
}
