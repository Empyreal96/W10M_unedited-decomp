// BgpFwMarkHiberPhase 
 
int BgpFwMarkHiberPhase()
{
  int i; // r5

  for ( i = dword_61909C; (int *)i != &dword_61909C; i = *(_DWORD *)i )
    PoSetHiberRange(0, 0x10000, (const void *)(i - 12), *(const void **)(i + 12), 1262634818);
  return 0;
}
