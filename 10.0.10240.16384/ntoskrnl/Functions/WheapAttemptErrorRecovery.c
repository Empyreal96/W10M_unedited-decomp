// WheapAttemptErrorRecovery 
 
int __fastcall WheapAttemptErrorRecovery(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r0

  v5 = WheapAttemptArchitecturalErrorRecovery(a1, a2, a3, a4);
  if ( v5 >= 0 && !*(_DWORD *)(a1 + 12) )
    *(_DWORD *)(a1 + 12) = 2;
  v6 = PshedAttemptErrorRecovery(a1);
  if ( !*(_DWORD *)(a1 + 12) )
  {
    if ( v6 >= 0 )
    {
      *(_DWORD *)(a1 + 12) = 2;
LABEL_9:
      *(_DWORD *)(a1 + 104) |= 1u;
      goto LABEL_10;
    }
    *(_DWORD *)(a1 + 12) = 1;
  }
  if ( *(_DWORD *)(a1 + 12) == 2 )
    goto LABEL_9;
LABEL_10:
  if ( v5 < 0 && v6 >= 0 )
    v5 = v6;
  return v5;
}
