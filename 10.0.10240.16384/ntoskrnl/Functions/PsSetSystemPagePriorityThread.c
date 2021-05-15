// PsSetSystemPagePriorityThread 
 
int __fastcall PsSetSystemPagePriorityThread(int a1, int a2)
{
  __int16 v3; // r3

  --*(_WORD *)(a1 + 310);
  if ( (*(_BYTE *)(a1 + 969) & 1) != 0 )
    return sub_51A9EC();
  *(_DWORD *)(a1 + 968) |= 0x100 | (a2 << 9);
  v3 = *(_WORD *)(a1 + 310) + 1;
  *(_WORD *)(a1 + 310) = v3;
  if ( !v3 && *(_DWORD *)(a1 + 100) != a1 + 100 )
    KiCheckForKernelApcDelivery(a1);
  return -1;
}
