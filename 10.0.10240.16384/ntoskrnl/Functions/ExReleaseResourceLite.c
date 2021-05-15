// ExReleaseResourceLite 
 
int __fastcall ExReleaseResourceLite(int a1)
{
  return ExpReleaseResourceForThreadLite(a1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
}
