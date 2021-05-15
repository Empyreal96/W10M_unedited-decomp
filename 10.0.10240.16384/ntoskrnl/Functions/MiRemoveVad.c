// MiRemoveVad 
 
int __fastcall MiRemoveVad(int a1, _DWORD *a2)
{
  int result; // r0
  int v5; // r3

  result = RtlAvlRemoveNode(a2 + 159, a1);
  if ( a2[160] == a1 )
    a2[160] = a2[159];
  --a2[161];
  *(_DWORD *)(a1 + 8) = -2;
  v5 = *(_DWORD *)(a1 + 28) & 7;
  if ( v5 == 5 || v5 == 2 && (*(_BYTE *)(a1 + 43) & 1) != 0 )
    result = sub_544868(result);
  return result;
}
