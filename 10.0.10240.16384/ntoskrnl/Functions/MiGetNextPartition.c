// MiGetNextPartition 
 
int *__fastcall MiGetNextPartition(int a1, int a2, int a3, int a4)
{
  int *v5; // r6
  int *v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // r3
  _DWORD v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[1] = a3;
  v11[2] = a4;
  v5 = 0;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634318, (unsigned int)v11);
  if ( a1 )
    v6 = *(int **)(a1 + 16);
  else
    v6 = (int *)dword_634328;
  while ( v6 != &dword_634328 )
  {
    if ( (*(v6 - 3) & 1) == 0 )
    {
      v5 = v6 - 4;
      ++*(v6 - 2);
      break;
    }
    v6 = (int *)*v6;
  }
  KeReleaseInStackQueuedSpinLock((int)v11);
  if ( a1 )
    MiDereferencePartition(a1, v7, v8, v9);
  return v5;
}
