// AdtpBuildMultiSzStringListString 
 
int __fastcall AdtpBuildMultiSzStringListString(unsigned __int16 *a1, _DWORD *a2, _BYTE *a3)
{
  int result; // r0
  unsigned int v5; // r7
  _WORD *v6; // r0
  unsigned int v7; // [sp+0h] [bp-28h] BYREF
  int v8; // [sp+4h] [bp-24h]
  _BYTE *v9; // [sp+8h] [bp-20h]

  v7 = 0;
  v8 = 0;
  v9 = a3;
  if ( !a1 || !*((_DWORD *)a1 + 1) )
  {
    if ( a2 )
      AdtpEtwBuildDashString(a2, a2);
    return 0;
  }
  if ( *a1 >> 1 )
    return sub_552EB0();
  result = RtlULongLongToULong(2, 0, &v7);
  if ( result >= 0 )
  {
    v5 = v7;
    if ( v7 > 0xFFFF )
      return -1073741811;
    v6 = (_WORD *)ExAllocatePoolWithTag(1, v7);
    if ( !v6 )
      return -1073741801;
    *v9 = 1;
    if ( v8 )
      qmemcpy(v6, "\r\n\t\t", 8);
    *v6 = 0;
    *a2 = v6;
    a2[1] = 0;
    a2[2] = v5;
    a2[3] = 0;
    return 0;
  }
  return result;
}
