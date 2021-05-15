// PiHotSwapGetDetachableNode 
 
int __fastcall PiHotSwapGetDetachableNode(int result, _DWORD *a2)
{
  while ( result && (*(_DWORD *)(result + 368) & 0x18) == 0 )
    result = *(_DWORD *)(result + 8);
  *a2 = result;
  return result;
}
