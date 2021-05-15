// KeQueryCpuSetsThread 
 
int __fastcall KeQueryCpuSetsThread(int a1, _DWORD *a2)
{
  int v4; // r0
  unsigned int *v5; // r4
  unsigned int v6; // r2

  v4 = KfRaiseIrql(2);
  v5 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  *a2 = *(_DWORD *)(a1 + 1092);
  a2[1] = 0;
  __dmb(0xBu);
  *v5 = 0;
  KfLowerIrql(v4);
  return 1;
}
