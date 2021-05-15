// WdipSemDisableAllProviders 
 
int WdipSemDisableAllProviders()
{
  unsigned int v0; // r3
  unsigned int v1; // r8
  unsigned int v2; // r3
  unsigned int v3; // r9
  int result; // r0

  __dmb(0xBu);
  v0 = WdipDiagLoggerId;
  do
    v1 = __ldrex((unsigned int *)&WdipDiagLoggerId);
  while ( __strex(v0, (unsigned int *)&WdipDiagLoggerId) );
  __dmb(0xBu);
  v2 = WdipContextLoggerId;
  do
    v3 = __ldrex((unsigned int *)&WdipContextLoggerId);
  while ( __strex(v2, (unsigned int *)&WdipContextLoggerId) );
  __dmb(0xBu);
  if ( dword_61C760 )
    result = sub_7D0DE8();
  return result;
}
