// KsepResolveShimHooks 
 
int __fastcall KsepResolveShimHooks(int a1, int *a2, int a3, int a4)
{
  int *v5; // r5
  int *v6; // r8
  int v7; // r3
  int v8; // r4
  int result; // r0
  _DWORD *v10; // r6
  int v11; // r9
  unsigned int v12; // r0
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v5 = a2;
  if ( a1 && a2 )
  {
    v6 = a2;
    while ( 1 )
    {
      v7 = *v5;
      if ( *v5 == 4 )
        return 0;
      if ( v7 )
      {
        switch ( v7 )
        {
          case 1:
            v8 = *(_DWORD *)(a1 + 296);
            break;
          case 2:
            result = KsepGetModuleInfoByName(v5[1], a1, v13);
            if ( result < 0 )
              return result;
            v8 = v13[0];
            goto LABEL_15;
          case 3:
            v8 = 0;
            break;
          default:
            return -1073741811;
        }
      }
      else
      {
        v8 = *(_DWORD *)(a1 + 12);
      }
      v13[0] = v8;
LABEL_15:
      v10 = (_DWORD *)v5[2];
      if ( v10 )
      {
        v11 = 0;
        while ( *v10 != 2 )
        {
          if ( !*v10 )
          {
            v12 = RtlFindExportedRoutineByName(v8, v10[1], a3, 0);
            if ( !v12 )
              return -1073741823;
            v10[3] = v12;
          }
          v11 += 16;
          v10 = (_DWORD *)(v5[2] + v11);
          if ( !v10 )
            break;
        }
      }
      v6 += 3;
      v5 = v6;
      if ( !v6 )
        return 0;
    }
  }
  return -1073741811;
}
