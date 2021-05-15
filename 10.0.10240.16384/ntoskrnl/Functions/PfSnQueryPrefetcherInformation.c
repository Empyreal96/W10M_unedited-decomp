// PfSnQueryPrefetcherInformation 
 
int __fastcall PfSnQueryPrefetcherInformation(int a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r8
  unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v16; // [sp+4h] [bp-1D4h]
  int v17; // [sp+10h] [bp-1C8h]
  unsigned int v18; // [sp+14h] [bp-1C4h]
  int v19; // [sp+18h] [bp-1C0h]
  _DWORD _20[115]; // [sp+20h] [bp-1B8h] BYREF
  int varg_r3; // [sp+1ECh] [bp+14h]

  _20[112] = a1;
  _20[113] = a2;
  _20[114] = a3;
  varg_r3 = a4;
  v16 = (char)a4;
  LOBYTE(varg_r3) = a4;
  if ( !SeSinglePrivilegeCheck(SeProfileSingleProcessPrivilege, dword_922B94, (char)a4, (char)a4) )
    return -1073741790;
  if ( a3 == 20 )
  {
    v17 = a2[2];
    v18 = a2[3];
    v19 = a2[4];
    if ( *a2 != 1 || a2[1] != 1802856515 )
      return -1073741811;
    if ( v17 == 1 )
      return PfSnGetCompletedTrace(v18, v19, a5);
    if ( v17 != 2 )
      return -1073741821;
    if ( v19 != 408 )
      return -1073741811;
    v7 = 0;
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire((unsigned int)dword_637278, 0, 0);
    do
      v10 = __ldrex(dword_637278);
    while ( !v10 && __strex(0x11u, dword_637278) );
    __dmb(0xBu);
    if ( v10 )
      ExfAcquirePushLockSharedEx(dword_637278, v9, (unsigned int)dword_637278);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    memmove((int)_20, (int)&dword_6370E0, 0x198u);
    __dmb(0xBu);
    do
      v11 = __ldrex(dword_637278);
    while ( v11 == 17 && __strex(0, dword_637278) );
    if ( v11 != 17 )
      ExfReleasePushLockShared(dword_637278);
    v12 = KeAbPostRelease((unsigned int)dword_637278);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    if ( v16 )
    {
      if ( (v18 & 7) != 0 )
        ExRaiseDatatypeMisalignment(v18);
      if ( v18 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)v18 = *(_BYTE *)v18;
      *(_BYTE *)(v18 + 400) = *(_BYTE *)(v18 + 400);
    }
    memmove(v18, (int)_20, 0x198u);
    *a5 = 408;
  }
  else
  {
    v7 = -1073741820;
    *a5 = 20;
  }
  return v7;
}
