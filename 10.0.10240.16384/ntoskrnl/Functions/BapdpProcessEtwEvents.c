// BapdpProcessEtwEvents 
 
int __fastcall BapdpProcessEtwEvents(int result)
{
  unsigned int v1; // r7
  int v2; // r4
  int i; // r6
  int v4; // r5
  int v5[2]; // [sp+8h] [bp-38h] BYREF
  int v6; // [sp+10h] [bp-30h] BYREF
  __int16 v7; // [sp+14h] [bp-2Ch]
  __int16 v8; // [sp+16h] [bp-2Ah]
  char v9; // [sp+18h] [bp-28h]
  char v10; // [sp+19h] [bp-27h]
  char v11; // [sp+1Ah] [bp-26h]
  char v12; // [sp+1Bh] [bp-25h]
  char v13; // [sp+1Ch] [bp-24h]
  char v14; // [sp+1Dh] [bp-23h]
  char v15; // [sp+1Eh] [bp-22h]
  char v16; // [sp+1Fh] [bp-21h]

  v1 = 0;
  v6 = -1667627438;
  v7 = 27623;
  v8 = 19158;
  v9 = -99;
  v10 = -73;
  v11 = 80;
  v12 = -22;
  v13 = -46;
  v14 = 3;
  v15 = 30;
  v16 = -76;
  v2 = 0;
  for ( i = 0; ; ++i )
  {
    v5[0] = 0;
    result = BapdpQueryData(result, &v6, i, 0, v5);
    if ( result != -1073741789 && result < 0 )
      break;
    v4 = v5[0];
    if ( v5[0] > v1 )
    {
      if ( v2 )
        ExFreePoolWithTag(v2, 0);
      result = ExAllocatePoolWithTag(512, v4, 1682989378);
      v2 = result;
      if ( !result )
        return result;
      v1 = v4;
    }
    result = BapdpQueryData(result, &v6, i, v2, v5);
    if ( result < 0 )
      break;
    result = BapdWriteEtwEvents(v2, v5[0]);
    if ( result < 0 )
      break;
  }
  if ( v2 )
    result = ExFreePoolWithTag(v2, 0);
  return result;
}
