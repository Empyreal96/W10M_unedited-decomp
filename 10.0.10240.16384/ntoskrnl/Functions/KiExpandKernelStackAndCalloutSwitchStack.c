// KiExpandKernelStackAndCalloutSwitchStack 
 
int __fastcall KiExpandKernelStackAndCalloutSwitchStack(int a1, int a2, unsigned int a3, int a4)
{
  int v8; // r3
  unsigned int v9; // r4
  int *v10; // r0
  int v11; // r10
  int v12; // r9
  unsigned int v13; // r4
  unsigned int v14; // r0
  int result; // r0
  int v16; // [sp+0h] [bp-30h]
  int v17; // [sp+8h] [bp-28h] BYREF
  unsigned int v18; // [sp+Ch] [bp-24h] BYREF
  char v19[32]; // [sp+10h] [bp-20h] BYREF

  if ( a3 > 0xE800 )
    return -1073741583;
  v8 = __mrc(15, 0, 13, 0, 3);
  v9 = v8 & 0xFFFFFFC0;
  v10 = KeGetCurrentStackPointer(a1, a2, a3, v8, v16);
  v11 = *(_DWORD *)(v9 + 36);
  v12 = (int)v10;
  v13 = *(_DWORD *)(*(_DWORD *)(v9 + 32) + 4) & 0xFFFFFFFE;
  v14 = KeGetCurrentIrql(v10);
  if ( v14 == 2 )
  {
    if ( (a4 & 2) != 0 )
      return -1073741582;
    if ( !KeQueryCurrentStackInformation(&v17, &v18, v19) )
      __fastfail(4u);
    if ( v17 == 1 )
    {
      v11 = v18;
      v13 = v18;
    }
  }
  else
  {
    if ( v14 > 2 )
      sub_5480B4();
    if ( a3 == KeKernelStackSize || a3 == 12288 && (unsigned int)KeKernelStackSize >= 0x3000 )
      a4 |= 9u;
  }
  if ( v12 - v13 < a3 || (a4 & 1) != 0 || v12 - v11 < a3 && MmGrowKernelStackEx(v12, a3) < 0 )
    result = KiExpandKernelStackAndCalloutOnStackSegment(a1, a2, a3, a4);
  else
    result = -1073740661;
  return result;
}
