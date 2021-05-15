// sub_51E05C 
 
void __fastcall sub_51E05C(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r8
  unsigned int v5; // r0
  _DWORD *v6; // r5

  *(_DWORD *)(v3 - 8) = a3;
  *(_DWORD *)(v3 - 4) = a1;
  while ( 1 )
  {
    v6 = RtlRealSuccessor((_DWORD *)v3);
    if ( !v6 || *(_QWORD *)(*(v6 - 4) + 8) > *(_QWORD *)(v3 - 8) )
      break;
    if ( !*(_BYTE *)(v3 - 12) && *((_BYTE *)v6 - 12) )
      FsRtlSplitLocks(v6 - 4, 0, 0, 0);
    **(_DWORD **)(v3 + 12) = *(v6 - 4);
    v5 = *(_DWORD *)(v3 - 8);
    *(_DWORD *)(v3 + 12) = v6[3];
    if ( *((_QWORD *)v6 - 1) > __PAIR64__(*(_DWORD *)(v3 - 4), v5) )
    {
      if ( *((_BYTE *)v6 - 12) )
        *(_BYTE *)(v3 - 12) = 1;
      *(_DWORD *)(v3 - 8) = *(v6 - 2);
      *(_DWORD *)(v3 - 4) = *(v6 - 1);
    }
    RtlDeleteNoSplay(v6, (_DWORD *)(v4 + 4));
    ExFreeToNPagedLookasideList((int)&FsRtlLockTreeNodeLookasideList, v6 - 4);
  }
  JUMPOUT(0x44C628);
}
