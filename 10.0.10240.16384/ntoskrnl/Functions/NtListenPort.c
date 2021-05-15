// NtListenPort 
 
int __fastcall NtListenPort(int a1, unsigned int a2)
{
  unsigned int v2; // r4
  int v3; // r5
  int result; // r0

  v2 = a2;
  v3 = a1;
  do
    result = NtReplyWaitReceivePortEx(v3, 0, 0, v2, 0);
  while ( !result && (*(_WORD *)(v2 + 4) & 0x7FFF) != 10 );
  return result;
}
