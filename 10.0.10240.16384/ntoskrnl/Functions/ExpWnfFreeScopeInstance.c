// ExpWnfFreeScopeInstance 
 
unsigned int __fastcall ExpWnfFreeScopeInstance(_DWORD *a1, int a2)
{
  unsigned int *v3; // r0
  unsigned int v4; // r1
  _DWORD *v5; // r0
  _DWORD *v6; // r2
  _DWORD *v7; // r2
  unsigned int v8; // r5

  if ( a2 )
  {
    v3 = a1 + 1;
    do
      v4 = __ldrex(v3);
    while ( !v4 && __strex(1u, v3) );
    __dmb(0xBu);
    if ( v4 )
      return sub_7BFC84(v3, v4, 1);
    v5 = (_DWORD *)a1[8];
    if ( v5 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v6 = (_DWORD *)*v5;
            if ( !*v5 )
              break;
            *v5 = 0;
            v5 = v6;
          }
          v7 = (_DWORD *)v5[1];
          if ( !v7 )
            break;
          v5[1] = 0;
          v5 = v7;
        }
        v8 = v5[2] & 0xFFFFFFFC;
        ExpWnfDeleteNameInstanceCallback();
        if ( !v8 )
          break;
        v5 = (_DWORD *)v8;
      }
    }
    a1[8] = 0;
  }
  if ( a1[9] )
    ZwClose();
  if ( a1[10] )
    ZwClose();
  return ExFreePoolWithTag((unsigned int)a1);
}
