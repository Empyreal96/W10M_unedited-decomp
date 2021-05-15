// ObpPostInterceptHandleCreate 
 
int __fastcall ObpPostInterceptHandleCreate(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r1
  int v7; // [sp+0h] [bp-30h] BYREF
  int v8[10]; // [sp+8h] [bp-28h] BYREF

  v8[5] = a3;
  v8[6] = (int)&v7;
  v8[1] = a2 & 1;
  v8[2] = a1;
  v8[0] = 1;
  v5 = *(unsigned __int8 *)(a1 - 12);
  v8[4] = 0;
  v7 = a4;
  v8[3] = ObTypeIndexTable[v5 ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  ObpCallPostOperationCallbacks((int)v8, a5);
  return 0;
}
