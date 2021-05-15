// BiGetObjectDescription 
 
int __fastcall BiGetObjectDescription(int a1, _DWORD *a2)
{
  unsigned int v3; // r4
  int v4; // r5
  int v5; // r6
  _DWORD *v7; // [sp+8h] [bp-18h] BYREF
  int v8[5]; // [sp+Ch] [bp-14h] BYREF

  v8[0] = 0;
  v3 = 0;
  v7 = 0;
  v4 = BiOpenKey(a1, L"Description", 131097, v8);
  v5 = v8[0];
  if ( v4 >= 0 )
  {
    *a2 = 1;
    v8[0] = 0;
    v4 = BiGetRegistryValue(v5, L"Type", 0, 4, &v7, v8);
    v3 = (unsigned int)v7;
    if ( v4 >= 0 )
    {
      if ( v8[0] == 4 )
        a2[1] = *v7;
      else
        v4 = -1073741788;
    }
  }
  if ( v5 )
    BiCloseKey(v5);
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v4;
}
