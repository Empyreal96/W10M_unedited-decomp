// KeExpandKernelStackAndCalloutInternal 
 
int __fastcall KeExpandKernelStackAndCalloutInternal(int (__fastcall *a1)(int), int a2, int a3, int a4)
{
  int v6; // r0
  unsigned int v7; // r2
  int v8; // r1
  char v9; // r3
  int v10; // r0
  int v11; // r0
  char v13; // [sp+8h] [bp-18h]
  unsigned __int8 v14; // [sp+9h] [bp-17h]
  unsigned int v16; // [sp+Ch] [bp-14h]

  v6 = KiExpandKernelStackAndCalloutSwitchStack(a1, a2, a3, a4);
  if ( v6 != -1073740661 )
    return v6;
  v14 = KeGetCurrentIrql(-1073740661);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = v7;
  v8 = *(_DWORD *)(v7 + 0x4C);
  if ( (v8 & 0x1000) != 0 )
  {
    v9 = 1;
  }
  else
  {
    *(_DWORD *)(v7 + 76) = v8 | 0x1000;
    v9 = 0;
  }
  v13 = v9;
  v10 = a1(a2);
  if ( !v13 )
    *(_DWORD *)(v16 + 76) &= 0xFFFFEFFF;
  v11 = KeGetCurrentIrql(v10);
  if ( v11 != v14 )
    KeBugCheckEx(200, v14, v11);
  return 0;
}
