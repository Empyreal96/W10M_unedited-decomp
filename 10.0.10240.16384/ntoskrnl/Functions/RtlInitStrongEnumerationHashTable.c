// RtlInitStrongEnumerationHashTable 
 
int __fastcall RtlInitStrongEnumerationHashTable(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r3
  int result; // r0
  int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[1] = a3;
  v7[2] = a4;
  RtlpPopulateContext(a1, v7, 0);
  memset((_BYTE *)a2, 0, 20);
  v5 = v7[0];
  result = 1;
  *(_DWORD *)(a2 + 12) = v7[0];
  *(_DWORD *)a2 = v5;
  return result;
}
