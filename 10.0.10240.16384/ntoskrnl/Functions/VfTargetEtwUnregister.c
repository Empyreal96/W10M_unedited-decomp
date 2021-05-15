// VfTargetEtwUnregister 
 
unsigned int __fastcall VfTargetEtwUnregister(unsigned int result, unsigned int a2)
{
  unsigned int v3; // r8
  int v4; // r5
  unsigned int v5; // r6
  int v6; // r2
  int v7; // r0
  int v8; // r4
  _QWORD *i; // r2
  int v10; // r3
  __int64 v11; // r0
  char v12[32]; // [sp+8h] [bp-20h] BYREF

  v3 = result;
  if ( !VfSafeMode )
  {
    v4 = 0;
    v5 = 0;
    VfAvlInitializeLockContext((int)v12, 0);
    v7 = VfAvlLookupTreeNode((int *)&ViTargetDriversAvl, (int)v12, v6, 1);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 24);
      if ( v8 )
      {
        for ( i = *(_QWORD **)(v8 + 8); ; i = *(_QWORD **)i )
        {
          if ( i == (_QWORD *)(v8 + 8) )
          {
            v10 = dword_620DE8;
            __dmb(0xBu);
            if ( !v10 && (*(_DWORD *)(v8 + 16) & 1) == 0 && (MmVerifierData & 0x800) != 0 )
              VerifierBugCheckIfAppropriate(196, 220, 0, 0, 0);
            goto LABEL_12;
          }
          v5 = (unsigned int)i;
          if ( i[1] == __PAIR64__(a2, v3) )
            break;
        }
        v11 = *i;
        v4 = 1;
        if ( *(_QWORD **)(*(_DWORD *)i + 4) != i || *(_QWORD **)HIDWORD(v11) != i )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v11) = v11;
        *(_DWORD *)(v11 + 4) = HIDWORD(v11);
      }
    }
LABEL_12:
    result = VfAvlCleanupLockContext((int)v12);
    if ( v4 )
      result = ExFreePoolWithTag(v5);
  }
  return result;
}
