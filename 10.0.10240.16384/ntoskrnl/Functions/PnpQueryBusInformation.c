// PnpQueryBusInformation 
 
int __fastcall PnpQueryBusInformation(int a1, int a2, int a3, int a4)
{
  int v5; // r6
  unsigned int v6; // r4
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[0] = a4;
  v5 = PpIrpQueryBusInformation(*(_DWORD *)(a1 + 16), v8);
  if ( v5 < 0 )
  {
    *(_WORD *)(a1 + 316) = -1;
    *(_DWORD *)(a1 + 308) = -1;
    *(_DWORD *)(a1 + 312) = -16;
  }
  else
  {
    v6 = v8[0];
    *(_WORD *)(a1 + 316) = PnpBusTypeGuidGetIndex(v8[0]);
    *(_DWORD *)(a1 + 308) = *(_DWORD *)(v6 + 16);
    *(_DWORD *)(a1 + 312) = *(_DWORD *)(v6 + 20);
    ExFreePoolWithTag(v6);
  }
  return v5;
}
