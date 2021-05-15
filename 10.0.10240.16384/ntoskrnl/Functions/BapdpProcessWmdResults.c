// BapdpProcessWmdResults 
 
int BapdpProcessWmdResults()
{
  int result; // r0
  unsigned int v1; // r4
  int v2[14]; // [sp+8h] [bp-68h] BYREF
  int v3; // [sp+40h] [bp-30h] BYREF
  __int16 v4; // [sp+44h] [bp-2Ch]
  __int16 v5; // [sp+46h] [bp-2Ah]
  char v6; // [sp+48h] [bp-28h]
  char v7; // [sp+49h] [bp-27h]
  char v8; // [sp+4Ah] [bp-26h]
  char v9; // [sp+4Bh] [bp-25h]
  char v10; // [sp+4Ch] [bp-24h]
  char v11; // [sp+4Dh] [bp-23h]
  char v12; // [sp+4Eh] [bp-22h]
  char v13; // [sp+4Fh] [bp-21h]

  v3 = 1421354843;
  v4 = -11215;
  v5 = 18239;
  v6 = -84;
  v7 = -5;
  v8 = -27;
  v9 = 54;
  v10 = -96;
  v11 = -124;
  v12 = -108;
  v13 = -93;
  result = ExAllocatePoolWithTag(512, 0x10000, 1682989378);
  v1 = result;
  if ( result )
  {
    v2[0] = 0x10000;
    if ( BapdpQueryData(result, &v3, 0, result, v2) < 0 )
      result = ExFreePoolWithTag(v1);
    else
      result = sub_96D914();
  }
  return result;
}
