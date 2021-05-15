// ExpSaPageGroupDescriptorFree 
 
int __fastcall ExpSaPageGroupDescriptorFree(int a1, int a2)
{
  unsigned int v3; // r7
  int v4; // r0
  int v5; // r4
  unsigned int v6; // r2
  unsigned int i; // r8
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r3
  int v11; // r4
  unsigned int v12; // r1

  v3 = KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
  v4 = KeAbPreAcquire((unsigned int)&ExSaPageGroupDescriptorArrayLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&ExSaPageGroupDescriptorArrayLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&ExSaPageGroupDescriptorArrayLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(
      &ExSaPageGroupDescriptorArrayLock,
      v4,
      (unsigned int)&ExSaPageGroupDescriptorArrayLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  for ( i = 0; i < v3; ++i )
  {
    v8 = *(_DWORD *)(a1 + 16);
    v9 = *(_DWORD *)(ExSaPageArrays + 4 * i);
    v10 = __clz(v8);
    v11 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * (29 - v10)) + 4 * ((1 << (31 - v10)) ^ v8) + 4);
    ExpSaBinaryArrayRemove(v9, v8);
    ExFreePoolWithTag(v11);
  }
  ExpSaBinaryArrayRemove(ExSaPageGroupDescriptorArray, *(_DWORD *)(a1 + 16));
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&ExSaPageGroupDescriptorArrayLock);
  while ( __strex(v12 - 1, (unsigned int *)&ExSaPageGroupDescriptorArrayLock) );
  if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExSaPageGroupDescriptorArrayLock);
  KeAbPostRelease((unsigned int)&ExSaPageGroupDescriptorArrayLock);
  return ExFreePoolWithTag(a1);
}
