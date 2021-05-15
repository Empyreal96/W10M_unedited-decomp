// MiDeletePartitionFromList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiDeletePartitionFromList(int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a2;
  v7[1] = a3;
  v7[2] = a4;
  v4 = result;
  if ( *(_DWORD *)(result + 16) )
  {
    KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634318, (unsigned int)v7);
    *(_QWORD *)&v5 = *(_QWORD *)(v4 + 16);
    if ( *(_DWORD *)(v5 + 4) != v4 + 16 || *v6 != v4 + 16 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    result = KeReleaseInStackQueuedSpinLock((int)v7);
  }
  return result;
}
