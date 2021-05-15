// CcCalculateVacbLevelLockCount 
 
int __fastcall CcCalculateVacbLevelLockCount(int a1, _DWORD *a2)
{
  int v2; // r4
  int v3; // r2
  _DWORD *v4; // r7
  _DWORD *v5; // r5
  int v7; // r3
  int result; // r0
  unsigned int v9; // r1
  int v10; // r5

  v2 = 0;
  v3 = 128;
  v4 = a2;
  v5 = a2;
  do
  {
    if ( *v5++ )
      ++v2;
    --v3;
  }
  while ( v3 );
  v7 = *(_DWORD *)(a1 + 96);
  result = 128;
  if ( (v7 & 0x200) != 0 )
  {
    v9 = 0;
    v10 = v5[1] - 16;
    do
    {
      if ( *(_WORD *)v10 == 765 )
        ++v2;
      else
        ++v9;
      v10 = *(_DWORD *)(v10 + 20) - 16;
    }
    while ( v9 <= 0x3F );
  }
  if ( (v7 & 0x200) == 0 )
    result = 0;
  v4[result + 128] = v2;
  return result * 4;
}
