// PsSetProcessHandleTracingInformation 
 
int __fastcall PsSetProcessHandleTracingInformation(int a1, int a2)
{
  int v4; // r0
  int v5; // r5
  unsigned int *v6; // r0
  unsigned int v7; // r4
  unsigned int v8; // r1

  v4 = ObReferenceProcessHandleTable(a1);
  if ( !v4 )
    return -1073741558;
  if ( a2 )
  {
    v5 = ExEnableHandleTracing();
  }
  else
  {
    ExDisableHandleTracing(v4);
    v5 = 0;
  }
  v6 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v7 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v8 = __ldrex(v6);
  while ( v8 == v7 && __strex(v7 - 2, v6) );
  if ( v8 != v7 )
    ExfReleaseRundownProtection((unsigned __int8 *)v6);
  return v5;
}
