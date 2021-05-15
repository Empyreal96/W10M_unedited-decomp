// RtlpQueryLowBoxId 
 
int RtlpQueryLowBoxId()
{
  int v0; // r0
  int v1; // r6
  int v2; // r4
  char v4[4]; // [sp+8h] [bp-18h] BYREF
  int v5; // [sp+Ch] [bp-14h] BYREF
  char v6[16]; // [sp+10h] [bp-10h] BYREF

  v0 = PsReferenceEffectiveToken(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, &v5, v4, v6, 0);
  v1 = v5;
  v2 = v0;
  if ( v5 == 2 )
    return sub_514C98();
  v5 = 0;
  SeQueryInformationToken(v0, 32, &v5);
  if ( v1 == 1 || v2 )
    ObfDereferenceObjectWithTag(v2, 1953261124);
  return v5;
}
