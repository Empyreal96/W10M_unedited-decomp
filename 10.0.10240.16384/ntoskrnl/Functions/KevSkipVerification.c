// KevSkipVerification 
 
int __fastcall KevSkipVerification(int a1)
{
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r4
  int result; // r0

  if ( (unsigned int)KeGetCurrentIrql(a1) < 2 )
    goto LABEL_8;
  v1 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( !*(_BYTE *)(v1 + 3162) || (*(_WORD *)(v1 + 3164) & 8) == 0 )
    goto LABEL_8;
  while ( 1 )
  {
    v2 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v3 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v2 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  if ( *(_DWORD *)(v1 + 3168) + 100 < ((v2 << 14) | (v3 >> 18)) )
    result = 1;
  else
LABEL_8:
    result = 0;
  return result;
}
