// MiUnlinkSessionList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiUnlinkSessionList(int a1, int a2, int a3, int a4)
{
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  _DWORD v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a3;
  v8[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634980, (unsigned int)v8);
  if ( *(_DWORD *)(a1 + 96) )
  {
    *(_QWORD *)&v5 = *(_QWORD *)(a1 + 96);
    if ( *(_DWORD *)(v5 + 4) != a1 + 96 || *v6 != a1 + 96 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
  }
  return KeReleaseInStackQueuedSpinLock((int)v8);
}
