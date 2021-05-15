// ViThunkFindAllSpecialTables 
 
_DWORD *__fastcall ViThunkFindAllSpecialTables(int a1, int a2)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r6

  v4 = (_DWORD *)ViThunkFindNextSpecialTable(a1, a2, 0);
  if ( !v4 )
    return 0;
  v6 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * (ViVerifierSpecialThunkTables + 1), 1951821133);
  v5 = v6;
  if ( !v6 )
    return 0;
  memset(v6, 0, 4 * (ViVerifierSpecialThunkTables + 1));
  v7 = v5;
  do
  {
    *v7++ = v4;
    v4 = (_DWORD *)ViThunkFindNextSpecialTable(a1, a2, *v4);
  }
  while ( v4 );
  return v5;
}
