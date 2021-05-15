// ObDereferenceSecurityDescriptor 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ObDereferenceSecurityDescriptor(int a1, int a2)
{
  _DWORD *v2; // r6
  unsigned int *v3; // r5
  int i; // r2
  int result; // r0
  unsigned __int8 *v7; // r9
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r8
  unsigned int v11; // r2
  unsigned int v12; // r0
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  unsigned int v15; // r1
  int v16; // r0
  __int16 v17; // r3
  unsigned int v18; // r1
  int v19; // r3

  v2 = (_DWORD *)(a1 - 16);
  v3 = (unsigned int *)(a1 - 8);
  __pld((void *)(a1 - 8));
  for ( i = *(_DWORD *)(a1 - 8); i - a2 > 0; i = result )
  {
    __dmb(0xBu);
    do
      result = __ldrex(v3);
    while ( result == i && __strex(i - a2, v3) );
    if ( result == i )
      return result;
  }
  if ( i != a2 )
    sub_7FB7D8();
  v7 = (unsigned __int8 *)&ObsSecurityDescriptorCache[3 * (v2[3] % 0x101u)];
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 0x134);
  v9 = KeAbPreAcquire((unsigned int)v7, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v7);
  while ( __strex(v11 | 1, v7) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v7, v9, (unsigned int)v7);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  __dmb(0xBu);
  do
    v12 = __ldrex(v3);
  while ( __strex(v12 - a2, v3) );
  if ( (int)(v12 - a2) > 0 )
  {
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)v7);
    while ( __strex(v18 - 1, (unsigned int *)v7) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v7);
    result = KeAbPostRelease((unsigned int)v7);
    v19 = (__int16)(*(_WORD *)(v8 + 308) + 1);
    *(_WORD *)(v8 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  else
  {
    if ( v12 != a2 )
      __fastfail(0xEu);
    __dmb(0xBu);
    *(_QWORD *)&v13 = *(_QWORD *)v2;
    if ( *(_DWORD **)(*v2 + 4) != v2 || (_DWORD *)*v14 != v2 )
      __fastfail(3u);
    *v14 = v13;
    *(_DWORD *)(v13 + 4) = v14;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)v7);
    while ( __strex(v15 - 1, (unsigned int *)v7) );
    if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v7);
    v16 = KeAbPostRelease((unsigned int)v7);
    v17 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v16);
    result = ExFreePoolWithTag((unsigned int)v2);
  }
  return result;
}
