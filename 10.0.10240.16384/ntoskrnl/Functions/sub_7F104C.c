// sub_7F104C 
 
void sub_7F104C()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r0
  int v5; // r1
  int *v6; // r2
  _BYTE *v7; // r0
  int v8; // r4
  char v9; // r3
  int **v10; // r2
  int v11; // r3
  int v12; // r0
  int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r3
  __int64 v19; // kr00_8
  int v20; // r5
  int v21; // r3

  v21 = *(_DWORD *)(v20 + 4);
  if ( v21 < 0 || v21 >= 5 )
    goto LABEL_44;
  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPdcDeviceListLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned __int8 *)&PopPdcDeviceListLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&PopPdcDeviceListLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopPdcDeviceListLock, v1, (unsigned int)&PopPdcDeviceListLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = 0;
  v5 = 0;
  v6 = (int *)PopPdcDeviceList;
  if ( (int *)PopPdcDeviceList != &PopPdcDeviceList )
  {
    while ( 1 )
    {
      v4 = (unsigned int)v6;
      if ( v6[2] == *(_DWORD *)v20 )
        break;
      v6 = (int *)*v6;
      if ( v6 == &PopPdcDeviceList )
        goto LABEL_21;
    }
    v5 = 1;
  }
LABEL_21:
  if ( *(_BYTE *)(v20 + 8) )
  {
    if ( v5 )
    {
      ++*(_DWORD *)(v4 + 16);
    }
    else
    {
      v7 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 1866683203);
      v8 = (int)v7;
      if ( v7 )
      {
        memset(v7, 0, 24);
        *(_DWORD *)(v8 + 8) = *(_DWORD *)v20;
        *(_DWORD *)(v8 + 12) = *(_DWORD *)(v20 + 4);
        v9 = *(_BYTE *)(v20 + 9);
        *(_DWORD *)(v8 + 16) = 1;
        *(_BYTE *)(v8 + 20) = v9;
        v10 = (int **)dword_61E4CC;
        *(_DWORD *)v8 = &PopPdcDeviceList;
        *(_DWORD *)(v8 + 4) = v10;
        if ( *v10 != &PopPdcDeviceList )
          __fastfail(3u);
        *v10 = (int *)v8;
        dword_61E4CC = v8;
LABEL_26:
        PopPdcUpdateDeviceCompliance();
        v11 = *(_DWORD *)(v20 + 4);
        if ( v11 == 1 || v11 == 2 || v11 == 4 )
        {
          v12 = PopAcquirePolicyLock();
          PopSnapStandbyNetworkingState(v12, v13);
          PopReleasePolicyLock();
        }
        goto LABEL_28;
      }
    }
  }
  else if ( v5 )
  {
    v18 = *(_DWORD *)(v4 + 16) - 1;
    *(_DWORD *)(v4 + 16) = v18;
    if ( v18 <= 0 )
    {
      v19 = *(_QWORD *)v6;
      if ( *(int **)(*v6 + 4) != v6 || *(int **)HIDWORD(v19) != v6 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      ExFreePoolWithTag(v4);
      goto LABEL_26;
    }
  }
LABEL_28:
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&PopPdcDeviceListLock);
  while ( __strex(v14 - 1, (unsigned int *)&PopPdcDeviceListLock) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopPdcDeviceListLock);
  v15 = KeAbPostRelease((unsigned int)&PopPdcDeviceListLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
LABEL_44:
  JUMPOUT(0x78BC02);
}
