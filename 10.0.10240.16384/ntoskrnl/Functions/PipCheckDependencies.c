// PipCheckDependencies 
 
int __fastcall PipCheckDependencies(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[8]; // [sp+0h] [bp-20h] BYREF

  v5[0] = a2;
  v5[1] = a3;
  v5[2] = a4;
  if ( IopGetRegistryValue(a1, L"DependOnGroup", 0, v5) < 0 )
    result = 1;
  else
    result = sub_96910C();
  return result;
}
