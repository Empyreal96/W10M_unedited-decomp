// KeGetCurrentNodeNumber 
 
int KeGetCurrentNodeNumber()
{
  return *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
}
