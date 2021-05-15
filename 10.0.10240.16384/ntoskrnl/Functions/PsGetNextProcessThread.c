// PsGetNextProcessThread 
 
_DWORD *__fastcall PsGetNextProcessThread(int a1, int a2)
{
  _DWORD *v3; // r8
  unsigned int v4; // r5
  _DWORD **v5; // r9
  int v6; // r10
  unsigned int *v7; // r6
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  _DWORD *v11; // r4
  unsigned int v12; // r2
  int v13; // r0
  __int16 v14; // r3

  v3 = 0;
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (_DWORD **)(a1 + 396);
  v6 = 0;
  --*(_WORD *)(v4 + 308);
  v7 = (unsigned int *)(a1 + 168);
  v8 = KeAbPreAcquire(a1 + 168, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( a2 )
    v11 = *(_DWORD **)(a2 + 932);
  else
    v11 = *v5;
  while ( v11 != v5 )
  {
    v3 = v11 - 233;
    if ( ObReferenceObjectSafeWithTag((int)(v11 - 233)) )
    {
      v6 = 1;
      break;
    }
    v11 = (_DWORD *)*v11;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex(v7);
  while ( v12 == 17 && __strex(0, v7) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(v7);
  v13 = KeAbPostRelease((unsigned int)v7);
  v14 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery(v13);
  if ( a2 )
    ObfDereferenceObjectWithTag(a2);
  if ( !v6 )
    v3 = 0;
  return v3;
}
