// BgpGxMarkClean 
 
int __fastcall BgpGxMarkClean(int result)
{
  *(_DWORD *)(result + 16) &= 0xFFFFFFEF;
  return result;
}
