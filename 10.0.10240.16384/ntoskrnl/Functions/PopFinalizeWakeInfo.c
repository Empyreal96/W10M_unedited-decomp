// PopFinalizeWakeInfo 
 
unsigned int __fastcall PopFinalizeWakeInfo(int a1)
{
  unsigned int result; // r0
  _DWORD *v3; // r4
  _DWORD *i; // r5
  _DWORD *v5; // t1
  unsigned int v6; // r0

  result = KeSetEvent((int)&PopWakeSourceAvailable, 0, 0);
  v5 = *(_DWORD **)(a1 + 12);
  v3 = (_DWORD *)(a1 + 12);
  for ( i = v5; i != v3; i = (_DWORD *)*i )
  {
    if ( !i[2] )
    {
      v6 = i[6];
      if ( v6 )
      {
        ExFreePoolWithTag(v6);
        i[5] = 0;
        i[6] = 0;
      }
      result = i[8];
      if ( result )
      {
        result = ExFreePoolWithTag(result);
        i[7] = 0;
        i[8] = 0;
      }
    }
  }
  return result;
}
