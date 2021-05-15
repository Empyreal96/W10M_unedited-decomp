// PopResetActionDefaults 
 
void PopResetActionDefaults()
{
  dword_61EC80 = 0;
  dword_61EC88 = 0;
  dword_61EC8C = 1;
  byte_61EC7D = 0;
  if ( (PopAction[0] & 2) == 0 )
  {
    PopAction[0] = 0;
    byte_61EC62 = 0;
    dword_61EC64 = 0;
    dword_61EC68 = 0;
    dword_61EC70 = 0;
    byte_61EC7C = 0;
    dword_61EC74 = 11;
    dword_61EC6C = 268435459;
  }
}
