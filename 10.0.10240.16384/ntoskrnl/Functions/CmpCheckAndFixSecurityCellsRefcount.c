// CmpCheckAndFixSecurityCellsRefcount 
 
int __fastcall CmpCheckAndFixSecurityCellsRefcount(int a1)
{
  int v1; // r5
  int v3; // r0
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[0] = -1;
  v1 = 0;
  if ( *(_DWORD *)(a1 + 1992) == 1 )
    return 1;
  while ( 1 )
  {
    v3 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v1), v5);
    if ( !v3 )
      break;
    if ( *(_DWORD *)(v3 + 12) < *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v1 + 4) + 20) )
      return sub_7E86BC();
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v5);
    if ( ++v1 >= (unsigned int)(*(_DWORD *)(a1 + 1992) - 1) )
      return 1;
  }
  return 0;
}
