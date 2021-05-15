// MiIssuePageExtendRequestNoWait 
 
int __fastcall MiIssuePageExtendRequestNoWait(int a1, int a2, int a3)
{
  int result; // r0
  unsigned int *v5; // r4
  unsigned int v6; // r5
  char v7; // r3

  result = a1 + 232;
  v5 = (unsigned int *)(result + 40);
  do
    v6 = __ldrex(v5);
  while ( !v6 && __strex(1u, v5) );
  if ( !v6 )
  {
    *(_DWORD *)(result + 12) = a1;
    *(_DWORD *)(result + 16) = (a2 + 4095) & 0xFFFFF000;
    v7 = *(_BYTE *)(result + 47);
    if ( a3 == 1 )
      v7 |= 1u;
    *(_DWORD *)(result + 20) = 0;
    if ( a3 != 1 )
      v7 &= 0xFEu;
    *(_BYTE *)(result + 47) = v7;
    *(_DWORD *)(result + 48) = 0;
    result = MiQueuePageFileExtension(result, 0);
  }
  return result;
}
