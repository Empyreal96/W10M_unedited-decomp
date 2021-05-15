// RtlpSparseBitmapCtxUpdateBits 
 
int __fastcall RtlpSparseBitmapCtxUpdateBits(int a1, unsigned int *a2, unsigned int a3, unsigned int a4, int a5, int a6, int a7, _DWORD *a8)
{
  int v12; // r0
  int v13; // r6
  int v14; // r0
  unsigned __int8 v16; // [sp+0h] [bp-20h]

  v16 = RtlpSparseBitmapCtxLockExclusive(a1, a2);
  if ( a8 )
  {
    if ( a7 )
      v12 = RtlNumberOfSetBitsInRange(a2 + 1, a3, a4);
    else
      v12 = RtlNumberOfClearBitsInRange((int)(a2 + 1), a3, a4);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  if ( a7 )
    RtlSetBits((_BYTE *)a2 + 4, a3, a4);
  else
    RtlClearBits((_BYTE *)a2 + 4, a3, a4);
  if ( a8 )
  {
    if ( v13 )
    {
      if ( a7 )
        v14 = RtlNumberOfSetBitsInRange(a2 + 1, a3, a4);
      else
        v14 = RtlNumberOfClearBitsInRange((int)(a2 + 1), a3, a4);
      a4 = v14;
    }
    *a8 = a4 - v13;
    a8[1] = 0;
  }
  return RtlpSparseBitmapCtxUnlockExclusive(a1, a2, v16);
}
