// PpmPerfReadFeedback 
 
int PpmPerfReadFeedback()
{
  int result; // r0

  if ( PpmPerfControlReadFeedback )
    result = sub_540CA4();
  else
    result = 1;
  return result;
}
