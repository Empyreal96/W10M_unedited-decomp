// EtwpCheckProviderLoggingAccess 
 
int __fastcall EtwpCheckProviderLoggingAccess(int a1, int a2, int a3)
{
  int v4; // r4
  int v6; // r3
  int v7[6]; // [sp+0h] [bp-18h] BYREF

  if ( !a3 || (*(_BYTE *)(a1 + 50) & 1) != 0 )
    return 0;
  SeCaptureSubjectContextEx(0, *(_DWORD **)(a1 + 40), v7);
  v4 = EtwpCheckGuidAccess(a2, 512, (char *)v7, v6);
  SeReleaseSubjectContext((int)v7);
  return v4;
}
