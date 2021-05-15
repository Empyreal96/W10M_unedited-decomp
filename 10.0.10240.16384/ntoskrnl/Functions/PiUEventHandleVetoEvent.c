// PiUEventHandleVetoEvent 
 
int __fastcall PiUEventHandleVetoEvent(int a1, int *a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r10
  int v6; // r3
  unsigned __int16 *v7; // r4
  int v8; // r7
  int v9; // r8
  unsigned int v10; // r6
  int v11; // r5
  int v12; // r1
  unsigned int v13; // r2
  unsigned int *v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r1
  _DWORD *v17; // r6
  int v18; // r8
  int v19; // r1
  unsigned int v20; // r2
  int v21; // r2
  _DWORD *v22; // r1
  int v23; // r0
  int v24; // r0
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r1
  unsigned int *v28; // r5
  unsigned int v29; // r6
  unsigned int v30; // r1
  int result; // r0
  int v32; // [sp+0h] [bp-48h] BYREF
  unsigned __int16 *v33; // [sp+4h] [bp-44h] BYREF
  int v34; // [sp+8h] [bp-40h]
  int v35; // [sp+Ch] [bp-3Ch]
  int v36; // [sp+10h] [bp-38h]
  unsigned __int16 v37; // [sp+18h] [bp-30h] BYREF
  int v38; // [sp+1Ah] [bp-2Eh]
  __int16 v39; // [sp+1Eh] [bp-2Ah]
  int v40[10]; // [sp+20h] [bp-28h] BYREF

  v5 = *(_DWORD **)(a1 + 16);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v9 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  if ( v5 && a2 && a3 == 8 )
  {
    v10 = v5[2];
    v40[0] = *a2;
    v36 = a2[1];
    v11 = KeAbPreAcquire(v10, 0, 0);
    v12 = KfRaiseIrql(1);
    v35 = v12;
    do
      v13 = __ldrex((unsigned __int8 *)v10);
    while ( __strex(v13 & 0xFE, (unsigned __int8 *)v10) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(v10, v11);
      v12 = v35;
    }
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    *(_DWORD *)(v10 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v10 + 28) = v12;
    if ( (_DWORD *)v5[14] == v5 + 14 )
    {
      v14 = (unsigned int *)v5[2];
      v8 = -1073741811;
      v15 = v14[7];
      v14[1] = 0;
      __dmb(0xBu);
      do
        v16 = __ldrex(v14);
      while ( !v16 && __strex(1u, v14) );
      if ( v16 )
        ExpReleaseFastMutexContended(v14, v16);
      KfLowerIrql((unsigned __int8)v15);
      KeAbPostRelease((unsigned int)v14);
      goto LABEL_59;
    }
    v17 = (_DWORD *)v5[14];
    if ( !*(_BYTE *)(v17[4] + 41) )
      goto LABEL_45;
    v18 = KeAbPreAcquire((unsigned int)&PiUEventUsermodeEventQueueLock, 0, 0);
    v19 = KfRaiseIrql(1);
    v35 = v19;
    do
      v20 = __ldrex((unsigned __int8 *)&PiUEventUsermodeEventQueueLock);
    while ( __strex(v20 & 0xFE, (unsigned __int8 *)&PiUEventUsermodeEventQueueLock) );
    __dmb(0xBu);
    if ( (v20 & 1) == 0 )
    {
      ExpAcquireFastMutexContended((int)&PiUEventUsermodeEventQueueLock, v18);
      v19 = v35;
    }
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    dword_630B04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_630B1C = v19;
    v21 = v17[4];
    v22 = *(_DWORD **)(v21 + 16);
    if ( v22 && *(_DWORD *)(v21 + 20) && !*v22 )
    {
      if ( LOBYTE(v40[0]) )
      {
        *v22 = v36;
        v23 = PsLookupProcessByProcessId(v5[7], &v32);
        v9 = v32;
        if ( v23 < 0 || (v8 = PsGetAllocatedFullProcessImageName(v32, &v33), v8 < 0) )
        {
          v7 = &v37;
          RtlInitUnicodeString((unsigned int)&v37, (unsigned __int16 *)&dword_8CE900);
          v8 = 0;
        }
        else
        {
          v7 = v33;
          if ( !*v33 )
          {
            v34 = 1;
            ExFreePoolWithTag((unsigned int)v33);
            v7 = &v37;
            v24 = PsGetProcessImageFileName(v9);
            RtlInitAnsiString((unsigned int)v40, v24);
            RtlAnsiStringToUnicodeString(&v37, (unsigned __int16 *)v40, 1, v25);
          }
        }
        v26 = v17[4];
        if ( *v7 > 0x400u )
        {
          v8 = RtlStringCchCopyNW(*(_WORD **)(*(_DWORD *)(v26 + 20) + 4), 0x200u, *((_DWORD *)v7 + 1), 0x1FFu);
          *(_WORD *)(*(_DWORD *)(*(_DWORD *)(v17[4] + 20) + 4) + 1022) = 0;
          **(_WORD **)(v17[4] + 20) = 1024;
        }
        else
        {
          RtlCopyUnicodeString(*(unsigned __int16 **)(v26 + 20), v7);
        }
        KeSetEvent(*(_DWORD *)(v17[4] + 12), 0, 0);
        goto LABEL_39;
      }
      **(_WORD **)(*(_DWORD *)(v21 + 20) + 4) = 0;
      **(_WORD **)(v21 + 20) = 0;
      **(_DWORD **)(v21 + 16) = 0;
    }
    v9 = 0;
LABEL_39:
    dword_630B04 = 0;
    v36 = dword_630B1C;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&PiUEventUsermodeEventQueueLock);
    while ( !v27 && __strex(1u, (unsigned int *)&PiUEventUsermodeEventQueueLock) );
    if ( v27 )
      ExpReleaseFastMutexContended((unsigned int *)&PiUEventUsermodeEventQueueLock, v27);
    KfLowerIrql((unsigned __int8)v36);
    KeAbPostRelease((unsigned int)&PiUEventUsermodeEventQueueLock);
LABEL_45:
    PiUEventDequeuePendingEventWorker((int)v5, v17);
    v28 = (unsigned int *)v5[2];
    v29 = v28[7];
    v28[1] = 0;
    __dmb(0xBu);
    do
      v30 = __ldrex(v28);
    while ( !v30 && __strex(1u, v28) );
    if ( v30 )
      ExpReleaseFastMutexContended(v28, v30);
    KfLowerIrql((unsigned __int8)v29);
    KeAbPostRelease((unsigned int)v28);
    v6 = v34;
    goto LABEL_52;
  }
  v8 = -1073741811;
LABEL_52:
  if ( v6 )
  {
    RtlFreeAnsiString(v7);
  }
  else if ( v7 && v7 != &v37 )
  {
    ExFreePoolWithTag((unsigned int)v7);
  }
  if ( v9 )
    ObfDereferenceObjectWithTag(v9);
LABEL_59:
  result = v8;
  *(_DWORD *)(a5 + 4) = 0;
  return result;
}
