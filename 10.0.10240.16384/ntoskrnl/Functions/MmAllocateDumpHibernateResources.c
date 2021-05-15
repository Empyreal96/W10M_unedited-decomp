// MmAllocateDumpHibernateResources 
 
int __fastcall MmAllocateDumpHibernateResources(unsigned int a1)
{
  int v1; // r0
  int result; // r0

  v1 = MiReservePtes(&dword_634D58, ((a1 & 0xFFF) != 0) + (a1 >> 12));
  if ( v1 )
    result = v1 << 10;
  else
    result = 0;
  return result;
}
