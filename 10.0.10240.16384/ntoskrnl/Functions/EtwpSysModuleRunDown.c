// EtwpSysModuleRunDown 
 
int __fastcall EtwpSysModuleRunDown(int a1, int a2)
{
  int v3[3]; // [sp+Ch] [bp-80h] BYREF
  __int16 v4; // [sp+18h] [bp-74h]
  char v5[8]; // [sp+1Ch] [bp-70h] BYREF
  int v6; // [sp+24h] [bp-68h]
  int v7; // [sp+2Ch] [bp-60h]
  __int16 v8; // [sp+32h] [bp-5Ah]
  int v9; // [sp+34h] [bp-58h]
  int v10; // [sp+38h] [bp-54h]
  int v11; // [sp+3Ch] [bp-50h]
  int v12; // [sp+40h] [bp-4Ch]
  int v13; // [sp+44h] [bp-48h]
  int v14[16]; // [sp+4Ch] [bp-40h] BYREF

  if ( !a2 )
    return sub_7D00E4();
  v3[1] = (int)v14;
  v3[2] = a1;
  v3[0] = (int)v5;
  v4 = 5123;
  v6 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14[0] = (int)v5;
  v14[1] = 0;
  v14[2] = 44;
  v14[3] = 0;
  v14[8] = (int)&EtwpNull;
  v14[9] = 0;
  v14[10] = 2;
  v14[11] = 0;
  return MmEnumerateSystemImages(EtwpSystemImageEnumCallback, v3);
}
