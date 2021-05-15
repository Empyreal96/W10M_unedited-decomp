// RtlpHeapRemoveListEntry 
 
int __fastcall RtlpHeapRemoveListEntry(int a1, _DWORD *a2, int a3, _DWORD *a4, unsigned int a5)
{
  unsigned int v6; // r7
  int v7; // r5
  int v8; // r1
  unsigned int v9; // r2
  int result; // r0

  v6 = a5 - a2[5];
  if ( a2[2] )
    v7 = 2 * v6;
  else
    v7 = a5 - a2[5];
  v8 = a2[8];
  v9 = a2[1];
  result = *(_DWORD *)(v8 + 4 * v7);
  --a2[3];
  if ( a5 == v9 - 1 )
    --a2[4];
  if ( (_DWORD *)result == a4 )
  {
    if ( !*a2 )
      --v9;
    if ( a5 >= v9 )
    {
      if ( *a4 == a2[6] )
      {
        *(_DWORD *)(v8 + 4 * v7) = 0;
        result = v6 >> 5;
        *(_DWORD *)(a2[7] + 4 * (v6 >> 5)) &= ~(1 << (v6 & 0x1F));
      }
      else
      {
        *(_DWORD *)(v8 + 4 * v7) = *a4;
      }
    }
    else
    {
      result = sub_50B9A8();
    }
  }
  return result;
}
