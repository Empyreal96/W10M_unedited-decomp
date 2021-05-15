// KiVerifyScopesExecute 
 
int KiVerifyScopesExecute()
{
  int v0; // r8
  void **v1; // r9
  int v2; // r10
  int (__fastcall *v3)(int *); // t1
  int v4; // r0
  char v5; // r1
  unsigned int v6; // r4
  int v7; // r2
  int v8; // r0
  int v10[2]; // [sp+8h] [bp-38h] BYREF
  int v11; // [sp+10h] [bp-30h]
  int v12; // [sp+14h] [bp-2Ch]
  unsigned int v13; // [sp+18h] [bp-28h]
  int v14; // [sp+1Ch] [bp-24h]

  v10[0] = -16777217;
  v13 = 0;
  v14 = 0;
  v0 = KiVerifyPass;
  if ( KiVerifyPass )
  {
    do
    {
      v10[1] = v0 % 2 == 0;
      v1 = &KiVerifyXcptRoutines;
      v2 = 0;
      do
      {
        v11 = 0;
        v12 = 0;
        v3 = (int (__fastcall *)(int *))*v1++;
        v4 = v3(v10);
        if ( !v12 )
          sub_96D594(v4);
        ++v2;
        v5 = 64 - (v11 & 0x3F);
        v6 = v14 ^ (v11 >> 31);
        v7 = ((v11 ^ v13) << (v11 & 0x3F)) | ((v11 ^ v13) >> v5) | (v6 << ((v11 & 0x3F) - 32)) | (v6 >> (32 - (v11 & 0x3F)));
        v8 = (v6 >> v5) | (__PAIR64__(v6, v11 ^ v13) << (v11 & 0x3F) >> 32);
        v13 = v7;
        v14 = v8;
      }
      while ( v2 < 15 );
      --v0;
    }
    while ( v0 );
  }
  else
  {
    v7 = v13;
    v8 = v14;
  }
  if ( v7 != 1336534682 || v8 != 1955845410 )
    KeBugCheckEx(333, -1, 0, 1336534682, v7);
  KiVerifyPdata(PsNtosImageBase);
  return KiVerifyPdata(PsHalImageBase);
}
