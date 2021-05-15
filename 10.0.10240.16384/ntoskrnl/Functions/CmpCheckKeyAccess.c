// CmpCheckKeyAccess 
 
int __fastcall CmpCheckKeyAccess(int a1, int a2, char a3, int a4)
{
  int v7; // r0
  int v9; // r4
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = -1;
  if ( !a1 || a2 == -1 || !a2 )
    return -1073741444;
  v7 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, v10);
  if ( !v7 )
    return -1073741670;
  v9 = *(_DWORD *)(v7 + 44);
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v10);
  return CmpCheckSecurityCellAccess(a1, v9, a3, a4);
}
