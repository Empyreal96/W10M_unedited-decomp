// ExUnregisterExtension 
 
int __fastcall ExUnregisterExtension(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned __int8 *v3; // r6
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  void (__fastcall *v7)(int, _DWORD); // r3
  unsigned int *v8; // r0
  int v9; // r2
  unsigned int v10; // r1
  void (__fastcall *v11)(int, _DWORD, int); // r3
  unsigned int v12; // r1
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = (unsigned __int8 *)(a1 + 10);
  v4 = KeAbPreAcquire((unsigned int)(a1 + 10), 0, 0);
  v5 = v4;
  do
    v6 = __ldrex(v3);
  while ( __strex(v6 | 1, v3) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v3, v4, (unsigned int)v3);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = (void (__fastcall *)(int, _DWORD))a1[7];
  if ( v7 )
    v7(2, a1[8]);
  v8 = a1 + 9;
  v9 = 1;
  do
    v10 = __ldrex(v8);
  while ( !v10 && __strex(1u, v8) );
  __dmb(0xBu);
  if ( v10 && v10 != 1 )
    ExfWaitForRundownProtectionRelease(v8, v10);
  a1[11] = 0;
  v11 = (void (__fastcall *)(int, _DWORD, int))a1[7];
  if ( v11 )
    v11(3, a1[8], v9);
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v3);
  while ( __strex(v12 - 1, (unsigned int *)v3) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  v13 = KeAbPostRelease((unsigned int)v3);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return ExpDereferenceHost(a1);
}
