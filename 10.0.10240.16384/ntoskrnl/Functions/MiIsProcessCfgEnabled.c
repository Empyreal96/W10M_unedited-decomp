// MiIsProcessCfgEnabled 
 
BOOL MiIsProcessCfgEnabled()
{
  return MEMORY[0xC0402150] != 0;
}
