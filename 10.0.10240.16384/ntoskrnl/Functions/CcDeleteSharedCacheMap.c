// CcDeleteSharedCacheMap 
 
int __fastcall CcDeleteSharedCacheMap(int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r6
  int v6; // r3
  _DWORD *v8; // r0
  __int64 v10; // kr00_8
  __int64 v11; // r2
  BOOL v12; // r1
  unsigned int *v13; // r4
  unsigned int v14; // r0
  unsigned int i; // r3
  unsigned int v16; // r1
  int v17; // r0
  int v18; // r0
  int v19; // r4
  int v20; // r0
  int v21; // r0
  int v22; // r0
  int v24; // r0

  v4 = a1 + 88;
  v6 = *(_DWORD *)(a1 + 88);
  v8 = *(_DWORD **)(a1 + 92);
  if ( *(_DWORD *)(v6 + 4) != v4 || *v8 != v4 )
    __fastfail(3u);
  *v8 = v6;
  *(_DWORD *)(v6 + 4) = v8;
  if ( (*(_DWORD *)(a1 + 96) & 0x3000000) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( *(_DWORD *)(v10 + 4) != a1 + 80 || *(_DWORD *)HIDWORD(v10) != a1 + 80 )
      sub_53E50C();
    *(_DWORD *)HIDWORD(v10) = v10;
    *(_DWORD *)(v10 + 4) = HIDWORD(v10);
  }
  *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(a1 + 68) & 0xFFFFFFF8) + 20) + 4) = 0;
  *(_DWORD *)(a1 + 96) |= 0x80020u;
  KeReleaseQueuedSpinLock(5, a2);
  LODWORD(v11) = a1 + 16;
  if ( *(_DWORD *)(a1 + 16) != a1 + 16 )
    CcDeleteBcbs(a1);
  v12 = 0;
  if ( (*(_DWORD *)(a1 + 96) & 0x1000) == 0 )
  {
    v11 = *(_QWORD *)(a1 + 8);
    if ( v11 >= 0x100000 )
      v12 = 1;
  }
  CcUnmapAndPurge(a1, v12, v11);
  if ( a3 )
  {
    FsRtlReleaseFile(a4);
    v13 = (unsigned int *)(a1 + 68);
    __pld((void *)(a1 + 68));
    v14 = *(_DWORD *)(a1 + 68);
    for ( i = v14 ^ a4; i < 7; i = v16 ^ a4 )
    {
      __dmb(0xBu);
      do
        v16 = __ldrex(v13);
      while ( v16 == v14 && __strex(v14 + 1, v13) );
      if ( v16 == v14 )
        goto LABEL_20;
      v14 = v16;
    }
    ObDereferenceObjectDeferDeleteWithTag(a4);
  }
LABEL_20:
  v17 = *(_DWORD *)(a1 + 108);
  if ( v17 )
    ObfDereferenceObjectWithTag(v17);
  if ( *(_DWORD *)(a1 + 104) )
    CcDeleteMbcb(a1);
  CcUninitializeVolumeCacheMap(*(_DWORD *)(a1 + 356));
  v18 = ObFastReplaceObject(a1 + 68, 0);
  ObfDereferenceObjectWithTag(v18);
  v19 = *(_DWORD *)(a1 + 176);
  while ( v19 )
  {
    v24 = (v19 & 0xFFFFFFFE) + 4;
    v19 = *(_DWORD *)(v19 & 0xFFFFFFFE);
    KeSetEvent(v24, 0, 0);
  }
  v20 = *(_DWORD *)(a1 + 64);
  if ( v20 != a1 + 48 && v20 )
    ExFreePoolWithTag(v20, 0);
  v21 = *(_DWORD *)(a1 + 112);
  if ( v21 && v21 != a1 + 224 )
    ExFreePoolWithTag(v21, 0);
  v22 = *(_DWORD *)(a1 + 116);
  if ( v22 && v22 != a1 + 224 )
    ExFreePoolWithTag(v22, 0);
  return ExFreePoolWithTag(a1, 0);
}
