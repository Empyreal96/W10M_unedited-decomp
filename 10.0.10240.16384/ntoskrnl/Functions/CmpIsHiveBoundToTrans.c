// CmpIsHiveBoundToTrans 
 
int __fastcall CmpIsHiveBoundToTrans(int a1, int a2)
{
  unsigned int v2; // r4
  unsigned int v4; // r2

  v2 = *(_DWORD *)(a2 + 68);
  if ( v2 )
  {
    v4 = 0;
    while ( a1 != *(_DWORD *)(a2 + 72) )
    {
      ++v4;
      a2 += 4;
      if ( v4 >= v2 )
        return 0;
    }
  }
  return 1;
}
