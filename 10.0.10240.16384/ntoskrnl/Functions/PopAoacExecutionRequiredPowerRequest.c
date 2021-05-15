// PopAoacExecutionRequiredPowerRequest 
 
int __fastcall PopAoacExecutionRequiredPowerRequest(int a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r7
  int *v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v18[6]; // [sp+0h] [bp-18h] BYREF

  v18[0] = a3;
  v5 = 0;
  PopAcquirePowerRequestPushLock(1);
  v6 = dword_60E1F8;
  v18[1] = a2;
  v7 = (int *)RtlLookupElementGenericTableAvl((int)&PopPowerRequestTable, (int)v18);
  if ( v7 )
  {
    v10 = *v7;
    if ( a1 )
      PopEnablePowerExecutionRequest(v10);
    else
      PopDisablePowerExecutionRequest(v10, 1, v8, v9, v18[0]);
  }
  if ( a1 || !v6 )
    v5 = 259;
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v11 = PopPowerRequestLock;
  v12 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v12 = 0;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_15;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&PopPowerRequestLock) );
  if ( v13 != v11 )
LABEL_15:
    ExfReleasePushLock(&PopPowerRequestLock, v11);
  v14 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v5;
}
