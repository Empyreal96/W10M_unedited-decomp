// KeFirstGroupAffinityEx 
 
int __fastcall KeFirstGroupAffinityEx(_DWORD *a1, int a2)
{
  int v2; // r3

  v2 = *(_DWORD *)(a2 + 8);
  if ( !v2 )
    return -1073741275;
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  *a1 = v2;
  return 0;
}
