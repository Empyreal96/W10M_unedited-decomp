// ViGrowPoolAllocation 
 
int __fastcall ViGrowPoolAllocation(int a1)
{
  _DWORD *v2; // r0
  _DWORD *v3; // r4
  int v5; // r6

  v2 = (_DWORD *)ExAllocatePoolWithTagPriority(640, 0x1000u, 1886414166, 32);
  v3 = v2;
  if ( !v2 )
    return RtlpInterlockedPopEntrySList((unsigned __int64 *)(a1 + 32));
  KeZeroSinglePage(v2);
  v3[1] = a1;
  v3[2] = 556929861;
  RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1 + 24), v3);
  v5 = 254;
  do
  {
    v3 += 4;
    v3[2] = 1;
    RtlpInterlockedPushEntrySList((unsigned __int64 *)(a1 + 32), v3);
    --v5;
  }
  while ( v5 );
  v3[6] = 1;
  return (int)(v3 + 4);
}
