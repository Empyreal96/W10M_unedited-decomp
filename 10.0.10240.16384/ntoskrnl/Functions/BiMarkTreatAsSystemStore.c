// BiMarkTreatAsSystemStore 
 
int __fastcall BiMarkTreatAsSystemStore(int a1)
{
  int v2; // r4
  int result; // r0
  int v4[2]; // [sp+8h] [bp-18h] BYREF
  unsigned int v5[4]; // [sp+10h] [bp-10h] BYREF

  v2 = 0;
  if ( BiGetRegistryValue(a1, L"System", (int)L"Description", 4, v4, v5) < 0 )
    goto LABEL_6;
  if ( *(_DWORD *)v4[0] )
    v2 = 1;
  ExFreePoolWithTag(v4[0]);
  if ( v2 )
  {
    v4[1] = 1;
    result = BiSetRegistryValue(a1, L"TreatAsSystem", L"Description", 4);
  }
  else
  {
LABEL_6:
    result = BiDeleteRegistryValue(a1);
    if ( result == -1073741772 )
      result = 0;
  }
  return result;
}
