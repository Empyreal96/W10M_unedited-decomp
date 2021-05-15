// PopBatteryAdd 
 
int __fastcall PopBatteryAdd(int a1)
{
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  unsigned int v10; // r1
  int v11; // r3

  KeInitializeEvent(a1 + 40, 1, 0);
  if ( ++dword_61ED68 == 1 )
  {
    v2 = PopAcquirePolicyLock();
    if ( byte_61EA5E != 1 )
    {
      byte_61EA5E = 1;
      PopResetCurrentPolicies(v2);
    }
    PopReleasePolicyLock();
  }
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)PopCB, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)PopCB);
  while ( __strex(v5 | 1, (unsigned __int8 *)PopCB) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    return sub_7F16C8(v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61ED64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  byte_61ED70 = 1;
  PopBatteryWaitTag(a1);
  dword_61ED64 = 0;
  __pld(PopCB);
  v7 = PopCB[0];
  if ( (PopCB[0] & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  else
    v8 = PopCB[0] - 16;
  if ( (PopCB[0] & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)PopCB);
  while ( v9 == v7 && __strex(v8, (unsigned int *)PopCB) );
  if ( v9 != v7 )
LABEL_21:
    ExfReleasePushLock(PopCB, v7);
  result = KeAbPostRelease((unsigned int)PopCB);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = (__int16)(*(_WORD *)(v10 + 0x134) + 1);
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
