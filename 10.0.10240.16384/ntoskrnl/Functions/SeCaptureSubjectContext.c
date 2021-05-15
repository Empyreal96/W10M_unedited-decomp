// SeCaptureSubjectContext 
 
int __fastcall SeCaptureSubjectContext(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r5
  unsigned int v6; // r0
  int result; // r0
  unsigned int v8; // r6
  unsigned int *v9; // r8
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r2
  __int16 v15; // r3
  _DWORD v16[6]; // [sp+8h] [bp-18h] BYREF

  v16[0] = a4;
  v5 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  a1[3] = v5[44];
  if ( !v6 )
    return sub_7BE748(0);
  *a1 = PsReferenceImpersonationTokenEx(v6, 0, (char *)v16 + 1, v16, a1 + 1, 0);
  result = ObFastReferenceObject(v5 + 61);
  if ( result )
  {
    a1[2] = result;
  }
  else
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = v5 + 42;
    v10 = KeAbPreAcquire((unsigned int)(v5 + 42), 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v9);
    while ( !v12 && __strex(0x11u, v9) );
    __dmb(0xBu);
    if ( v12 )
      ExfAcquirePushLockSharedEx(v5 + 42, v10, (unsigned int)(v5 + 42));
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v13 = ObFastReferenceObjectLocked(v5 + 61);
    __dmb(0xBu);
    do
      v14 = __ldrex(v9);
    while ( v14 == 17 && __strex(0, v9) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(v9);
    result = KeAbPostRelease((unsigned int)v9);
    v15 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      result = KiCheckForKernelApcDelivery(result);
    a1[2] = v13;
  }
  return result;
}
