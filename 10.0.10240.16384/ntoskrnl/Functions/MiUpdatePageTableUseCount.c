// MiUpdatePageTableUseCount 
 
int __fastcall MiUpdatePageTableUseCount(unsigned int a1, int a2)
{
  if ( a1 > MmHighestUserAddress )
    return sub_521364();
  MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER(2 * ((a1 >> 22) - 534769440), a2, a1);
  return 1;
}
