// ExQueryRaiseUMExceptionOnInvalidHandleClose 
 
BOOL __fastcall ExQueryRaiseUMExceptionOnInvalidHandleClose(int a1)
{
  return (*(_BYTE *)(a1 + 28) & 0x10) != 0;
}
