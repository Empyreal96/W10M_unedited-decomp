// ExShareAddressSpaceWithDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExShareAddressSpaceWithDevice(int a1, unsigned int *a2)
{
  int v2; // r5
  _DWORD *v3; // r6
  _DWORD *v4; // r9
  unsigned int *v5; // r10
  unsigned int v6; // r0
  unsigned int v7; // r1
  unsigned __int8 *v8; // r7
  int v9; // r0
  int v10; // r4
  int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r7
  unsigned int v14; // r0
  unsigned int *v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int v20; // r7
  int v21; // r4
  int v22; // r0
  int v23; // r4
  unsigned int v24; // r2
  int *v25; // r2
  int v26; // r3
  int v27; // r4
  int v28; // r0
  unsigned int v29; // r1
  int v30; // r4
  int v31; // r1 OVERLAPPED
  _DWORD *v32; // r2 OVERLAPPED
  int v33; // r8
  int *v34; // r1
  int *v35; // r2 OVERLAPPED
  int v36; // r1 OVERLAPPED
  int v37; // [sp+0h] [bp-40h]
  int *v38; // [sp+4h] [bp-3Ch] BYREF
  int v39; // [sp+8h] [bp-38h]
  unsigned int *v40; // [sp+Ch] [bp-34h]
  unsigned int *v41; // [sp+10h] [bp-30h]
  int v42[10]; // [sp+18h] [bp-28h] BYREF

  v2 = 0;
  *a2 = -1;
  v40 = a2;
  v38 = 0;
  v3 = 0;
  v39 = a1;
  if ( !ExpSvmIommuSystemContext )
    return -1073741637;
  if ( !a1 )
    return -1073741585;
  v4 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v5 = v4 + 43;
  __pld(v4 + 43);
  v6 = v4[43] & 0xFFFFFFFE;
  do
    v7 = __ldrex(v5);
  while ( v7 == v6 && __strex(v6 + 2, v5) );
  __dmb(0xBu);
  if ( v7 != v6 && !ExfAcquireRundownProtection(v4 + 43) )
    return -1073741558;
  v8 = (unsigned __int8 *)(v4 + 187);
  v41 = v4 + 187;
  v9 = KeAbPreAcquire((unsigned int)(v4 + 187), 0, 0);
  v10 = v9;
  do
  {
    v11 = __ldrex(v8);
    v12 = __strex(v11 | 1, v8);
  }
  while ( v12 );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    v9 = ExfAcquirePushLockExclusiveEx(v4 + 187, v9, (unsigned int)(v4 + 187));
  if ( v10 )
  {
    v12 = *(unsigned __int8 *)(v10 + 14) | 1;
    *(_BYTE *)(v10 + 14) = v12;
  }
  v13 = v4[185];
  if ( !v13 )
  {
    v14 = ExpAllocateAsid(v9, 1, v11, v12);
    v13 = v14;
    if ( !v14 )
    {
      v2 = -1073741709;
      goto LABEL_20;
    }
    if ( !ExpAssignPasid(v4, v14) )
      v13 = v4[185];
  }
  v20 = v13 - 1;
  v37 = v4[186];
  if ( !v37 )
  {
    v2 = ((int (__cdecl *)())HalIommuDispatch[2])();
    if ( v2 < 0 )
      goto LABEL_20;
    v21 = KfRaiseIrql(15);
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v4 + 188, v42);
    if ( v4[186] )
      v37 = v4[186];
    else
      v4[186] = 0;
    KeReleaseInStackQueuedSpinLockFromDpcLevel(v42);
    KfLowerIrql(v21);
  }
  v22 = KeAbPreAcquire((unsigned int)&ExpSvmDeviceListLock, 0, 0);
  v23 = v22;
  do
    v24 = __ldrex((unsigned __int8 *)&ExpSvmDeviceListLock);
  while ( __strex(v24 | 1, (unsigned __int8 *)&ExpSvmDeviceListLock) );
  __dmb(0xBu);
  if ( (v24 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpSvmDeviceListLock, v22, (unsigned int)&ExpSvmDeviceListLock);
  if ( v23 )
    *(_BYTE *)(v23 + 14) |= 1u;
  v25 = (int *)ExpSvmDevices;
  if ( (int *)ExpSvmDevices == &ExpSvmDevices )
    goto LABEL_52;
  do
  {
    v26 = v25[2];
    v27 = (int)v25;
    v38 = v25;
    if ( v26 == v39 )
      break;
    v25 = (int *)*v25;
  }
  while ( v25 != &ExpSvmDevices );
  if ( *(_DWORD *)(v27 + 8) != v39 )
  {
    v27 = 0;
    v38 = 0;
  }
  if ( !v27 )
  {
LABEL_52:
    v28 = ExpPrepareNewSvmDevice(v39, v37, (int *)&v38);
    v27 = (int)v38;
    v2 = v28;
  }
  else
  {
    ++*(_DWORD *)(v27 + 12);
  }
  __dmb(0xBu);
  do
    v29 = __ldrex((unsigned int *)&ExpSvmDeviceListLock);
  while ( __strex(v29 - 1, (unsigned int *)&ExpSvmDeviceListLock) );
  if ( (v29 & 2) != 0 && (v29 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpSvmDeviceListLock);
  KeAbPostRelease((unsigned int)&ExpSvmDeviceListLock);
  if ( v2 < 0 )
    goto LABEL_61;
  v3 = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1682995269);
  if ( !v3 )
  {
    v2 = -1073741670;
LABEL_61:
    if ( v27 )
      ExpSvmDereferenceDevice(v27);
    if ( v3 )
    {
      v30 = KfRaiseIrql(15);
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v4 + 188, v42);
      *(_QWORD *)&v31 = *(_QWORD *)v3;
      if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v32 != v3 )
        __fastfail(3u);
      *v32 = v31;
      *(_DWORD *)(v31 + 4) = v32;
      KeReleaseInStackQueuedSpinLockFromDpcLevel(v42);
      KfLowerIrql(v30);
      ExFreePoolWithTag((unsigned int)v3);
    }
    goto LABEL_20;
  }
  v3[2] = v27;
  v33 = 0;
  v38 = (int *)KfRaiseIrql(15);
  KeAcquireInStackQueuedSpinLockAtDpcLevel(v4 + 188, v42);
  v34 = (int *)v4[189];
  v35 = v4 + 189;
  if ( v34 == v4 + 189 )
  {
LABEL_70:
    v36 = *v35;
    *(_QWORD *)v3 = *(_QWORD *)(&v35 - 1);
    if ( *(int **)(v36 + 4) != v35 )
      __fastfail(3u);
    *(_DWORD *)(v36 + 4) = v3;
    *v35 = (int)v3;
  }
  else
  {
    while ( *(_DWORD *)(v34[2] + 8) != v39 )
    {
      v34 = (int *)*v34;
      if ( v34 == v35 )
        goto LABEL_70;
    }
    v33 = 1;
  }
  KeReleaseInStackQueuedSpinLockFromDpcLevel(v42);
  KfLowerIrql(v38);
  if ( v33 )
  {
    ExFreePoolWithTag((unsigned int)v3);
    v3 = 0;
  }
  else
  {
    MmEnableProcessSvm();
    v2 = ((int (__cdecl *)())HalIommuDispatch[4])();
    if ( v2 < 0 )
      goto LABEL_61;
    v2 = ((int (__cdecl *)())HalIommuDispatch[5])();
  }
  if ( v2 < 0 )
    goto LABEL_61;
  *v40 = v20;
LABEL_20:
  __dmb(0xBu);
  v15 = v41;
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 - 1, v15) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock(v15);
  KeAbPostRelease((unsigned int)v15);
  __pld(v5);
  v17 = *v5 & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v18 = __ldrex(v5);
  while ( v18 == v17 && __strex(v17 - 2, v5) );
  if ( v18 != v17 )
    ExfReleaseRundownProtection((unsigned __int8 *)v4 + 172);
  return v2;
}
