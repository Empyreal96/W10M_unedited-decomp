// KeCancelTimerInternal 
 
int __fastcall KeCancelTimerInternal(int a1, _DWORD *a2, _DWORD *a3, unsigned int *a4)
{
  int result; // r0
  int v9; // r2
  unsigned int v10; // r1

  result = KiCancelTimer(a1, 0);
  if ( result )
  {
    v9 = *(unsigned __int8 *)(a1 + 1);
    *a2 = *(_DWORD *)(a1 + 16);
    a2[1] = *(_DWORD *)(a1 + 20);
    *a3 = 2;
    if ( (v9 & 1) != 0 )
    {
      *a3 = 1;
    }
    else if ( (v9 & 2) != 0 )
    {
      *a3 = 3;
    }
    *a4 = ((v9 & 0xFFFFFFFC) << 16) / 0x2710;
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)a1);
  while ( __strex(v10 & 0xFFFFFF7F, (unsigned int *)a1) );
  return result;
}
