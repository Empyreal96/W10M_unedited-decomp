// MiInitPerfMemoryFlags 
 
int __fastcall MiInitPerfMemoryFlags(int a1, char a2)
{
  return (a1 != 0) | (2 * (a2 & 0xF));
}
