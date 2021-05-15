// IopReleaseFilteredBootResources 
 
int __fastcall IopReleaseFilteredBootResources(int result, unsigned int a2)
{
  _DWORD *v3; // r4
  int v4; // r5

  v3 = (_DWORD *)result;
  if ( result < a2 )
  {
    do
    {
      if ( (v3[1] & 0x28) == 0 )
      {
        if ( !v3[9] && v3[2] == 4 && v3[7] )
        {
          v4 = *v3 ? *(_DWORD *)(*(_DWORD *)(*v3 + 176) + 20) : 0;
          result = PnpNeedToReleaseBootResources(v4);
          if ( result )
            return sub_80D93C();
        }
        if ( ((v3[1] & 0x10) != 0 || !v3[7]) && v3[9] != -1073739512 )
          v3[9] = -1073741800;
      }
      v3 += 10;
    }
    while ( (unsigned int)v3 < a2 );
  }
  return result;
}
