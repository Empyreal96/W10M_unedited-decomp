// FsRtlRegisterUncProvider 
 
int __fastcall FsRtlRegisterUncProvider(_DWORD *a1, int a2, int a3, int a4)
{
  __int16 v5[2]; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+4h] [bp-Ch]
  int v7; // [sp+8h] [bp-8h]

  v7 = a4;
  v6 = 0;
  v5[0] = 8;
  v5[1] = 256;
  if ( a3 )
    v6 = 1;
  return FsRtlpRegisterUncProvider(a2, 0, (int)v5, a1);
}
