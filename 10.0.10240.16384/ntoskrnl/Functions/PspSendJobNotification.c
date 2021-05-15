// PspSendJobNotification 
 
int __fastcall PspSendJobNotification(int a1)
{
  int result; // r0
  unsigned __int64 *v3; // r3
  unsigned __int64 v4; // kr00_8

  result = IoSetIoCompletion(*(_DWORD *)(a1 + 212), *(_DWORD *)(a1 + 216));
  if ( result >= 0 )
  {
    __dmb(0xBu);
    v3 = (unsigned __int64 *)(a1 + 224);
    do
      v4 = __ldrexd(v3);
    while ( __strexd(v4 + 1, v3) );
    __dmb(0xBu);
  }
  return result;
}
