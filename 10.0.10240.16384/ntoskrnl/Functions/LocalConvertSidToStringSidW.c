// LocalConvertSidToStringSidW 
 
int __fastcall LocalConvertSidToStringSidW(_BYTE *a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  _WORD *v6; // r0
  __int64 v7; // [sp+0h] [bp-10h] BYREF
  int v8; // [sp+8h] [bp-8h]

  v8 = a4;
  v7 = 0i64;
  if ( !a1 || !a2 )
    return -1073741811;
  result = RtlConvertSidToUnicodeString((unsigned __int16 *)&v7, a1, 1);
  if ( result >= 0 )
  {
    v6 = (_WORD *)SddlpAlloc((unsigned __int16)v7 + 2);
    *a2 = v6;
    if ( v6 )
    {
      result = RtlStringCbCopyNW(v6, (unsigned __int16)v7 + 2, SHIDWORD(v7), (unsigned __int16)v7);
      if ( result >= 0 )
      {
        RtlFreeAnsiString(&v7);
        result = 0;
      }
    }
    else
    {
      RtlFreeAnsiString(&v7);
      result = -1073741801;
    }
  }
  return result;
}
