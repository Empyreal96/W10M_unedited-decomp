// CmpTraceHiveLoadStart 
 
int __fastcall CmpTraceHiveLoadStart(int a1, int a2, int a3, int a4, char a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, char a30)
{
  int result; // r0
  int v31; // r1
  __int16 v32; // r2
  int v33; // r3
  _DWORD var58[26]; // [sp+Ch] [bp-58h] BYREF

  var58[24] = a1;
  var58[25] = a2;
  var58[0] = 285212709;
  var58[1] = 327940;
  var58[2] = 0;
  var58[3] = 0x40000000;
  result = EtwEventEnabled(EtwpRegTraceHandle, unk_92026C, (int)var58);
  if ( result )
    result = sub_7C2EC4(
               result,
               v31,
               v32,
               v33,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               a15,
               a16,
               a17,
               a18,
               a19,
               a20,
               a21,
               a22,
               a23,
               a24,
               a25,
               a26,
               a27,
               a28,
               a29,
               a30);
  return result;
}
