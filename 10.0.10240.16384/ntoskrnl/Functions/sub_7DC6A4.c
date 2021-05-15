// sub_7DC6A4 
 
void __fastcall sub_7DC6A4(int a1, int a2, int a3, int a4, char a5)
{
  int v5; // r6
  int v6; // r5
  int v7; // r0

  v6 = a1 + 8;
  if ( a1 != -8 )
  {
    a5 = 0;
    v7 = SepLocateTokenTrustLevel((int *)(v5 + 28), a2, a3, 0);
    RtlSidDominatesForTrust(v7, v6, &a5);
  }
  JUMPOUT(0x6E8CDC);
}
