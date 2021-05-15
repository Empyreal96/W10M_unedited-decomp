// BiUnloadHiveByHandle 
 
int __fastcall BiUnloadHiveByHandle(int a1, int a2)
{
  int v3; // r5
  unsigned int v5; // [sp+8h] [bp-18h] BYREF
  unsigned int v6[5]; // [sp+Ch] [bp-14h] BYREF

  v5 = 0;
  v3 = BiGetRegistryValue(a1, L"KeyName", (int)L"Description", 1, (int *)&v5, v6);
  BiCloseKey();
  if ( v3 >= 0 )
  {
    v3 = BiUnloadHiveByName(v5, v6[0], a2);
    ExFreePoolWithTag(v5);
  }
  return v3;
}
