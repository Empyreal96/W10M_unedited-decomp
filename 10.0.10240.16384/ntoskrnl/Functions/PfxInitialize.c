// PfxInitialize 
 
int __fastcall PfxInitialize(int result)
{
  *(_WORD *)result = 512;
  *(_WORD *)(result + 2) = 0;
  *(_DWORD *)(result + 4) = result;
  return result;
}
