// CcSetLogHandleForFile 
 
int __fastcall CcSetLogHandleForFile(int a1, int a2, int a3)
{
  _DWORD *v5; // r4
  int v6; // r0
  int v7; // r3
  int v8; // lr
  __int64 v9; // kr00_8
  int *v10; // r2
  int *v11; // r1
  int **v12; // r0

  v5 = *(_DWORD **)(*(_DWORD *)(a1 + 20) + 4);
  if ( !v5[1] )
    KeBugCheckEx(52, 590, -1073740768, 0, 0);
  if ( (v5[24] & 0x1000000) != 0 )
    KeBugCheckEx(52, 596, -1073740768, 0, 0);
  v6 = KeAcquireQueuedSpinLock(5);
  v7 = v5[38];
  v8 = v6;
  v5[39] = a3;
  if ( v7 )
  {
    v9 = *((_QWORD *)v5 + 10);
    if ( *(_DWORD **)(v9 + 4) != v5 + 20 || *(_DWORD **)HIDWORD(v9) != v5 + 20 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v9) = v9;
    *(_DWORD *)(v9 + 4) = HIDWORD(v9);
  }
  if ( a2 )
  {
    v10 = v5 + 20;
    v5[24] |= 0x2000000u;
    if ( v5[19] )
    {
      v11 = &CcDirtySharedCacheMapWithLogHandleList;
      v12 = (int **)dword_632614;
      *v10 = (int)&CcDirtySharedCacheMapWithLogHandleList;
      v5[21] = v12;
      if ( *v12 != &CcDirtySharedCacheMapWithLogHandleList )
        __fastfail(3u);
    }
    else
    {
      v11 = (int *)&CcCleanSharedCacheMapWithLogHandleList;
      v12 = (int **)dword_632604;
      *v10 = (int)&CcCleanSharedCacheMapWithLogHandleList;
      v5[21] = v12;
      if ( *v12 != (int *)&CcCleanSharedCacheMapWithLogHandleList )
        __fastfail(3u);
    }
    *v12 = v10;
    v11[1] = (int)v10;
  }
  v5[38] = a2;
  return KeReleaseQueuedSpinLock(5, v8);
}
