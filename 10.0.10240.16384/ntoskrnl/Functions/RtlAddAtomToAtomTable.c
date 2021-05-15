// RtlAddAtomToAtomTable 
 
int __fastcall RtlAddAtomToAtomTable(int a1, _WORD *a2, _WORD *a3)
{
  return RtlAddAtomToAtomTableEx(a1, a2, a3, 0);
}
