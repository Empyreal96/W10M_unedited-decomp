// ExpWin32ParseProcedure 
 
int __fastcall ExpWin32ParseProcedure(int *a1, int a2, int a3, char a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  int v12; // [sp+0h] [bp-38h] BYREF
  int v13[3]; // [sp+8h] [bp-30h] BYREF
  char v14; // [sp+14h] [bp-24h]
  int v15; // [sp+18h] [bp-20h]
  int v16; // [sp+1Ch] [bp-1Ch]
  int v17; // [sp+20h] [bp-18h]
  int v18; // [sp+24h] [bp-14h]
  int v19; // [sp+28h] [bp-10h]
  int v20; // [sp+2Ch] [bp-Ch]

  v14 = a4;
  v10 = *a1;
  v13[1] = a2;
  v13[2] = a3;
  v15 = a5;
  v13[0] = (int)a1;
  v16 = a6;
  v12 = v10;
  v17 = a7;
  v18 = a8;
  v19 = a9;
  v20 = a10;
  return PsInvokeWin32Callout(15, (int)v13, 1, &v12);
}
