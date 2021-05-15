// BgpDisplayCharacterDestroyContext 
 
int __fastcall BgpDisplayCharacterDestroyContext(int result)
{
  int v1; // r4

  v1 = result;
  if ( result )
  {
    BgpTxtDestroyRegion(*(_DWORD *)(result + 20));
    result = BgpFwFreeMemory(v1);
  }
  return result;
}
