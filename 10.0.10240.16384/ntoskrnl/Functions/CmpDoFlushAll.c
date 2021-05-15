// CmpDoFlushAll 
 
int __fastcall CmpDoFlushAll(int result)
{
  int v1; // r5
  int i; // r0
  int v3; // r4

  v1 = result;
  if ( !CmpNoWrite )
  {
    for ( i = 0; ; i = v3 )
    {
      result = CmpGetNextActiveHive(i);
      v3 = result;
      if ( !result )
        break;
      if ( (*(_DWORD *)(result + 92) & 2) == 0 )
        CmpFlushHive(result, v1);
    }
  }
  return result;
}
