// sub_7EA62C 
 
int sub_7EA62C()
{
  int v0; // r5
  int v1; // r6
  unsigned int *v2; // r7
  int v3; // r8
  int v4; // r9
  int v5; // r10
  unsigned int v6; // r1
  int v7; // r0
  __int16 v8; // r3
  int v10; // [sp+0h] [bp-28h]
  int (__fastcall *v11)(int); // [sp+24h] [bp-4h]

  ExfAcquirePushLockExclusiveEx(v2, v3, (unsigned int)v2);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  if ( v5 )
  {
    if ( (*(_DWORD *)(v0 + 192) & 8) != 0 || *(_DWORD *)(v0 + 284) )
      v4 = -1073741558;
    else
      *(_DWORD *)(v0 + 284) = v5;
  }
  else if ( *(_DWORD *)(v0 + 284) == v10 )
  {
    *(_DWORD *)(v0 + 284) = 0;
  }
  else
  {
    v4 = -1073741823;
  }
  __dmb(0xBu);
  do
    v6 = __ldrex(v2);
  while ( __strex(v6 - 1, v2) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock(v2);
  v7 = KeAbPostRelease((unsigned int)v2);
  v8 = *(_WORD *)(v1 + 308) + 1;
  *(_WORD *)(v1 + 308) = v8;
  if ( !v8 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return v11(v4);
}
