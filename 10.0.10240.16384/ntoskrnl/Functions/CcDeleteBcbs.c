// CcDeleteBcbs 
 
int __fastcall CcDeleteBcbs(int result)
{
  int v1; // r5
  _DWORD *v2; // r6
  _DWORD *v3; // r7
  _DWORD *v4; // r4
  int v5; // r2
  __int64 v6; // r0
  int v7; // r3
  int v8; // r0
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r0
  int v13; // r0
  unsigned int v14; // r1
  int v15; // r2

  v1 = result;
  v2 = *(_DWORD **)(result + 16);
  v3 = (_DWORD *)(result + 16);
  while ( v2 != v3 )
  {
    v4 = v2 - 4;
    v5 = *((__int16 *)v2 - 8);
    v2 = (_DWORD *)*v2;
    if ( v5 == 765 )
    {
      if ( v4[13] )
        KeBugCheckEx(52, 3146, -1073740768, 0, 0);
      v6 = *((_QWORD *)v4 + 2);
      if ( *(_DWORD **)(v6 + 4) != v4 + 4 || *(_DWORD **)HIDWORD(v6) != v4 + 4 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v6) = v6;
      *(_DWORD *)(v6 + 4) = HIDWORD(v6);
      if ( *(__int64 *)(v1 + 24) > 0x2000000 && (*(_DWORD *)(v1 + 96) & 0x200) != 0 )
        CcAdjustVacbLevelLockCount(v1, HIDWORD(v6), v4[2], v4[3]);
      if ( v4[29] )
      {
        v7 = v4[12];
        v8 = *(_DWORD *)(v7 + 4);
        __dmb(0xBu);
        v9 = (unsigned int *)(v7 + 8);
        do
        {
          v10 = __ldrex(v9);
          v11 = v10 - 1;
        }
        while ( __strex(v11, v9) );
        __dmb(0xBu);
        if ( !(_WORD)v11 )
        {
          v12 = *(_DWORD *)(v8 + 116);
          if ( v12 )
            KeSetEvent(v12, 0, 0);
        }
      }
      v13 = KeAcquireQueuedSpinLock(5);
      if ( *((_BYTE *)v4 + 2) )
      {
        v14 = v4[1];
        CcGlobalDirtyPageStatistics -= v14 >> 12;
        v15 = *(_DWORD *)(v1 + 356);
        *(_DWORD *)(v1 + 76) -= v14 >> 12;
        *(_DWORD *)(v15 + 20) -= v14 >> 12;
        if ( (*(_DWORD *)(v1 + 96) & 0x1000000) != 0 )
          *(_DWORD *)(*(_DWORD *)(v1 + 152) + 12) -= v14 >> 12;
      }
      KeReleaseQueuedSpinLock(5, v13);
      result = CcDeallocateBcb(v4);
    }
  }
  return result;
}
