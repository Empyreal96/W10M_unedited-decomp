// CcUnpinRepinnedBcb 
 
int __fastcall CcUnpinRepinnedBcb(int a1, int a2, int *a3)
{
  int v5; // r4
  int result; // r0
  int v7; // r3
  _DWORD *v8; // r8
  int v9; // r7
  unsigned int v10; // r0
  unsigned int i; // r3
  unsigned int v12; // r1
  int v13; // r9
  int v14; // r4
  _DWORD *v15; // r8
  int v16; // r0
  int v17; // r3
  int v18; // r10
  unsigned int v19; // r7
  unsigned int j; // r3
  unsigned int v21; // r6

  if ( *(_WORD *)a1 != 765 )
    KeBugCheckEx(52, 7720, -1073740768);
  v5 = *(_DWORD *)(a1 + 112);
  *a3 = 0;
  if ( a2 )
  {
    v7 = *(_DWORD *)(v5 + 96);
    if ( (v7 & 0x200) != 0 )
      ExAcquireResourceExclusiveLite(a1 + 56, 1, (int)a3, v7);
    if ( *(_BYTE *)(a1 + 2) )
    {
      MmSetAddressRangeModified(*(_DWORD *)(a1 + 116), *(_DWORD *)(a1 + 4));
      CcUnpinFileDataEx(a1, 1, 2);
      v8 = (_DWORD *)(v5 + 68);
      v9 = ObFastReferenceObject((_DWORD *)(v5 + 68));
      if ( !v9 )
        v9 = CcSlowReferenceSharedCacheMapFileObject(v5);
      if ( (dword_682610 & 0x20000) != 0 )
      {
        result = sub_54A180();
      }
      else
      {
        MmFlushSection(*(_DWORD *)(v9 + 20), (int *)(a1 + 8), *(_DWORD *)(a1 + 4), dword_682610, a3, 1u);
        __pld(v8);
        v10 = *v8;
        for ( i = *v8 ^ v9; i < 7; i = v12 ^ v9 )
        {
          __dmb(0xBu);
          do
            v12 = __ldrex(v8);
          while ( v12 == v10 && __strex(v10 + 1, v8) );
          if ( v12 == v10 )
            goto LABEL_18;
          v10 = v12;
        }
        ObDereferenceObjectDeferDeleteWithTag(v9);
LABEL_18:
        v13 = *a3;
        if ( *a3 < 0 )
        {
          v14 = *(_DWORD *)(a1 + 112);
          if ( !*(_DWORD *)(v14 + 4) )
            KeBugCheckEx(52, 4935, -1073740768);
          v15 = (_DWORD *)(v14 + 68);
          v16 = ObFastReferenceObject((_DWORD *)(v14 + 68));
          if ( !v16 )
            v16 = CcSlowReferenceSharedCacheMapFileObject(v14);
          v17 = *(_DWORD *)(v16 + 4);
          __pld(v15);
          v18 = *(_DWORD *)(v17 + 32);
          v19 = *v15;
          for ( j = *v15 ^ v16; j < 7; j = v21 ^ v16 )
          {
            __dmb(0xBu);
            do
              v21 = __ldrex(v15);
            while ( v21 == v19 && __strex(v19 + 1, v15) );
            if ( v21 == v19 )
              goto LABEL_35;
            v19 = v21;
          }
          ObDereferenceObjectDeferDeleteWithTag(v16);
LABEL_35:
          if ( !MmIsWriteErrorFatal(1, v18 & 0x10, v13) )
            CcSetDirtyPinnedData(a1, 0);
        }
        result = CcUnpinFileDataEx(a1, 0, 0);
        if ( (int *)CcDeferredWrites != &CcDeferredWrites )
          result = CcPostDeferredWrites(result);
      }
    }
    else
    {
      result = CcUnpinFileDataEx(a1, 0, 0);
    }
  }
  else
  {
    result = CcUnpinFileDataEx(a1, 1, 0);
    *a3 = 0;
  }
  return result;
}
