// SmProcessGlobalCacheStatsRequest 
 
int __fastcall SmProcessGlobalCacheStatsRequest(unsigned int a1, int a2, _DWORD *a3, char a4)
{
  int v4; // r9
  _BYTE *v8; // r0
  int v9; // r4
  _DWORD v11[234]; // [sp+8h] [bp-3A8h] BYREF

  v4 = a4;
  v8 = memset(v11, 0, 904);
  if ( a2 != 904 )
    return -1073741306;
  if ( v4 )
  {
    if ( (a1 & 7) != 0 )
      ExRaiseDatatypeMisalignment(v8);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 896) = *(_BYTE *)(a1 + 896);
  }
  memmove((int)v11, a1, 0x388u);
  if ( LOBYTE(v11[0]) != 5 || (v11[0] & 0xFFFFFF00) != 0 )
    return -1073741811;
  SmpCacheStatsCopy(SmGlobals, &v11[2], &dword_636EA8);
  v9 = 0;
  memmove(a1, (int)v11, 0x388u);
  *a3 = 904;
  return v9;
}
