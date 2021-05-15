// IopQueueThreadIrp 
 
int __fastcall IopQueueThreadIrp(int a1)
{
  int v1; // r3
  int *v2; // r5
  int *v3; // r4
  unsigned int *v4; // r6
  int v5; // r7
  unsigned int v7; // r2
  int v8; // r2

  v1 = *(_DWORD *)(a1 + 80);
  v2 = (int *)(a1 + 16);
  v3 = (int *)(v1 + 908);
  v4 = (unsigned int *)(v1 + 1024);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52C910();
  do
    v7 = __ldrex(v4);
  while ( __strex(1u, v4) );
  __dmb(0xBu);
  if ( v7 )
    KxWaitForSpinLockAndAcquire(v4);
  v8 = *v3;
  *v2 = *v3;
  v2[1] = (int)v3;
  if ( *(int **)(v8 + 4) != v3 )
    __fastfail(3u);
  *(_DWORD *)(v8 + 4) = v2;
  *v3 = (int)v2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  return KfLowerIrql(v5);
}
