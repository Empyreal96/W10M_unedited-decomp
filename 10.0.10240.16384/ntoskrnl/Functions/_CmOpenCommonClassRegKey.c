// _CmOpenCommonClassRegKey 
 
int __fastcall CmOpenCommonClassRegKey(int *a1, unsigned __int16 *a2, int a3, int a4, int a5, char a6, int a7, _DWORD *a8)
{
  int v9; // r8
  int v12; // r5
  int (__fastcall *v13)(int *, unsigned __int16 *, int, int, int, int *); // r9
  int v14; // r3
  char v15; // r2
  int v17; // r4
  int *v18; // [sp+10h] [bp-58h]
  int v20; // [sp+18h] [bp-50h] BYREF
  int v21[19]; // [sp+1Ch] [bp-4Ch] BYREF

  v9 = a7;
  v18 = a1;
  v20 = 0;
  memset(v21, 0, 40);
  if ( (unsigned __int8)a3 == 32 )
  {
    v12 = 2;
  }
  else
  {
    if ( (unsigned __int8)a3 != 64 )
    {
      v17 = -1073741811;
      goto LABEL_8;
    }
    v12 = 4;
  }
  v13 = (int (__fastcall *)(int *, unsigned __int16 *, int, int, int, int *))a1[40];
  v14 = a5;
  v15 = a6;
  v21[2] = a4;
  v21[3] = a5;
  LOBYTE(v21[4]) = a6;
  v21[1] = a3;
  v21[5] = a7;
  if ( v13 )
  {
    if ( v13(v18, a2, v12, 11, 1, &v20) != -1073741822 )
      return sub_7C72D4();
    LOWORD(a3) = v21[1];
    a4 = v21[2];
    v14 = v21[3];
    v15 = v21[4];
    v9 = v21[5];
  }
  v17 = CmOpenCommonClassRegKeyWorker(v18, a2, a3, a4, v14, v15, v9, &v21[6]);
LABEL_8:
  if ( a8 )
  {
    if ( v17 >= 0 )
      *a8 = v21[6];
  }
  return v17;
}
