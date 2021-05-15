// ObReferenceProcessHandleTable 
 
int __fastcall ObReferenceProcessHandleTable(int a1)
{
  unsigned int *v1; // r5
  int v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r1
  int result; // r0

  v1 = (unsigned int *)(a1 + 172);
  __pld((void *)(a1 + 172));
  v3 = 0;
  v4 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
  do
    v5 = __ldrex(v1);
  while ( v5 == v4 && __strex(v4 + 2, v1) );
  __dmb(0xBu);
  if ( (v5 == v4 || ExfAcquireRundownProtection((_DWORD *)(a1 + 172))) && (v3 = *(_DWORD *)(a1 + 336)) == 0 )
    result = sub_7F7594();
  else
    result = v3;
  return result;
}
