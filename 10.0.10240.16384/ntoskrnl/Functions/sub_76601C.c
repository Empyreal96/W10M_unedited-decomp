// sub_76601C 
 
int __fastcall sub_76601C(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // [sp+8h] [bp-68h]
  int v4; // [sp+Ch] [bp-64h]
  int v5; // [sp+10h] [bp-60h] BYREF
  int v6; // [sp+14h] [bp-5Ch] BYREF
  int *v7; // [sp+18h] [bp-58h]
  int v8; // [sp+1Ch] [bp-54h]
  int v9[14]; // [sp+20h] [bp-50h] BYREF
  _DWORD v10[2]; // [sp+68h] [bp-8h] BYREF

  v10[0] = a1;
  v10[1] = a2;
  v7 = 0;
  v8 = 0;
  memset(v9, 0, sizeof(v9));
  v6 = 6;
  v5 = 1;
  result = EtwRegister((int)LicensingSqmProvider, 0, 0);
  if ( result >= 0 )
  {
    v7 = &v6;
    v8 = 0;
    v9[0] = 4;
    v9[1] = 0;
    v9[2] = (int)dword_8C822C;
    v9[3] = 0;
    v9[4] = 16;
    v9[5] = 0;
    v9[6] = (int)v10;
    v9[7] = 0;
    v9[8] = 4;
    v9[9] = 0;
    v9[10] = (int)&v5;
    v9[11] = 0;
    v9[12] = 4;
    v9[13] = 0;
    EtwWrite(v3, v4, (int)LICENSING_SQM_INCREMENT_DWORD, 0);
    result = EtwUnregister(v3);
  }
  return result;
}
