// PopBatteryAcquireExclusiveLock 
 
int PopBatteryAcquireExclusiveLock()
{
  unsigned int v0; // r2
  int result; // r0
  int v2; // r4
  unsigned int v3; // r2

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  result = KeAbPreAcquire((unsigned int)PopCB, 0, 0);
  v2 = result;
  do
    v3 = __ldrex((unsigned __int8 *)PopCB);
  while ( __strex(v3 | 1, (unsigned __int8 *)PopCB) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(PopCB, result, (unsigned int)PopCB);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61ED64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}
