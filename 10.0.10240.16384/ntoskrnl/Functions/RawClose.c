// RawClose 
 
int __fastcall RawClose(int a1, int a2, int a3)
{
  if ( (*(_DWORD *)(*(_DWORD *)(a3 + 28) + 44) & 0x100) == 0 )
    return sub_7CFA98();
  *(_DWORD *)(a2 + 24) = 0;
  IofCompleteRequest(a2, 1);
  return 0;
}
