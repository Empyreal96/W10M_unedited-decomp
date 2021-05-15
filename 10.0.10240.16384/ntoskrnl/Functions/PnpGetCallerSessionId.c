// PnpGetCallerSessionId 
 
int __fastcall PnpGetCallerSessionId(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r4
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  SeCaptureSubjectContext(v8, a2, a3, a4);
  v5 = v8[0];
  if ( !v8[0] )
    v5 = v8[2];
  v6 = SeQuerySessionIdToken(v5, a1);
  SeReleaseSubjectContext((int)v8);
  return v6;
}
