// SepMergeObjectTypeListAccesses 
 
int __fastcall SepMergeObjectTypeListAccesses(int result, int a2, int a3)
{
  int v3; // r5

  if ( a3 )
  {
    v3 = a2 - result;
    do
    {
      *(_DWORD *)(result + 28) &= *(_DWORD *)(v3 + result + 28);
      *(_DWORD *)(result + 32) |= *(_DWORD *)(v3 + result + 32);
      result += 44;
      --a3;
    }
    while ( a3 );
  }
  return result;
}
