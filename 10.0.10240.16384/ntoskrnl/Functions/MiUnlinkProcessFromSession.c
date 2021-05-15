// MiUnlinkProcessFromSession 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiUnlinkProcessFromSession(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  _DWORD v11[4]; // [sp+0h] [bp-10h] BYREF

  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v5 = KeAcquireInStackQueuedSpinLock(&dword_634980, v11);
  if ( *(_DWORD *)(a1 + 324) && *(_DWORD *)(a1 + 232) )
  {
    if ( (*(_BYTE *)(a1 + 605) & 1) != 0 )
      return sub_514FE4(v5);
    *(_QWORD *)&v7 = *(_QWORD *)(a1 + 232);
    if ( *(_DWORD *)(v7 + 4) != a1 + 232 || *v8 != a1 + 232 )
      __fastfail(3u);
    *v8 = v7;
    *(_DWORD *)(v7 + 4) = v8;
  }
  *(_QWORD *)&v9 = *(_QWORD *)(a1 + 620);
  if ( *(_DWORD *)(v9 + 4) != a1 + 620 || *v10 != a1 + 620 )
    __fastfail(3u);
  *v10 = v9;
  *(_DWORD *)(v9 + 4) = v10;
  return KeReleaseInStackQueuedSpinLock(v11);
}
