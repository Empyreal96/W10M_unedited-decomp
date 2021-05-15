// FsRtlOplockKeysEqual 
 
int __fastcall FsRtlOplockKeysEqual(int a1, int a2)
{
  return FsRtlpOplockKeysEqual(a1, a2, 0);
}
