// PopClearSpecialRequest 
 
int __fastcall PopClearSpecialRequest(_DWORD *a1, int a2)
{
  int v3; // r6
  int v4; // r5
  int v5; // r1
  int v6; // r1
  unsigned int v7; // r0
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3
  int v12; // r2
  char v13; // r3

  if ( a2 != 3 )
    return -1073741811;
  v4 = 0;
  PopAcquirePowerRequestPushLock(1);
  if ( a1[17] )
  {
    v4 = a1[16];
    if ( v4 )
      a1[16] = 0;
    a1[17] = 0;
    --a1[9];
    PopDiagTracePowerRequestChange((int)a1, v5);
    v3 = 0;
  }
  else
  {
    v3 = -1073741811;
  }
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v6 = PopPowerRequestLock;
  v7 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v7 = 0;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_15;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v8 == v6 && __strex(v7, (unsigned int *)&PopPowerRequestLock) );
  if ( v8 != v6 )
LABEL_15:
    ExfReleasePushLock(&PopPowerRequestLock, v6);
  v9 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  if ( v4 )
  {
    v12 = v4 & 7;
    v13 = 1;
    if ( v12 == 5 )
    {
      v13 = 5;
      v12 = 0;
    }
    PspChargeJobWakeCounter((_DWORD *)(v4 & 0xFFFFFFF8), 0, v12, -1, 0xFFFFFFFF, 0xFFFFFFFF, v13, 0, (int)a1);
    ObDereferenceObjectDeferDeleteWithTag(v4 & 0xFFFFFFF8);
  }
  return v3;
}
