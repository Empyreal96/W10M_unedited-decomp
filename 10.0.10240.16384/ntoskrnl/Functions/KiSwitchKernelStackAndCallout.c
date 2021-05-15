// KiSwitchKernelStackAndCallout 
 
int __fastcall KiSwitchKernelStackAndCallout(int a1, int a2, int a3)
{
  int v3; // r9
  unsigned int v4; // r2
  _DWORD *v5; // r4
  unsigned int v6; // r7
  int v7; // r12
  _BYTE v9[24]; // [sp+0h] [bp-18h] BYREF

  v3 = a3 & 3;
  v4 = a3 & 0xFFFFFFFC;
  v5 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  *(_DWORD *)(v4 + 16) = v9;
  v6 = v4 - 24;
  *(_DWORD *)(v6 + 20) = &loc_4205B8;
  *(_DWORD *)(v6 + 16) = v9;
  __disable_irq();
  *(_DWORD *)(v4 + 12) = v5[9];
  v5[8] = v4;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44) = v4;
  v5[10] = v4 + 24;
  v7 = KeKernelStackSize;
  if ( v3 )
  {
    v7 = 12288;
    if ( v3 != 1 )
      v7 = 61440;
  }
  v5[9] = v4 + 24 - v7;
  return KxSwitchKernelStackCallout();
}
