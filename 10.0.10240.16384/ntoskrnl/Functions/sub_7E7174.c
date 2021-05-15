// sub_7E7174 
 
void sub_7E7174()
{
  _DWORD *v0; // r6
  int v1; // r7
  unsigned __int8 *v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r3

  __pld(v0);
  v2 = (unsigned __int8 *)(*v0 & ~v1);
  __dmb(0xBu);
  do
    v3 = __ldrex(v0);
  while ( (unsigned __int8 *)v3 == v2 && __strex((unsigned int)(v2 - 2), v0) );
  if ( (unsigned __int8 *)v3 != v2 )
    v2 = ExfReleaseRundownProtection((unsigned __int8 *)v0);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (__int16)(*(_WORD *)(v4 + 0x134) + 1);
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery((int)v2);
  JUMPOUT(0x6F47AA);
}
