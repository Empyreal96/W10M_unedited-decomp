// PoFxSystemLatencyNotify 
 
int __fastcall PoFxSystemLatencyNotify(int a1, int a2, int a3, int a4)
{
  BOOL v6; // r7
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r2
  int *i; // r4
  int (__fastcall *v12)(int, int *); // r3
  int v13; // r0
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // [sp+0h] [bp-20h] BYREF
  int v19; // [sp+4h] [bp-1Ch]

  v18 = a3;
  v19 = a4;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire(&PopFxPluginLock, 0, 0);
  do
    v9 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( !v9 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
  __dmb(0xBu);
  if ( v9 )
    return sub_5299F0(v8, 17);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  for ( i = (int *)PopFxPluginList; i != &PopFxPluginList; i = (int *)*i )
  {
    v12 = (int (__fastcall *)(int, int *))i[16];
    if ( v12 )
    {
      v18 = a1;
      v19 = a2;
      v13 = v12(16, &v18);
    }
    else
    {
      v13 = 0;
    }
    if ( v13 )
    {
      if ( !v6 )
        v6 = i[4] >= 0;
    }
  }
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( v14 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
  if ( v14 != 17 )
    ExfReleasePushLockShared(&PopFxPluginLock, 0);
  v15 = KeAbPostRelease(&PopFxPluginLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return v6;
}
