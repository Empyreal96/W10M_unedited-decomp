// Win7RtlGetVersion 
 
int __fastcall Win7RtlGetVersion(int a1, int a2, int a3, int a4)
{
  int result; // r0

  result = RtlGetVersion((int *)a1, a2, a3, a4);
  if ( result >= 0 )
  {
    *(_DWORD *)(a1 + 4) = 6;
    *(_DWORD *)(a1 + 8) = 1;
    *(_DWORD *)(a1 + 12) = 7600;
    *(_WORD *)(a1 + 20) = 0;
    if ( *(_DWORD *)a1 == 284 || *(_DWORD *)a1 == 292 )
    {
      *(_WORD *)(a1 + 276) = 0;
      *(_WORD *)(a1 + 278) = 0;
    }
  }
  return result;
}
