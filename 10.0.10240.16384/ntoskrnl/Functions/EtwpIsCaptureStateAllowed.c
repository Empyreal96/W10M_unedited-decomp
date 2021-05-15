// EtwpIsCaptureStateAllowed 
 
int __fastcall EtwpIsCaptureStateAllowed(int a1, int a2, int a3)
{
  int result; // r0
  _WORD *v7; // r1
  unsigned int v8; // r5
  int v9; // r1
  int i; // r4
  int *v11; // r2
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r2
  int *v15; // r1
  int v16; // t1

  result = 1;
  if ( !*(_DWORD *)a3 || (result = EtwpApplyExeFilter(a1, *(_WORD **)a3)) != 0 )
  {
    v7 = *(_WORD **)(a3 + 4);
    if ( v7 || *(_DWORD *)(a3 + 8) )
      result = EtwpApplyPackageIdFilter(a1, v7, *(_WORD **)(a3 + 8));
    if ( result )
    {
      v8 = *(_DWORD *)(a2 + 116);
      v9 = 0;
      if ( v8 )
      {
        for ( i = a2 + 120; *(_DWORD *)(i + 12) != -2147483644; i += 16 )
        {
          if ( ++v9 >= v8 )
            return result;
        }
        v11 = (int *)(a2 + 120 + 16 * v9);
        v12 = *v11;
        result = 0;
        v13 = (unsigned int)v11[2] >> 2;
        v14 = 0;
        if ( v13 )
        {
          v15 = (int *)(v12 + a2);
          while ( 1 )
          {
            v16 = *v15++;
            if ( v16 == *(_DWORD *)(*(_DWORD *)(a1 + 40) + 176) )
              break;
            if ( ++v14 >= v13 )
              return result;
          }
          result = 1;
        }
      }
    }
  }
  return result;
}
