// BiCreateEfiEntry 
 
int __fastcall BiCreateEfiEntry(int a1, _DWORD *a2)
{
  int v3; // r5
  int v5; // r2
  int v6; // r4
  int v7; // r7
  unsigned int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v14; // [sp+8h] [bp-28h] BYREF
  int v15; // [sp+Ch] [bp-24h] BYREF
  int v16[8]; // [sp+10h] [bp-20h] BYREF

  v3 = 0;
  v15 = 0;
  v6 = BcdOpenObject(a1, a2 + 2, v16);
  v7 = v16[0];
  if ( v6 < 0 )
    goto LABEL_14;
  v8 = a2[8];
  if ( (v8 & 2) != 0 )
  {
    v6 = BiGetSavedBootEntry(v16[0], &v15, v5, v8);
    if ( v6 >= 0 )
    {
      v10 = a2[8];
      v3 = v15;
      if ( (v10 & 8) != 0 || (v6 = BiUpdateObjectReferenceInEfiEntry(v15, v7), v6 >= 0) )
      {
        v6 = BiAddBootEntry(v3, (int)&v14, v9, v10);
        if ( v6 >= 0 )
        {
          *(_DWORD *)(v3 + 8) = v14;
          a2[6] = v14;
          a2[7] = v3;
          a2[8] |= 1u;
          v6 = BiSetRegistryValue(v7, L"FirmwareVariable", L"Description", 3);
          if ( v6 >= 0 )
            v6 = BiUpdateEfiEntry(a1, (int)a2);
        }
      }
      goto LABEL_14;
    }
LABEL_13:
    v3 = v15;
    goto LABEL_14;
  }
  v6 = BiCreateBootEntry(v16[0], (int)&v15);
  if ( v6 < 0 )
    goto LABEL_13;
  v3 = v15;
  v6 = BiAddBootEntry(v15, (int)&v14, v11, v12);
  if ( v6 >= 0 )
  {
    *(_DWORD *)(v3 + 8) = v14;
    a2[6] = v14;
    a2[7] = v3;
    a2[8] |= 1u;
    v6 = BiSetRegistryValue(v7, L"FirmwareVariable", L"Description", 3);
    if ( v6 >= 0 )
      a2[8] |= 2u;
  }
LABEL_14:
  if ( v7 )
    BcdCloseObject(v7);
  if ( (a2[8] & 1) == 0 && v3 )
    ExFreePoolWithTag(v3);
  return v6;
}
