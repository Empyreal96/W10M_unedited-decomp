// IopLiveDumpUncorralProcessors 
 
int __fastcall IopLiveDumpUncorralProcessors(int a1, int a2)
{
  int v4; // r1
  int v5; // r2
  int v6; // r3
  __int64 v7; // r0
  int v8; // r2

  IopLiveDumpInitiateCorralStateChange((unsigned int *)a1, 5u);
  IopLiveDumpInitiateCorralStateChange((unsigned int *)a1, 6u);
  PoAllProcIntrDisabled = 0;
  IopLiveDumpInitiateCorralStateChange((unsigned int *)a1, 0xFFFFFFFF);
  LODWORD(v7) = KeRevertToUserGroupAffinityThread(a1 + 56, v4, v5, v6);
  if ( a2 == 1 )
    v7 = KfLowerIrql(*(unsigned __int8 *)(a1 + 52));
  IopLiveDumpUnLockPages(v7, SHIDWORD(v7), v8);
  *(_DWORD *)(a1 + 4) &= 0xFFFFFFFE;
  return IopLiveDumpTraceSystemQuiesceEnd();
}
