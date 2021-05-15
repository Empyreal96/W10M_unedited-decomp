// CcRemapBcb 
 
int __fastcall CcRemapBcb(int a1)
{
  unsigned int v1; // r0
  int v2; // r2
  unsigned int *v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1

  v1 = a1 & 0xFFFFFFFE;
  v2 = *(__int16 *)v1;
  if ( v2 == 762 )
  {
    v1 = *(_DWORD *)(*(_DWORD *)(v1 + 16) + 48);
  }
  else if ( v2 == 765 )
  {
    v1 = *(_DWORD *)(v1 + 48);
  }
  if ( !*(_WORD *)(v1 + 8) )
    KeBugCheckEx(52, 7599, -1073740768);
  if ( !*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) )
    KeBugCheckEx(52, 7600, -1073740768);
  __dmb(0xBu);
  v3 = (unsigned int *)(v1 + 8);
  do
  {
    v4 = __ldrex(v3);
    v5 = v4 + 1;
  }
  while ( __strex(v5, v3) );
  __dmb(0xBu);
  if ( !(_WORD)v5 )
    sub_51E8C0();
  return v1 | 1;
}
