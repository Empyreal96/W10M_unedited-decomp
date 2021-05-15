// SepRmCallLsa 
 
int __fastcall SepRmCallLsa(int a1)
{
  unsigned int v1; // r7
  int v3; // r8
  _DWORD *v4; // r6
  int v5; // r2
  int v6; // r3
  int v7; // r0
  _DWORD *v8; // r1
  __int64 v10; // r2
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3
  unsigned int *v14; // r1
  unsigned int v15; // r2
  unsigned int *v16; // r2
  unsigned int v17; // r7
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v21; // r4
  int v22; // r7
  unsigned int v23; // r2
  int v24; // r3
  __int64 v25; // r0
  int v26; // r0
  __int64 v27; // r2
  char v28[4]; // [sp+0h] [bp-50h] BYREF
  int v29; // [sp+4h] [bp-4Ch] BYREF
  char v30[16]; // [sp+8h] [bp-48h] BYREF
  char v31[56]; // [sp+18h] [bp-38h] BYREF

  v1 = 1;
  v3 = (unsigned __int8)SepRmAuditingEnabled;
  v29 = 0;
  if ( AdtpRegisteredWithEtw
    || (v19 = SepAdtOpenEtwReadyEvent(&v29), v19 >= 0)
    && (v19 = NtWaitForSingleObject(v29, 1, 0), NtClose(v29), v19 >= 0) )
  {
    if ( v3 )
      KiStackAttachProcess(SepRmLsaCallProcess, 0, (int)v31);
    do
    {
      v4 = 0;
      if ( (*(_WORD *)(a1 + 120) & 1) == 0 )
        goto LABEL_58;
      v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v6 = *(__int16 *)(v5 + 0x134) - 1;
      *(_WORD *)(v5 + 308) = v6;
      v7 = ExAcquireResourceExclusiveLite(a1 + 16, 1, v5, v6);
      v8 = *(_DWORD **)a1;
      if ( *(_DWORD *)a1 == a1 )
        return sub_54D21C(v7);
      if ( v8[10] == *(_DWORD *)(a1 + 100) + 1 )
      {
        v10 = *(_QWORD *)v8;
        v4 = *(_DWORD **)a1;
        if ( v8[1] != a1 || *(_DWORD **)(v10 + 4) != v8 )
          __fastfail(3u);
        *(_DWORD *)a1 = v10;
        *(_DWORD *)(v10 + 4) = a1;
      }
      v11 = ExpReleaseResourceForThreadLite(a1 + 16, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v11);
      if ( !v4 )
      {
LABEL_58:
        if ( (*(_WORD *)(a1 + 120) & 2) == 0 )
          continue;
        KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 72), (unsigned int)v30);
        HIDWORD(v25) = a1 + 8;
        if ( *(_DWORD *)(a1 + 8) == a1 + 8 )
        {
          v26 = *(_DWORD *)(a1 + 108);
          if ( v26 )
            KeSetEvent(v26, 0, 0);
        }
        else if ( *(_DWORD *)(*(_DWORD *)(a1 + 8) + 40) == *(_DWORD *)(a1 + 100) + 1 )
        {
          v4 = *(_DWORD **)(a1 + 8);
          LODWORD(v25) = *(_DWORD *)HIDWORD(v25);
          v27 = *(_QWORD *)*(_DWORD *)HIDWORD(v25);
          if ( __PAIR64__(HIDWORD(v27), *(_DWORD *)(v27 + 4)) != v25 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v25) = v27;
          *(_DWORD *)(v27 + 4) = HIDWORD(v25);
        }
        KeReleaseInStackQueuedSpinLock((int)v30);
        if ( !v4 )
          continue;
      }
      if ( v4[6] != 1 || (*(_DWORD *)(v4[4] + 20) & 2) != 0 )
      {
        if ( v3 )
          SepRmDispatchDataToLsa(v4);
      }
      else
      {
        v20 = v4[11];
        v28[0] = 0;
        v21 = PsAttachSiloToCurrentThread(v20);
        v22 = AdtpWriteToEtw(v4[4], v28);
        PsDetachSiloFromCurrentThread(v21);
        if ( v22 < 0 )
        {
          SepAdtLastAuditFailStatus = v22;
          __dmb(0xBu);
          do
            v23 = __ldrex((unsigned int *)&SepAdtAuditFailureCount);
          while ( __strex(v23 + 1, (unsigned int *)&SepAdtAuditFailureCount) );
          __dmb(0xBu);
          if ( !v28[0] )
            SepAuditFailed(v22);
        }
        v24 = v4[2];
        if ( v24 == 4 || v24 == 5 )
          ExFreePoolWithTag(v4[4], 0);
      }
      __dmb(0xBu);
      v14 = (unsigned int *)(a1 + 100);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 + 1, v14) );
      __dmb(0xBu);
      v16 = (unsigned int *)(a1 + 92);
      do
      {
        v17 = __ldrex(v16);
        v1 = v17 - 1;
      }
      while ( __strex(v1, v16) );
      __dmb(0xBu);
      v18 = v4[11];
      if ( v18 )
        ObfDereferenceObjectWithTag(v18);
      v4[11] = 0;
      (*(void (__fastcall **)(_DWORD *))(a1 + 116))(v4);
    }
    while ( v1 );
    if ( v3 )
      KiUnstackDetachProcess((unsigned int)v31, 0);
    v19 = 0;
  }
  return v19;
}
