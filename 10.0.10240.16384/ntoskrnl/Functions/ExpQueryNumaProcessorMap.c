// ExpQueryNumaProcessorMap 
 
int __fastcall ExpQueryNumaProcessorMap(int *a1, unsigned int a2, _DWORD *a3)
{
  int result; // r0
  unsigned int v7; // r0
  unsigned int v8; // r5
  unsigned int i; // r4

  if ( a2 >= 4 )
  {
    *a1 = KeQueryHighestNodeNumber();
    v7 = KeQueryHighestNodeNumber() + 1;
    v8 = (a2 - 8) / 0xC;
    if ( v8 > v7 )
      v8 = v7;
    if ( a2 >= 8 && v8 )
    {
      *a3 = 12 * v8 + 8;
      for ( i = 0; i < v8; ++i )
        KeQueryNodeActiveAffinity((unsigned __int16)i, &a1[3 * i + 2], 0);
      result = 0;
    }
    else
    {
      *a3 = 4;
      result = 0;
    }
  }
  else
  {
    if ( a3 )
      *a3 = 4;
    result = -1073741820;
  }
  return result;
}
