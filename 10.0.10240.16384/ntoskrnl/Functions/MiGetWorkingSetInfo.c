// MiGetWorkingSetInfo 
 
int __fastcall MiGetWorkingSetInfo(int a1, _DWORD *a2, unsigned int a3, int a4)
{
  unsigned int v4; // r8
  _DWORD *v5; // r9
  int v7; // r0
  int v8; // r5
  int v9; // r4
  int v10; // r2
  _DWORD *v11; // r6
  int v13; // [sp+8h] [bp-28h]
  int varg_r0; // [sp+38h] [bp+8h]

  varg_r0 = a1;
  v13 = a4;
  v4 = a3;
  v5 = a2;
  *a2 = 0;
  v7 = ExAllocatePoolWithTag(512, 4 * (((a3 & 0xFFF) != 0) + (a3 >> 12) + 8));
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  *(_DWORD *)v7 = 0;
  v10 = a1 & 0xFFF;
  *(_WORD *)(v7 + 4) = 4 * (((v10 + v4 + 4095) >> 12) + 7);
  *(_WORD *)(v7 + 6) = 0;
  *(_DWORD *)(v7 + 16) = a1 & 0xFFFFF000;
  *(_DWORD *)(v7 + 24) = v10;
  *(_DWORD *)(v7 + 20) = v4;
  __mrc(15, 0, 13, 0, 3);
  MmProbeAndLockPages(v7);
  if ( (*(_WORD *)(v8 + 6) & 5) != 0 )
    v11 = *(_DWORD **)(v8 + 12);
  else
    v11 = (_DWORD *)MmMapLockedPagesSpecifyCache(v8, 0, 1, 0, 0, 1073741840);
  if ( v11 )
  {
    v9 = MiGetWorkingSetInfoEx(v13 + 492, v11, v4, 1);
    if ( v9 >= 0 )
      *v5 = *v11;
  }
  else
  {
    v9 = -1073741670;
  }
  MmUnlockPages(v8);
  ExFreePoolWithTag(v8);
  return v9;
}
