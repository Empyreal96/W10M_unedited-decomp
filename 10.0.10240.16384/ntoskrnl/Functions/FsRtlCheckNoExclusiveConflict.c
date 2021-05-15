// FsRtlCheckNoExclusiveConflict 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall FsRtlCheckNoExclusiveConflict(int a1, unsigned __int64 *a2, _DWORD *a3, int a4, int a5, int a6)
{
  int v8; // r5
  __int64 v9; // r0 OVERLAPPED
  unsigned __int64 v10; // kr00_8
  int v14[8]; // [sp+10h] [bp-20h] BYREF

  v8 = 1;
  LODWORD(v9) = FsRtlFindFirstOverlappingExclusiveNode(*(_DWORD *)(a1 + 8), a2, a3, v14, 0);
  if ( (_DWORD)v9 )
  {
    v10 = *(_QWORD *)a3;
    while ( v10 >= *(_QWORD *)(v9 + 16) )
    {
      *(__int64 *)((char *)&v9 + 4) = *a2;
      if ( *a2 <= *(_QWORD *)(v9 + 48)
        && (*(_DWORD *)(v9 + 40) != a5 || *(_DWORD *)(v9 + 44) != a6 || *(_DWORD *)(v9 + 36) != a4) )
      {
        v8 = 0;
        break;
      }
      LODWORD(v9) = RtlRealSuccessor((_DWORD *)v9);
      if ( !(_DWORD)v9 )
        break;
    }
  }
  LODWORD(v9) = v14[0];
  if ( v14[0] )
    *(_DWORD *)(a1 + 8) = RtlSplay(v9);
  return v8;
}
