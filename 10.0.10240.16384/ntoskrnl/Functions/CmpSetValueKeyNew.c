// CmpSetValueKeyNew 
 
int __fastcall CmpSetValueKeyNew(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v11; // r0
  int result; // r0

  if ( *(_DWORD *)(a2 + 36) && !HvpMarkCellDirty(a1, *(_DWORD *)(a2 + 40), 0, 0) )
    return -1073741443;
  v11 = CmpAddValueKeyNew(a1, a3, a5, a6, a7, a8);
  if ( v11 == -1 )
    JUMPOUT(0x803B78);
  if ( CmpAddValueToListEx(a1, v11, a4, a8) >= 0 )
    result = 0;
  else
    result = sub_803B70();
  return result;
}
