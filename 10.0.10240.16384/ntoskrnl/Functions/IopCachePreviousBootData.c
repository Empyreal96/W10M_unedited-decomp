// IopCachePreviousBootData 
 
int IopCachePreviousBootData()
{
  int result; // r0
  int v1; // [sp+10h] [bp-28h] BYREF
  char v2[8]; // [sp+18h] [bp-20h] BYREF
  int v3; // [sp+20h] [bp-18h] BYREF
  __int16 v4; // [sp+24h] [bp-14h]
  __int16 v5; // [sp+26h] [bp-12h]
  char v6; // [sp+28h] [bp-10h]
  char v7; // [sp+29h] [bp-Fh]
  char v8; // [sp+2Ah] [bp-Eh]
  char v9; // [sp+2Bh] [bp-Dh]
  char v10; // [sp+2Ch] [bp-Ch]
  char v11; // [sp+2Dh] [bp-Bh]
  char v12; // [sp+2Eh] [bp-Ah]
  char v13; // [sp+2Fh] [bp-9h]

  v3 = 2012912317;
  v4 = 857;
  v5 = 19762;
  v6 = -67;
  v7 = 96;
  v8 = 40;
  v9 = -12;
  v10 = -25;
  v11 = -113;
  v12 = 120;
  v13 = 75;
  v1 = 8;
  result = IoGetEnvironmentVariableEx((int)L"DumpInstance", (int)&v3, (int)v2, (int)&v1, 0);
  if ( result >= 0 )
    result = ZwSetValueKey();
  return result;
}
