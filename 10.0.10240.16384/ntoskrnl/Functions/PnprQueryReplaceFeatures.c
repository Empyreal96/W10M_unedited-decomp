// PnprQueryReplaceFeatures 
 
int __fastcall PnprQueryReplaceFeatures(int a1, _DWORD *a2)
{
  int v2; // r3
  int v3; // r4
  int v5; // [sp+8h] [bp-28h] BYREF
  char v6[4]; // [sp+10h] [bp-20h] BYREF
  int v7; // [sp+14h] [bp-1Ch]
  void (__fastcall *v8)(int); // [sp+1Ch] [bp-14h]
  int (__fastcall *v9)(int, int *); // [sp+24h] [bp-Ch]

  v2 = *(_DWORD *)(a1 + 8);
  v3 = 0;
  if ( (v2 & 4) != 0 )
  {
    v3 = 8;
  }
  else if ( (v2 & 8) != 0 )
  {
    v3 = 16;
  }
  if ( (v2 & 0x10) != 0 )
    v3 |= 0x20u;
  if ( !v3 )
  {
    if ( PnpQueryInterface(*a2, &GUID_PARTITION_UNIT_INTERFACE_STANDARD, 1, 28, 0, v6) >= 0 )
    {
      v3 = 0;
      if ( v9(v7, &v5) >= 0 )
      {
        if ( (v5 & 1) != 0 )
        {
          v3 = 8;
        }
        else if ( (v5 & 2) != 0 )
        {
          v3 = 16;
        }
        if ( (v5 & 4) != 0 )
          v3 |= 0x20u;
      }
      v8(v7);
    }
    else
    {
      v3 = 0;
    }
  }
  return v3;
}
