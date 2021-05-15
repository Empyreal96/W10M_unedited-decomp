// ViFaultsIsTagTarget 
 
int __fastcall ViFaultsIsTagTarget(int a1)
{
  unsigned int v2; // r2
  int v3; // r1
  int v4; // r4
  int result; // r0
  int v6; // r2
  int i; // r1
  int v8; // r0
  int v9; // [sp+0h] [bp-10h] BYREF
  _DWORD v10[3]; // [sp+4h] [bp-Ch] BYREF

  v2 = 0;
  v9 = a1;
  v10[0] = 1786137926;
  v3 = 0;
  do
  {
    v4 = *((unsigned __int8 *)v10 + v3);
    if ( v4 == 42 )
      break;
    if ( v4 != 63 && (v2 != 3 || (*((_BYTE *)&v9 + v3) & 0x7F) != v4) && *((unsigned __int8 *)&v9 + v3) != v4 )
    {
      v6 = 0;
      v9 = a1;
      v10[0] = 1819692358;
      for ( i = 0; ; ++i )
      {
        v8 = *((unsigned __int8 *)v10 + i);
        if ( v8 == 42 )
          break;
        if ( v8 != 63 && (v6 != 3 || (*((_BYTE *)&v9 + i) & 0x7F) != v8) && *((unsigned __int8 *)&v9 + i) != v8 )
        {
          result = ViFaultTagsList == (_DWORD)&ViFaultTagsList;
          if ( (int *)ViFaultTagsList != &ViFaultTagsList )
          {
            result = ViFaultsIsTagPresentInList(a1, i, (int)&ViFaultTagsList, ViFaultTagsList);
            if ( result )
              ++dword_908670;
            else
              ++dword_90866C;
          }
          return result;
        }
        if ( (unsigned int)++v6 >= 4 )
          return 0;
      }
      return 0;
    }
    ++v2;
    ++v3;
  }
  while ( v2 < 4 );
  return 0;
}
