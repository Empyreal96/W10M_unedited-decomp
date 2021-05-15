// PnpDeleteLockedDeviceNodes 
 
int __fastcall PnpDeleteLockedDeviceNodes(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r4
  int v9; // r5
  int v12; // r7
  _DWORD *v13; // r4
  int v14; // r2
  int v15; // r0
  int v16; // r4
  int v17; // r0
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h] BYREF
  int v20; // [sp+10h] [bp-30h]
  int v21[10]; // [sp+18h] [bp-28h] BYREF

  v8 = *(unsigned __int8 *)(a2 + 4);
  v9 = 0;
  v20 = a1;
  if ( !v8 )
    return -1073741823;
  v21[0] = 1;
  v21[1] = 0;
  while ( IopEnumerateRelations(a2, v21, &v18, &v19, 0) )
  {
    if ( !v19 )
      return sub_7DFBE4();
    v12 = v18;
    v13 = *(_DWORD **)(*(_DWORD *)(v18 + 176) + 20);
    if ( a5 == 54 )
    {
      v14 = 54;
    }
    else if ( v18 == v20 )
    {
      v14 = a5;
    }
    else if ( v19 != 1 || a3 == 1 )
    {
      v14 = 0;
    }
    else
    {
      v14 = 51;
    }
    if ( a3 != 2 || (v13[114] & 2) == 0 )
    {
      v15 = PnpDeleteLockedDeviceNode(*(_DWORD *)(*(_DWORD *)(v18 + 176) + 20), a3, v14, a6, a7);
      v9 = v15;
      if ( !a3 && a5 == 54 && v15 == -1073740537 )
      {
        v16 = v13[2];
        if ( PipIsDeviceInDeviceObjectList(*(_DWORD **)a2, *(_DWORD *)(v16 + 16), 0) )
          *(_DWORD *)(v16 + 456) |= 2u;
        v9 = 0;
      }
      else if ( v15 < 0 )
      {
        if ( (v13[114] & 4) == 0 )
          KeBugCheckEx(202, 13, (int)v13, 4, 0);
        PoFxIdleDevice(v13[4]);
        v13[114] &= 0xFFFFFFFB;
        IopReverseEnumerationOrder(a2, v21);
        while ( IopEnumerateRelations(a2, v21, &v18, 0, 0) )
        {
          if ( v12 != v18 )
          {
            if ( v18 )
              v17 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
            else
              v17 = 0;
            PnpDeleteLockedDeviceNode(v17, 1, 0, a6, a7);
          }
        }
        return -1073741823;
      }
    }
  }
  return v9;
}
