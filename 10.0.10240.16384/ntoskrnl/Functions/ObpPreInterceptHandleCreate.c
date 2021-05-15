// ObpPreInterceptHandleCreate 
 
int __fastcall ObpPreInterceptHandleCreate(int a1, int a2, int *a3, _DWORD *a4)
{
  int v6; // r0
  int v7; // r5
  int v9; // r4
  int v10; // r4
  int result; // r0
  int v12[4]; // [sp+0h] [bp-48h] BYREF
  int v13[14]; // [sp+10h] [bp-38h] BYREF

  v6 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v7 = *a3;
  v9 = *(_DWORD *)(v6 + 72);
  v12[2] = 0;
  v12[3] = 0;
  v13[5] = (int)v12;
  v13[0] = 1;
  v13[1] = a2 & 1;
  v13[2] = a1;
  v13[3] = v6;
  v13[4] = 0;
  v10 = v9 & v7;
  v12[0] = v7;
  v12[1] = v7;
  result = ObpCallPreOperationCallbacks(v6, v13, a4);
  if ( result >= 0 && !a2 )
    *a3 &= v12[0] | v10;
  return result;
}
