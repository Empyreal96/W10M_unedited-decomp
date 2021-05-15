// IopFreeReqAlternative 
 
int __fastcall IopFreeReqAlternative(int result)
{
  int v1; // r7
  int i; // r6
  int v3; // r5

  if ( result )
  {
    v1 = 0;
    if ( *(_DWORD *)(result + 16) )
    {
      for ( i = result; ; i += 4 )
      {
        v3 = *(_DWORD *)(*(_DWORD *)(i + 20) + 20);
        if ( v3 )
        {
          if ( !*(_DWORD *)(v3 + 12) )
            break;
        }
        if ( (unsigned int)++v1 >= *(_DWORD *)(result + 16) )
          return result;
      }
      result = sub_80DD6C();
    }
  }
  return result;
}
