// IopCheckInitiatorHint 
 
int __fastcall IopCheckInitiatorHint(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  _DWORD *v7; // r5
  int v8; // r9
  int v9; // r0
  int v10; // r5
  int v11; // r3
  _DWORD *v12; // r2
  int v14; // [sp+8h] [bp-28h] BYREF
  int v15; // [sp+Ch] [bp-24h]
  _DWORD v16[8]; // [sp+10h] [bp-20h] BYREF

  v14 = a1;
  v15 = a2;
  v16[0] = a3;
  v16[1] = a4;
  v6 = 0;
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
    || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    v7 = 0;
  }
  else
  {
    v7 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
  }
  if ( (v7[9] | 1) == v7[430] )
  {
    v8 = v7[429] & 1;
    v6 = ObReferenceObjectByHandle(v7[429] & 0xFFFFFFFE, 64, PsProcessType, 1, &v14, 0);
    v15 = v6;
    if ( v6 >= 0 )
    {
      v6 = IopGetSetSpecificExtension(a1, 1, 16, 1, v16, 0);
      v15 = v6;
      if ( v6 < 0 )
      {
        ObfDereferenceObjectWithTag(v14);
      }
      else
      {
        if ( a2 )
        {
          v9 = IoGetInitiatorProcess(a2);
          v10 = v14;
          if ( v9 != v14 )
          {
            v6 = -1073741811;
            v15 = -1073741811;
            ObfDereferenceObjectWithTag(v14);
          }
        }
        else
        {
          v10 = v14;
        }
        if ( v6 >= 0 )
        {
          *(_DWORD *)(v16[0] + 4) = v10;
          if ( v8 == 1 )
          {
            *(_DWORD *)(a1 + 44) |= 0x20000000u;
            v11 = 0;
            v12 = *(_DWORD **)(a1 + 124);
            v16[0] = v12;
            if ( !v12 )
              v11 = -1073741275;
            if ( v11 >= 0 )
              *v12 |= 8u;
          }
        }
      }
    }
  }
  return v6;
}
