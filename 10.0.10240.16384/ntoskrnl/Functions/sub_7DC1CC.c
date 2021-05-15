// sub_7DC1CC 
 
void __fastcall sub_7DC1CC(int a1, int a2, int a3, int a4, char a5)
{
  int v5; // r4
  char v6; // r5
  bool v7; // zf
  int v8; // r8
  int v9; // r0
  int v10; // r7
  int v11; // r6
  int v12; // r0
  int v13; // r3

  v8 = a1 + 8;
  v7 = a1 == -8;
  v9 = *(_DWORD *)(a1 + 4);
  v10 = ~v9 & 0x1120089;
  v11 = ~v9 & 0x11F0116;
  if ( !v7 )
  {
    v12 = SepLocateTokenTrustLevel((int *)(v5 + 28), a2, a3, 18809110);
    RtlSidDominatesForTrust(v12, v8, &a5);
    if ( !a5 )
    {
      v13 = *(_DWORD *)(v5 + 20);
      if ( (v6 & 2) != 0 )
        v13 &= ~v10;
      if ( (v6 & 4) != 0 )
        v13 &= ~v11;
      *(_DWORD *)(v5 + 20) = v13;
    }
  }
  JUMPOUT(0x6E71E4);
}
