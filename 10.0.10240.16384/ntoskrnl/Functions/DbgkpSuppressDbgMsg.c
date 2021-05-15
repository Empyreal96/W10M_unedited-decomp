// DbgkpSuppressDbgMsg 
 
BOOL __fastcall DbgkpSuppressDbgMsg(int a1)
{
  return (*(_WORD *)(a1 + 4042) & 0x80) != 0;
}
