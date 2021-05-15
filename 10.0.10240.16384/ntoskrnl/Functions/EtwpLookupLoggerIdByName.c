// EtwpLookupLoggerIdByName 
 
int __fastcall EtwpLookupLoggerIdByName(unsigned __int16 *a1)
{
  unsigned int v2; // r4
  int v3; // r0
  _DWORD *v4; // r5

  v2 = 0;
  while ( 1 )
  {
    v3 = EtwpAcquireLoggerContextByLoggerId(v2, 0);
    v4 = (_DWORD *)v3;
    if ( v3 )
      break;
LABEL_3:
    if ( ++v2 >= 0x40 )
      return -1073741162;
  }
  if ( !RtlEqualUnicodeString((unsigned __int16 *)(v3 + 92), a1, 1) )
  {
    EtwpReleaseLoggerContext(v4, 0);
    goto LABEL_3;
  }
  return sub_7E8D30(v4);
}
