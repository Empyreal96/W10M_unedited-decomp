// AuthzBasepFindSystemSecurityAttribute 
 
_DWORD *__fastcall AuthzBasepFindSystemSecurityAttribute(int a1)
{
  unsigned int v2; // r3
  unsigned int v3; // r4
  unsigned int v4; // r2
  _DWORD *v5; // r4
  unsigned int v7[4]; // [sp+0h] [bp-10h] BYREF

  v7[0] = 0;
  __dmb(0xBu);
  v2 = WindowsSystemAttributes;
  do
    v3 = __ldrex(v7);
  while ( __strex(v2, v7) );
  __dmb(0xBu);
  v4 = v7[0];
  if ( !v7[0] )
    return 0;
  v5 = *(_DWORD **)(v7[0] + 4);
  while ( 1 )
  {
    if ( v5 == (_DWORD *)(v4 + 4) )
      JUMPOUT(0x7C5130);
    if ( AuthzBasepEqualUnicodeString((int)(v5 + 4), a1) )
      break;
    v5 = (_DWORD *)*v5;
    v4 = v7[0];
  }
  return v5;
}
