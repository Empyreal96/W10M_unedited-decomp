// PopPepCompleteComponentIdleStateChangeActivity 
 
int __fastcall PopPepCompleteComponentIdleStateChangeActivity(int result, int a2)
{
  int v3; // r6
  int v4; // r4

  v3 = result;
  if ( a2 )
  {
    *(_DWORD *)(*(_DWORD *)(a2 + 52) + 12) = 0;
    *(_BYTE *)(*(_DWORD *)(a2 + 52) + 16) = 0;
    if ( *(_BYTE *)(a2 + 152) )
    {
      result = sub_54B254();
    }
    else
    {
      if ( !*(_DWORD *)(a2 + 144) )
        KeSetEvent(a2 + 32, 0, 0);
      PopPepUpdateIdleState(v3, a2, 0);
      PopPepTryPowerDownComponent(v3, (_DWORD *)a2);
      v4 = *(_DWORD *)(a2 + 144);
      PopPepUpdateIdleStateRefCount(
        *(_DWORD *)(*(_DWORD *)(a2 + 160) + 24 * *(_DWORD *)(a2 + 148) + 16),
        *(_DWORD *)(*(_DWORD *)(a2 + 160) + 24 * v4 + 16),
        0);
      result = PopFxUpdateComponentAccountingEnhanced(*(_DWORD *)(v3 + 24), *(_DWORD *)(a2 + 8), v4, 1);
    }
  }
  return result;
}
