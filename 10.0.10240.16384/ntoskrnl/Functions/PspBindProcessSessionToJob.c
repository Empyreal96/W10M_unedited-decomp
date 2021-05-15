// PspBindProcessSessionToJob 
 
int __fastcall PspBindProcessSessionToJob(int a1, int a2)
{
  unsigned int *v2; // r6
  int v3; // r5
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0

  v2 = (unsigned int *)(a1 + 232);
  v3 = *(_DWORD *)(a1 + 232);
  __dmb(0xBu);
  v4 = MmGetSessionId(a2);
  if ( v3 == v4 )
    goto LABEL_7;
  if ( v3 != -1 )
    JUMPOUT(0x7C228E);
  __dmb(0xBu);
  do
    v5 = __ldrex(v2);
  while ( v5 == -1 && __strex(v4, v2) );
  __dmb(0xBu);
  if ( v5 == -1 )
LABEL_7:
    result = 0;
  else
    result = sub_7C2288();
  return result;
}
