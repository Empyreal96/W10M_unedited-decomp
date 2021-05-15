// ViTargetWMIDeregisterCallback 
 
int __fastcall ViTargetWMIDeregisterCallback(int a1, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = *(_DWORD *)(a1 + 24);
  if ( !v2 || *(_DWORD *)(v2 + 4) != a2 )
    return 1;
  *(_DWORD *)(v2 + 4) = 0;
  v3 = dword_90807C + 1;
  __dmb(0xBu);
  dword_90807C = v3;
  return 0;
}
