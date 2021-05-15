// RtlCreateUnicodeString 
 
int __fastcall RtlCreateUnicodeString(int a1, unsigned __int16 *a2)
{
  int v3; // r5
  unsigned int v4; // r0
  unsigned int v5; // r4
  int v6; // r0
  unsigned __int16 *_24; // [sp+24h] [bp+Ch]

  _24 = a2;
  v3 = a1;
  v4 = wcslen(a2);
  v5 = 2 * (v4 + 1);
  if ( v5 > 0xFFFE )
    return 0;
  if ( !v5 )
    return 0;
  v6 = ExpAllocateStringRoutine(2 * (v4 + 1));
  if ( (*(_DWORD *)(v3 + 4) = v6) == 0 )
    return 0;
  *(_WORD *)(v3 + 2) = v5;
  memmove(v6, (int)a2, v5);
  *(_WORD *)v3 = v5 - 2;
  return 1;
}
