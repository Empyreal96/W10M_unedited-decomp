// PfpEventHandleOutOfBuffers 
 
int __fastcall PfpEventHandleOutOfBuffers(int a1)
{
  int result; // r0

  result = PfFbBufferListAllocateTemporary(a1, 2048);
  if ( result < 0 )
    ++dword_643B0C;
  return result;
}
