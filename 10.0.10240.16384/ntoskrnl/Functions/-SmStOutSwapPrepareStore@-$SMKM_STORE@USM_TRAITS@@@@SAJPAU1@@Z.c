// -SmStOutSwapPrepareStore@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStOutSwapPrepareStore(int a1)
{
  unsigned int *v2; // r5
  unsigned int v3; // r2
  int result; // r0
  _DWORD *v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r2
  unsigned int v8; // r2

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 3860);
  do
    v3 = __ldrex(v2);
  while ( !v3 && __strex(0xFFFFFFFF, v2) );
  __dmb(0xBu);
  if ( v3 )
    return -1073740682;
  v5 = (_DWORD *)ExAllocatePoolWithTag(512, 4 * (((unsigned int)(*(_DWORD *)(a1 + 3656) + 31) >> 5) + 3));
  v6 = (unsigned int)v5;
  if ( v5 )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[1] = *(_DWORD *)(a1 + 3656);
    v5[2] = v5 + 3;
    RtlSetAllBits(v5 + 1);
    __dmb(0xBu);
    do
      v8 = __ldrex(v2);
    while ( v8 == -1 && __strex(v6, v2) );
    __dmb(0xBu);
    result = 0;
  }
  else
  {
    result = -1073741670;
    __dmb(0xBu);
    do
      v7 = __ldrex(v2);
    while ( __strex(0, v2) );
    __dmb(0xBu);
  }
  return result;
}
