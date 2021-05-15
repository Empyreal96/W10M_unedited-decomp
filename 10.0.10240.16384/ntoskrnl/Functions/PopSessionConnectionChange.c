// PopSessionConnectionChange 
 
int __fastcall PopSessionConnectionChange(int a1, unsigned __int8 *a2, int a3)
{
  int v4; // r7
  int v5; // r6

  v4 = *a2;
  v5 = a2[1];
  PopAcquireAdaptiveLock(1);
  PopPrintEx(3);
  if ( !v4 )
    return sub_81BAA8(a1);
  PopSessionConnected(a1, v5, a3);
  return PopReleaseAdaptiveLock();
}
