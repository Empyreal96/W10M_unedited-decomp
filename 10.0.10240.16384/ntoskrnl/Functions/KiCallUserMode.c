// KiCallUserMode 
 
void __fastcall __noreturn KiCallUserMode(int a1, int a2, int a3, int a4, int a5, int a6)
{
  __int64 v6; // d8
  __int64 v7; // d9
  __int64 v8; // d10
  __int64 v9; // d11
  __int64 v10; // d12
  __int64 v11; // d13
  __int64 v12; // d14
  __int64 v13; // d15
  _DWORD *v19; // r4
  int v20; // r6
  int v21; // r0
  int v22; // r0
  _DWORD _0[14]; // [sp+0h] [bp-30h] BYREF
  __int64 vars8; // [sp+38h] [bp+8h]
  __int64 anonymous0; // [sp+40h] [bp+10h]
  __int64 anonymous1; // [sp+48h] [bp+18h]
  __int64 anonymous2; // [sp+50h] [bp+20h]
  __int64 anonymous3; // [sp+58h] [bp+28h]
  __int64 anonymous4; // [sp+60h] [bp+30h]
  __int64 anonymous5; // [sp+68h] [bp+38h]
  __int64 anonymous6; // [sp+70h] [bp+40h]
  int vars48; // [sp+78h] [bp+48h]

  _R4 = -1;
  if ( (__mrc(15, 0, 1, 0, 2) & 0xF00000) != 0 )
  {
    vars8 = v6;
    anonymous0 = v7;
    anonymous1 = v8;
    anonymous2 = v9;
    anonymous3 = v10;
    anonymous4 = v11;
    anonymous5 = v12;
    anonymous6 = v13;
    __asm { VMRS            R4, FPSCR }
  }
  vars48 = _R4;
  _0[2] = a1;
  _0[3] = a2;
  *(_DWORD *)(a3 + 16) = _0;
  v19 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v20 = v19[24];
  _0[1] = v20;
  __disable_irq();
  v19[8] = a3;
  v19[10] = a4;
  v21 = a4 - KeKernelStackSize;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44) = a3;
  v19[9] = v21;
  v22 = 136;
  do
  {
    v22 -= 4;
    *(_DWORD *)(a3 - 408 + v22) = *(_DWORD *)(v20 + v22);
  }
  while ( v22 );
  _0[5] = 0;
  KiSystemServiceExit(
    KeUserCallbackDispatcher,
    a6 & 0xF9FF03E0 | 0x10,
    100727839,
    0,
    KeUserCallbackDispatcher,
    a6 & 0xF9FF03E0 | 0x10);
}
