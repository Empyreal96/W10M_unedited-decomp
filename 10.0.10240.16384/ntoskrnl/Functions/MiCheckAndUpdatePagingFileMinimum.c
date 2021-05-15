// MiCheckAndUpdatePagingFileMinimum 
 
int __fastcall MiCheckAndUpdatePagingFileMinimum(unsigned int *a1, unsigned int a2, int a3, int a4)
{
  int v6; // r4
  _DWORD v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  v6 = 1;
  KeAcquireInStackQueuedSpinLock(a1 + 29, (unsigned int)v8);
  if ( a2 > *a1 )
    v6 = 0;
  else
    a1[2] = a2;
  KeReleaseInStackQueuedSpinLock((int)v8);
  return v6;
}
