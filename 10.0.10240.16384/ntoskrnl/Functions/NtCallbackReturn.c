// NtCallbackReturn 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall NtCallbackReturn(int a1, int a2, int a3)
{
  unsigned int v3; // r4
  _DWORD *v4; // r5
  int v5; // r6
  int *v7; // r2
  int v8; // r0
  int v9; // r1
  int v10; // r1
  _DWORD *v11; // r1
  int v12; // r2
  int (__fastcall *v13)(int, _DWORD *); // lr
  int (__fastcall *v15)(int, _DWORD *); // [sp-44h] [bp-4Ch]
  _DWORD v16[18]; // [sp-40h] [bp-48h] BYREF

  if ( !*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x20) + 16) )
    return -1073741224;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD **)(v3 + 32);
  v5 = v4[4];
  v7 = *(int **)(v5 + 12);
  **(_DWORD **)(v5 + 8) = a1;
  *v7 = a2;
  if ( *(_DWORD *)(*(_DWORD *)(v3 + 156) + 3952) )
    PsInvokeWin32Callout(7, 0, 0, 0);
  v8 = *(_DWORD *)(v5 + 4);
  __disable_irq();
  v9 = *(_DWORD *)(v3 + 96);
  *(_DWORD *)(v3 + 96) = v8;
  if ( (*(_BYTE *)(v3 + 3) & 1) != 0 )
    KiCopyDebugRegs(v8, v9);
  v10 = v4[2];
  *(_DWORD *)(v3 + 40) = v10;
  v11 = (_DWORD *)(v10 - KeKernelStackSize);
  *(_DWORD *)(v3 + 36) = v11;
  v12 = v4[5];
  *(_DWORD *)(v3 + 32) = v12;
  *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC44) = v12;
  if ( v16[16] != -1 )
    v11 = v16;
  v13 = v15;
  __enable_irq();
  return v13(a3, v11);
}
