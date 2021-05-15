// PnpSetRegistryRequirementsList 
 
int __fastcall PnpSetRegistryRequirementsList(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD v6[4]; // [sp+8h] [bp-10h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  RtlInitUnicodeString((unsigned int)v6, L"BasicConfigVector");
  if ( a3 )
    result = ZwSetValueKey();
  else
    result = ZwDeleteValueKey();
  return result;
}
