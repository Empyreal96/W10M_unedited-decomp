// PopCreateUserPowerRequest 
 
int __fastcall PopCreateUserPowerRequest(int *a1, int a2, int a3, int a4)
{
  unsigned int v7; // r3
  int v8; // r8
  int v9; // r5
  int v10; // r4
  _DWORD *v11; // r0
  int result; // r0
  int v13; // r4
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25[8]; // [sp+0h] [bp-20h] BYREF

  v25[0] = a3;
  v25[1] = a4;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(_DWORD *)(v7 + 116);
  if ( a2 )
  {
    v9 = PsReferencePrimaryToken(*(_DWORD *)(v7 + 116));
    v10 = SeSecurityAttributePresent(v9, (int)&PspSysAppIdClaim);
    v11 = ObFastDereferenceObject((_DWORD *)(v8 + 244), v9);
    if ( v10 )
      return sub_7F2CC4(v11);
  }
  result = PopCreatePowerRequestObject(v25, a3);
  if ( result >= 0 )
  {
    v13 = v25[0];
    *(_BYTE *)(v25[0] + 72) = a2;
    if ( !a2 )
      *(_DWORD *)(v13 + 68) = v8;
    v18 = MmGetSessionIdEx(*(_DWORD *)(a3 + 4));
    if ( a2 )
    {
      v14 = 8;
    }
    else if ( (v18 == -1 || !v18) && (v18 || MEMORY[0xFFFF92D8]) )
    {
      v14 = 30;
    }
    else
    {
      v14 = 31;
    }
    *(_DWORD *)(v13 + 12) = v14;
    PopAcquirePowerRequestPushLock(1);
    PopInsertPowerRequestObject(v13, a2);
    if ( !a2 )
      PopUmpoSendPowerRequestOverrideQuery(v13, v15, v16, v17);
    dword_61F834 = 0;
    __pld(&PopPowerRequestLock);
    v19 = PopPowerRequestLock;
    if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
      v20 = 0;
    else
      v20 = PopPowerRequestLock - 16;
    if ( (PopPowerRequestLock & 2) != 0 )
      goto LABEL_27;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)&PopPowerRequestLock);
    while ( v21 == v19 && __strex(v20, (unsigned int *)&PopPowerRequestLock) );
    if ( v21 != v19 )
LABEL_27:
      ExfReleasePushLock(&PopPowerRequestLock, v19);
    v22 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
    PopDiagTracePowerRequestCreate(0, v13);
    *a1 = v13;
    result = 0;
  }
  return result;
}
