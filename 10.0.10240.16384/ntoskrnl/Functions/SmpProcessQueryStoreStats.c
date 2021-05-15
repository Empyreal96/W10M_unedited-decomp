// SmpProcessQueryStoreStats 
 
int __fastcall SmpProcessQueryStoreStats(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r4
  int v7; // r7
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // r2
  int v16; // r0
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = a4;
  if ( a1 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = KeAbPreAcquire((unsigned int)&unk_636CC4, 0, 0);
    do
      v8 = __ldrex((unsigned int *)&unk_636CC4);
    while ( !v8 && __strex(0x11u, (unsigned int *)&unk_636CC4) );
    __dmb(0xBu);
    if ( v8 )
      ExfAcquirePushLockSharedEx(&unk_636CC4, v7, (unsigned int)&unk_636CC4);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = dword_636CD4;
    if ( !dword_636CD4 || *(_DWORD *)(dword_636CD4 + 4) != a1 )
    {
      if ( a1 != dword_636CD8 )
      {
        v17[0] = (-1 << (dword_636CCC & 0x1F)) & a1;
        if ( (unsigned int)dword_636CCC >> 5 )
          return sub_547718();
        dword_636CD8 = a1;
      }
      v9 = 0;
    }
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&unk_636CC4);
    while ( v10 == 17 && __strex(0, (unsigned int *)&unk_636CC4) );
    if ( v10 != 17 )
      ExfReleasePushLockShared(&unk_636CC4, v10);
    v11 = KeAbPostRelease((unsigned int)&unk_636CC4);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      KiCheckForKernelApcDelivery(v11);
    if ( !v9 )
      return -1073741275;
    v15 = *(unsigned __int16 *)(v9 + 8);
  }
  else
  {
    v15 = dword_636CDC;
  }
  if ( v15 == -1 )
    return -1073741275;
  v16 = SmGlobals[24 * (v15 & 0x1F)];
  v17[0] = 1528;
  return ((int (__fastcall *)(int, _DWORD, int, int *))SMKM_STORE<SM_TRAITS>::SmStGetStoreStats)(v16, 0, a2, v17);
}
