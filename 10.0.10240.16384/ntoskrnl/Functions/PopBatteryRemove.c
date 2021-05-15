// PopBatteryRemove 
 
int __fastcall PopBatteryRemove(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  __int64 v6; // r0
  int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r2
  int result; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  IoCancelIrp(*(_DWORD *)(a1 + 28));
  KeWaitForSingleObject(a1 + 40, 0, 0, 0, 0);
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)PopCB, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)PopCB);
  while ( __strex(v5 | 1, (unsigned __int8 *)PopCB) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(PopCB, v3, (unsigned int)PopCB);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_61ED64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(a1 + 32) )
  {
    v6 = *(_QWORD *)(a1 + 32);
    if ( *(_DWORD *)(v6 + 4) != a1 + 32 || *(_DWORD *)HIDWORD(v6) != a1 + 32 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v6) = v6;
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    *(_DWORD *)(a1 + 32) = 0;
    byte_61ED70 = 1;
    --dword_61ED6C;
    ++dword_61EDBC;
    PopBatteryQueueWork(3);
  }
  dword_61ED64 = 0;
  __pld(PopCB);
  v7 = PopCB[0];
  if ( (PopCB[0] & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  else
    v8 = PopCB[0] - 16;
  if ( (PopCB[0] & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)PopCB);
  while ( v9 == v7 && __strex(v8, (unsigned int *)PopCB) );
  if ( v9 != v7 )
LABEL_20:
    ExfReleasePushLock(PopCB, v7);
  result = KeAbPostRelease((unsigned int)PopCB);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( !--dword_61ED68 )
  {
    PopAcquirePolicyLock();
    if ( byte_61EA5E )
    {
      byte_61EA5E = 0;
      PopResetCurrentPolicies();
    }
    result = PopReleasePolicyLock();
  }
  return result;
}
