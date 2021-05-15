// SepLocateTokenTrustLevel 
 
int __fastcall SepLocateTokenTrustLevel(int *a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r4
  _DWORD v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = a4;
  v4 = *a1;
  v5 = a1[2];
  if ( *a1 )
  {
    RtlSidDominatesForTrust(*(_DWORD *)(v5 + 640), *(_DWORD *)(v4 + 640), v7);
    if ( LOBYTE(v7[0]) )
      v5 = v4;
  }
  return *(_DWORD *)(v5 + 640);
}
