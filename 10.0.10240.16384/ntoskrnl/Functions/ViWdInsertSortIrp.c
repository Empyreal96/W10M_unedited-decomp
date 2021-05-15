// ViWdInsertSortIrp 
 
int __fastcall ViWdInsertSortIrp(int result)
{
  int *i; // r2
  int v2; // r3
  int v3; // r2
  int v4; // r3
  int v5; // r3

  for ( i = (int *)dword_908F14; i != &VfWdIrpListHead; i = (int *)i[1] )
  {
    if ( (unsigned int)i[3] <= *(_DWORD *)(result + 12) )
      break;
  }
  *(_DWORD *)(result + 4) = i;
  *(_DWORD *)result = *i;
  *(_DWORD *)(*i + 4) = result;
  *i = result;
  __dmb(0xBu);
  *(_BYTE *)(result + 16) = 1;
  v2 = ViWdIrpListLength + 1;
  __dmb(0xBu);
  ViWdIrpListLength = v2;
  v3 = v2;
  __dmb(0xBu);
  v4 = ViWdIrpListLengthMaximum;
  __dmb(0xBu);
  if ( v3 > v4 )
  {
    v5 = ViWdIrpListLength;
    __dmb(0xBu);
    ViWdIrpListLengthMaximum = v5;
  }
  return result;
}
