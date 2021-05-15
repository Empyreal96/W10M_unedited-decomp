// rand 
 
int rand()
{
  dword_60E004 = 214013 * dword_60E004 + 2531011;
  return HIWORD(dword_60E004) & 0x7FFF;
}
