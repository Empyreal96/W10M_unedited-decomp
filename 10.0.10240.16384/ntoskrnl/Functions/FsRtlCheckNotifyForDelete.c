// FsRtlCheckNotifyForDelete 
 
int *__fastcall FsRtlCheckNotifyForDelete(int *result, int a2)
{
  int *v2; // r5
  int *i; // r4

  v2 = result;
  for ( i = (int *)*result; i != v2; i = (int *)*i )
  {
    if ( i[15] == a2 )
    {
      *((_WORD *)i + 10) |= 0x20u;
      if ( (int *)i[2] != i + 2 )
        result = (int *)FsRtlNotifyCompleteIrpList((int)(i - 4));
    }
  }
  return result;
}
