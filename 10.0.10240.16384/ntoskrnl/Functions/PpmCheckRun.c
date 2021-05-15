// PpmCheckRun 
 
int PpmCheckRun()
{
  int v0; // r2
  int (*v1)(void); // r1
  int result; // r0
  int v3; // r4
  int v4; // r0

  v0 = PpmCheckPipelineIndex;
  v1 = *(int (**)(void))(PpmCheckPipeline + 4 * PpmCheckPipelineIndex);
  if ( v1 )
  {
    while ( 1 )
    {
      PpmCheckPipelineIndex = v0 + 1;
      result = v1();
      if ( !result )
        break;
      v0 = PpmCheckPipelineIndex;
      v1 = *(int (**)(void))(PpmCheckPipeline + 4 * PpmCheckPipelineIndex);
      if ( !v1 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = PpmPerfPolicyLock;
    PpmPerfPolicyLock = 0;
    v4 = KeSetEvent((int)&byte_61E8A4, 0, 0);
    if ( v3 )
      result = sub_540AA4(v4);
    else
      result = PpmEventTracePerfCheckStop(v4);
  }
  return result;
}
