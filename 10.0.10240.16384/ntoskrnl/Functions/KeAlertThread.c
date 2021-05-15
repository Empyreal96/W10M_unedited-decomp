// KeAlertThread 
 
int __fastcall KeAlertThread(int a1, char a2)
{
  int v3; // r7
  int v4; // r8
  unsigned int v5; // r6
  unsigned int *v6; // r5
  unsigned int v7; // r2
  int v8; // r4

  v3 = a2;
  v4 = KfRaiseIrql(2);
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( !v7 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v6 );
  }
  v8 = KiAlertThread(v5 + 1408, a1, v3);
  __dmb(0xBu);
  *v6 = 0;
  KiExitDispatcher(v5 + 1408, 0, 1, 2, v4);
  return v8;
}
