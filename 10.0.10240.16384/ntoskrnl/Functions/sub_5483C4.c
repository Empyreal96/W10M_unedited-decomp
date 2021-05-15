// sub_5483C4 
 
void sub_5483C4()
{
  int v0; // r5
  int v1; // r7
  int v2; // r4
  int v3; // r2
  unsigned int v4; // r1

  v2 = KfRaiseIrql(2);
  MiClearStackOwners(v1, v0);
  KfLowerIrql(v2);
  v3 = v1 << 10;
  *(_DWORD *)(v3 + 4080) = dword_634C80 ^ (v1 << 10);
  *(_DWORD *)(v3 + 4092) = v0 & 0xFFFFFFFD;
  RtlpInterlockedPushEntrySList((unsigned __int64 *)&algn_634841[7], (_DWORD *)((v1 << 10) + 4088));
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)algn_634868);
  while ( !v4 && __strex(1u, (unsigned int *)algn_634868) );
  if ( !v4 )
    ExQueueWorkItem(&dword_634858, 2);
  JUMPOUT(0x4C7BCC);
}
