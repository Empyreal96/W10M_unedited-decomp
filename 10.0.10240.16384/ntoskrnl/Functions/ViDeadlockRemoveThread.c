// ViDeadlockRemoveThread 
 
int __fastcall ViDeadlockRemoveThread(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  int v5; // r4
  __int64 v6; // r0
  unsigned int v7; // r5
  unsigned int v8; // r1
  unsigned int v9; // r3
  _DWORD *v10; // r3

  v3 = *(_DWORD *)(ViDeadlockGlobals + 16400);
  __dmb(0xBu);
  if ( v3 )
  {
    v5 = ViDeadlockGlobals;
LABEL_5:
    a2 = 1;
    goto LABEL_6;
  }
  v4 = ViDeadlockChildrenCountMaximum;
  __dmb(0xBu);
  v5 = ViDeadlockGlobals;
  if ( *(_DWORD *)(ViDeadlockGlobals + 16604) > v4 )
    goto LABEL_5;
LABEL_6:
  if ( !a2 && *(_DWORD *)(a1 + 20) )
  {
    ViDeadlockPreprocessOptions(
      &dword_6187D4,
      "Terminated thread 0x%p owns lock.",
      4106,
      *(_DWORD *)a1,
      (unsigned int)a1);
    VfReportIssueWithOptions(196, 4106, *(_DWORD *)a1, a1, 0, &dword_6187D4);
    v5 = ViDeadlockGlobals;
  }
  --*(_DWORD *)(v5 + 8212);
  v6 = *(_QWORD *)(a1 + 12);
  if ( *(_DWORD *)(v6 + 4) != a1 + 12 || *(_DWORD *)HIDWORD(v6) != a1 + 12 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v6) = v6;
  *(_DWORD *)(v6 + 4) = HIDWORD(v6);
  v7 = *(_DWORD *)a1;
  v8 = (v7 >> 12)
     - 1023
     * ((unsigned int)((((v7 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)
                     + ((unsigned int)((v7 >> 12) - (((v7 >> 12) * (unsigned __int64)(unsigned int)&unk_401005) >> 32)) >> 1)) >> 9);
  v9 = v8 + 1027;
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 8208) + 8 * v8) == *(_DWORD *)(v5 + 8208) + 8 * v8 )
  {
    v10 = (_DWORD *)(v5 + 8 * v9);
    *v10 = 0;
    v10[1] = 0;
  }
  else
  {
    LODWORD(v6) = VfUtilAddressRangeRemove((_DWORD *)(v5 + 8 * v9), v7, 1104);
  }
  return v6;
}
