// DebugPrompt 
 
void __noreturn DebugPrompt()
{
  __debugservice();
  JUMPOUT(0x423326);
}
