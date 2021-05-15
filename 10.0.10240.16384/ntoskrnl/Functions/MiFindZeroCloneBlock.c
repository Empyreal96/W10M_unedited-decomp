// MiFindZeroCloneBlock 
 
unsigned int __fastcall MiFindZeroCloneBlock(int a1, int a2)
{
  unsigned int v2; // r0
  unsigned int i; // r2
  __int64 v4; // kr00_8

  v4 = *(_QWORD *)(a1 + 12);
  v2 = *(_DWORD *)(a1 + 16);
  for ( i = v4; i <= v2; i += 16 )
  {
    if ( *(_DWORD *)(i + 8) >> 27 == a2 && *(_DWORD *)(i + 12) != -1 )
      return i;
  }
  return 0;
}
