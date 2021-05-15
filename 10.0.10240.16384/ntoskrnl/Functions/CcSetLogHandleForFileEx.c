// CcSetLogHandleForFileEx 
 
int __fastcall CcSetLogHandleForFileEx(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // r6
  _DWORD *v7; // r5
  int v9; // r9
  int *v10; // r2
  int *v11; // r1
  int **v12; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r1
  unsigned int v16; // r3
  __int64 v18; // kr00_8
  int v20[34]; // [sp+10h] [bp-88h] BYREF

  v5 = a3;
  v7 = *(_DWORD **)(*(_DWORD *)(a1 + 20) + 4);
  if ( !v7[1] )
    KeBugCheckEx(52, 741, -1073740768);
  if ( (v7[24] & 0x2000000) != 0 )
    KeBugCheckEx(52, 747, -1073740768);
  v9 = KeAcquireQueuedSpinLock(5);
  if ( v7[38] )
  {
    v18 = *((_QWORD *)v7 + 10);
    if ( *(_DWORD **)(v18 + 4) != v7 + 20 || *(_DWORD **)HIDWORD(v18) != v7 + 20 )
      sub_5239DC();
    *(_DWORD *)HIDWORD(v18) = v18;
    *(_DWORD *)(v18 + 4) = HIDWORD(v18);
    v5 = a3;
  }
  if ( a2 )
  {
    v10 = v7 + 20;
    if ( v7[19] )
    {
      v11 = &CcDirtySharedCacheMapWithLogHandleList;
      v12 = (int **)dword_632614;
      *v10 = (int)&CcDirtySharedCacheMapWithLogHandleList;
      v7[21] = v12;
      if ( *v12 != &CcDirtySharedCacheMapWithLogHandleList )
        __fastfail(3u);
    }
    else
    {
      v11 = (int *)&CcCleanSharedCacheMapWithLogHandleList;
      v12 = (int **)dword_632604;
      *v10 = (int)&CcCleanSharedCacheMapWithLogHandleList;
      v7[21] = v12;
      if ( *v12 != (int *)&CcCleanSharedCacheMapWithLogHandleList )
        __fastfail(3u);
    }
    *v12 = v10;
    v11[1] = (int)v10;
    if ( !*(_DWORD *)(v7[89] + 24) )
    {
      memset(v20, 0, 104);
      v20[1] = v5;
      v20[2] = a4;
      v20[0] = a2;
      v20[22] = -1;
      v20[23] = -1;
      if ( a5 )
      {
        ObfReferenceObjectWithTag(a5, 1953261124);
        v20[20] = a5;
      }
      memmove(v7[89] + 24, (int)v20, 0x68u);
    }
    v13 = v7[89] + 24;
    v14 = v7[24];
    v7[38] = v13;
    if ( (v14 & 0x1000000) == 0 )
    {
      v15 = v7[19];
      if ( v15 )
        *(_DWORD *)(v13 + 12) += v15;
    }
    v16 = v7[24] | 0x1000000;
  }
  else
  {
    v7[38] = 0;
    v16 = v7[24] & 0xFEFFFFFF;
  }
  v7[24] = v16;
  return KeReleaseQueuedSpinLock(5, v9);
}
