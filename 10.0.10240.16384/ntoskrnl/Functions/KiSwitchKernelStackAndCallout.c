// KiSwitchKernelStackAndCallout 
 
void __fastcall KiSwitchKernelStackAndCallout(int a1, int a2, int a3, int a4, int a5, void (*a6)(void), int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v12; // r9
  unsigned int v13; // r2
  _DWORD *v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r7
  int v17; // r12
  _BYTE v18[24]; // [sp+0h] [bp-18h] BYREF

  v12 = a3 & 3;
  v13 = a3 & 0xFFFFFFFC;
  v14 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v15 = v13 + 24;
  *(_DWORD *)(v13 + 16) = v18;
  v16 = v13 - 24;
  *(_DWORD *)(v16 + 20) = &loc_4205B8;
  *(_DWORD *)(v16 + 16) = v18;
  __disable_irq();
  *(_DWORD *)(v13 + 12) = v14[9];
  v14[8] = v13;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44) = v13;
  v14[10] = v13 + 24;
  v17 = KeKernelStackSize;
  if ( v12 )
  {
    v17 = 12288;
    if ( v12 != 1 )
      v17 = 61440;
  }
  v14[9] = v15 - v17;
  KxSwitchKernelStackCallout(a1, (void (*)(void))a2, v15 - v17, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}
