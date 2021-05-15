// RtlIsSandboxedToken 
 
BOOL __fastcall RtlIsSandboxedToken(char *a1, char a2)
{
  char *v3; // r5
  int v4; // r6
  int v6; // [sp+18h] [bp-28h] BYREF
  int v7; // [sp+1Ch] [bp-24h] BYREF
  char v8[32]; // [sp+20h] [bp-20h] BYREF

  v3 = 0;
  v4 = 0;
  v6 = 0;
  v7 = 0;
  if ( !a2
    || (a1 ? (v3 = a1) : (v3 = v8, SeCaptureSubjectContext(v8)),
        SeAccessCheck(SeMediumDaclSd, (int)v3, 0, 0x20000, 0, 0, (int)RtlpRestrictedMapping, a2, (int)&v7, (int)&v6) == 1) )
  {
    v4 = 1;
  }
  if ( v3 == v8 )
    SeReleaseSubjectContext((int)v3);
  return v4 != 1;
}
