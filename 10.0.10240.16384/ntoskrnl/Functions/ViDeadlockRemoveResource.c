// ViDeadlockRemoveResource 
 
int __fastcall ViDeadlockRemoveResource(int a1, int a2, int *a3)
{
  int v5; // r3
  int v6; // r4
  int v7; // r5
  _DWORD *v8; // r3
  _DWORD *v9; // r7
  _DWORD *v10; // r4
  int v11; // r3
  __int64 v12; // r0
  unsigned int v13; // r1
  _DWORD *v14; // r3
  __int64 v16; // [sp+0h] [bp-28h]

  v5 = *(_DWORD *)(ViDeadlockGlobals + 16400);
  __dmb(0xBu);
  if ( v5 )
  {
    v7 = ViDeadlockGlobals;
LABEL_5:
    a2 = 1;
    goto LABEL_6;
  }
  v6 = ViDeadlockChildrenCountMaximum;
  __dmb(0xBu);
  v7 = ViDeadlockGlobals;
  if ( *(_DWORD *)(ViDeadlockGlobals + 16604) > v6 )
    goto LABEL_5;
LABEL_6:
  if ( !a2 )
  {
    v8 = *(_DWORD **)(a1 + 12);
    if ( v8 )
    {
      LODWORD(v16) = *v8;
      HIDWORD(v16) = a1;
      ViDeadlockPreprocessOptions(
        &dword_6187D0,
        "Deleted lock 0x%p is still owned by the thread 0x%p.",
        4107,
        *(_DWORD *)(a1 + 8),
        v16);
      VfReportIssueWithOptions(196, 4107, *(_DWORD *)(a1 + 8), **(_DWORD **)(a1 + 12), a1, &dword_6187D0);
      v7 = ViDeadlockGlobals;
    }
  }
  v9 = *(_DWORD **)(a1 + 16);
  if ( v9 != (_DWORD *)(a1 + 16) )
  {
    do
    {
      v10 = v9 - 5;
      v9 = (_DWORD *)*v9;
      ViDeadlockRemoveNode(v10, a2);
      v11 = *a3;
      *a3 = (int)v10;
      *v10 = v11;
    }
    while ( v9 != (_DWORD *)(a1 + 16) );
    v7 = ViDeadlockGlobals;
  }
  --*(_DWORD *)(v7 + 20);
  v12 = *(_QWORD *)(a1 + 24);
  if ( *(_DWORD *)(v12 + 4) != a1 + 24 || *(_DWORD *)HIDWORD(v12) != a1 + 24 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v12) = v12;
  *(_DWORD *)(v12 + 4) = HIDWORD(v12);
  v13 = (*(_DWORD *)(a1 + 8) >> 12)
      - 1023
      * ((unsigned int)((((*(_DWORD *)(a1 + 8) >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                      + ((unsigned int)((*(_DWORD *)(a1 + 8) >> 12)
                                      - (((*(_DWORD *)(a1 + 8) >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  if ( *(_DWORD *)(*(_DWORD *)(v7 + 16) + 8 * v13) == *(_DWORD *)(v7 + 16) + 8 * v13 )
  {
    v14 = (_DWORD *)(v7 + 8 * (v13 + 3));
    *v14 = 0;
    v14[1] = 0;
  }
  else
  {
    LODWORD(v12) = VfUtilAddressRangeRemove(
                     (_DWORD *)(v7 + 8 * (v13 + 3)),
                     *(_DWORD *)(a1 + 8),
                     ViDeadlockResourceTypeSizeInfo[*(_DWORD *)a1]);
  }
  return v12;
}
