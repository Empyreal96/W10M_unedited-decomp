// BapdpProcessSiData 
 
_DWORD *__fastcall BapdpProcessSiData(int a1)
{
  _DWORD *v1; // r4
  _DWORD *result; // r0
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

  v4 = -1237722659;
  v5 = 25202;
  v6 = 18204;
  v7 = -79;
  v8 = -78;
  v9 = 89;
  v10 = 52;
  v11 = 16;
  v12 = 72;
  v13 = -32;
  v14 = 47;
  v3[0] = 0;
  v1 = 0;
  result = (_DWORD *)BapdpQueryData(a1, &v4, 0, 0, v3);
  if ( result == (_DWORD *)-1073741789 )
  {
    result = (_DWORD *)ExAllocatePoolWithTag(512, v3[0], 1682989378);
    v1 = result;
    if ( !result )
      return result;
    result = 0;
  }
  if ( (int)result >= 0 )
  {
    result = (_DWORD *)BapdpQueryData(result, &v4, 0, v1, v3);
    if ( (int)result >= 0 )
      result = BapdRegisterSiData(v1, v3[0], 0);
  }
  if ( v1 )
    result = (_DWORD *)ExFreePoolWithTag((unsigned int)v1);
  return result;
}
