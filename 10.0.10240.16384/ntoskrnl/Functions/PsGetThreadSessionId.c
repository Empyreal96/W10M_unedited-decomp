// PsGetThreadSessionId 
 
int __fastcall PsGetThreadSessionId(int a1)
{
  return MmGetSessionId(*(_DWORD *)(a1 + 336));
}
