// PnpIsBeingRemovedSafely 
 
int __fastcall PnpIsBeingRemovedSafely(_DWORD *a1, int a2)
{
  int result; // r0
  int v3; // r2

  if ( a2 != 1 && a2 != 2 || (a1[92] & 0x200) != 0 )
    goto LABEL_3;
  v3 = a1[43];
  if ( v3 == 782 || v3 == 783 )
    v3 = a1[44];
  if ( v3 == 776 || v3 == 778 || v3 == 775 || v3 == 779 )
    result = 0;
  else
LABEL_3:
    result = 1;
  return result;
}
