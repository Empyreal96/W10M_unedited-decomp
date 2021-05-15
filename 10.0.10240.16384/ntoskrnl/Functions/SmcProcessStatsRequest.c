// SmcProcessStatsRequest 
 
int __fastcall SmcProcessStatsRequest(int a1, unsigned int a2, int a3, _DWORD *a4, char a5)
{
  _BYTE *v9; // r0
  int v10; // r4
  char v12[1160]; // [sp+10h] [bp-488h] BYREF

  v9 = memset(v12, 0, 1128);
  if ( a3 != 1128 )
    return -1073741306;
  if ( a5 )
  {
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(v9);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    *(_BYTE *)(a2 + 1120) = *(_BYTE *)(a2 + 1120);
  }
  memmove((int)v12, a2, 0x468u);
  if ( v12[0] != 3 )
    return -1073741811;
  v10 = SmcGetCacheStats(a1, v12);
  if ( v10 >= 0 )
  {
    memmove(a2, (int)v12, 0x468u);
    *a4 = 1128;
  }
  return v10;
}
