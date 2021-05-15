// PiDevCfgFreeDeviceMigrationNode 
 
unsigned int __fastcall PiDevCfgFreeDeviceMigrationNode(_DWORD *a1)
{
  _DWORD *v2; // r5
  int v3; // r6

  if ( a1[5] )
    ZwClose();
  RtlFreeAnsiString(a1 + 3);
  v2 = a1 + 6;
  v3 = 2;
  do
  {
    RtlFreeAnsiString(v2);
    v2 += 2;
    --v3;
  }
  while ( v3 );
  RtlFreeAnsiString(a1 + 15);
  RtlFreeAnsiString(a1 + 17);
  RtlFreeAnsiString(a1 + 19);
  RtlFreeAnsiString(a1 + 22);
  return ExFreePoolWithTag((unsigned int)a1);
}
