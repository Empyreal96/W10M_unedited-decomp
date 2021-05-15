// KiInterruptExceptionFilter 
 
void __fastcall __noreturn KiInterruptExceptionFilter(int a1, int *a2)
{
  int v2; // r3

  if ( (*(_DWORD *)(*(_DWORD *)a1 + 4) & 0x66) != 0 )
    v2 = 60;
  else
    v2 = 61;
  *a2 = v2;
  KeBugCheck2(*a2, *(_DWORD *)a1, *(_DWORD *)(a1 + 4), 0, 0, 0);
}
