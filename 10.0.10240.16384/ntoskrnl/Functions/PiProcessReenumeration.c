// PiProcessReenumeration 
 
int __fastcall PiProcessReenumeration(int a1)
{
  int v2; // r0
  int v3; // r5
  int v4; // r2
  int result; // r0
  int v6; // r6
  int v7; // [sp+10h] [bp-18h] BYREF
  char v8; // [sp+14h] [bp-14h]

  v2 = *(_DWORD *)(a1 + 8);
  v3 = *(_DWORD *)(*(_DWORD *)(v2 + 176) + 20);
  v4 = *(_DWORD *)(v3 + 172);
  if ( v4 == 787 || v4 == 788 )
  {
    ObfDereferenceObject(v2);
    result = -1073741738;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 12) == 8 )
    {
      if ( *(_BYTE *)(a1 + 20) )
        return sub_7E0910();
      v6 = 1;
    }
    else
    {
      v6 = 2;
    }
    PnpLogActionQueueEvent(*(_DWORD *)(*(_DWORD *)(v2 + 176) + 20), *(_DWORD *)(a1 + 12), 1);
    PiMarkDeviceTreeForReenumeration(v3, v6 != 1);
    v7 = 3;
    v8 = PnPBootDriversInitialized;
    PipProcessDevNodeTree(v3, a1, (int)&v7, v6, 0, 0, 0);
    PnpLogActionQueueEvent(v3, *(_DWORD *)(a1 + 12), 2);
    result = 0;
  }
  return result;
}
