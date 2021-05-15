// FsRtlCheckNotifyForDeleteLite 
 
int *__fastcall FsRtlCheckNotifyForDeleteLite(int *result)
{
  int *v1; // r5
  int *i; // r4

  v1 = result;
  for ( i = (int *)*result; i != v1; i = (int *)*i )
  {
    *((_WORD *)i + 10) |= 0x20u;
    if ( (int *)i[2] != i + 2 )
      result = (int *)FsRtlNotifyCompleteIrpList((int)(i - 4));
  }
  return result;
}
