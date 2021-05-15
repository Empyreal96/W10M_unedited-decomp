// PopPepStartComponentIdleStateChangeActivity 
 
int __fastcall PopPepStartComponentIdleStateChangeActivity(int a1, _DWORD *a2, _DWORD *a3)
{
  int v6; // r8
  int v7; // r6
  int v8; // r4

  v6 = 0;
  if ( !a2 )
    return v6;
  a2[37] = a2[36];
  a2[36] = *(_DWORD *)(a2[13] + 8);
  v7 = a2[13];
  if ( !*(_DWORD *)(v7 + 12) )
  {
    if ( *(_BYTE *)(a1 + 76) )
    {
      *(_DWORD *)(v7 + 12) = 1;
      goto LABEL_5;
    }
    *(_DWORD *)(v7 + 12) = 2;
  }
  if ( *(_DWORD *)(v7 + 12) == 1 )
  {
LABEL_5:
    v8 = a2[36];
    PopPepUpdateIdleStateRefCount(*(_DWORD *)(a2[40] + 24 * a2[37] + 16), *(_DWORD *)(a2[40] + 24 * v8 + 16), 1);
    PopFxUpdateComponentAccountingEnhanced(*(_DWORD *)(a1 + 24), a2[2], v8, 0);
    if ( PopPluginNotifyIdleState(*(_DWORD *)(a1 + 24), a2[2], a2[36], 0) == 1 )
      *(_DWORD *)(v7 + 12) = 2;
  }
  if ( *(_DWORD *)(v7 + 12) == 2 )
  {
    *a3 = 1;
    v6 = 1;
    a3[1] = *(_DWORD *)(a1 + 24);
    a3[2] = a2[2];
    a3[3] = a2[36];
    *(_DWORD *)(v7 + 12) = 3;
  }
  return v6;
}
