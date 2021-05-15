// IopQueryEnvironmentVariableInfoTrEE 
 
int __fastcall IopQueryEnvironmentVariableInfoTrEE(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int v7; // r2
  int v9; // [sp+18h] [bp-40h] BYREF
  int v10; // [sp+1Ch] [bp-3Ch] BYREF
  unsigned int v11[14]; // [sp+20h] [bp-38h] BYREF

  v9 = a3;
  v7 = IopIssueTrEERequest(2, a1, a2, (int)&v9, 4, (int)v11, 32, 0x20u, &v10);
  if ( v7 >= 0 )
  {
    if ( v11[0] )
    {
      v7 = IopEfiStatusToNTSTATUS(v11[0]);
    }
    else
    {
      *a4 = v11[2];
      a4[1] = v11[3];
      *a5 = v11[4];
      a5[1] = v11[5];
      *a6 = v11[6];
      a6[1] = v11[7];
    }
  }
  return v7;
}
