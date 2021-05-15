// CcNotifyOfMappedWriteComplete 
 
// local variable allocation has failed, the output may be wrong!
int CcNotifyOfMappedWriteComplete(int a1, int a2, ...)
{
  unsigned int v2; // r2
  unsigned __int64 v3; // r0
  int v4; // r4
  char v5; // r9
  _DWORD *v6; // r6
  int v7; // r0
  int v8; // r3
  int v9; // r8
  unsigned int v10; // r7
  unsigned int i; // r3
  unsigned int v12; // r5
  unsigned int v13; // r5 OVERLAPPED
  unsigned int v14; // r6 OVERLAPPED
  int v15; // r6
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int *v19; // r2
  __int64 v20; // kr00_8
  int **v21; // r0
  int *v22; // r2
  __int64 v23; // r0
  int **v24; // r0
  int v25; // r1
  int v26; // r0
  BOOL v28; // r5
  int *v29; // r2
  __int64 v30; // r0
  int **v31; // r0
  int *v32; // r2
  __int64 v33; // r0
  int **v34; // r0
  unsigned int varg_r2; // [sp+38h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+38h] [bp+10h]
  unsigned int varg_r3; // [sp+3Ch] [bp+14h]
  int v38; // [sp+40h] [bp+18h]
  int v39; // [sp+44h] [bp+1Ch]
  va_list va1; // [sp+48h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  v2 = varg_r2;
  varg_r3 = va_arg(va1, _DWORD);
  v38 = va_arg(va1, _DWORD);
  v39 = va_arg(va1, _DWORD);
  HIDWORD(v3) = varg_r3;
  v4 = *(_DWORD *)(a1 + 4);
  v5 = 0;
  if ( v39 < 0 )
  {
    if ( !*(_DWORD *)(v4 + 4) )
      KeBugCheckEx(52, 4935, -1073740768, 0, 0);
    v6 = (_DWORD *)(v4 + 68);
    v7 = ObFastReferenceObject((_DWORD *)(v4 + 68));
    if ( !v7 )
      v7 = CcSlowReferenceSharedCacheMapFileObject(v4);
    v8 = *(_DWORD *)(v7 + 4);
    __pld(v6);
    v9 = *(_DWORD *)(v8 + 32);
    v10 = *v6;
    for ( i = *v6 ^ v7; i < 7; i = v12 ^ v7 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex(v6);
      while ( v12 == v10 && __strex(v10 + 1, v6) );
      if ( v12 == v10 )
        goto LABEL_13;
      v10 = v12;
    }
    ObDereferenceObjectDeferDeleteWithTag(v7);
LABEL_13:
    v3 = __PAIR64__(varg_r3, MmIsWriteErrorFatal(1, v9 & 0x10, v39));
    v2 = varg_r2;
    if ( !(_DWORD)v3 )
      v5 = 1;
  }
  LODWORD(v3) = v38;
  *(_QWORD *)&v13 = *(_QWORD *)(v4 + 40);
  if ( (__int64)(v3 + v2) > *(__int64 *)&v13 )
  {
    if ( __SPAIR64__(HIDWORD(v3), v2) > __SPAIR64__(v14, v13) )
      goto LABEL_20;
    LODWORD(v3) = v13 - v2;
  }
  if ( (_DWORD)v3 )
    LODWORD(v3) = CcReleaseByteRangeFromWrite(v4, (unsigned int *)varg_r2a, v3, 0, v5);
LABEL_20:
  if ( (int *)CcDeferredWrites != &CcDeferredWrites )
    CcPostDeferredWrites(v3);
  v15 = KeAcquireQueuedSpinLock(5);
  --*(_DWORD *)(v4 + 364);
  v16 = *(_DWORD *)(v4 + 4) - 1;
  *(_DWORD *)(v4 + 4) = v16;
  if ( !v16 )
  {
    byte_632771 = 1;
    v17 = *(_DWORD *)(v4 + 96);
    v18 = *(_DWORD *)(v4 + 76);
    if ( (v17 & 0x10000) != 0 )
    {
      if ( !v18 )
      {
        if ( (v17 & 0x3000000) != 0 )
        {
          v19 = (int *)(v4 + 80);
          v20 = *(_QWORD *)(v4 + 80);
          if ( *(_DWORD *)(v20 + 4) != v4 + 80 || *(int **)HIDWORD(v20) != v19 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v20) = v20;
          *(_DWORD *)(v20 + 4) = HIDWORD(v20);
          v21 = (int **)dword_632614;
          *v19 = (int)&CcDirtySharedCacheMapWithLogHandleList;
          *(_DWORD *)(v4 + 84) = v21;
          if ( *v21 != &CcDirtySharedCacheMapWithLogHandleList )
            __fastfail(3u);
          *v21 = v19;
          dword_632614 = v4 + 80;
        }
        v22 = (int *)(v4 + 88);
        v23 = *(_QWORD *)(v4 + 88);
        if ( *(_DWORD *)(v23 + 4) != v4 + 88 || *(int **)HIDWORD(v23) != v22 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v23) = v23;
        *(_DWORD *)(v23 + 4) = HIDWORD(v23);
        v24 = (int **)dword_632634;
        *v22 = (int)&CcLazyWriterCursor;
        *(_DWORD *)(v4 + 92) = v24;
        if ( *v24 != &CcLazyWriterCursor )
          __fastfail(3u);
        *v24 = v22;
        dword_632634 = v4 + 88;
      }
      v25 = 1;
      v26 = 1;
LABEL_39:
      CcScheduleLazyWriteScan(v26, v25);
      return KeReleaseQueuedSpinLock(5, v15);
    }
    if ( !v18 && (v17 & 0x20) == 0 )
    {
      v28 = *(_DWORD *)(v4 + 176) != 0;
      if ( (v17 & 0x3000000) != 0 )
      {
        v29 = (int *)(v4 + 80);
        v30 = *(_QWORD *)(v4 + 80);
        if ( *(_DWORD *)(v30 + 4) != v4 + 80 || *(int **)HIDWORD(v30) != v29 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v30) = v30;
        *(_DWORD *)(v30 + 4) = HIDWORD(v30);
        v31 = (int **)dword_632614;
        *v29 = (int)&CcDirtySharedCacheMapWithLogHandleList;
        *(_DWORD *)(v4 + 84) = v31;
        if ( *v31 != &CcDirtySharedCacheMapWithLogHandleList )
          __fastfail(3u);
        *v31 = v29;
        dword_632614 = v4 + 80;
      }
      v32 = (int *)(v4 + 88);
      v33 = *(_QWORD *)(v4 + 88);
      if ( *(_DWORD *)(v33 + 4) != v4 + 88 || *(int **)HIDWORD(v33) != v32 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v33) = v33;
      *(_DWORD *)(v33 + 4) = HIDWORD(v33);
      v34 = (int **)dword_632634;
      *v32 = (int)&CcLazyWriterCursor;
      *(_DWORD *)(v4 + 92) = v34;
      if ( *v34 != &CcLazyWriterCursor )
        __fastfail(3u);
      *v34 = v32;
      dword_632634 = v4 + 88;
      v25 = 0;
      v26 = v28;
      goto LABEL_39;
    }
  }
  return KeReleaseQueuedSpinLock(5, v15);
}
