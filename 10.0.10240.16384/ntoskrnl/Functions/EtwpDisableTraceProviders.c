// EtwpDisableTraceProviders 
 
int __fastcall EtwpDisableTraceProviders(int a1)
{
  int i; // r0
  int v3; // r0
  int v4; // r4
  int j; // r0
  int result; // r0
  int v7; // r4
  int v8; // r4

  for ( i = 0; ; i = v4 )
  {
    v3 = EtwpGetNextGuidEntry(i, 0);
    v4 = v3;
    if ( !v3 )
      break;
    EtwpClearSessionAndUnreferenceEntry(a1, v3, 0);
  }
  for ( j = 0; ; j = v7 )
  {
    result = EtwpGetNextGuidEntry(j, 2);
    v7 = result;
    if ( !result )
      break;
    EtwpClearSessionAndUnreferenceEntry(a1, result, 2);
  }
  v8 = 0;
  while ( *(unsigned __int8 *)(2 * (v8 - 13888)) != (unsigned __int8)a1 )
  {
    if ( (unsigned int)++v8 >= 9 )
      return result;
  }
  return sub_7EE230();
}
