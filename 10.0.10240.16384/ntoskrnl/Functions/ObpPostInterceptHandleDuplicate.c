// ObpPostInterceptHandleDuplicate 
 
int __fastcall ObpPostInterceptHandleDuplicate(int a1, char a2, int a3, int a4, _DWORD *a5)
{
  int v8; // r7
  int v10; // r3
  int v12; // [sp+0h] [bp-40h] BYREF
  _DWORD v13[14]; // [sp+8h] [bp-38h] BYREF

  v8 = a1 - 24;
  memset(v13, 0, 28);
  v13[5] = a3;
  v13[6] = &v12;
  v13[0] = 2;
  v13[1] = v13[1] & 0xFFFFFFFE | a2 & 1;
  v10 = *(unsigned __int8 *)(v8 + 12);
  v13[2] = a1;
  v12 = a4;
  v13[3] = ObTypeIndexTable[v10 ^ (unsigned __int8)ObHeaderCookie ^ BYTE1(v8)];
  ObpCallPostOperationCallbacks((int)v13, a5);
  return 0;
}
