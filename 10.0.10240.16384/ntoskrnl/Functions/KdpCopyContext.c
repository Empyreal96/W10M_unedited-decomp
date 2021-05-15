// KdpCopyContext 
 
int __fastcall KdpCopyContext(_DWORD *a1, int a2, _BYTE *a3)
{
  int result; // r0

  result = KdpQuickMoveMemory((int)a1, a3, 416);
  *a1 = a2;
  return result;
}
