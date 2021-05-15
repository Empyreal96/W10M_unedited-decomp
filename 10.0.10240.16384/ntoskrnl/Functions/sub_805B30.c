// sub_805B30 
 
void __fastcall sub_805B30(int a1, int a2, int a3, int a4, unsigned int a5)
{
  unsigned int *v5; // r4
  unsigned int v6; // r1
  unsigned int v7; // r0

  v6 = a5;
  __dmb(0xBu);
  v7 = v6 / 3;
  if ( v6 / 3 < 0x1000000 )
    v7 = 0x1000000;
  __dmb(0xBu);
  *v5 = a5;
  CmpGlobalQuota = v7;
  CmpGlobalQuotaAllowed = v7;
  CmpGlobalQuotaWarning = 95 * (v7 / 0x64);
  JUMPOUT(0x7517AC);
}
