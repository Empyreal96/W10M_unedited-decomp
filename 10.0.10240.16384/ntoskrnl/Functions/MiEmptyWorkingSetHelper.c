// MiEmptyWorkingSetHelper 
 
int __fastcall MiEmptyWorkingSetHelper(int a1, _DWORD *a2, unsigned int a3, unsigned int *a4)
{
  int v7; // r3
  int v8; // r3
  int v10; // r3

  v7 = MmPfnDatabase + 24 * (*a2 >> 12);
  if ( *(unsigned __int16 *)(v7 + 16) > 1u && (*(_BYTE *)(a1 + 112) & 7) != 0 )
    return 0;
  v8 = *(_DWORD *)(v7 + 4);
  if ( v8 >= 0 )
    MiDemoteCombinedPte((unsigned int)a2, v8 | 0x80000000);
  if ( dword_634484 )
    return sub_53DF24();
  a4[*a4 + 1] = a3;
  v10 = *a4 + 1;
  *a4 = v10;
  if ( v10 == 32 )
  {
    MiFreeWsleList(a1, a4, 0);
    *a4 = 0;
  }
  return 1;
}
