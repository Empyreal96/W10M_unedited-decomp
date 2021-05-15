// FsRtlFastUnlockSingle 
 
int __fastcall FsRtlFastUnlockSingle(int a1, int a2, _DWORD *a3, _DWORD *a4, int a5, int a6, int a7)
{
  int v7; // r8
  __int64 v12; // r0
  int v13; // r9
  unsigned int v14; // r3

  v7 = *(_DWORD *)(a1 + 12);
  if ( !v7 )
    return -1073741698;
  LODWORD(v12) = *a4;
  HIDWORD(v12) = a3[1];
  v13 = *a4 + *a3 - 1;
  v14 = ((v12 + __PAIR64__(a4[1], *a3)) >> 32) + (*a4 + *a3 != 0) - 1;
  if ( __PAIR64__(v14, v13) < *(_QWORD *)a3 )
    return sub_51E114();
  if ( FsRtlFastUnlockSingleExclusive(v7, a2, a3, a4, a5, a6, a7, 0, 1) )
    return FsRtlFastUnlockSingleShared(*(_DWORD *)(a1 + 12), a2, a3, a4, a5, a6, a7, 0, 1);
  return 0;
}
