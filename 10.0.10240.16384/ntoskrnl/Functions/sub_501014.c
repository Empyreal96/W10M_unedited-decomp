// sub_501014 
 
_DWORD *__fastcall sub_501014(int *a1)
{
  int v1; // r3
  int v2; // r6
  int v3; // r5
  _DWORD *result; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r4

  v1 = a1[3];
  v2 = __mrc(15, 0, 13, 0, 3);
  v3 = *(_DWORD *)(v1 + 1036);
  v5 = *a1;
  v6 = a1[1];
  v7 = a1[2];
  v8 = a1[3];
  result = a1 + 4;
  *(_DWORD *)v3 = v5;
  *(_DWORD *)(v3 + 4) = v6;
  *(_DWORD *)(v3 + 8) = v7;
  *(_DWORD *)(v3 + 12) = v8;
  *(_DWORD *)((v2 & 0xFFFFFFC0) + 0x35C) = -v3;
  return result;
}
