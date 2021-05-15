// LocalGetStringForSid 
 
int __fastcall LocalGetStringForSid(_BYTE *a1, char **a2)
{
  unsigned int v3; // r4
  int v5; // r0
  int v6; // r2
  int v7; // r5
  int v8; // r0
  int v9; // r1
  unsigned int v10; // r7
  char *v11; // r0
  char *v12; // r2

  v3 = 0;
  if ( !a1 || !a2 )
    return 87;
  v5 = LookupSidInTable(a1, a1);
  v7 = v5;
  if ( v5 )
  {
    v10 = 2 * (*(_DWORD *)(v5 + 12) + 1);
    v11 = (char *)SddlpAlloc(v10);
    *a2 = v11;
    if ( v11 )
    {
      if ( v7 )
        v12 = (char *)(v7 + 2);
      else
        v12 = (char *)L"SA";
      wcscpy_s(v11, v10 >> 1, v12);
    }
    else
    {
      v3 = 8;
    }
  }
  else
  {
    v8 = LocalConvertSidToStringSidW(a1, a2, v6, 0);
    if ( v8 < 0 )
      v3 = RtlNtStatusToDosError(v8, v9);
  }
  return v3;
}
