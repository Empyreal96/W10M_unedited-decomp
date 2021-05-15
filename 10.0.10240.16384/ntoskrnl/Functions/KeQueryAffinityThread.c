// KeQueryAffinityThread 
 
int __fastcall KeQueryAffinityThread(int a1, int a2)
{
  int v4; // r0
  unsigned int *v5; // r4
  unsigned int v6; // r2

  *(_DWORD *)(a2 + 6) = 0;
  *(_WORD *)(a2 + 10) = 0;
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
  *(_WORD *)(a2 + 4) = *(_WORD *)(a1 + 344);
  *(_DWORD *)a2 = *(_DWORD *)(a1 + 340);
  __dmb(0xBu);
  *v5 = 0;
  return KfLowerIrql(v4);
}
