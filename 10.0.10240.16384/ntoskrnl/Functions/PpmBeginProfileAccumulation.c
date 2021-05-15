// PpmBeginProfileAccumulation 
 
int __fastcall PpmBeginProfileAccumulation(int result, int a2, int a3, int a4)
{
  *(_DWORD *)(result + 384) = a3;
  *(_DWORD *)(result + 388) = a4;
  return result;
}
