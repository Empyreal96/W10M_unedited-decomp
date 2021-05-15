// PopFxEmergencyWorker 
 
void __fastcall __noreturn PopFxEmergencyWorker(int a1, int a2, int a3, int *a4)
{
  int *v5; // [sp+8h] [bp-10h] BYREF

  v5 = a4;
  KeSetActualBasePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 16);
  while ( 1 )
  {
    do
      KeRemoveQueueEx(a1, 0, 0, 0, &v5, 1u);
    while ( v5 == (int *)128 );
    ((void (__fastcall *)(int))v5[2])(v5[3]);
  }
}
