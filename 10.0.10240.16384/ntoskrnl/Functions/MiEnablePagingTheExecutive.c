// MiEnablePagingTheExecutive 
 
int __fastcall MiEnablePagingTheExecutive(int a1, int a2, unsigned int a3)
{
  int *i; // r4
  int v4; // r3
  int result; // r0

  for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
  {
    v4 = i[13] | 0x400000;
    i[13] = v4;
    MiEnablePagingOfDriver((int)i, a2, a3, v4);
    result = MiLockPagableSections(i, 1);
  }
  return result;
}
