// PopFreeRegistration 
 
unsigned int __fastcall PopFreeRegistration(unsigned int a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r5
  int v3; // r6
  unsigned int v4; // r0

  v1 = a1;
  v2 = a1;
  v3 = 3;
  do
  {
    v4 = *(_DWORD *)(v2 + 48);
    if ( v4 )
      PopUnreferencePowerSetting(v4);
    v2 += 4;
    --v3;
  }
  while ( v3 );
  if ( *(_DWORD *)(v1 + 40) || *(_DWORD *)(v1 + 44) )
    ZwDeleteWnfStateName();
  return ExFreePoolWithTag(v1);
}
