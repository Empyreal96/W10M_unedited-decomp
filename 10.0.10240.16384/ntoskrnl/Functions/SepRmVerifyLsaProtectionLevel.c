// SepRmVerifyLsaProtectionLevel 
 
int SepRmVerifyLsaProtectionLevel()
{
  char v1[8]; // [sp+18h] [bp-28h] BYREF
  int v2; // [sp+20h] [bp-20h]
  __int16 v3; // [sp+24h] [bp-1Ch]
  __int16 v4; // [sp+26h] [bp-1Ah]
  char v5; // [sp+28h] [bp-18h]
  char v6; // [sp+29h] [bp-17h]
  char v7; // [sp+2Ah] [bp-16h]
  char v8; // [sp+2Bh] [bp-15h]
  char v9; // [sp+2Ch] [bp-14h]
  char v10; // [sp+2Dh] [bp-13h]
  char v11; // [sp+2Eh] [bp-12h]
  char v12; // [sp+2Fh] [bp-11h]

  v2 = 2012912317;
  v3 = 857;
  v4 = 19762;
  v5 = -67;
  v6 = 96;
  v7 = 40;
  v8 = -12;
  v9 = -25;
  v10 = -113;
  v11 = 120;
  v12 = 75;
  RtlInitUnicodeString((unsigned int)v1, L"Kernel_Lsa_Ppl_Config");
  return ZwQuerySystemEnvironmentValueEx();
}
