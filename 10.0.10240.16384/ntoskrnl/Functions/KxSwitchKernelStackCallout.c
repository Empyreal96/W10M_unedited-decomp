// KxSwitchKernelStackCallout 
 
void __fastcall KxSwitchKernelStackCallout(int a1, void (*a2)(void), int a3, int a4, int a5, void (*a6)(void), int a7, int a8, int a9, int a10, int a11, int a12)
{
  _DWORD *v12; // r4
  _DWORD *v13; // r1
  int v14; // r6

  __enable_irq();
  a6 = a2;
  if ( a4 )
  {
    a5 = a1;
    if ( MmGrowKernelStackEx((int)&a5, a4) )
      goto LABEL_5;
    a1 = a5;
  }
  ((void (__fastcall *)(int, void (*)(void), int))a6)(a1, a2, a3);
LABEL_5:
  v13 = (_DWORD *)v12[8];
  __disable_irq();
  v12[10] = v13[2];
  v12[9] = v13[3];
  v14 = v13[5];
  v12[8] = v14;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44) = v14;
  __enable_irq();
  __asm { POP.W           {R4-R9,R11,PC} }
}
