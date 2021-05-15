// CmpInitializePreloadedHives 
 
int __fastcall CmpInitializePreloadedHives(int a1, int a2)
{
  _BYTE *v2; // r4
  int v3; // r5
  int v5; // r3
  _DWORD *v6; // r7

  v2 = 0;
  v3 = 0;
  if ( a2 )
  {
    CmpPreloadedHivesList = (int)&CmpPreloadedHivesList;
    dword_632524 = (int)&CmpPreloadedHivesList;
    v5 = *(_DWORD *)(a1 + 132);
    v6 = *(_DWORD **)(v5 + 124);
    if ( v6 != (_DWORD *)(v5 + 124) )
    {
      while ( 1 )
      {
        if ( !v2 )
        {
          v2 = CmpHiveRootSecurityDescriptor();
          if ( !v2 )
            break;
        }
        CmpInitializePreloadedHive(v6, v2);
        v6 = (_DWORD *)*v6;
        if ( v6 == (_DWORD *)(*(_DWORD *)(a1 + 132) + 124) )
          goto LABEL_10;
      }
      v3 = -1073741670;
LABEL_10:
      if ( v2 )
        ExFreePoolWithTag((unsigned int)v2);
    }
    return v3;
  }
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 132) + 124) == *(_DWORD *)(a1 + 132) + 124 )
    return v3;
  return sub_966EF0();
}
