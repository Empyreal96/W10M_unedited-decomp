// PspReferenceMonitorServerSilo 
 
int __fastcall PspReferenceMonitorServerSilo(int a1)
{
  _DWORD *v1; // r0
  unsigned int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  int result; // r0

  v1 = (_DWORD *)(a1 + 28);
  __pld(v1);
  v2 = *v1 & 0xFFFFFFFE;
  v3 = v2 + 2;
  do
    v4 = __ldrex(v1);
  while ( v4 == v2 && __strex(v3, v1) );
  __dmb(0xBu);
  if ( v4 == v2 )
    result = 0;
  else
    result = sub_810C08(v1, v4, v3);
  return result;
}
