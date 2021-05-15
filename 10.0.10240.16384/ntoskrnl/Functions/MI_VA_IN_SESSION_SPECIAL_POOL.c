// MI_VA_IN_SESSION_SPECIAL_POOL 
 
int __fastcall MI_VA_IN_SESSION_SPECIAL_POOL(unsigned int a1)
{
  int v1; // r3
  int result; // r0

  if ( a1 >= dword_63389C
    && ((v1 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v1 == 1)
     || v1 == 11) )
  {
    result = sub_549CD8();
  }
  else
  {
    result = 0;
  }
  return result;
}
