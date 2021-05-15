// CmpTraceHiveUnloadStart 
 
int __fastcall CmpTraceHiveUnloadStart(int a1, int a2, int a3, int a4, char a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int result; // r0
  int v13; // r1
  __int16 v14; // r2
  int v15; // r3
  _DWORD v16[28]; // [sp+Ch] [bp-70h] BYREF

  v16[0] = 285212692;
  v16[1] = 131332;
  v16[2] = 0;
  v16[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)v16);
  if ( result )
    result = sub_7D1F28(result, v13, v14, v15, a5, a6, a7, a8, a9, a10, a11, a12);
  return result;
}
