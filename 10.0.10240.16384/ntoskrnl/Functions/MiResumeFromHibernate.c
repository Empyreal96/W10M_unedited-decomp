// MiResumeFromHibernate 
 
int __fastcall MiResumeFromHibernate(int a1)
{
  if ( a1 )
    dword_634348 = a1;
  byte_634378 = 1;
  return MiPurgeLargeZeroNodePages();
}
