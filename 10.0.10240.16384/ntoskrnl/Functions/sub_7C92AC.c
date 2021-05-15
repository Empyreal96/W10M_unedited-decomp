// sub_7C92AC 
 
unsigned int sub_7C92AC()
{
  int v0; // r3
  unsigned int v1; // r4
  int v2; // r4
  unsigned int *v3; // r5
  unsigned int v4; // r6
  int v5; // r10
  _DWORD *v6; // r6
  __int64 v7; // r2
  int v8; // r8
  int v9; // r9
  unsigned int v10; // r2
  int v11; // r6
  unsigned int v12; // r1
  unsigned int v13; // r4
  unsigned int v14; // r1

  ExpAcquireFastMutexContended((int)v3, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= v5;
  v3[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3[7] = v4;
  while ( 1 )
  {
    v6 = PnpDeferredRegistrationList;
    if ( PnpDeferredRegistrationList == &PnpDeferredRegistrationList )
      break;
    v7 = *(_QWORD *)PnpDeferredRegistrationList;
    if ( *((void ***)PnpDeferredRegistrationList + 1) != &PnpDeferredRegistrationList
      || *(void **)(v7 + 4) != PnpDeferredRegistrationList )
    {
      __fastfail(3u);
    }
    PnpDeferredRegistrationList = *(void **)PnpDeferredRegistrationList;
    *(_DWORD *)(v7 + 4) = &PnpDeferredRegistrationList;
    v0 = v6[2];
    v1 = *(_DWORD *)(v0 + 36);
    if ( v1 )
    {
      v8 = KeAbPreAcquire(*(_DWORD *)(v0 + 36), 0, 0);
      v9 = KfRaiseIrql(1);
      do
        v10 = __ldrex((unsigned __int8 *)v1);
      while ( __strex(v10 & 0xFE, (unsigned __int8 *)v1) );
      __dmb(0xBu);
      if ( (v10 & v5) == 0 )
        ExpAcquireFastMutexContended(v1, v8);
      if ( v8 )
        *(_BYTE *)(v8 + 14) |= v5;
      *(_DWORD *)(v1 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v1 + 28) = v9;
    }
    *(_BYTE *)(v6[2] + 34) = 0;
    PnpDereferenceNotify(v6[2]);
    ExFreePoolWithTag((unsigned int)v6);
    if ( v1 )
    {
      v11 = *(_DWORD *)(v1 + 28);
      *(_DWORD *)(v1 + 4) = 0;
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned int *)v1);
      while ( !v12 && __strex(1u, (unsigned int *)v1) );
      if ( v12 )
        ExpReleaseFastMutexContended((unsigned int *)v1, v12);
      KfLowerIrql((unsigned __int8)v11);
      KeAbPostRelease(v1);
    }
  }
  v3[1] = 0;
  v13 = v3[7];
  __dmb(0xBu);
  do
    v14 = __ldrex(v3);
  while ( !v14 && __strex(1u, v3) );
  if ( v14 )
    ExpReleaseFastMutexContended(v3, v14);
  KfLowerIrql((unsigned __int8)v13);
  return KeAbPostRelease((unsigned int)v3);
}
