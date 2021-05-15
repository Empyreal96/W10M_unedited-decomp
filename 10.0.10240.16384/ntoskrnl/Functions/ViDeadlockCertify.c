// ViDeadlockCertify 
 
int __fastcall ViDeadlockCertify(unsigned int a1, int a2)
{
  unsigned int v3; // r5
  int v4; // r6
  int *v5; // r3
  int v6; // r1
  unsigned int v7; // r0
  int v8; // r4
  int v9; // r6
  int v10; // r1
  _DWORD *i; // r2
  unsigned int v12; // r4
  int v13; // r6
  _DWORD *v14; // r0

  if ( VfWin32kDllBase
    && VfWin32kDllBase <= a1
    && VfWin32kSizeOfImage + VfWin32kDllBase > a1
    && *(_BYTE *)(*(_DWORD *)(a2 + 32) + 28) )
  {
    return 0;
  }
  v3 = *(_DWORD *)(ViDeadlockGlobals + 16472);
  if ( v3 >= 3 )
  {
    if ( (v4 = **(_DWORD **)(*(_DWORD *)(ViDeadlockGlobals + 16476) + 28),
          v5 = *(int **)(*(_DWORD *)(ViDeadlockGlobals + 16480) + 28),
          v4 == 5)
      && (v6 = *v5, *v5 == 6)
      || (v6 = *v5, *v5 == 5) && v4 == 6 )
    {
      if ( VfTcpIpDllBase && VfTcpIpDllBase <= a1 && VfTcpIpSizeOfImage + VfTcpIpDllBase > a1
        || VfTdxDllBase && VfTdxDllBase <= a1 && VfTdxSizeOfImage + VfTdxDllBase > a1
        || VfMrxsmbDllBase && VfMrxsmbDllBase <= a1 && VfMrxsmbSizeOfImage + VfMrxsmbDllBase > a1 )
      {
        return 0;
      }
    }
    if ( v4 == 1
      && v6 == 1
      && (VfTmDllBase && VfTmDllBase <= a1 && VfTmSizeOfImage + VfTmDllBase > a1
       || VfKsDllBase && VfKsDllBase <= a1 && VfKsSizeOfImage + VfKsDllBase > a1) )
    {
      return 0;
    }
  }
  v7 = 1;
  if ( v3 > 1 )
  {
    v8 = ViDeadlockGlobals + 4;
    while ( 1 )
    {
      v9 = *(_DWORD *)(v8 + 16472);
      if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 16476) + 28) + 8) == *(_DWORD *)(*(_DWORD *)(v9 + 28) + 8)
        && (*(_DWORD *)(v9 + 36) & 2) != 0 )
      {
        return 0;
      }
      ++v7;
      v8 += 4;
      if ( v7 >= v3 )
      {
        v10 = ViDeadlockGlobals + 4 * v3;
        while ( 2 )
        {
          --v3;
          v10 -= 4;
          for ( i = **(_DWORD ***)(v10 + 16476); i; i = (_DWORD *)*i )
          {
            v12 = v3 - 1;
            if ( v3 != 1 )
            {
              v13 = v10 - 4;
              while ( 1 )
              {
                v13 -= 4;
                --v12;
                v14 = **(_DWORD ***)(v13 + 16476);
                if ( v14 )
                  break;
LABEL_40:
                if ( !v12 )
                  goto LABEL_41;
              }
              while ( *(_DWORD *)(v14[7] + 8) != *(_DWORD *)(i[7] + 8) )
              {
                v14 = (_DWORD *)*v14;
                if ( !v14 )
                  goto LABEL_40;
              }
              ++*(_DWORD *)(ViDeadlockGlobals + 16444);
              return 0;
            }
LABEL_41:
            ;
          }
          if ( v3 > 1 )
            continue;
          return 1;
        }
      }
    }
  }
  return 1;
}
