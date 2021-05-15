// DbgkCopyProcessDebugPort 
 
int __fastcall DbgkCopyProcessDebugPort(int a1, int a2, int a3, _BYTE *a4)
{
  *(_DWORD *)(a1 + 340) = 0;
  if ( a3 )
    JUMPOUT(0x7F4C1C);
  if ( *(_DWORD *)(a2 + 340) )
    return sub_7F4B78();
  *a4 = 0;
  return 0;
}
