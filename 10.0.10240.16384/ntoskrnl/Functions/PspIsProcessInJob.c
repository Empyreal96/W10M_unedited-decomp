// PspIsProcessInJob 
 
int __fastcall PspIsProcessInJob(int a1, int a2)
{
  int v2; // r3
  int v3; // r2

  v2 = *(_DWORD *)(a1 + 288);
  v3 = 291;
  __dmb(0xBu);
  while ( v2 )
  {
    if ( v2 == a2 )
      v3 = 292;
    v2 = *(_DWORD *)(v2 + 572);
  }
  return v3;
}
