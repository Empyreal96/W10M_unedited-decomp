// PsTerminateServerSilo 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PsTerminateServerSilo(int a1, int a2)
{
  int v5; // r5
  unsigned int *v6; // r2
  unsigned int v7; // r1
  int (*v8)(); // r3

  if ( !a1 )
    return -1073741811;
  v5 = *(_DWORD *)(a1 + 144);
  __dmb(0xBu);
  v6 = (unsigned int *)(v5 + 56);
  do
    v7 = __ldrex(v6);
  while ( v7 == 1 && __strex(2u, v6) );
  __dmb(0xBu);
  if ( v7 == 1 )
  {
    PsTerminateAllProcessesInSilo(a1, a2);
    v8 = PspTerminateServerSiloDeferred;
    *(_QWORD *)(v5 + 48) = *(_QWORD *)(&a1 - 1);
    *(_DWORD *)(v5 + 40) = 0;
    ExQueueWorkItem((_DWORD *)(v5 + 40), 1);
  }
  return 0;
}
