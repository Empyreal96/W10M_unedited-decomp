// sub_7F1524 
 
void __fastcall sub_7F1524(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // r6
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  a5[3] = 18;
  PopAcquirePowerRequestPushLock(1);
  PopInsertPowerRequestObject(a5, 0);
  PopUmpoSendPowerRequestOverrideQuery((int)a5, v6, v7, v8);
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v9 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  else
    v10 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_9;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v11 == v9 && __strex(v10, (unsigned int *)&PopPowerRequestLock) );
  if ( v11 != v9 )
LABEL_9:
    ExfReleasePushLock(&PopPowerRequestLock, v9);
  v12 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  PopDiagTracePowerRequestCreate(0);
  *v5 = a5;
  JUMPOUT(0x78C3FE);
}
