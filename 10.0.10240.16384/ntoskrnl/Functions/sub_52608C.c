// sub_52608C 
 
void sub_52608C()
{
  PpmCheckCurrentPipelineId = 1;
  PpmCheckPipeline = *(_DWORD *)(PpmCheckPipelines + 4);
  PpmCheckPipelineIndex = 0;
  JUMPOUT(0x460ED8);
}
