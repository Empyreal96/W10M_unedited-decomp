// PsRevertToSelf 
 
int PsRevertToSelf()
{
  return PsRevertThreadToSelf((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0));
}
