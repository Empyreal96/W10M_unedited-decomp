// ViKeObjectAcquired 
 
int __fastcall ViKeObjectAcquired(int result, _BYTE **a2, int a3)
{
  int v4; // r4
  BOOL i; // r5
  _BYTE *v6; // t1

  v4 = result;
  for ( i = a3 != 0; v4; --v4 )
  {
    v6 = *a2++;
    result = (int)v6;
    if ( (*v6 & 0x7F) == 2 )
      result = VfDeadlockAcquireResource(result, 1, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, i);
  }
  return result;
}
