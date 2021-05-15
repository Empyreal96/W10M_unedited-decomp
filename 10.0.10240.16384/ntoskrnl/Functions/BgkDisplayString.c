// BgkDisplayString 
 
int __fastcall BgkDisplayString(_BYTE *a1)
{
  int v2; // r4
  char *v3; // r6
  _WORD *v4; // r0
  _WORD *v5; // r5
  unsigned int v6; // r2
  __int16 v7; // r3

  if ( !a1 )
    return 0;
  if ( !*a1 )
    return 1;
  v3 = strlen((unsigned int)a1);
  v4 = (_WORD *)ExAllocatePoolWithTag(512, 2 * (_DWORD)(v3 + 1));
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = 0;
  if ( v3 )
  {
    do
    {
      v7 = (char)a1[v6++];
      *v4++ = v7;
    }
    while ( v6 < (unsigned int)v3 );
  }
  v5[v6] = 0;
  v2 = BgkDisplayStringEx(v5);
  ExFreePoolWithTag(v5);
  return v2;
}
