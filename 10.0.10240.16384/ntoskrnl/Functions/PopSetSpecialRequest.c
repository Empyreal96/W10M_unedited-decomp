// PopSetSpecialRequest 
 
int __fastcall PopSetSpecialRequest(_DWORD *a1, int a2, int a3)
{
  int v4; // r4
  int v5; // r4
  int v6; // r8
  int v7; // r6
  int v8; // r1
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r2
  char v16; // r3
  int v18[8]; // [sp+18h] [bp-20h] BYREF

  if ( a2 != 3 )
    return -1073741811;
  v4 = ObReferenceObjectByHandle(a3, 0x1FFFFF, PsProcessType, 1, (int)v18, 0);
  if ( v4 >= 0 )
  {
    v5 = *(_DWORD *)(v18[0] + 288);
    __dmb(0xBu);
    v6 = v18[0];
    if ( v5 && (*(_DWORD *)(v5 + 744) & 0x1000) != 0 )
    {
      __mrc(15, 0, 13, 0, 3);
      PspChargeJobWakeCounter((_DWORD *)v5, 0, 3, 1, 1u, 0, 1, v6, (int)a1);
      ObfReferenceObjectWithTag(v5);
      v7 = v5 | 3;
    }
    else
    {
      v7 = 0;
    }
    PopAcquirePowerRequestPushLock(1);
    if ( a1[17] )
    {
      v4 = -1073741811;
    }
    else
    {
      a1[16] = v7;
      a1[17] = v6;
      v7 = 0;
      ++a1[9];
      PopDiagTracePowerRequestChange((int)a1, v8);
      v4 = 0;
    }
    dword_61F834 = 0;
    __pld(&PopPowerRequestLock);
    v9 = PopPowerRequestLock;
    v10 = PopPowerRequestLock - 16;
    if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
      v10 = 0;
    if ( (PopPowerRequestLock & 2) != 0 )
      goto LABEL_18;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&PopPowerRequestLock);
    while ( v11 == v9 && __strex(v10, (unsigned int *)&PopPowerRequestLock) );
    if ( v11 != v9 )
LABEL_18:
      ExfReleasePushLock(&PopPowerRequestLock, v9);
    v12 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = *(_WORD *)(v13 + 0x134) + 1;
    *(_WORD *)(v13 + 308) = v14;
    if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
      KiCheckForKernelApcDelivery(v12);
    if ( v7 )
    {
      v15 = v7 & 7;
      v16 = 1;
      if ( v15 == 5 )
      {
        v16 = 5;
        v15 = 0;
      }
      PspChargeJobWakeCounter((_DWORD *)(v7 & 0xFFFFFFF8), 0, v15, -1, 0xFFFFFFFF, 0xFFFFFFFF, v16, 0, (int)a1);
      ObDereferenceObjectDeferDeleteWithTag(v7 & 0xFFFFFFF8);
    }
    ObfDereferenceObject(v6);
  }
  return v4;
}
