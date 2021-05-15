// PpmResetPerformanceAccumulation 
 
int __fastcall PpmResetPerformanceAccumulation(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r1
  int result; // r0
  int v8; // [sp+0h] [bp-10h] BYREF
  int v9; // [sp+4h] [bp-Ch]
  int v10; // [sp+8h] [bp-8h]

  v8 = a2;
  v9 = a3;
  v10 = a4;
  v5 = ReadTimeStampCounter();
  a1[755] = v6;
  a1[754] = v5;
  result = KeQueryPerformanceCounter(&v8, 0);
  a1[760] = v8;
  a1[761] = v9;
  return result;
}
