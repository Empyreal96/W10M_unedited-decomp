// sub_7D2258 
 
void sub_7D2258()
{
  int v0; // r4
  _DWORD *v1; // r6
  unsigned __int8 *v2; // r0
  unsigned int v3; // r1
  unsigned int v4; // r1
  int v5; // r3

  __pld(v1);
  v2 = (unsigned __int8 *)(*v1 & ~v0);
  __dmb(0xBu);
  do
    v3 = __ldrex(v1);
  while ( (unsigned __int8 *)v3 == v2 && __strex((unsigned int)(v2 - 2), v1) );
  if ( (unsigned __int8 *)v3 != v2 )
    v2 = ExfReleaseRundownProtection((unsigned __int8 *)v1);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (__int16)(*(_WORD *)(v4 + 0x134) + 1);
  *(_WORD *)(v4 + 308) = v5;
  if ( !v5 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    KiCheckForKernelApcDelivery((int)v2);
  JUMPOUT(0x6D1306);
}
