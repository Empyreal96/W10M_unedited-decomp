// BapdpProcessSecureBootPolicy 
 
int __fastcall BapdpProcessSecureBootPolicy(int a1)
{
  unsigned int v1; // r4
  int result; // r0
  int v3[2]; // [sp+8h] [bp-20h] BYREF
  int v4; // [sp+10h] [bp-18h] BYREF
  __int16 v5; // [sp+14h] [bp-14h]
  __int16 v6; // [sp+16h] [bp-12h]
  char v7; // [sp+18h] [bp-10h]
  char v8; // [sp+19h] [bp-Fh]
  char v9; // [sp+1Ah] [bp-Eh]
  char v10; // [sp+1Bh] [bp-Dh]
  char v11; // [sp+1Ch] [bp-Ch]
  char v12; // [sp+1Dh] [bp-Bh]
  char v13; // [sp+1Eh] [bp-Ah]
  char v14; // [sp+1Fh] [bp-9h]

  v4 = 1870866835;
  v5 = 20869;
  v6 = 0x4000;
  v7 = -104;
  v8 = 94;
  v9 = 22;
  v10 = 70;
  v11 = -3;
  v12 = 110;
  v13 = -70;
  v14 = 120;
  v3[0] = 0;
  v1 = 0;
  result = BapdpQueryData(a1, &v4, 0, 0, v3);
  if ( result == -1073741789 )
  {
    result = ExAllocatePoolWithTag(512, v3[0], 1682989378);
    v1 = result;
    if ( !result )
      return result;
    result = 0;
  }
  if ( result >= 0 )
  {
    result = BapdpQueryData(result, &v4, 0, v1, v3);
    if ( result >= 0 )
      result = SeSecureBootRegisterPolicy(v1, v3[0]);
  }
  if ( v1 )
    result = ExFreePoolWithTag(v1);
  return result;
}
