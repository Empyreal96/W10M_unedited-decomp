// sub_7E0E8C 
 
// positive sp value has been detected, the output may be wrong!
unsigned int sub_7E0E8C()
{
  _DWORD *v1; // r4
  __int64 **v2; // r5
  __int64 v3; // r2
  __int64 **v4; // r5
  __int64 v5; // r2
  __int64 **v6; // r5
  __int64 v7; // r2

  while ( *v2 != (__int64 *)v2 )
  {
    v3 = **v2;
    if ( (__int64 **)HIDWORD(v3) != v2 || *(__int64 **)(v3 + 4) != *v2 )
      __fastfail(3u);
    *v2 = (__int64 *)v3;
    *(_DWORD *)(v3 + 4) = v2;
    PiDevCfgFreeDriverNode();
  }
  v4 = (__int64 **)(v1 + 30);
  while ( *v4 != (__int64 *)v4 )
  {
    v5 = **v4;
    if ( (__int64 **)HIDWORD(v5) != v4 || *(__int64 **)(v5 + 4) != *v4 )
      __fastfail(3u);
    *v4 = (__int64 *)v5;
    *(_DWORD *)(v5 + 4) = v4;
    PiDevCfgFreeDriverNode();
  }
  v6 = (__int64 **)(v1 + 52);
  while ( *v6 != (__int64 *)v6 )
  {
    v7 = **v6;
    if ( (__int64 **)HIDWORD(v7) != v6 || *(__int64 **)(v7 + 4) != *v6 )
      __fastfail(3u);
    *v6 = (__int64 *)v7;
    *(_DWORD *)(v7 + 4) = v6;
    PiDevCfgFreeDriverNode();
  }
  if ( v1[2] )
    ZwClose();
  if ( v1[3] )
    ZwClose();
  if ( v1[4] )
    ZwClose();
  RtlFreeAnsiString(v1 + 7);
  RtlFreeAnsiString(v1 + 5);
  RtlFreeAnsiString(v1 + 9);
  RtlFreeAnsiString(v1 + 11);
  RtlFreeAnsiString(v1 + 20);
  RtlFreeAnsiString(v1 + 22);
  RtlFreeAnsiString(v1 + 38);
  RtlFreeAnsiString(v1 + 40);
  RtlFreeAnsiString(v1 + 42);
  RtlFreeAnsiString(v1 + 44);
  RtlFreeAnsiString(v1 + 46);
  RtlFreeAnsiString(v1 + 48);
  RtlFreeAnsiString(v1 + 50);
  RtlFreeAnsiString(v1 + 56);
  return ExFreePoolWithTag((unsigned int)v1);
}
