// sub_963EC8 
 
void **sub_963EC8()
{
  int v0; // r5
  void **result; // r0
  int v2; // r1
  int v3; // t1

  v0 = 0;
  if ( !KeNumberNodes )
    return (void **)sub_96FD40();
  result = &KeNodeBlock;
  v2 = (unsigned __int16)KeNumberNodes;
  do
  {
    v3 = (int)*result++;
    if ( *(unsigned __int16 *)(v3 + 266) == *(unsigned __int16 *)(v3 + 268) )
      ++v0;
    --v2;
  }
  while ( v2 );
  if ( v0 != 1 )
    return (void **)sub_96FD40();
  return result;
}
