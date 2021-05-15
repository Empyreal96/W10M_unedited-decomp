// RtlpDereferenceAtom 
 
int __fastcall RtlpDereferenceAtom(int a1, int a2, int a3)
{
  int v3; // r3

  if ( (*(_WORD *)(a2 + 14) & 1) != 0 )
    return 0;
  v3 = (unsigned __int16)(*(_WORD *)(a2 + 12) - 1);
  *(_WORD *)(a2 + 12) = v3;
  if ( v3 )
    return 0;
  if ( a2 != a1 + 8 )
    return sub_5148F4();
  RtlpFreeAllAtom(a1, a3);
  return 1;
}
