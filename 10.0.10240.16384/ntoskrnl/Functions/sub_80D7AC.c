// sub_80D7AC 
 
int sub_80D7AC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, ...)
{
  unsigned int v9; // r6
  int v10; // r7
  __int16 v11; // r10
  int v12; // r0
  unsigned __int16 *v13; // r1
  int v14; // r4
  unsigned int v15; // r0
  unsigned int v16; // r0
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v21; // [sp+10h] [bp-A0h]
  int v22; // [sp+18h] [bp-98h]
  int (__fastcall *v23)(int); // [sp+ACh] [bp-4h]
  va_list va; // [sp+C4h] [bp+14h] BYREF

  va_start(va, a9);
  v12 = a9;
  v13 = (unsigned __int16 *)(*(_DWORD *)(v9 + 8) + v9);
  if ( v13[(*(_DWORD *)(v9 + 12) >> 1) - 1] )
  {
    v14 = -1073741811;
  }
  else
  {
    v14 = ArbpGetRegistryValue(a9, v13, (int *)va);
    if ( v14 >= 0 )
    {
      ExFreePoolWithTag(v9);
      JUMPOUT(0x794A84);
    }
    v12 = v21;
  }
  if ( v22 )
  {
    ZwClose();
    v12 = v21;
  }
  if ( v12 )
    ZwClose();
  if ( v9 )
    ExFreePoolWithTag(v9);
  v15 = *(_DWORD *)(v10 + 32);
  if ( v15 )
  {
    ExFreePoolWithTag(v15);
    *(_WORD *)(v10 + 28) = v11;
    *(_WORD *)(v10 + 30) = v11;
  }
  v16 = *(_DWORD *)(v10 + 40);
  if ( v16 )
  {
    ExFreePoolWithTag(v16);
    *(_WORD *)(v10 + 36) = v11;
    *(_WORD *)(v10 + 38) = v11;
  }
  v17 = KeSetEvent(*(_DWORD *)(v10 + 4), 0, 0);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
  return v23(v14);
}
