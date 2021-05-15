// PiCMReleaseRegistryPropertyInputData 
 
int __fastcall PiCMReleaseRegistryPropertyInputData(int a1)
{
  int v2; // r3
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0

  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = *(_DWORD *)(a1 + 12);
  v4 = v2 & 0xFFFFFFC0;
  if ( v3 && *(_BYTE *)(v4 + 346) )
    ExFreePoolWithTag(v3);
  if ( *(_DWORD *)(a1 + 28) )
    result = sub_811A80();
  else
    result = 0;
  return result;
}
