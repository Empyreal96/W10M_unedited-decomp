// PopFxPlatformRegisterInterface 
 
int __fastcall PopFxPlatformRegisterInterface(_DWORD *a1, int (__fastcall **a2)(int *a1))
{
  int v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r0

  if ( a1[1] != 1 )
    return -1073741735;
  if ( !a1[2] || !a1[4] )
    return -1073741811;
  v3 = -1073741823;
  __dmb(0xBu);
  v4 = a1[4];
  do
    v5 = __ldrex((unsigned int *)&dword_61DB48);
  while ( !v5 && __strex(v4, (unsigned int *)&dword_61DB48) );
  __dmb(0xBu);
  if ( !v5 )
  {
    v3 = 0;
    PopFxPlatformInterface = (int (__fastcall *)(_DWORD))a1[2];
    dword_61DB44 = a1[3];
    a2[1] = 0;
    *a2 = PoFxPlatformRequestHandler;
    ObfReferenceObjectWithTag(a1[4]);
  }
  return v3;
}
