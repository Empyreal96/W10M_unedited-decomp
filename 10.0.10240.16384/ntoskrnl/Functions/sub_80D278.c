// sub_80D278 
 
void __fastcall sub_80D278(int a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r6
  _DWORD *v4; // r2
  int v5; // r2
  _DWORD *v6; // r3
  _DWORD *v7; // r5

  if ( v2[73] )
  {
    v4 = (_DWORD *)v2[1];
    v2[73] = a2;
    if ( v4 )
      *v4 = *v2;
    if ( *v2 )
      *(_DWORD *)(*v2 + 4) = v2[1];
    if ( (_DWORD *)IopLegacyDeviceNode == v2 )
      IopLegacyDeviceNode = *v2;
    v5 = v2[88];
    if ( v5 )
    {
      while ( 1 )
      {
        v6 = *(_DWORD **)(v5 + 356);
        if ( v6 == v2 )
          break;
        v5 = *(_DWORD *)(v5 + 356);
        if ( !v6 )
          goto LABEL_13;
      }
      *(_DWORD *)(v5 + 356) = v2[89];
    }
LABEL_13:
    v2[2] = a2;
    v2[3] = a2;
    *v2 = a2;
    v2[1] = a2;
    v7 = (_DWORD *)v2[4];
    PipClearDevNodeFlags((int)v2, 0x20000);
    IopDestroyDeviceNode((int)v2);
    if ( !v3 )
    {
      v7[2] = PnpDriverObject;
      IoDeleteDevice(v7);
    }
  }
  JUMPOUT(0x794346);
}
