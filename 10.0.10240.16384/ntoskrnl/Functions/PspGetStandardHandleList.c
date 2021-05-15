// PspGetStandardHandleList 
 
int __fastcall PspGetStandardHandleList(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  unsigned int i; // r2

  v2 = *(_DWORD *)(*(_DWORD *)(a1 + 320) + 16);
  __dmb(0xBu);
  if ( ((v2 + 24) & 3) != 0 )
    ExRaiseDatatypeMisalignment(a1);
  result = 0;
  for ( i = 0; i < 3; ++i )
    *(_DWORD *)(a2 + 4 * i) = *(_DWORD *)(v2 + 24 + 4 * i);
  return result;
}
