// ExpDeleteTimer 
 
int __fastcall ExpDeleteTimer(int a1)
{
  int v3; // r0

  if ( *(_DWORD *)(a1 + 152) )
    return sub_53F908();
  v3 = *(_DWORD *)(a1 + 160);
  if ( v3 )
    PsRemoveVirtualizedTimer(v3, a1 + 164);
  return KeCancelTimer(a1);
}
