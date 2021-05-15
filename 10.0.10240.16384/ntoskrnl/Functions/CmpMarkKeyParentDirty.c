// CmpMarkKeyParentDirty 
 
BOOL __fastcall CmpMarkKeyParentDirty(int a1, int a2)
{
  int v4; // r0
  BOOL v5; // r4
  int v6; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = -1;
  v4 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, v8);
  if ( !v4 )
    return 0;
  v5 = 1;
  if ( (*(_WORD *)(v4 + 2) & 4) == 0 )
  {
    v6 = *(_DWORD *)(v4 + 16);
    if ( !CmpMarkIndexDirty(a1, v6, a2) || !HvpMarkCellDirty(a1, v6, 0, 0) )
      v5 = 0;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v8);
  return v5;
}
