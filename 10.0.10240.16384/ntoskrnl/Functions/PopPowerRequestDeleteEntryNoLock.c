// PopPowerRequestDeleteEntryNoLock 
 
int __fastcall PopPowerRequestDeleteEntryNoLock(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r1
  unsigned int v5; // r0
  unsigned int v6; // r2
  int result; // r0
  unsigned int v8; // r1
  __int16 v9; // r3

  PopAcquirePowerRequestPushLock(1);
  RtlDeleteElementGenericTableAvl((int)&PopPowerRequestTable, a1, v2, v3);
  dword_61F834 = 0;
  __pld(&PopPowerRequestLock);
  v4 = PopPowerRequestLock;
  v5 = PopPowerRequestLock - 16;
  if ( (PopPowerRequestLock & 0xFFFFFFF0) <= 0x10 )
    v5 = 0;
  if ( (PopPowerRequestLock & 2) != 0 )
    goto LABEL_8;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&PopPowerRequestLock);
  while ( v6 == v4 && __strex(v5, (unsigned int *)&PopPowerRequestLock) );
  if ( v6 != v4 )
LABEL_8:
    ExfReleasePushLock(&PopPowerRequestLock, v4);
  result = KeAbPostRelease((unsigned int)&PopPowerRequestLock);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
