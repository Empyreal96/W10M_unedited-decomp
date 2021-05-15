// MiInitializeLargePageNodeLists 
 
int __fastcall MiInitializeLargePageNodeLists(int result)
{
  int v1; // r1
  int v2; // r2
  _DWORD *v3; // r3
  int v4; // r4

  v1 = (unsigned __int16)KeNumberNodes;
  if ( KeNumberNodes )
  {
    v2 = *(_DWORD *)(result + 24) + 8;
    do
    {
      v3 = (_DWORD *)v2;
      v4 = 2;
      do
      {
        result = 2;
        do
        {
          *v3 = v3;
          v3[1] = v3;
          v3 += 2;
          --result;
        }
        while ( result );
        --v4;
      }
      while ( v4 );
      v2 += 104;
      --v1;
    }
    while ( v1 );
  }
  return result;
}
