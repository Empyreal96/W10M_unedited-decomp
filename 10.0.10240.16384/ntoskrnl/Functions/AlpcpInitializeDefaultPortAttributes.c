// AlpcpInitializeDefaultPortAttributes 
 
_DWORD *__fastcall AlpcpInitializeDefaultPortAttributes(_DWORD *result, int a2, int a3, int a4)
{
  int v4; // [sp+8h] [bp-10h]

  HIWORD(v4) = HIWORD(a4);
  LOWORD(v4) = 257;
  result[4] = 256;
  result[6] = 0x4000;
  result[7] = 0x4000;
  result[8] = 0;
  result[9] = 0x20000;
  *result = 0;
  result[5] = 0;
  result[1] = 12;
  result[2] = 0;
  result[3] = v4;
  result[10] = 0;
  return result;
}
