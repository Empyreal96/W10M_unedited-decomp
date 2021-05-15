// PfSnEndProcessTrace 
 
int __fastcall PfSnEndProcessTrace(int a1, unsigned int a2, int a3)
{
  int v5; // r0
  int v6; // r4
  unsigned int *v8; // r2
  unsigned int v9; // r1
  int v10; // r5
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1

  v5 = PfSnReferenceProcessTrace(a1);
  v6 = v5;
  if ( !v5 )
    return -1073741275;
  if ( a3 )
    return sub_7E9ACC();
  __dmb(0xBu);
  v8 = (unsigned int *)(v5 + 288);
  do
    v9 = __ldrex(v8);
  while ( !v9 && __strex(a2, v8) );
  __dmb(0xBu);
  if ( v9 )
  {
    v10 = -1073741431;
  }
  else
  {
    ExQueueWorkItem((_DWORD *)(v5 + 272), 1);
    v10 = 0;
  }
  v11 = (unsigned int *)(v6 + 268);
  __pld((void *)(v6 + 268));
  v12 = *(_DWORD *)(v6 + 268) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v13 = __ldrex(v11);
  while ( v13 == v12 && __strex(v12 - 2, v11) );
  if ( v13 != v12 )
    ExfReleaseRundownProtection((unsigned __int8 *)v11);
  return v10;
}
