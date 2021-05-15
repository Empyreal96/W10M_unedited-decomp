// FsRtlPrivateCheckForExclusiveLockAccess 
 
int __fastcall FsRtlPrivateCheckForExclusiveLockAccess(__int64 a1, int a2, int a3)
{
  int v3; // r6
  int v4; // r5
  int v5; // r4
  int v7; // r0
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v8[0] = a2;
  v8[1] = a3;
  v3 = a1;
  v4 = *(_DWORD *)(a1 + 4);
  LODWORD(a1) = 0;
  v5 = HIDWORD(a1);
  v8[0] = 0;
  if ( v4 )
  {
    LODWORD(a1) = FsRtlFindFirstOverlappingSharedNode(
                    v4,
                    (unsigned __int64 *)HIDWORD(a1),
                    (_DWORD *)(HIDWORD(a1) + 32),
                    v8,
                    0);
    if ( (_DWORD)a1 )
    {
      if ( *(_BYTE *)(a1 - 12) )
        return sub_51E35C();
      v7 = *(_DWORD *)(a1 - 16);
      if ( v7 )
      {
        if ( *(_QWORD *)(v5 + 8) || *(_QWORD *)(v7 + 16) )
          return 0;
      }
    }
    LODWORD(a1) = v8[0];
    if ( v8[0] )
    {
      *(_DWORD *)(v3 + 4) = RtlSplay(a1);
      LODWORD(a1) = 0;
      v8[0] = 0;
    }
  }
  if ( *(_DWORD *)(v3 + 8) )
  {
    LODWORD(a1) = FsRtlFindFirstOverlappingExclusiveNode(*(_DWORD *)(v3 + 8), v5, v5 + 32);
    if ( !(_DWORD)a1 || !*(_QWORD *)(v5 + 8) && !*(_QWORD *)(a1 + 24) )
    {
      LODWORD(a1) = v8[0];
      goto LABEL_5;
    }
    return 0;
  }
LABEL_5:
  if ( (_DWORD)a1 )
    *(_DWORD *)(v3 + 8) = RtlSplay(a1);
  return 1;
}
