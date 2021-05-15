// SepAuditAssignPrimaryToken 
 
int SepAuditAssignPrimaryToken()
{
  _BYTE *v0; // r0
  char v2[664]; // [sp+20h] [bp-2B8h] BYREF

  v0 = memset(v2, 0, sizeof(v2));
  if ( !*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 380) )
    JUMPOUT(0x81BE1E);
  return sub_81BD28(v0);
}
