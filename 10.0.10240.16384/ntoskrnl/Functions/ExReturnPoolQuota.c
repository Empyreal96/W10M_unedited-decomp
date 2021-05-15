// ExReturnPoolQuota 
 
int __fastcall ExReturnPoolQuota(int a1)
{
  int result; // r0
  int v2; // r4
  unsigned int v3; // r1
  int v4; // r1
  int v5; // r7
  _BYTE *v6; // r5
  int v7; // r2
  int v8; // r1
  int v9; // r0

  if ( ExpSpecialAllocations )
    return sub_523AC8();
  v2 = a1 - 8;
  v3 = *(unsigned __int16 *)(a1 - 6);
  result = v3 >> 9;
  if ( ((v3 >> 9) & 8) != 0 && (v3 & 0x1000) != 0 )
  {
    v4 = v3 & 0x1FF;
    v5 = v2 + 8 * v4;
    v6 = (_BYTE *)(ExpPoolQuotaCookie ^ v2 ^ *(_DWORD *)(v5 - 4));
    if ( v6 && ((unsigned int)v6 < MmSystemRangeStart || (*v6 & 0x7F) != 3) )
      KeBugCheckEx(194, 13, v2 + 8);
    if ( v6 )
    {
      if ( (result & 4) != 0 )
        v4 = *(_WORD *)(v2 - 8 * (*(_WORD *)v2 & 0x1FF) + 2) & 0x1FF;
      v7 = 8 * v4;
      v8 = result & 1;
      v9 = ExpPoolQuotaCookie ^ v2 ^ *(_DWORD *)(v5 - 4);
      *(_DWORD *)(v5 - 4) = ExpPoolQuotaCookie ^ v2;
      PsReturnPoolQuota(v9, v8, v7);
      result = ObDereferenceObjectDeferDeleteWithTag(v6, *(_DWORD *)(v2 + 4));
    }
  }
  return result;
}
