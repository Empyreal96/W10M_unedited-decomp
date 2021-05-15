// PopBatteryReleaseLock 
 
int PopBatteryReleaseLock()
{
  int v0; // r1
  unsigned int v1; // r0
  unsigned int v2; // r2
  int result; // r0
  unsigned int v4; // r1
  __int16 v5; // r3

  dword_61ED64 = 0;
  __pld(PopCB);
  v0 = PopCB[0];
  v1 = PopCB[0] - 16;
  if ( (PopCB[0] & 0xFFFFFFF0) <= 0x10 )
    v1 = 0;
  if ( (PopCB[0] & 2) != 0 )
    goto LABEL_8;
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)PopCB);
  while ( v2 == v0 && __strex(v1, (unsigned int *)PopCB) );
  if ( v2 != v0 )
LABEL_8:
    ExfReleasePushLock(PopCB, v0);
  result = KeAbPostRelease((unsigned int)PopCB);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(_WORD *)(v4 + 0x134) + 1;
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
