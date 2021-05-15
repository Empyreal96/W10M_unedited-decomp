// sub_7BFFC0 
 
void sub_7BFFC0(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r8
  char v5; // r9
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)&LowboxSessionMapLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned int *)&LowboxSessionMapLock);
  while ( !v9 && __strex(0x11u, (unsigned int *)&LowboxSessionMapLock) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(&LowboxSessionMapLock, v7, (unsigned int)&LowboxSessionMapLock);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= v5;
  SepGetTokenSessionMapEntry(v4, 0, (int *)va);
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&LowboxSessionMapLock);
  while ( v10 == 17 && __strex(0, (unsigned int *)&LowboxSessionMapLock) );
  if ( v10 != 17 )
    ExfReleasePushLockShared(&LowboxSessionMapLock);
  v11 = KeAbPostRelease((unsigned int)&LowboxSessionMapLock);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  JUMPOUT(0x6A5E06);
}
