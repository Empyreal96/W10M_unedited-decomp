// PiUEventHandleRegistration 
 
int __fastcall PiUEventHandleRegistration(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // r6
  int v7; // r7
  int v8; // r2
  int v9; // r1
  int v10; // r3
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r5
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r0
  char *v20; // r2
  int *v21; // r1
  int *v22; // r2
  unsigned __int8 v23; // r5
  unsigned int v24; // r1
  int *v26; // r2
  int *v27; // r1
  int v29; // [sp+4h] [bp-24h] BYREF
  int v30[8]; // [sp+8h] [bp-20h] BYREF

  v29 = a3;
  v30[0] = 0;
  if ( !a2 || a3 != 936 || a4 != 8 )
    JUMPOUT(0x7C252C);
  v6 = PiUEventInitClientRegistrationContext();
  if ( !v6 )
    return sub_7C2438(0);
  *(_DWORD *)(v6 + 28) = PsGetCurrentThreadProcessId();
  SeCaptureSubjectContext(v6 + 32);
  v7 = RtlStringCchLengthW((unsigned __int16 *)a2, 0x104u, &v29);
  if ( v7 < 0 )
    goto LABEL_57;
  if ( *(_DWORD *)(a2 + 520) != 416 )
    goto LABEL_57;
  v8 = *(_DWORD *)(a2 + 528);
  if ( v8 >= 4 )
    goto LABEL_57;
  v9 = *(_DWORD *)(a2 + 524);
  if ( (v9 & 0xFFFFFFFC) != 0 || (v9 & 1) != 0 && v8 )
    goto LABEL_57;
  if ( (v9 & 2) != 0 )
    JUMPOUT(0x7C2444);
  if ( v8 == 1 )
  {
    v10 = *(_DWORD *)(a2 + 536);
    if ( !v10 || v10 == -1 )
      goto LABEL_57;
  }
  if ( v8 == 2 )
    JUMPOUT(0x7C2452);
  if ( *(_DWORD *)(a2 + 528) == 3 )
    JUMPOUT(0x7C2468);
  *(_DWORD *)(v6 + 76) = *(_DWORD *)(a2 + 528);
  v11 = *(_DWORD *)(a2 + 528);
  if ( v11 )
  {
    if ( v11 != 1 )
      JUMPOUT(0x7C247E);
    if ( PiUEventGetDeviceInstanceIdFromUserHandle(*(_DWORD *)(a2 + 536), v30, &v29) >= 0 )
    {
      v7 = PiDmGetObject(1, *(_DWORD *)(v30[0] + 4), v6 + 12);
      if ( v7 < 0 )
        JUMPOUT(0x7C2534);
      *(_DWORD *)(v6 + 16) = v29;
      *(_BYTE *)(v6 + 20) = 0;
      goto LABEL_23;
    }
LABEL_57:
    JUMPOUT(0x7C243E);
  }
  if ( (*(_DWORD *)(a2 + 524) & 1) == 0 )
  {
    v12 = *(_DWORD *)(a2 + 540);
    v13 = *(_DWORD *)(a2 + 544);
    v14 = *(_DWORD *)(a2 + 548);
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(a2 + 536);
    *(_DWORD *)(v6 + 16) = v12;
    *(_DWORD *)(v6 + 20) = v13;
    *(_DWORD *)(v6 + 24) = v14;
  }
LABEL_23:
  *(_DWORD *)a2 = *(_DWORD *)(v6 + 48);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v6 + 52);
  *(_DWORD *)(a5 + 4) = 8;
  v15 = KeAbPreAcquire((unsigned int)&PiUEventClientRegistrationListLock, 0, 0);
  v16 = KfRaiseIrql(1);
  v30[0] = v16;
  do
    v17 = __ldrex((unsigned __int8 *)&PiUEventClientRegistrationListLock);
  while ( __strex(v17 & 0xFE, (unsigned __int8 *)&PiUEventClientRegistrationListLock) );
  __dmb(0xBu);
  if ( (v17 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&PiUEventClientRegistrationListLock, v15);
    v16 = v30[0];
  }
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  dword_6308E4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_6308FC = v16;
  v18 = *(_DWORD *)(a2 + 528);
  if ( v18 )
  {
    if ( v18 != 1 )
      JUMPOUT(0x7C24AA);
    v26 = &PiUEventDevHandleClientList[2
                                     * PiUEventHashStringIntoBucket(
                                         *(_DWORD *)(*(_DWORD *)(v6 + 12) + 12),
                                         v16,
                                         v17,
                                         *(_DWORD *)(v6 + 12))];
    v27 = (int *)v26[1];
    *(_DWORD *)v6 = v26;
    *(_DWORD *)(v6 + 4) = v27;
    if ( (int *)*v27 != v26 )
      JUMPOUT(0x7C2524);
    *v27 = v6;
    v26[1] = v6;
    v22 = &PiUEventDevHandleClientCount;
  }
  else
  {
    if ( (*(_DWORD *)(a2 + 524) & 1) != 0 )
      v19 = 13;
    else
      v19 = PiUEventHashGuidIntoBucket((unsigned __int8 *)(a2 + 536));
    v20 = (char *)&PiUEventDevInterfaceClientList + 8 * v19;
    v21 = (int *)*((_DWORD *)v20 + 1);
    *(_DWORD *)v6 = v20;
    *(_DWORD *)(v6 + 4) = v21;
    if ( (char *)*v21 != v20 )
      JUMPOUT(0x7C2528);
    *v21 = v6;
    *((_DWORD *)v20 + 1) = v6;
    v22 = &PiUEventDevInterfaceClientCount;
  }
  ++*v22;
  dword_6308E4 = 0;
  v23 = dword_6308FC;
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)&PiUEventClientRegistrationListLock);
  while ( !v24 && __strex(1u, (unsigned int *)&PiUEventClientRegistrationListLock) );
  if ( v24 )
    ExpReleaseFastMutexContended((unsigned int *)&PiUEventClientRegistrationListLock, v24);
  KfLowerIrql(v23);
  KeAbPostRelease((unsigned int)&PiUEventClientRegistrationListLock);
  *(_DWORD *)(a1 + 16) = v6;
  return v7;
}
