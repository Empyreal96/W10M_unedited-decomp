// _SysCtxRegOpenCurrentUserKey 
 
int __fastcall SysCtxRegOpenCurrentUserKey(int a1)
{
  int v2; // r4
  int v4; // [sp+8h] [bp-20h] BYREF
  unsigned __int16 v5; // [sp+10h] [bp-18h] BYREF
  _BYTE v6[6]; // [sp+12h] [bp-16h]

  v4 = 0;
  v5 = 0;
  *(_DWORD *)v6 = 0;
  *(_WORD *)&v6[4] = 0;
  v2 = RtlFormatCurrentUserKeyPath(&v5);
  if ( v2 >= 0 )
  {
    v2 = SysCtxGetCachedContextBaseKey(a1, 3, &v4);
    if ( v2 >= 0 )
    {
      if ( RtlPrefixUnicodeString((unsigned __int16 *)&dword_41E1E8, &v5, 1) )
        v2 = SysCtxRegOpenKey(a1, v4, *(_DWORD *)&v6[2] + 30, 0, 0x2000000);
      else
        v2 = -1073741811;
    }
  }
  RtlFreeAnsiString(&v5);
  return v2;
}
