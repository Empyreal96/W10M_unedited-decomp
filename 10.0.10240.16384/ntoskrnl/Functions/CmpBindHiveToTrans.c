// CmpBindHiveToTrans 
 
int __fastcall CmpBindHiveToTrans(int result, int a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r5
  int v4; // r4

  if ( result )
  {
    v2 = *(_DWORD *)(a2 + 68);
    v3 = 0;
    if ( v2 )
    {
      v4 = a2;
      while ( result != *(_DWORD *)(v4 + 72) )
      {
        ++v3;
        v4 += 4;
        if ( v3 >= v2 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      *(_DWORD *)(a2 + 4 * v2 + 72) = result;
      ++*(_DWORD *)(a2 + 68);
    }
  }
  return result;
}
