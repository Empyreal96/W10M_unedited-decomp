// PspAllocateAndQueryNotificationChannel 
 
int __fastcall PspAllocateAndQueryNotificationChannel(int a1, _DWORD *a2, int a3)
{
  int v3; // r9
  char *v6; // r10
  int v7; // r6
  unsigned int v8; // r7
  int v9; // r6
  _DWORD *v10; // r7
  int v11; // r1
  int v12; // r0
  int v13; // r6
  int v14; // r2
  int v15; // r7
  int v16; // r3
  int v17; // r2
  int v18; // r3
  _DWORD *v19; // r6
  int v20; // r0
  unsigned __int8 *v21; // r3
  unsigned int v22; // r2
  unsigned __int64 v23; // kr00_8
  int v24; // r0
  __int16 v25; // r3
  unsigned int i; // r5
  int v28; // r3
  int v29; // r2
  int v30; // r3
  int v31; // r2
  int v32; // r3
  int v33; // r2
  int *v34; // r1
  _DWORD *v35; // t1
  int v36; // r3
  unsigned int v37; // [sp+10h] [bp-70h]
  int v38; // [sp+10h] [bp-70h]
  int v39; // [sp+10h] [bp-70h]
  char v40[4]; // [sp+14h] [bp-6Ch] BYREF
  int v41; // [sp+18h] [bp-68h] BYREF
  char v42; // [sp+1Ch] [bp-64h] BYREF
  char v43[3]; // [sp+1Dh] [bp-63h] BYREF
  int v44; // [sp+20h] [bp-60h] BYREF
  int v45; // [sp+24h] [bp-5Ch] BYREF
  int v46; // [sp+28h] [bp-58h] BYREF
  _DWORD *v47; // [sp+2Ch] [bp-54h] BYREF
  char v48[8]; // [sp+30h] [bp-50h] BYREF
  char v49[8]; // [sp+38h] [bp-48h] BYREF
  char v50[24]; // [sp+40h] [bp-40h] BYREF
  int v51; // [sp+58h] [bp-28h]
  int v52; // [sp+5Ch] [bp-24h]

  v51 = 0;
  v52 = 0;
  v3 = a3;
  v6 = 0;
  if ( (a2[186] & 0x800) != 0 )
  {
    v15 = 1;
    if ( a1 )
      --*(_WORD *)(a1 + 310);
    while ( 1 )
    {
      v28 = a2[144];
      __dmb(0xBu);
      v39 = v28;
      __dmb(0xBu);
      ExAcquireResourceExclusiveLite(v28 + 32, 1, a3, v28);
      v29 = v39;
      __dmb(0xBu);
      v30 = a2[144];
      __dmb(0xBu);
      if ( v29 == v30 )
        break;
      v36 = v39;
      __dmb(0xBu);
      ExReleaseResourceLite(v36 + 32);
    }
    v19 = (_DWORD *)v39;
    v41 = v39;
    __dmb(0xBu);
    if ( a2 != v19 )
    {
      ExConvertExclusiveToSharedLite(v39 + 32);
      ExAcquireResourceExclusiveLite((int)(a2 + 8), 1, v31, v32);
    }
    goto LABEL_18;
  }
  v7 = ObpGetObjectSecurity(a2, &v45, v40, 0);
  if ( v7 < 0 )
    return v7;
  if ( v45 )
  {
    if ( RtlGetOwnerSecurityDescriptor(v45, &v44, v43) < 0 )
      goto LABEL_46;
    v8 = PsReferenceEffectiveToken(a1, &v46, &v42, v48, 0);
    v9 = SeQueryInformationToken(v8, 1, &v47);
    if ( v46 != 1 )
      JUMPOUT(0x7C235C);
    ObFastDereferenceObject((_DWORD *)(*(_DWORD *)(a1 + 116) + 244), v8);
    if ( v9 < 0 )
LABEL_46:
      JUMPOUT(0x7C238E);
    v10 = v47;
    v11 = 4 * (*(unsigned __int8 *)(v44 + 1) + *(unsigned __int8 *)(*v47 + 1) + 12);
    v41 = *(unsigned __int8 *)(v44 + 1) + *(unsigned __int8 *)(*v47 + 1) + 12;
    v12 = ExAllocatePoolWithTag(512, v11, 1717007184);
    v37 = v12;
    if ( !v12
      || (RtlCreateAcl(v12, 4 * v41, 2),
          RtlAddAccessAllowedAce(v37, 2, 0x80000000, v44),
          RtlAddAccessAllowedAce(v37, 2, 0x80000000, *v10),
          RtlCreateSecurityDescriptor(v50, 1),
          RtlSetDaclSecurityDescriptor(v50, 1, v37, 0),
          v13 = ZwCreateWnfStateName(),
          ExFreePoolWithTag(v37),
          v13 < 0) )
    {
      JUMPOUT(0x7C2386);
    }
    v15 = 0;
    if ( a1 )
      --*(_WORD *)(a1 + 310);
    v16 = a2[144];
    __dmb(0xBu);
    v38 = v16;
    __dmb(0xBu);
    ExAcquireResourceExclusiveLite(v16 + 32, 1, v14, v16);
    v17 = v38;
    __dmb(0xBu);
    v18 = a2[144];
    __dmb(0xBu);
    if ( v17 != v18 )
      JUMPOUT(0x7C236C);
    v19 = (_DWORD *)v38;
    v41 = v38;
    __dmb(0xBu);
    if ( (a2[186] & 0x800) != 0 )
      JUMPOUT(0x7C237E);
    a2[108] = v51;
    v6 = v49;
    a2[109] = v52;
    v20 = PspComputeReportWakeFilter(a2, v49, a2 + 122, 0, 0, 0);
    PspEnumJobsAndProcessesInJobHierarchy(v20, 0, PspEnableWakeCounters, PspEnableProcessWakeCounters, 0, 2, v50);
    __dmb(0xBu);
    v21 = (unsigned __int8 *)a2 + 745;
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 | 8, v21) );
    __dmb(0xBu);
    do
      v23 = __ldrexd((unsigned __int64 *)&PspJobTimeLimitsRequest);
    while ( __strexd(v23 + 1, (unsigned __int64 *)&PspJobTimeLimitsRequest) );
    __dmb(0xBu);
LABEL_18:
    memmove(v3, (int)(a2 + 108), 0x30u);
    if ( v15 )
    {
      v33 = 0;
      v34 = &v41;
      while ( 1 )
      {
        v35 = (_DWORD *)*v34++;
        if ( a2 == v35 )
          break;
        if ( ++v33 )
        {
          ExReleaseResourceLite((int)(a2 + 8));
          break;
        }
      }
    }
    v24 = ExReleaseResourceLite((int)(v19 + 8));
    if ( a1 )
    {
      v25 = *(_WORD *)(a1 + 310) + 1;
      *(_WORD *)(a1 + 310) = v25;
      if ( !v25 && *(_DWORD *)(a1 + 100) != a1 + 100 )
        KiCheckForKernelApcDelivery(v24);
    }
    if ( !v15 && *(_QWORD *)v6 )
    {
      for ( i = 0; i < 5; ++i )
      {
        v3 += 8;
        if ( PspSendWakeNotification(a2, i, v6) )
          break;
      }
    }
    return 0;
  }
  return sub_7C2358();
}
