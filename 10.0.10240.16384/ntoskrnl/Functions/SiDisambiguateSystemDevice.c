// SiDisambiguateSystemDevice 
 
int __fastcall SiDisambiguateSystemDevice(int a1)
{
  int v1; // r4
  int result; // r0

  v1 = SiGetRegistryValue(a1, L"SystemPartition");
  if ( v1 < 0 )
    result = v1;
  else
    result = sub_815730();
  return result;
}
