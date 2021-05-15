// ViDeadlockUpdateChildrenCount 
 
int __fastcall ViDeadlockUpdateChildrenCount(_DWORD *a1, int a2)
{
  int v2; // r2
  int result; // r0

  do
  {
    v2 = a1[10] + a2;
    a1[10] = v2;
    a1 = (_DWORD *)*a1;
  }
  while ( a1 );
  result = ViDeadlockGlobals;
  if ( v2 > *(_DWORD *)(ViDeadlockGlobals + 16604) )
    *(_DWORD *)(ViDeadlockGlobals + 16604) = v2;
  return result;
}
