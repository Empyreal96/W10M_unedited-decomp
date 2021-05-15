// IopDuplicateDetection 
 
int __fastcall IopDuplicateDetection(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r0
  int result; // r0
  char v6[32]; // [sp+8h] [bp-20h] BYREF

  *a4 = 0;
  v4 = IopFindLegacyBusDeviceNode(a1, a2);
  if ( v4 && IopQueryResourceHandlerInterface(3, *(_DWORD *)(v4 + 16), 0, v6) >= 0 )
    result = sub_80CCF4();
  else
    result = -1073741808;
  return result;
}
