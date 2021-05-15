// SmWaitForSyncIo 
 
int __fastcall SmWaitForSyncIo(int a1)
{
  return KeWaitForSingleObject(a1 + 3632, 7, 0, 0, 0);
}
