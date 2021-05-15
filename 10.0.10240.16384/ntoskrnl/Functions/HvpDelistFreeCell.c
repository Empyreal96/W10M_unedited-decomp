// HvpDelistFreeCell 
 
int __fastcall HvpDelistFreeCell(int a1, int a2)
{
  int result; // r0
  int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[0] = -1;
  result = HvpGetHCell(a1, a2, v5);
  if ( result )
  {
    HvpRemoveFreeCellHint(a1, a2);
    result = HvpReleaseHCell(a1);
  }
  return result;
}
