// ObpPreInterceptHandleDuplicate 
 
int __fastcall ObpPreInterceptHandleDuplicate(int a1, int a2, int *a3, int a4, int a5, _DWORD *a6)
{
  int v8; // r0
  int v9; // r5
  int v10; // r4
  int result; // r0
  int v13[4]; // [sp+0h] [bp-48h] BYREF
  int v14[14]; // [sp+10h] [bp-38h] BYREF

  v8 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v9 = *a3;
  v10 = *(_DWORD *)(v8 + 72);
  v14[0] = 2;
  v14[1] = a2 & 1;
  v14[2] = a1;
  v14[3] = v8;
  v14[4] = 0;
  v13[2] = a4;
  v13[3] = a5;
  v14[5] = (int)v13;
  v13[0] = v9;
  v13[1] = v9;
  result = ObpCallPreOperationCallbacks(v8, v14, a6);
  if ( result >= 0 && !a2 )
    *a3 &= v13[0] | v10 & v9;
  return result;
}
