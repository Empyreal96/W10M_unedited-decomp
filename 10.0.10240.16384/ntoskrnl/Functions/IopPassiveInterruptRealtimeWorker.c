// IopPassiveInterruptRealtimeWorker 
 
void __fastcall __noreturn IopPassiveInterruptRealtimeWorker(int a1, int a2, int a3, int *a4)
{
  int *i; // [sp+8h] [bp-10h] BYREF

  for ( i = a4; ; ((void (__fastcall *)(int))i[2])(i[3]) )
  {
    do
      KeRemoveQueueEx(a1, 0, 0, 0, &i, 1u);
    while ( i == (int *)128 );
  }
}
