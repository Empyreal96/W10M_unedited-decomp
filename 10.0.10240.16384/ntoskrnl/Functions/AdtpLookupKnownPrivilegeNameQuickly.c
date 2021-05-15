// AdtpLookupKnownPrivilegeNameQuickly 
 
int __fastcall AdtpLookupKnownPrivilegeNameQuickly(__int64 *a1, _DWORD *a2)
{
  __int64 v2; // r2
  int v3; // r4
  __int16 *v4; // r2

  v2 = *a1;
  v3 = 0;
  if ( *((_DWORD *)a1 + 1) || (unsigned int)(v2 - 2) > 0x21 )
    return -1073741728;
  v4 = &AdtpKnownPrivilege[8 * v2];
  *a2 = *((_DWORD *)v4 - 8);
  a2[1] = *((_DWORD *)v4 - 7);
  return v3;
}
