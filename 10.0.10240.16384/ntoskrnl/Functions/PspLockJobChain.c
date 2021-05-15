// PspLockJobChain 
 
int __fastcall PspLockJobChain(int a1, int a2, int a3)
{
  unsigned int v4; // r3

  if ( a2 )
    --*(_WORD *)(a2 + 310);
  v4 = *(_DWORD *)(a1 + 588);
  if ( !v4 )
    return ExAcquireResourceExclusiveLite(a1 + 32, 1, a3, v4);
  if ( v4 <= 1 )
  {
    ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 572) + 32, 1, a3, *(_DWORD *)(a1 + 572));
    return ExAcquireResourceExclusiveLite(a1 + 32, 1, a3, v4);
  }
  return sub_7C2D84();
}
