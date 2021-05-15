// MI_UNUSED_SUBSECTIONS_COUNT_REMOVE 
 
int __fastcall MI_UNUSED_SUBSECTIONS_COUNT_REMOVE(int result)
{
  unsigned int v1; // r2
  unsigned int v2; // r3

  v1 = 4 * (*(_DWORD *)(result + 28) + *(_DWORD *)(result + 36));
  if ( v1 <= 0xFF0 )
  {
    v2 = v1 + 15;
LABEL_3:
    dword_632E14 -= v2 & 0xFFFFFFF8;
    return result;
  }
  if ( (v1 & 0xFFF) <= 0xFE0 && v1 < 0x10000 )
  {
    v2 = v1 + 7;
    goto LABEL_3;
  }
  return sub_520804();
}
