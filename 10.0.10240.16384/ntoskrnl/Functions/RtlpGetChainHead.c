// RtlpGetChainHead 
 
int __fastcall RtlpGetChainHead(int a1, char a2, int a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(_DWORD *)(a1 + 32);
  if ( *(_DWORD *)(a1 + 8) <= 0x80u )
    result = v3 + 8 * (a2 & 0x7F);
  else
    result = sub_52AFBC(a1, a2, a3, v3);
  return result;
}
