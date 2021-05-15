// MiDoReplacement 
 
_DWORD *__fastcall MiDoReplacement(_DWORD *result, int a2)
{
  _DWORD *v2; // r4
  int v4; // r1

  v2 = result;
  if ( result[13] >= result[12] )
  {
    if ( result[27] )
    {
      v4 = 0;
    }
    else
    {
      if ( MiWorkingSetVeryLarge() != 1 )
        return (_DWORD *)MiReplaceWorkingSetEntryIfNecessary(v2, a2);
      v4 = 1;
      result = v2;
    }
    MiForcedTrim(result, v4);
    return (_DWORD *)MiReplaceWorkingSetEntryIfNecessary(v2, a2);
  }
  return result;
}
