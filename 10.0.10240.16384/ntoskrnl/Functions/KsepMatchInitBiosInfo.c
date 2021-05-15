// KsepMatchInitBiosInfo 
 
int KsepMatchInitBiosInfo()
{
  int v0; // r7
  int v1; // r9
  int v3[2]; // [sp+8h] [bp-40h] BYREF
  char v4[56]; // [sp+10h] [bp-38h] BYREF

  v3[0] = 0;
  memset(dword_6474D0, 0, 36);
  v0 = KsepRegistryOpenKey(L"\\Registry\\Machine\\Hardware\\Description\\System", 0, v3);
  v1 = v3[0];
  if ( v0 >= 0 )
  {
    v0 = KsepRegistryQuerySZ(v3[0], L"SystemBiosDate", 1, (int)v4, 0x16u, v3);
    if ( v0 >= 0 )
      return sub_965644();
  }
  if ( v1 )
    KsepRegistryCloseKey(v1);
  if ( v0 >= 0 )
    JUMPOUT(0x965776);
  dword_6474D0[0] = 0;
  dword_6474E8 = -1;
  return v0;
}
