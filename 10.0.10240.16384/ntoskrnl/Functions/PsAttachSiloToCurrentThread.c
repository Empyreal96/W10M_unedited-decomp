// PsAttachSiloToCurrentThread 
 
int __fastcall PsAttachSiloToCurrentThread(int a1)
{
  unsigned int v2; // r4
  int v3; // r8
  char v4; // r3
  char v6; // r3
  unsigned int *v7; // r7
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r5
  int v12; // r3
  unsigned int v13; // r2
  int v14; // r0
  __int16 v15; // r3
  int v16; // r3
  char v17; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(_DWORD *)(v2 + 0x150);
  v4 = PspDebugFlags;
  __dmb(0xBu);
  if ( (v4 & 4) != 0 )
    return sub_80A488();
  v6 = PspDebugFlags;
  __dmb(0xBu);
  if ( (v6 & 0x10) != 0 )
  {
    if ( a1 )
    {
      v16 = *(_DWORD *)(a1 + 144);
      if ( v16 )
      {
        if ( *(int *)(v16 + 56) >= 3 )
        {
          v17 = PspDebugFlags;
          __dmb(0xBu);
          if ( (v17 & 0x20) != 0 )
            __debugbreak();
        }
      }
    }
  }
  --*(_WORD *)(v2 + 308);
  v7 = (unsigned int *)(v3 + 168);
  v8 = KeAbPreAcquire(v3 + 168, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx((_DWORD *)(v3 + 168), v8, v3 + 168);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = *(_DWORD *)(v2 + 1096);
  if ( v11 == -3 )
    v12 = *(_DWORD *)(v3 + 804);
  else
    v12 = *(_DWORD *)(v2 + 1096);
  if ( v12 == a1 )
    v11 = -2;
  else
    *(_DWORD *)(v2 + 1096) = a1;
  __dmb(0xBu);
  do
    v13 = __ldrex(v7);
  while ( v13 == 17 && __strex(0, v7) );
  if ( v13 != 17 )
    ExfReleasePushLockShared((_DWORD *)(v3 + 168));
  v14 = KeAbPostRelease(v3 + 168);
  v15 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v11;
}
