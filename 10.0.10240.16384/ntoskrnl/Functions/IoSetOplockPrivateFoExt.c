// IoSetOplockPrivateFoExt 
 
int __fastcall IoSetOplockPrivateFoExt(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v7; // r5
  _BYTE *v9; // r0
  int v10[6]; // [sp+0h] [bp-18h] BYREF

  v10[1] = a4;
  v10[0] = 0;
  v4 = 0;
  v5 = 0;
  if ( !*(_DWORD *)(a1 + 124) )
  {
    v4 = IopAllocateFileObjectExtension(a1, v10);
    if ( v4 < 0 )
      return v4;
    goto LABEL_8;
  }
  v7 = IopGetFileObjectExtension(a1, 6, v10);
  if ( !v7 )
  {
LABEL_8:
    v9 = (_BYTE *)ExAllocateFromNPagedLookasideList(&IopOplockFoExtLookasideList);
    v7 = (int)v9;
    if ( !v9 )
      return -1073741670;
    memset(v9, 0, 44);
    v5 = 1;
  }
  *(_DWORD *)(v7 + 40) = *(_DWORD *)(a2 + 40);
  if ( v5 )
  {
    v4 = IopSetTypeSpecificFoExtension(v10[0], 6, v7);
    if ( v4 < 0 )
      return sub_529F8C();
  }
  return v4;
}
