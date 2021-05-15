// ResFwGetContext 
 
int __fastcall ResFwGetContext(_DWORD *a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r2
  unsigned int v5; // r7
  unsigned int v6; // r8
  int v7; // r0
  int v8; // r6
  int v9; // r0
  _DWORD *v10; // r1
  int v11; // r2

  if ( !a1 )
    return -1073741811;
  v3 = dword_619018;
  *a1 = 0;
  if ( (v3 & 1) == 0 )
    return -1073741823;
  v4 = dword_619038;
  if ( dword_619038 < (unsigned int)dword_619034 )
    v4 = dword_619034;
  v5 = (v4 + dword_619044 + dword_619040 + 20479) & 0xFFFFF000;
  v6 = ((v5 >> 3) + 4095) & 0xFFFFF000;
  v7 = MmAllocatePagesForMdlEx(0, 0, -1, -1, 0, 0, v6 + v5, 1, 5);
  v8 = v7;
  if ( v7 )
  {
    if ( (*(_WORD *)(v7 + 6) & 5) != 0 )
      v9 = *(_DWORD *)(v7 + 12);
    else
      v9 = MmMapLockedPagesSpecifyCache(v7, 0, 1, 0, 0, 32);
  }
  else
  {
    v9 = 0;
  }
  v10 = (_DWORD *)dword_619048;
  *(_DWORD *)(dword_619048 + 4) = v8;
  v10[2] = v9;
  if ( v9 )
  {
    v10[3] = v6 + v5;
    v10[36] = v6 + v9;
    v10[37] = v5;
  }
  else
  {
    v10[3] = 0;
    v10[36] = 0;
    v10[37] = 0;
  }
  v11 = dword_619094;
  *a1 = v10;
  result = 0;
  BgpAnimationRegionSave = v11;
  BgpTextRegionSave = dword_619098;
  return result;
}
