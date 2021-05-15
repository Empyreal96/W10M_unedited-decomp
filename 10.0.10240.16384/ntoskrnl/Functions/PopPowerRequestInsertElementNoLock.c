// PopPowerRequestInsertElementNoLock 
 
int __fastcall PopPowerRequestInsertElementNoLock(int a1, int a2, int a3, int a4)
{
  int v4; // r6
  int v5; // r1
  unsigned int v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  _DWORD v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[2] = a4;
  v12[1] = a1;
  PopAcquirePowerRequestPushLock(1);
  v4 = RtlInsertElementGenericTableAvl((int)&PopPowerRequestTable, (int)v12, 8, 0);
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v5 = PopPowerRequestLock;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) > 0x10 )
    v6 = PopPowerRequestLock - 16;
  else
    v6 = 0;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_14;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&PopPowerRequestLock) );
  if ( v7 != v5 )
LABEL_14:
    ExfReleasePushLock(&PopPowerRequestLock, v5);
  v8 = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v4;
}
