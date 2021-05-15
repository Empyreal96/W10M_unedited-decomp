// SepAdtLogAuditRecord 
 
int __fastcall SepAdtLogAuditRecord(int result)
{
  int v1; // r5
  unsigned int v2; // r8
  int v3; // r6
  _DWORD *v4; // r0
  _DWORD *v5; // r4
  int v6; // r0
  int v7; // r9
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r0
  unsigned int v12; // r2
  char v13[8]; // [sp+0h] [bp-40h] BYREF
  char v14[56]; // [sp+8h] [bp-38h] BYREF

  v1 = result;
  if ( !SepRmAuditingEnabled && (*(_DWORD *)(result + 20) & 2) != 0 )
    return result;
  v2 = KeGetCurrentIrql(result);
  if ( v2 == 2 )
    v3 = 512;
  else
    v3 = 1;
  v4 = (_DWORD *)ExAllocatePoolWithTag(v3, 48);
  v5 = v4;
  if ( !v4 )
    return sub_51DA08();
  v4[3] = 1;
  v4[6] = 1;
  v4[8] = 0;
  v4[9] = 0;
  if ( v2 == 2 )
    v6 = 0;
  else
    v6 = PsGetCurrentServerSilo();
  v5[11] = v6;
  result = SepAdtMarshallAuditRecord(v1, v5 + 4, v5 + 2, v3);
  v7 = result;
  if ( result < 0 )
  {
    v11 = v5[11];
    if ( v11 )
      ObfDereferenceObjectWithTag(v11);
    result = ExFreePoolWithTag(v5, 0);
    SepAdtLastAuditFailStatus = v7;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&SepAdtAuditFailureCount);
    while ( __strex(v12 + 1, (unsigned int *)&SepAdtAuditFailureCount) );
    __dmb(0xBu);
    if ( *(_DWORD *)(v1 + 4) == 521 )
      goto LABEL_14;
    v10 = v7;
  }
  else
  {
    if ( !SepRmAuditingEnabled )
    {
      result = v5[4];
      if ( (*(_DWORD *)(result + 20) & 2) != 0 )
      {
        ExFreePoolWithTag(result, 0);
        return ExFreePoolWithTag(v5, 0);
      }
    }
    v8 = *(_DWORD *)(v5[4] + 12);
    v5[7] = v8;
    if ( *(_DWORD *)(v1 + 4) == 521 && (*(_DWORD *)(v1 + 20) & 0x10) != 0 )
    {
      if ( v8 <= 0xE0 )
      {
        KiStackAttachProcess(SepRmLsaCallProcess, 0, (int)v14);
        SepRmDispatchDataToLsa(v5);
        result = KiUnstackDetachProcess((unsigned int)v14, 0);
      }
      goto LABEL_14;
    }
    v13[0] = 0;
    result = SepQueueWorkItem((int)&SepLsaAuditQueueInfo, v5, v13, 0);
    if ( result )
      goto LABEL_14;
    v9 = v5[11];
    if ( v9 )
      ObfDereferenceObjectWithTag(v9);
    ExFreePoolWithTag(v5[4], 0);
    result = ExFreePoolWithTag(v5, 0);
    if ( v13[0] )
      goto LABEL_14;
    v10 = -1073741823;
  }
  result = SepAuditFailedRaisedIrql(v10);
LABEL_14:
  if ( SepAdtAuditFailureCount && v2 < 2 && *(_DWORD *)(v1 + 4) != 521 )
    result = SepAdtLogAuditFailureEvent(SepAdtLastAuditFailStatus, 0);
  return result;
}
