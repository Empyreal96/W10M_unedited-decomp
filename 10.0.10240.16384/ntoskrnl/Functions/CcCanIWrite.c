// CcCanIWrite 
 
int __fastcall CcCanIWrite(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 && ((*(_DWORD *)(a1 + 44) & 0x10) != 0 || IoIsFileOriginRemote(a1))
    || (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) != 0
    || (a4 || (int *)CcDeferredWrites == &CcDeferredWrites) && CcCanIWriteStream(a1, a2, 0, 0) )
  {
    result = 1;
  }
  else
  {
    result = sub_53D57C();
  }
  return result;
}
