// IoSetDeviceToVerify 
 
int __fastcall IoSetDeviceToVerify(int result, int a2)
{
  *(_DWORD *)(result + 920) = a2;
  return result;
}
