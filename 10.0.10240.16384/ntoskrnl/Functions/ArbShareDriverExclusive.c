// ArbShareDriverExclusive 
 
int __fastcall ArbShareDriverExclusive(int a1, int a2)
{
  int v3; // r2
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r3
  int v11; // r5
  unsigned __int64 v12; // kr00_8
  unsigned __int64 v13; // kr08_8
  int v14; // r0
  int v15; // r0
  char v16; // r3
  int v17; // r2
  int v18; // r1
  int v20; // [sp+8h] [bp-48h] BYREF
  unsigned int v21; // [sp+Ch] [bp-44h] BYREF
  _DWORD v22[4]; // [sp+10h] [bp-40h] BYREF
  int v23[12]; // [sp+20h] [bp-30h] BYREF

  v3 = *(_DWORD *)(a2 + 32);
  v4 = 0;
  v5 = *(_DWORD *)(v3 + 24);
  if ( (v5 & 2) != 0 )
  {
    v4 = 1;
  }
  else if ( (v5 & 4) == 0 && IoGetDeviceProperty(*(_DWORD *)(v3 + 16), 15, 0xAu, v23, &v21) >= 0 )
  {
    v7 = wcsicmp((int)v23, L"ROOT");
    v8 = *(_DWORD *)(a2 + 32);
    v9 = *(_DWORD *)(v8 + 24);
    if ( v7 )
    {
      v10 = v9 | 4;
    }
    else
    {
      v10 = v9 | 2;
      v4 = 1;
    }
    *(_DWORD *)(v8 + 24) = v10;
  }
  RtlGetFirstRange(*(_DWORD **)(a1 + 24), v22, &v20);
  v11 = v20;
  if ( !v20 )
    return 0;
  while ( 1 )
  {
    v12 = *(_QWORD *)v11;
    v13 = *(_QWORD *)(a2 + 16);
    if ( (*(_QWORD *)v11 >= v13 || *(_QWORD *)(v11 + 8) >= v13)
      && (v13 >= v12 || *(_QWORD *)(a2 + 24) >= v12)
      && (*(_BYTE *)(a2 + 51) & *(_BYTE *)(v11 + 24)) == 0
      && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a2 + 36) + 40) + 2) == 2 || (*(_BYTE *)(v11 + 24) & 2) != 0) )
    {
      v14 = *(_DWORD *)(v11 + 20);
      if ( v14 )
      {
        if ( v4 )
        {
          if ( (*(_BYTE *)(v11 + 25) & 0x40) == 0 )
          {
            if ( (*(_BYTE *)(v11 + 25) & 0x20) != 0 || IoGetDeviceProperty(v14, 15, 0xAu, v23, &v21) < 0 )
              goto LABEL_33;
            v15 = wcsicmp((int)v23, L"ROOT");
            v16 = *(_BYTE *)(v11 + 25);
            if ( !v15 )
            {
              *(_BYTE *)(v11 + 25) = v16 | 0x20;
              goto LABEL_33;
            }
            *(_BYTE *)(v11 + 25) = v16 | 0x40;
          }
          v4 = 0;
        }
        v17 = *(_DWORD *)(*(_DWORD *)(v11 + 20) + 16);
        if ( v17 )
          break;
      }
    }
LABEL_30:
    RtlGetNextRange(v22, &v20, 1);
    v11 = v20;
    if ( !v20 )
      return 0;
  }
  while ( 1 )
  {
    v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 32) + 16) + 16);
    if ( v18 )
      break;
LABEL_29:
    v17 = *(_DWORD *)(v17 + 16);
    if ( !v17 )
      goto LABEL_30;
  }
  while ( *(_DWORD *)(v17 + 8) != *(_DWORD *)(v18 + 8) )
  {
    v18 = *(_DWORD *)(v18 + 16);
    if ( !v18 )
      goto LABEL_29;
  }
LABEL_33:
  *(_DWORD *)a2 = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 28);
  if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(a2 + 36) + 40) + 2) == 2 )
    *(_BYTE *)(a2 + 50) |= 2u;
  return 1;
}
