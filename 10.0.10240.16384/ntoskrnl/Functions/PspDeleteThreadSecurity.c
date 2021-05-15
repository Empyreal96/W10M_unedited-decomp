// PspDeleteThreadSecurity 
 
int __fastcall PspDeleteThreadSecurity(int result)
{
  unsigned int *v1; // r5
  int v2; // r4
  unsigned int v3; // r1

  v1 = (unsigned int *)(result + 960);
  v2 = result;
  if ( (*(_DWORD *)(result + 960) & 8) == 0 )
    goto LABEL_2;
  ObfDereferenceObject(*(_DWORD *)(result + 904) & 0xFFFFFFF8);
  result = *(_DWORD *)(v2 + 1052);
  if ( !result )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(v1);
    while ( __strex(v3 & 0xFFFFFFF7, v1) );
    __dmb(0xBu);
LABEL_2:
    *(_DWORD *)(v2 + 904) = 0;
    return result;
  }
  return sub_7F7164();
}
