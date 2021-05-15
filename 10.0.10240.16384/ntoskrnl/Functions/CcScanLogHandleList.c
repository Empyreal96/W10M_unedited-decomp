// CcScanLogHandleList 
 
int __fastcall CcScanLogHandleList(int *a1, int a2, _DWORD *a3)
{
  int v5; // r7
  int v6; // r6
  int v7; // r4
  int v8; // r0
  int v9; // r3
  int v10; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r0
  unsigned int v16; // r3
  __int64 v17; // kr00_8
  int v18; // r3
  __int64 v19; // r0
  int v20; // r0
  unsigned __int16 v21; // [sp+8h] [bp-28h] BYREF
  int v22; // [sp+Ch] [bp-24h]

  v21 = 0;
  *a3 = -1;
  a3[1] = 0x7FFFFFFF;
  *a1 = 0;
  v22 = a2;
  v5 = KeAcquireQueuedSpinLock(5);
  v6 = CcVolumeCacheMapList;
  if ( (int *)CcVolumeCacheMapList == &CcVolumeCacheMapList )
    return KeReleaseQueuedSpinLock(5, v5);
  while ( 1 )
  {
    v7 = v6 - 12;
    ++*(_DWORD *)(v6 - 8);
    KeReleaseQueuedSpinLock(5, v5);
    v8 = *(_DWORD *)(v6 + 12);
    if ( v8 )
      (*(void (__fastcall **)(int, unsigned __int16 *))(v6 + 20))(v8, &v21);
    v5 = KeAcquireQueuedSpinLock(5);
    if ( !*(_DWORD *)(v6 + 12) )
      goto LABEL_5;
    v12 = *(_DWORD *)(v6 + 24);
    if ( v12 == -1 )
      return sub_53BD30();
    *(_DWORD *)(v6 + 48) = v12;
    if ( v21 )
    {
      *(_DWORD *)(v6 + 48) = 100 * v12;
      if ( !v21 )
        __brkdiv0();
      *(_DWORD *)(v6 + 48) = 100 * v12 / (unsigned int)v21;
    }
    else
    {
      *(_DWORD *)(v6 + 48) = *(_DWORD *)(v6 + 80);
    }
    v13 = *(_DWORD *)(v6 + 48);
    v14 = v22;
    *(_DWORD *)(v6 + 40) = v13;
    *(_DWORD *)(v6 + 44) = v13;
    *(_DWORD *)(v6 + 36) = v13;
    *(_DWORD *)(v6 + 48) = (unsigned int)(3 * v13) >> 2;
    v15 = CcCalculatePagesToWrite(v14, v6 + 24, v6 + 36, 1);
    v16 = *(_DWORD *)(v6 + 24);
    *(_DWORD *)(v6 + 28) = v16;
    if ( v15 > v16 >> 3 )
    {
      v18 = *a1;
      *(_DWORD *)(v6 + 76) = v15;
      *a1 = v18 + v15;
      ++CcDbgAdditionalPagesQueuedCount;
    }
    else
    {
      *(_DWORD *)(v6 + 76) = 0;
    }
    *(_DWORD *)(v6 + 32) = *(_DWORD *)(v6 + 76);
    if ( *(_DWORD *)(v6 + 8) )
    {
      v17 = *(_QWORD *)(v6 + 100);
      if ( v17 < *(_QWORD *)a3 )
        *(_QWORD *)a3 = v17;
    }
LABEL_5:
    v9 = *(_DWORD *)(v6 - 8);
    v6 = *(_DWORD *)v6;
    if ( !v9 )
      KeBugCheckEx(52, 1369, -1073740768);
    v10 = v9 - 1;
    *(_DWORD *)(v7 + 4) = v10;
    if ( !v10 )
    {
      v19 = *(_QWORD *)(v7 + 12);
      if ( *(_DWORD *)(v19 + 4) != v7 + 12 || *(_DWORD *)HIDWORD(v19) != v7 + 12 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      v20 = *(_DWORD *)(v7 + 104);
      if ( v20 )
      {
        ObfDereferenceObjectWithTag(v20);
        *(_DWORD *)(v7 + 104) = 0;
      }
      ExFreePoolWithTag(v7, 1834378051);
    }
    if ( (int *)v6 == &CcVolumeCacheMapList )
      return KeReleaseQueuedSpinLock(5, v5);
  }
}
