// PsGetJobSessionId 
 
unsigned int __fastcall PsGetJobSessionId(int a1)
{
  unsigned int result; // r0

  result = *(_DWORD *)(a1 + 232);
  if ( result > 0xFFFFFFFD )
    result = -1;
  return result;
}
