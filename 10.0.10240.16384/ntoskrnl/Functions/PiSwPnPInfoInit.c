// PiSwPnPInfoInit 
 
int __fastcall PiSwPnPInfoInit(_DWORD *a1, int a2)
{
  int v4; // r6
  _DWORD *v6; // r0
  _DWORD *v7; // r5
  int v8; // r2
  int v9; // r3
  int v10; // r4

  a1[5] = *(_DWORD *)(a2 + 32);
  v4 = PnpAllocateMultiSZ(*(_DWORD *)(a2 + 16), *(_DWORD *)(a2 + 12));
  if ( v4 >= 0 )
  {
    v4 = PnpAllocateMultiSZ(*(_DWORD *)(a2 + 24), *(_DWORD *)(a2 + 20));
    if ( v4 >= 0 )
    {
      if ( *(_DWORD *)(a2 + 28) )
      {
        v6 = (_DWORD *)ExAllocatePoolWithTag(1, 16, 1466986064);
        a1[2] = v6;
        if ( v6 )
        {
          v7 = *(_DWORD **)(a2 + 28);
          v8 = v7[1];
          v9 = v7[2];
          v10 = v7[3];
          *v6 = *v7;
          v6[1] = v8;
          v6[2] = v9;
          v6[3] = v10;
        }
        else
        {
          v4 = -1073741670;
        }
      }
      if ( v4 >= 0 )
      {
        v4 = PnpAllocatePWSTR(*(unsigned __int16 **)(a2 + 36), 0x7FFFu, 1466986064, a1 + 3);
        if ( v4 >= 0 )
          v4 = PnpAllocatePWSTR(*(unsigned __int16 **)(a2 + 40), 0x7FFFu, 1466986064, a1 + 4);
      }
    }
  }
  return v4;
}
