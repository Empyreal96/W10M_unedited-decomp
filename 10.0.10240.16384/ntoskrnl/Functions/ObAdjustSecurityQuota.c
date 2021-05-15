// ObAdjustSecurityQuota 
 
int __fastcall ObAdjustSecurityQuota(int a1, int a2)
{
  int v2; // r0
  __int64 v3; // r6
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r3

  v2 = a1 - 24;
  LODWORD(v3) = a2;
  if ( *(_DWORD *)(v2 + 16) == 1 )
    return 0;
  if ( (*(_BYTE *)(v2 + 14) & 8) != 0 )
    v4 = v2 - ObpInfoMaskToOffset[*(_BYTE *)(v2 + 14) & 0xF];
  else
    v4 = 0;
  HIDWORD(v3) = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a2, 0);
  if ( HIDWORD(v3) )
  {
    v5 = *(_DWORD *)(v4 + 12);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v4 + 8);
      if ( v5 != 1 )
      {
        if ( v6 )
          PspReturnQuota(*(_DWORD *)(v4 + 12), 0, 1, v6);
        PspDereferenceQuotaBlock(v5);
      }
    }
    *(_QWORD *)(v4 + 8) = v3;
    return 0;
  }
  return -1073741756;
}
