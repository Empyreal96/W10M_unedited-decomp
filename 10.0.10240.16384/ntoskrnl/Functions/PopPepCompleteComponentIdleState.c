// PopPepCompleteComponentIdleState 
 
_DWORD *__fastcall PopPepCompleteComponentIdleState(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r0
  int v7; // r2
  int v8; // r7
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r4
  _DWORD v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v4 = a1 + 168 * a2 + 128;
  v6 = PopPepLockActivityLink();
  v7 = *(_DWORD *)(v4 + 52);
  v8 = v6;
  if ( *(_DWORD *)(v7 + 12) != 1 )
    return (_DWORD *)sub_5231D0();
  *(_DWORD *)(v7 + 12) = 2;
  v10 = *(_DWORD *)(v4 + 72) + *(_DWORD *)(a1 + 72);
  **(_DWORD **)(v4 + 52) |= 8u;
  __dmb(0xBu);
  v11 = (unsigned int *)(v4 + 72);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 + 1, v11) );
  __dmb(0xBu);
  PopPepRequestWork(v10, *(_DWORD *)(v4 + 72) + *(_DWORD *)(a1 + 72));
  PopPepReleaseActivityLink(a1, v4, v8, LOBYTE(v13[0]));
  return v13;
}
