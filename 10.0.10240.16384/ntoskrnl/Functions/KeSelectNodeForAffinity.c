// KeSelectNodeForAffinity 
 
void *KeSelectNodeForAffinity()
{
  void *result; // r0

  if ( KeNumberNodes == 1 )
    result = KeNodeBlock;
  else
    result = (void *)sub_5260B8();
  return result;
}
