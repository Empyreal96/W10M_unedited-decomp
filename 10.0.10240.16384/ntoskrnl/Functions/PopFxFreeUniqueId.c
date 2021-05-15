// PopFxFreeUniqueId 
 
int __fastcall PopFxFreeUniqueId(int a1)
{
  int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a1 + 24);
  result = *(_DWORD *)(a1 + 164);
  if ( v2 != result )
    return sub_7E0DB4();
  *(_WORD *)(a1 + 160) = 0;
  *(_WORD *)(a1 + 162) = 0;
  *(_DWORD *)(a1 + 164) = 0;
  return result;
}
