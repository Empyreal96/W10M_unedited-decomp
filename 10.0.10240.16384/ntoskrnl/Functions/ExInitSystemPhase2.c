// ExInitSystemPhase2 
 
int ExInitSystemPhase2()
{
  int result; // r0

  sub_95F378();
  MEMORY[0xFFFF92E0] = -1;
  result = BootApplicationPersistentDataProcess(0);
  if ( dword_92038C >= (unsigned int)KeNumberProcessors_0 )
    dword_92038C = KeNumberProcessors_0;
  return result;
}
