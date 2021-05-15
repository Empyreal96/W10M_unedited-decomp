// ViXdvSearchAndReplaceThunkArray 
 
int __fastcall ViXdvSearchAndReplaceThunkArray(int a1, int a2, int a3, int a4)
{
  int v4; // t1
  __int64 v6; // r0

  while ( *(_DWORD *)(a1 + 16) != a3 || !*(_DWORD *)(a1 + 12) )
  {
    v4 = *(_DWORD *)(a1 + 20);
    a1 += 20;
    if ( !v4 )
      return 0;
  }
  v6 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)HIDWORD(v6) != (_DWORD)v6 )
    ++ViXdvThunksNotPristine;
  if ( (_DWORD)v6 )
    ++ViXdvThunksBoundToXdv;
  else
    ++ViXdvThunksShared;
  *(_DWORD *)HIDWORD(v6) = a4;
  return 1;
}
