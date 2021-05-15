// WmipRegisterEtwProvider 
 
int __fastcall WmipRegisterEtwProvider(int a1, int a2)
{
  int v3; // r5
  int v5; // r3
  int result; // r0

  v3 = *(_DWORD *)(a1 + 28);
  v5 = *(_DWORD *)(v3 + 108) + 1;
  *(_DWORD *)(v3 + 108) = v5;
  if ( v5 != 1 )
    return sub_819CF4();
  result = ExAllocatePoolWithTag(1, 12, 1885957463);
  if ( result )
  {
    *(_DWORD *)(v3 + 80) = result;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(a1 + 8) |= 0x100000u;
    result = WmipQueueLegacyEtwWork(result, v3, a2);
  }
  return result;
}
