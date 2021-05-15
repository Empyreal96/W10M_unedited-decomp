// EtwpWaitForBufferReferenceCount 
 
int __fastcall EtwpWaitForBufferReferenceCount(int result)
{
  int v1; // r3

  v1 = *(_DWORD *)(result + 12);
  __dmb(0xBu);
  if ( v1 )
    result = sub_809BF8();
  return result;
}
