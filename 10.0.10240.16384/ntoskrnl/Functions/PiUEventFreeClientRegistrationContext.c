// PiUEventFreeClientRegistrationContext 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall PiUEventFreeClientRegistrationContext(unsigned int *a1, int a2)
{
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  unsigned int v7; // r7
  int v8; // r5
  int v9; // r8
  unsigned int v10; // r2
  unsigned int *v11; // r1 OVERLAPPED
  unsigned int **v12; // r2 OVERLAPPED
  unsigned int v13; // r3
  int *v14; // r2
  unsigned int *v15; // r5
  unsigned int *v16; // r5
  unsigned int *v17; // r5
  unsigned int v18; // r7
  unsigned int v19; // r1
  unsigned __int8 v20; // r5
  unsigned int v21; // r1
  unsigned int v22; // r3
  int v23; // r0
  unsigned int *v24; // r1
  unsigned int *v25; // r1

  if ( a2 )
  {
    v3 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
    v4 = KfRaiseIrql(1);
    do
      v5 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
    while ( __strex(v5 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
    __dmb(0xBu);
    if ( (v5 & 1) == 0 )
      return sub_7E9614(v4);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_6308FC = v4;
    v7 = a1[2];
    v8 = KeAbPreAcquire(v7, 0, 0);
    v9 = KfRaiseIrql(1);
    do
      v10 = __ldrex((unsigned __int8 *)v7);
    while ( __strex(v10 & 0xFE, (unsigned __int8 *)v7) );
    __dmb(0xBu);
    if ( (v10 & 1) == 0 )
      ExpAcquireFastMutexContended(v7, v8);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    *(_DWORD *)(v7 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v7 + 28) = v9;
    *(_QWORD *)&v11 = *(_QWORD *)a1;
    if ( *(unsigned int **)(*a1 + 4) != a1 || *v12 != a1 )
      __fastfail(3u);
    *v12 = v11;
    v11[1] = (unsigned int)v12;
    v13 = a1[19];
    if ( v13 )
    {
      switch ( v13 )
      {
        case 1u:
          v14 = &PiUEventDevHandleClientCount;
          break;
        case 2u:
          v14 = &PiUEventDevInstanceClientCount;
          break;
        case 3u:
          v14 = &PiUEventDevInstancePropertyClientCount;
          break;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      v14 = &PiUEventDevInterfaceClientCount;
    }
    --*v14;
LABEL_19:
    v15 = (unsigned int *)a1[16];
    while ( v15 != a1 + 16 )
    {
      v24 = v15;
      v15 = (unsigned int *)*v15;
      PiUEventDequeuePendingEventWorker((int)a1, v24);
    }
    v16 = (unsigned int *)a1[14];
    while ( v16 != a1 + 14 )
    {
      v25 = v16;
      v16 = (unsigned int *)*v16;
      PiUEventDequeuePendingEventWorker((int)a1, v25);
    }
    v17 = (unsigned int *)a1[2];
    v18 = v17[7];
    v17[1] = 0;
    __dmb(0xBu);
    do
      v19 = __ldrex(v17);
    while ( !v19 && __strex(1u, v17) );
    if ( v19 )
      ExpReleaseFastMutexContended(v17, v19);
    KfLowerIrql((unsigned __int8)v18);
    KeAbPostRelease((unsigned int)v17);
    dword_6308E4 = 0;
    v20 = dword_6308FC;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
    while ( !v21 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
    if ( v21 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v21);
    KfLowerIrql(v20);
    KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  }
  v22 = a1[19];
  if ( v22 == 1 || v22 == 2 || v22 == 3 )
  {
    v23 = a1[3];
    if ( v23 )
      PiDmObjectRelease(v23);
  }
  ZwDeleteWnfStateName();
  SeReleaseSubjectContext((int)(a1 + 8));
  ExFreePoolWithTag(a1[2]);
  memset(a1, 0, 88);
  return ExFreePoolWithTag((unsigned int)a1);
}
