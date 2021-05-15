// RtlpReferenceAtom 
 
int __fastcall RtlpReferenceAtom(int result, int a2)
{
  int v2; // r3
  int v3; // r3

  if ( a2 != result + 8 && !*(_WORD *)(a2 + 12) )
  {
    v2 = *(unsigned __int16 *)(result + 20);
    if ( v2 == 0xFFFF )
      return sub_514CE4();
    *(_WORD *)(result + 20) = v2 + 1;
  }
  v3 = *(unsigned __int16 *)(a2 + 12);
  if ( v3 == 0xFFFF )
    *(_WORD *)(a2 + 14) |= 1u;
  else
    *(_WORD *)(a2 + 12) = v3 + 1;
  return result;
}
