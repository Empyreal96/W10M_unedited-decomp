// BiIsSystemStore 
 
int __fastcall BiIsSystemStore(int a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r4
  _DWORD *v6; // [sp+8h] [bp-18h] BYREF
  char v7[20]; // [sp+Ch] [bp-14h] BYREF

  v2 = 0;
  v3 = 0;
  if ( BiGetRegistryValue(a1, L"System", L"Description", 4, &v6, v7) >= 0 )
  {
    if ( *v6 )
      v3 = 1;
    ExFreePoolWithTag((unsigned int)v6);
    if ( v3 )
    {
      v4 = 0;
      if ( BiGetRegistryValue(a1, L"TreatAsSystem", L"Description", 4, &v6, v7) >= 0 )
      {
        if ( *v6 )
          v4 = 1;
        ExFreePoolWithTag((unsigned int)v6);
        if ( v4 )
          v2 = 1;
      }
    }
  }
  return v2;
}
