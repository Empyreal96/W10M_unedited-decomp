// PsSetProcessWindowStation 
 
int __fastcall PsSetProcessWindowStation(int result, int a2)
{
  *(_DWORD *)(result + 308) = a2;
  return result;
}
