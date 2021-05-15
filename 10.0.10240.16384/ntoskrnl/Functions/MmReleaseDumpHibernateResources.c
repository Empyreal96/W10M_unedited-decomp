// MmReleaseDumpHibernateResources 
 
int __fastcall MmReleaseDumpHibernateResources(unsigned int a1, unsigned int a2)
{
  return MiReleasePtes(&dword_634D58, ((a1 >> 10) & 0x3FFFFC) - 0x40000000, ((a2 & 0xFFF) != 0) + (a2 >> 12));
}
