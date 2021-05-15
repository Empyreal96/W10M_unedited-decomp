// PopCompleteAction 
 
int __fastcall PopCompleteAction(int result, int a2)
{
  int v2; // r3
  int v3; // r0

  v2 = *(_DWORD *)(result + 4);
  if ( (v2 & 0x20) != 0 )
  {
    *(_DWORD *)(result + 4) = v2 & 0xFFFFFFDF;
    v3 = *(_DWORD *)(result + 8);
    *(_DWORD *)(v3 + 16) = a2;
    result = KeSetEvent(v3, 0, 0);
  }
  return result;
}
