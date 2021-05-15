// BapdpProcessFwUpdateResults 
 
int __fastcall BapdpProcessFwUpdateResults(int a1)
{
  int result; // r0
  int v2[2]; // [sp+8h] [bp-20h] BYREF
  int v3; // [sp+10h] [bp-18h] BYREF
  __int16 v4; // [sp+14h] [bp-14h]
  __int16 v5; // [sp+16h] [bp-12h]
  char v6; // [sp+18h] [bp-10h]
  char v7; // [sp+19h] [bp-Fh]
  char v8; // [sp+1Ah] [bp-Eh]
  char v9; // [sp+1Bh] [bp-Dh]
  char v10; // [sp+1Ch] [bp-Ch]
  char v11; // [sp+1Dh] [bp-Bh]
  char v12; // [sp+1Eh] [bp-Ah]
  char v13; // [sp+1Fh] [bp-9h]

  v3 = -714793284;
  v4 = 5423;
  v5 = 18767;
  v6 = -69;
  v7 = 69;
  v8 = 74;
  v9 = 60;
  v10 = -125;
  v11 = -21;
  v12 = -39;
  v13 = -18;
  v2[0] = 0;
  result = BapdpQueryData(a1, &v3, 0, 0, v2);
  if ( result == -1073741789 )
    return sub_96D868();
  if ( result >= 0 )
  {
    result = BapdpQueryData(result, &v3, 0, 0, v2);
    if ( result >= 0 )
      result = BapdpRegisterFwUpdateResults(0, v2[0]);
  }
  return result;
}
